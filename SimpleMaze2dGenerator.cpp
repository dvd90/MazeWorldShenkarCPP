#include <random>
#include "Interface.h"
#include "SimpleMaze2dGenerator.h"

using std::cout;
using std::uniform_int_distribution;
using namespace std;

Maze2d SimpleMaze2dGenerator::generate(string name, int size)
{
    SIZE = size;
    //set board game and borders
    createGrid();

    //set start to top left
    int x = 1;
    int y = SIZE;
    grid[x][y].atr = Enter;
    Start = grid[x][y];

    // walking randomly
    while (x < SIZE - 1 && y > 1)
    {
        int direct = rand() % 2;
        switch (direct)
        {
        case 0: //move right
            grid[++x][y].atr = Open;
            break;
        case 1: //move down
            grid[x][--y].atr = Open;
            break;
        default:
            break;
        }
        cout << endl;
        printTest(grid);
    }
    End = grid[x][y];
    cout << endl;
    gen_walls();
    cout << endl;
    printTest(grid);
    cout << endl;
    printTest(grid);
    return Maze2d(name, Start, End, Start, grid, size);
}