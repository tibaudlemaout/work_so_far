/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-trade-thomas-cluseau
** File description:
** Makefile
*/
#include "include/Bot.hpp"

Candle::Candle(const std::vector<std::string>& format, const std::string& intel)
{
    std::stringstream ss(intel);
    std::vector<std::string> tmp;
    std::string item;
    while (getline(ss, item, ',')) {
        tmp.push_back(item);
    }
    for (size_t i = 0; i < format.size(); ++i) {
        if (format[i] == "pair") pair = tmp[i];
        if (format[i] == "date") date = std::stoi(tmp[i]);
        if (format[i] == "high") high = std::stod(tmp[i]);
        if (format[i] == "low") low = std::stod(tmp[i]);
        if (format[i] == "open") open = std::stod(tmp[i]);
        if (format[i] == "close") close = std::stod(tmp[i]);
        if (format[i] == "volume") volume = std::stod(tmp[i]);
    }
}

void Chart::addCandle(const Candle& candle)
{
    dates.push_back(candle.date);
    opens.push_back(candle.open);
    highs.push_back(candle.high);
    lows.push_back(candle.low);
    closes.push_back(candle.close);
    volumes.push_back(candle.volume);
}

double Chart::calculateSMA(int period)
{
    double sum = 0.0;

    if (closes.size() < period)
        return 0.0;
    for (size_t i = closes.size() - period; i < closes.size(); ++i) {
        sum += closes[i];
    }
    return sum / period;
}

double Chart::calculateRSI(int period)
{
    double gain = 0.0;
    double loss = 0.0;
    double rsi = 0;

    if (closes.size() < period + 1)
        return 0.0;
    for (size_t i = closes.size() - period; i < closes.size(); ++i) {
        double change = closes[i] - closes[i - 1];
        if (change > 0) {
            gain += change;
        } else {
            loss -= change;
        }
    }
    gain /= period;
    loss /= period;
    if (loss == 0)
        return 100.0;
    rsi = gain / loss;
    return 100.0 - (100.0 / (1.0 + rsi));
}

double Chart::calculateStandardDeviation(int period)
{
    double sum = 0.0;
    double mean = calculateSMA(period);// Calculate mean (SMA)

    if (closes.size() < period + 1)
        return 0.0;
    for (size_t i = closes.size() - period; i < closes.size(); ++i) {
        sum += std::pow(closes[i] - mean, 2);
    }
    double variance = sum / period;
    return std::sqrt(variance);
}

double Chart::calculateEMA(int period)
{
    double multiplier = 2.0 / (period + 1);
    double ema = closes[0];
    if (closes.size() < period)
        return 0.0;
    for (int i = 1; i < period; ++i) {
        ema = closes[i] * multiplier + ema * (1 - multiplier);
    }
    return ema;
}


BotState::BotState() : timeBank(0), maxTimeBank(0), timePerMove(1), candleInterval(1), candlesTotal(0), candlesGiven(0), initialStack(0), transactionFee(0.2), date(0) {}

void BotState::updateChart(const std::string& pair, const std::string& newCandleStr)
{
    if (charts.find(pair) == charts.end()) {
        charts[pair] = Chart();
    }
    Candle newCandle(candleFormat, newCandleStr);
    charts[pair].addCandle(newCandle);
}

void BotState::updateStack(const std::string& key, double value)
{
    stacks[key] = value;
}

void BotState::updateSettings(const std::string& key, const std::string& value)
{
    if (key == "timebank") {
        maxTimeBank = std::stoi(value);
        timeBank = std::stoi(value);
    } else if (key == "time_per_move") {
        timePerMove = std::stoi(value);
    } else if (key == "candle_interval") {
        candleInterval = std::stoi(value);
    } else if (key == "candle_format") {
        std::stringstream ss(value);
        std::string item;
        while (getline(ss, item, ',')) {
            candleFormat.push_back(item);
        }
    } else if (key == "candles_total") {
        candlesTotal = std::stoi(value);
    } else if (key == "candles_given") {
        candlesGiven = std::stoi(value);
    } else if (key == "initial_stack") {
        initialStack = std::stoi(value);
    } else if (key == "transaction_fee_percent") {
        transactionFee = std::stod(value);
    }
}

