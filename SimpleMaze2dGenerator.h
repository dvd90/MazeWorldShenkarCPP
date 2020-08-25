#ifndef MAZE_TEST_MASTER_SIMPLEMAZE2DGENERATOR_H
#define MAZE_TEST_MASTER_SIMPLEMAZE2DGENERATOR_H
#include "Maze2dGeneratorAbs.h"

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{

public:
    SimpleMaze2dGenerator() : Maze2dGeneratorAbs(){};
    ~SimpleMaze2dGenerator() = default;

    virtual Maze2d generate(string name, int size);
};
#endif //MAZE_TEST_MASTER_MAZE2DGENERATOR_H
