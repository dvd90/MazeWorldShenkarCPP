#ifndef MAZE_TEST_MASTER_CONTROLLER_H
#define MAZE_TEST_MASTER_CONTROLLER_H
#include "Interface.h"

#include "AstarSolver.h"
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "BFSSolver.h"
#include <fstream>

class Controller
{
public:
    Controller(){};
    ~Controller(){};
    void Play();
    void saveMaze(vector<int> toCompress);
    void loadMaze(){};

private:
    std::shared_ptr<Interface> view;
    std::shared_ptr<Maze2d> maze;
};

#endif //MAZE_TEST_MASTER_CONTROLLER_H