void BotState::updateGame(const std::string& key, const std::string& value)
{
    if (key == "next_candles") {
        std::stringstream ss(value);
        std::string candleStr;
        while (getline(ss, candleStr, ';')) {
            std::stringstream ssCandle(candleStr);
            std::vector<std::string> candleInfos;
            std::string item;
            while (getline(ssCandle, item, ',')) {
                candleInfos.push_back(item);
            }
            if (!candleInfos.empty()) {
                date = std::stoi(candleInfos[1]);
                updateChart(candleInfos[0], candleStr);
            }
        }
    } else if (key == "stacks") {
        std::stringstream ss(value);
        std::string stackStr;
        while (getline(ss, stackStr, ',')) {
            std::stringstream ssStack(stackStr);
            std::vector<std::string> stackInfos;
            std::string item;
            while (getline(ssStack, item, ':')) {
                stackInfos.push_back(item);
            }
            if (stackInfos.size() == 2) {
                updateStack(stackInfos[0], std::stod(stackInfos[1]));
            }
        }
    }
}

void Bot::parse(const std::string& info)
{
    std::stringstream ss(info);
    std::string tmp;
    std::vector<std::string> tokens;
    while (ss >> tmp) {
        tokens.push_back(tmp);
    }
    if (tokens[0] == "settings") {
        botState.updateSettings(tokens[1], tokens[2]);
    } else if (tokens[0] == "update") {
        if (tokens[1] == "game") {
            botState.updateGame(tokens[2], tokens[3]);
        }
    } else if (tokens[0] == "action") {
        makeDecision();
    }
}

double roundDown(double value, int decimalPlaces)
{
    double factor = pow(10, decimalPlaces);
    return std::floor(value * factor) / factor;
}

void Bot::makeDecision(void)
{
    double dollars = botState.stacks["USDT"];
    Chart& chart = botState.charts["USDT_BTC"];
    double currentClosingPrice = chart.closes.back();
    double sma50 = chart.calculateSMA(10);
    double sma200 = chart.calculateSMA(50);
    double rsi14 = chart.calculateRSI(4);
    double ema20 = chart.calculateEMA(10);
    const double limits = 0.0001;
    double deduction = 0;
    const int precision = 8;

    //Calculate bollinger bands
    double middleBand = chart.calculateSMA(20);
    double standardDeviation = chart.calculateStandardDeviation(20);
    double upperBand = middleBand + 2 * standardDeviation;
    double lowerBand = middleBand - 2 * standardDeviation;

    if (currentClosingPrice < lowerBand) {
        double affordable = dollars / currentClosingPrice;
        affordable = roundDown(affordable * 0.5, precision);
        if (affordable > 0) {
            std::cout << "buy USDT_BTC " << 0.5 * affordable << std::endl << std::flush;
            deduction =  (currentClosingPrice / 100) * (botState.transactionFee * 10);
            botState.purchasePrices["USDT_BTC"] = currentClosingPrice - deduction;
        }
    }
    if (sma50 > sma200 && rsi14 < 30 && currentClosingPrice < lowerBand && dollars > 100 && dollars > 100) {
        double affordable = dollars / currentClosingPrice;
        affordable = roundDown(affordable * 0.5, precision);
        if (affordable > 0) {
            std::cout << "buy USDT_BTC " << 0.5 * affordable << std::endl << std::flush;
            deduction =  (currentClosingPrice / 100) * (botState.transactionFee * 10);
            botState.purchasePrices["USDT_BTC"] = currentClosingPrice - deduction;
        }
    if (rsi14 < 30 && currentClosingPrice < lowerBand && dollars > 100 && currentClosingPrice > ema20 && dollars > 100) {
        double affordable = dollars / currentClosingPrice;
        affordable = roundDown(affordable * 0.5, precision);
        if (affordable > 0) {
            std::cout << "buy USDT_BTC " << 0.5 * affordable << std::endl << std::flush;
            deduction =  (currentClosingPrice / 100) * (botState.transactionFee * 10);
            botState.purchasePrices["USDT_BTC"] = currentClosingPrice - deduction;
        }
    }
    } else if (sma50 < sma200 && rsi14 > 70 && currentClosingPrice > upperBand && botState.stacks["BTC"] > limits && currentClosingPrice < ema20) {
        double btc = botState.stacks["BTC"];
        std::cout << "sell USDT_BTC " << btc << std::endl << std::flush;
    } else if ( rsi14 > 70 && currentClosingPrice > upperBand && botState.stacks["BTC"] > limits && currentClosingPrice < ema20) {
        double btc = botState.stacks["BTC"];
        std::cout << "sell USDT_BTC " << btc << std::endl << std::flush;
    } else {
        std::cout << "no_moves" << std::endl << std::flush;
    }
}

void Bot::run(void)
{
    std::string reading;
    while (getline(std::cin, reading)) {
        if (reading.empty())
            continue;
        parse(reading);
    }
}
