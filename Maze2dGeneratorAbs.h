#ifndef MAZE_TEST_MASTER_MAZE2DGENERATORABS_H
#define MAZE_TEST_MASTER_MAZE2DGENERATORABS_H

#include <chrono>
#include "Maze2dGenerator.h"
using namespace std::chrono;
using namespace std;
class Maze2dGeneratorAbs : public Maze2dGenerator
{

public:
    virtual Maze2d generate(string name, int size) = 0;
    virtual void measureAlgorithmTime(int x);

protected:
    high_resolution_clock::time_point _start;
    high_resolution_clock::time_point _end;
};

#endif
