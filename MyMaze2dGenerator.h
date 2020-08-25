#ifndef MAZE_TEST_MASTER_MYMAZE2DGENERATOR_H
#define MAZE_TEST_MASTER_MYMAZE2DGENERATOR_H
#include "Maze2dGeneratorAbs.h"

class MyMaze2dGenerator : public Maze2dGeneratorAbs
{

public:
    MyMaze2dGenerator(){};
    ~MyMaze2dGenerator() = default;

    Maze2d generate(string name, int size);
};
#endif //MAZE_TEST_MASTER_MAZE2DGENERATOR_H
