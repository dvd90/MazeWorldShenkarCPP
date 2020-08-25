#ifndef MAZE_TEST_MASTER_MAZE2DGENERATOR_H
#define MAZE_TEST_MASTER_MAZE2DGENERATOR_H

#include <iostream>
#include <vector>
#include <random>
using namespace std;
#include "Maze2d.h"

class Maze2dGenerator
{
protected:
    vector<vector<Position>> grid;
    Position Start, End; //capitalize bc end all lowers throws an error
    uint8_t cx, cy;      //current "character" position x and y
    int SIZE = 0;

public:
    Maze2dGenerator(){};
    ~Maze2dGenerator() = default;
    virtual Maze2d generate(string name, int size) = 0;
    virtual void measureAlgorithmTime(int x) = 0;
    void createGrid();
    void printTest(vector<vector<Position>> grid);

    std::string get_directions(const uint8_t &x, const uint8_t &y, bool isGen = false) const;
    char gen_next(const std::string &dir);
    void gen_walls();
    void gen_start();
    void gen_exit(const uint8_t &ent);
    void gen_switch_case(const uint8_t &swtch, const bool &isEnter);
};

#endif //MAZE_TEST_MASTER_MAZE2DGENERATOR_H
