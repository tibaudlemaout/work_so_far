# Zappy

A network game with multiple teams and <span style="color:#B31ca6">AI</span>, made of three different executables.

## First executable: Zappy Server

This is the main server, that generates everything we need.
> Created in C

### Usage

```sh
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
    port        the port number
    width       the width of the map, in tiles
    height      the height of the map, in tiles
    nameX       a list of team names
    clientsNb   the number of authorized clients per team
    freq        the time unit for execution of actions
```

The server, once launched, is the core of the game himself.
We can connect a <span style="color:#4d30bf">GUI</span> and multiple <span style="color:#B31ca6">AI</span> in order to interact with it.

## GUI executable

### Usage

```sh
USAGE: ./zappy_gui -p port [-h host]
    port        the port number
    host        the host (default localhost)
```

The <span style="color:#4d30bf">GUI</span> is used to display the world itself.

#### Protocol

> This is how the <span style="color:#4d30bf">GUI</span> can interact with the server
> The team name GRAPHIC is reserved for the <span style="color:#4d30bf">GUI</span> to authenticate itself as such to the server

|   Symbol  |                 Meaning                 |
|-----------|-----------------------------------------|
|     X     |       width or horizontal position      |
|     Y     |       height or vertical position       |
|    q0     |       ressource 0 (food) quantity       |
|    q1     |     ressource 1 (linemate) quantity     |
|    q2     |     ressource 2 (deraumere) quantity    |
|    q3     |      ressource 3 (sibur) quantity       |
|    q4     |     ressource 4 (mendiane) quantity     |
|    q5     |      ressource 5 (phiras) quantity      |
|    q6     |     ressource 6 (thystame) quantity     |
|     n     |               player number             |
|     O     |   orientation: 1(N), 2(E), 3(S), 4(W)   |
|     L     |       player or incantation level       |
|     e     |                egg number               |
|     T     |                time unit                |
|     N     |            name of the team             |
|     R     |           incantation result            |
|     M     |                 message                 |
|     i     |             resource number             |

##### Commands:

|                   Server                   |   Client  |                   Details                     |
|--------------------------------------------|:---------:|-----------------------------------------------|
| msz X Y\n                                  | msz\n     | map size                                      |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n             | bct X Y\n | content of a tile                             |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles | mct\n     | content of the map (all the tiles)            |
| tna N\n * nbr_teams                        | tna\n     | name of all the teams                         |
| pnw #n X Y O L N\n                         |     -     | connection of a new player                    |
| ppo #n X Y O\n                             | ppo #n\n  | player's position                             |
| plv #n L\n                                 | plv #n\n  | player's level                                |
| pin #n X Y q0 q1 q2 q3 q4 q5 q6\n          | pin #n\n  | player's inventory                            |
| pex #n\n                                   |     -     | expulsion                                     |
| pbc #n M\n                                 |     -     | broadcast                                     |
| pic X Y L #n #n ...\n                      |     -     | start of an incantation (by the first player) |
| pie X Y R\n                                |     -     | end of an incantation                         |
| pfk #n\n                                   |     -     | egg laying by the player                      |
| pdr #n i\n                                 |     -     | resource dropping                             |
| pgt #n i\n                                 |     -     | resource collecting                           |
| pdi #n\n                                   |     -     | death of a player                             |
| enw #e #n X Y\n                            |     -     | an egg was laid by a player                   |
| ebo #e\n                                   |     -     | player connection for an egg                  |
| edi #e\n                                   |     -     | death of an egg                               |
| sgt T\n                                    |     -     | time unit request                             |
| sst T\n                                    | sst T\n   | time unit modification                        |
| seg N\n                                    |     -     | end of game                                   |
| smg M\n                                    |     -     | message from the server                       |
| suc\n                                      |     -     | unknown command                               |
| sbp\n                                      |     -     | command parameter                             |

This is how informations are transmitted between the server and the <span style="color:#4d30bf">GUI</span>:

```
1- The client connects the GUI to the server's port

2- The server and the client communicate the following way:
    Server --> WELCOME\n
           <-- GRAPHIC\n
           --> game informations (see the above grid)
```

## AI executable

### Usage

```sh
USAGE: ./zappy_ai -p port -n name [-h host]
    port        the port number
    name        the team name
    host        the host (default localhost)
```
An <span style="color:#B31ca6">AI</span> represents a team and its player. They interact with the server to win the game

### Protocol

Each player responds to the following actions and only to these ones, with the following syntax:

