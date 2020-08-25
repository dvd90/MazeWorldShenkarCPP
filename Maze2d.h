#ifndef MAZE_TEST_MASTER_MAZE2D_H
#define MAZE_TEST_MASTER_MAZE2D_H
#include <string>
#include <utility>
#include <vector>
#include "Position.h"
#include <iostream>    //cout for print()
#include "universal.h" //randmaze (random numbers)
#include <stack>       //stack s for DFS gen and min_steps
#include <map>

using namespace std;

class Maze2d
{
public:
    string _name;
    Position _Start;
    Position _End;
    Position _PlayerPosition;
    vector<vector<Position>> _grid;
    int _Size = 0;

public:
    Maze2d(){};

    Maze2d(string name, Position Start, Position End, Position player, vector<vector<Position>> maze, int size) : _name(name), _Start(Start), _End(End), _PlayerPosition(player), _grid(maze), _Size(size){};
    Maze2d(const Maze2d &maze)
    {
        *this = maze;
    }
    ~Maze2d(){};
    Position getStartPosition();
    Position getGoalPosition();
    string getNAme();
    vector<vector<Position>> getData();
    vector<int> compress(Maze2d data);
};

#endif //MAZE_TEST_MASTER_MAZE2D_H
