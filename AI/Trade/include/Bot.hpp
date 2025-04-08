/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-trade-thomas-cluseau
** File description:
** Makefile
*/

#ifndef BOT_HPP
    #define BOT_HPP
    #include <iostream>
    #include <sstream>
    #include <vector>
    #include <unordered_map>
    #include <string>
    #include <algorithm>
    #include <cmath>

class Candle {
public:
    std::string pair;
    int date;
    double high;
    double low;
    double open;
    double close;
    double volume;

    Candle(const std::vector<std::string>& format, const std::string& intel);
};

class Chart {
public:
    std::vector<int> dates;
    std::vector<double> opens;
    std::vector<double> highs;
    std::vector<double> lows;
    std::vector<double> closes;
    std::vector<double> volumes;
    std::unordered_map<std::string, double> indicators;

    void addCandle(const Candle& candle);
    double calculateSMA(int period);
    double calculateRSI(int period);
    double calculateStandardDeviation(int period);
    double calculateEMA(int period);

};

class BotState {
public:
    int timeBank;
    int maxTimeBank;
    int timePerMove;
    int candleInterval;
    std::vector<std::string> candleFormat;
    int candlesTotal;
    int candlesGiven;
    int initialStack;
    double transactionFee;
    int date;
    std::unordered_map<std::string, double> stacks;
    std::unordered_map<std::string, Chart> charts;
    std::unordered_map<std::string, double> purchasePrices;

    BotState();
    void updateChart(const std::string& pair, const std::string& newCandleStr);
    void updateStack(const std::string& key, double value);
    void updateSettings(const std::string& key, const std::string& value);
    void updateGame(const std::string& key, const std::string& value);
};

class Bot {
public:
    BotState botState;

    void run();
    void parse(const std::string& info);
    void makeDecision();
};

#endif // BOT_HPP
