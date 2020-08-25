#ifndef MAZE_TEST_MASTER_BFSSOLVER_H
#define MAZE_TEST_MASTER_BFSSOLVER_H

#include "Searchable.h"

class BFSSolver : public Searchable
{

public:
    BFSSolver() : Searchable(){};
    virtual Maze2d Solve(Maze2d data);
    virtual ~BFSSolver(){};
};

#endif //MAZE_TEST_MASTER_BFSSOLVER_H
