#include "Controller.h"

void Controller::Demo()
{
    // ask for name
    string name = view->getName();
    // ask for creation type and size
    vector<int> gen_choice = view->genMenu();
    Maze2d maze;
    if (gen_choice[1] == 1)
    {
        SimpleMaze2dGenerator gen;
        gen.measureAlgorithmTime(0);
        maze = gen.generate("name", gen_choice[0]);
        gen.measureAlgorithmTime(1);
        view->print(maze);
    }

    if (gen_choice[1] == 2)
    {
        MyMaze2dGenerator gen;
        gen.measureAlgorithmTime(0);
        maze = gen.generate("name", gen_choice[0]);
        gen.measureAlgorithmTime(1);
        view->print(maze);
    }

    if (gen_choice[1] == 3)
    {
        MyMaze2dGenerator gen;
        maze = gen.generate("name", gen_choice[0]);
        AstarSolver solution;
        view->print(solution.Solve(maze));
    }
    if (gen_choice[1] == 4)
    {
        MyMaze2dGenerator gen;
        maze = gen.generate("name", gen_choice[0]);
        BFSSolver solution;
        solution.Solve(maze);
    }
    if (gen_choice[1] == 5)
    {
        MyMaze2dGenerator gen;
        maze = gen.generate("name", gen_choice[0]);
        view->print(maze);

        vector<int> compressed;
        compressed = maze.compress(maze);

        saveMaze(compressed);
        view->afterSave();
    }
    if (gen_choice[1] == 6)
    {
        view->showFiles();
    }
}

void Controller::saveMaze(vector<int> toCompress)
{
    std::ofstream f("CompressedMaze.txt");
    for (vector<int>::const_iterator i = toCompress.begin(); i != toCompress.end(); ++i)
    {
        f << *i << '\n';
    }
}