|            Action            |       Command      | Time limit |                   Response                    |
|------------------------------|--------------------|:----------:|-----------------------------------------------|
| move up one tile             | __Forward__        |     7/f    | ok                                            |
| turn 90° right               | __Right__          |     7/f    | ok                                            |
| turn 90° left                | __Left__           |     7/f    | ok                                            |
| look around                  | __Look__           |     7/f    | [tile1, tile2,...]                            |
| inventory                    | __Inventory__      |     1/f    | [linemate n, sibur n, ...]                    |
| broadcast text               | __Broadcast text__ |     7/f    | ok                                            |
| number of team unused slots  | __Connect_nbr__    |      -     | value                                         |
| fork a player                | __Fork__           |    42/f    | ok                                            |
| eject players from this tile | __Eject__          |     7/f    | ok/ko                                         |
| death of a player            | _-_                |      -     | dead                                          |
| fork a player                | __Fork__           |    42/f    | ok                                            |
| take object                  | __Take object__    |     7/f    | ok/ko                                         |
| set object down              | __Set object__     |     7/f    | ok/ko                                         |
| start incantation            | __Incantation__    |    300/f   | Elevation underway<br>Current level: k<br>/ko |

> All commands are transmitted through a character string that ends with a new line.
> In case of a bad/unknown command, the server must answer "ko".

The <span style="color:#B31ca6">AI</span> client's connection to the server happens as follows:

```
1- The client connects the IA to the server's port

2- The server and the client communicate the following way:
    Server --> WELCOME\n
           <-- TEAM-NAME\n
           --> game informations (see the above grid)
```

> The client can send up to 10 requests in a row without any response from the server. Over 10, the server will no longer take them into account

### General informations
#### Context
<pre>
The game is about managing a world and its inhabitants.
This world, Trantor is geographically made of zero-relief planes: no craters, no valleys, no moun-
tains.
The game board represents the entirety of this world’s surface, like a world map.
</pre>

#### Ressources
<pre>
The environment is rather rich in resources (mineral as well as dietary).
Therefore, by walking around this planet, the players can find succulent food and a variety of
natural stones.
These stones have six distinct categories, as follows:

✓ linemate
✓ deraumere
✓ sibur
✓ mendiane
✓ phiras
✓ thystame

The server spawns resources upon starting and every 20 time units.
</pre>

#### Activities
<pre>
Trantor’s inhabitants take care of two things:

✓ feeding themselves
✓ looking for, and collecting, stones

These objectives determine elevation, which is an important activity for the Trantorians.
</pre>

#### Individuals
<pre>
The inhabitants are bodiless, blurry and takes up the entire tile they are in.
They are pacifists. They are neither violent nor aggressive.
They eat and meander happily in search of stones.
They easily run into their fellow creatures on the same tile.
Trantorians can see as far as their visual capacities allow.
It is impossible to distinguish their direction when we run into them.
The food the Trantorians collect is the only resource they need to survive.
One unit of food allows them to live for 126 time units.
</pre>

#### The elevation ritual
<pre>
Everyone’s goal is to rise up in the Trantorian hierarchy.
This ritual, which enhances physical and mental capacities must be done according to a partic-
ular rite: they must gather the following on the same unit of terrain:
✓ At least a certain number of each stones
✓ At least a certain number of players with the same level
The elevation begins as soon as a player initiates the incantation.
It is not necessary for the players to be on the same team; they only need to be of the same level.
Every player in a group doing an incantation attain the higher level.
Passed down from generation to generation, the elevation secret comes down to this:
</pre>

| elevation | nb players | linemate | deraumere | sibur | mendiane | phiras | thystame |
|:---------:|:----------:|:--------:|:---------:|:-----:|:--------:|:------:|:--------:|
|   1->2    |     1      |    1     |     0     |   0   |    0     |   0    |    0     |
|   2->3    |     2      |    1     |     1     |   1   |    0     |   0    |    0     |
|   3->4    |     2      |    2     |     2     |   1   |    0     |   2    |    0     |
|   4->5    |     4      |    1     |     1     |   2   |    0     |   1    |    0     |
|   5->6    |     4      |    1     |     1     |   1   |    3     |   0    |    0     |
|   6->7    |     6      |    1     |     1     |   3   |    0     |   1    |    0     |
|   7->8    |     6      |    2     |     2     |   2   |    2     |   2    |    1     |

<pre>
The verification of the prerequisites for the incantation is done at the beginning and at the end
of the action.
</pre>
> If the conditions are not met at one of the verifications, the elevation fails.
> Each player participating is an elevation is frozen during the ritual. They can’t do any other action in the meantime.
<pre>
Once the ritual succeeds, the stones are removed from the terrain.
</pre>

#### Communication
<pre>
Sound is a wave that spreads out linearly (at least on Trantor) by broadcasting.
All the players can hear the broadcasts without knowing who is playing them.
They can only perceive the direction the sound is coming from and its subsequent message.

The direction is indicated by the number of the tile affected by the sound, before arriving
in the player’s tile.
This numbering is done through attributing 1 to the tile that is located in front of the player,
then through deducting the tiles that trigonomically encircle the player.
In the event that the broadcast is emitted from the same player receptor tile, they will
receive the message coming from the 0 tile.
</pre>
> As the world is spherical, several trajectories are possible for the sound between the emitter and the player.
> The shortest path will always be chosen.
