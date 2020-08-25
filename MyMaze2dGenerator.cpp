#include "MyMaze2dGenerator.h"

using std::cout;
using std::uniform_int_distribution;

Maze2d MyMaze2dGenerator::generate(string name, int size)
{
    SIZE = size;
    //set board game and borders
    createGrid();
    // create stack for DFS generation
    std::stack<Position> s;
    uniform_int_distribution<uint8_t> startpt(1, SIZE - 3);
    uint8_t x;
    uint8_t y;

    startpt(randmaze);     //run the randmaze once before using it
    x = startpt(randmaze); //x = startpt(randmaze);
    y = startpt(randmaze);

    /* We do the following to confirm x (and y) begins on an odd number. If they
    do not, our implementation of DFS will not work correctly. We depend on each
    calculation moving two blocks at a time. If it starts on an even block, the
    "edge" will be two blocks thick. Making them odd ensures the wall stays one
    block thick. */
    if (x % 2 == 0) //if x is even
        x++;
    if (y % 2 == 0) //if y is even
        y++;

    grid[x][y].atr = Open;
    s.push(grid[x][y]);

    while (!s.empty())
    {
        x = s.top().x;
        y = s.top().y;

        std::string dir = get_directions(x, y, true); //get all avail. directions

        switch (gen_next(dir))
        {
        case 'r': //move right
            grid[x + 1][y].atr = Open;
            grid[x + 2][y].atr = Open;
            s.push(grid[x + 2][y]);
            break;
        case 'u': //move up
            grid[x][y + 1].atr = Open;
            grid[x][y + 2].atr = Open;
            s.push(grid[x][y + 2]);
            break;
        case 'l': //move left
            grid[x - 1][y].atr = Open;
            grid[x - 2][y].atr = Open;
            s.push(grid[x - 2][y]);
            break;
        case 'd': //move down
            grid[x][y - 1].atr = Open;
            grid[x][y - 2].atr = Open;
            s.push(grid[x][y - 2]);
            break;
        default:
            s.pop();
            break;
        }
    }
    gen_walls();
    gen_start();
    return Maze2d(name, Start, End, Start, grid, size);
}