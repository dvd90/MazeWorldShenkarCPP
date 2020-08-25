#ifndef MAZE_TEST_MASTER_POSITION_H
#define MAZE_TEST_MASTER_POSITION_H

#include <iostream>
using namespace std;
enum attribute : uint8_t
{
        Enter = 0,
        Exit = 1,
        Open = 2,
        Wall = 3,
        Unassigned = 4
};
enum generation : uint8_t
{
        Unvisited = 0,
        Visited = 1
};

class Position
{

public:
        attribute atr = Unassigned;
        bool is_seen = true;
        generation gen = Unvisited;
        uint8_t x, y; //these are for keeping track of the x/y for gen purposes
        bool has_player = false;
};

#endif //MAZE_TEST_MASTER_POSITION_H
