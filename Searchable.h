#include "Maze2d.h"
#ifndef MAZE_TEST_MASTER_SEARCHABLE_H
#define MAZE_TEST_MASTER_SEARCHABLE_H

struct ListInfo
{
    double cost_g = 0;
    double cost_h = -10;
    double total_cost = -10;
    pair<int, int> node{make_pair(-100, -100)};
    pair<int, int> parent{make_pair(-100, -100)};
};

#include <memory>
#include <random>
#include <vector>

class Searchable
{
public:
    vector<vector<Position>> grid_;
    Searchable();
    void createGrid(Maze2d &maze);
    virtual Maze2d Solve(Maze2d data) = 0;
    virtual ~Searchable();
};

#endif //MAZE_TEST_MASTER_SEARCHABLE_H
