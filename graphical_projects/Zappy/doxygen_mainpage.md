# Zappy Project Documentation

Welcome to the Zappy project!

Zappy is a tribute to Zaphod Beeblebrox, a network game where several teams confront each other on a tile map containing resources. The winning team is the first one where at least 6 players reach the maximum elevation.

## Environment

The game is about managing a world and its inhabitants.  
This world, Trantor, is geographically made of zero-relief planes: no craters, no valleys, no mountains.  
The game board represents the entirety of this world’s surface, like a world map.  
If a player exits by the right of the board, they will come back through the left. Up->down, and so on.

The environment is rather rich in resources (mineral as well as dietary).  
Therefore, by walking around this planet, the players can find succulent food and a variety of natural stones. These stones have six distinct categories: linemate, deraumere, sibur, mendiane, phiras, thystame.

## Binaries

The project includes three binaries: zappy_server (C), zappy_gui (C++), and zappy_ai (C++).  
Our Makefile contain a zappy_server, a zappy_gui, and a zappy_ai rules to compile the eponymous binaries.  
In this project, we use the whole C standard library.  

## How to use
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 . . . -c clientsNB -f freq  
    -p port     port number  
    -x width    width of the world  
    -y height   height of the world  
    -n name1 name2...   name of the team  
    -c clientsNb        number of authorized clients per team  
    -f freq     reciprocal of time unit for execution of actions  

USAGE: ./zappy_ai -p port -n name -h machine  
-p port     the port of the server  
-n name     the name of the team  
-h machine  the ip adresse of your localhost  

USAGE: ./zappy_gui -p port  
-p port     the port of the server  

---

For more details and constraints, please refer to the subsequent pages of this documentation.