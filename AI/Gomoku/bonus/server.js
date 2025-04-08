const http = require("http");
const express = require("express");
const multer = require("multer");
const fs = require("fs");
const path = require("path");
const { spawn } = require("child_process");
const socketIo = require("socket.io");

const PORT = 4242;

const app = express();
const server = http.createServer(app);
const io = socketIo(server);

const game = multer({ dest: path.join(__dirname, "temp/") });

const botPath = path.join(__dirname, "bot");

// Create bot/ if it doesn"t exist
if (!fs.existsSync(botPath)) {
    fs.mkdirSync(botPath);
}

app.use(express.static(path.join(__dirname, "public")));
app.use(express.json());  // Idk if it"s really useful but I keep it for the moment

app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "index.html"));
});

app.get("/in-game", (req, res) => {
    res.sendFile(path.join(__dirname, "public/in-game.html"));
});

app.get("/lose", (req, res) => {
    res.sendFile(path.join(__dirname, "public", "lose.html"));
});

app.get("/win", (req, res) => {
    res.sendFile(path.join(__dirname, "public", "win.html"));
});

let currentMapSize = 15; // Default map size
let botProcess;
let currentWhoStarts = "player";

app.post("/game", game.single("file"), (req, res) => {
    const file = req.file;
    const mapSize = parseInt(req.body.mapSize);
    const whoStarts = req.body.whoStarts || "player";

    if (!file) {
        return res.status(400).send("You must select a file");
    }

    if (!file.originalname.endsWith(".gomoku")) {
        return res.status(400).send("The file must have a .gomoku extension");
    }

    if (mapSize < 5) {
        return res.status(400).send("The map size must be at least 5");
    }

    currentMapSize = mapSize;
    currentWhoStarts = whoStarts;

    // Rename and move file into bot/
    const botFilePath = path.join(botPath, "bot");
    fs.renameSync(file.path, botFilePath);

    // Set bot permissions
    fs.chmodSync(botFilePath, "755");

    // Flux redirection
    const stdoutLogPath = path.join(botPath, "bot_stdout.log");
    const stderrLogPath = path.join(botPath, "bot_stderr.log");
    const stdinLogPath = path.join(botPath, "bot_stdin.txt");

    // Execute given file
    executeBot(botFilePath, stdoutLogPath, stderrLogPath, stdinLogPath, mapSize, whoStarts);

    res.send(`
        File uploaded and moved to "bot" successfully<br>
        Given map size: ${mapSize}<br>
        Starting player: ${whoStarts}
    `);
});

app.get("/game-config", (req, res) => {
    res.json({ 
        mapSize: currentMapSize, 
        whoStarts: currentWhoStarts
    });
});

function executeBot(botFilePath, stdoutLogPath, stderrLogPath, stdinLogPath, mapSize, whoStarts) {
    // 1 sec timeout before execution
    setTimeout(() => {
        if (!fs.existsSync(botFilePath)) {
            console.error(`Error: The bot file does not exist at ${botFilePath}`);
            return;
        }

        // Process creation
        botProcess = spawn(botFilePath, [], {
            stdio: [
                "pipe",
                "pipe",
                "pipe",
            ]
        });

        if (!botProcess || !botProcess.stdout || !botProcess.stderr) {
            console.error("Error: The bot process could not be started");
            return;
        }

        // Flux redirection into bot"s files and attach them to process
        const stdoutStream = fs.createWriteStream(stdoutLogPath, { flags: "w" });
        const stderrStream = fs.createWriteStream(stderrLogPath, { flags: "w" });
        botProcess.stdout.pipe(stdoutStream);
        botProcess.stderr.pipe(stderrStream);

        let inputData = `START ${mapSize}\n`;
        fs.writeFileSync(stdinLogPath, inputData);
        botProcess.stdin.write(inputData);

        let beginSent = false;
        let coordinatesReceived = false;

        botProcess.stdout.on("data", (data) => {
            console.log(`[stdout]: ${data.toString()}`);

            // Check for "OK" in the output and send BEGIN
            if (data.toString().includes("OK") && !beginSent && whoStarts === "bot") {
                const beginData = "BEGIN\n";
                fs.appendFileSync(stdinLogPath, beginData);  // Add BEGIN command to log
                botProcess.stdin.write(beginData);  // Send BEGIN command to bot
                beginSent = true;
            }

            // Wait for coordinates and send them to client
            if (!coordinatesReceived && /^[0-9]+,[0-9]+$/.test(data.toString().trim())) {
                console.log(`Coordinates received: ${data.toString().trim()}`);
                coordinatesReceived = true;

                const coordinates = data.toString().trim().split(",");
                const x = parseInt(coordinates[0]);
                const y = parseInt(coordinates[1]);
                io.emit("coordinates", { x, y });
            }
        });

        botProcess.stderr.on("data", (data) => {
            console.error(`[stderr]: ${data.toString()}`);
        });

        botProcess.on("exit", (code) => {
            console.log(`Bot process exited with code ${code}`);
        });
    }, 1000);
}

app.post("/turn", (req) => {
    const { x, y } = req.body;

    let coordinatesReceived = false;

    if (botProcess && botProcess.stdin) {
        const turnCommand = `TURN ${x},${y}\n`;
        fs.appendFileSync(path.join(botPath, "bot_stdin.txt"), turnCommand);  // Add TURN command to log
        botProcess.stdin.write(turnCommand);  // Send TURN command to bot
        console.log(`Commande TURN envoyée : ${turnCommand.trim()}`);
    }

    botProcess.stdout.on("data", (data) => {
        console.log(`[stdout]: ${data.toString()}`);

        // Wait for coordinates and send them to client
        if (!coordinatesReceived && /^[0-9]+,[0-9]+$/.test(data.toString().trim())) {
            console.log(`Coordinates received: ${data.toString().trim()}`);
            coordinatesReceived = true;

            const coordinates = data.toString().trim().split(",");
            const x = parseInt(coordinates[0]);
            const y = parseInt(coordinates[1]);
            io.emit("coordinates", { x, y });
        }
    });
});

// Start server
server.listen(PORT, () => {
    console.log(`🚀 Server started at http://localhost:${PORT}`);
});
