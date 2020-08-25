#include "Searchable.h"

Searchable::Searchable() {}

Searchable::~Searchable()
{
}

void Searchable::createGrid(Maze2d &maze)
{

    vector<Position> pos(maze._Size);
    // initiate grid
    for (uint8_t x = 0; x < maze._Size; x++)
    {
        grid_.push_back(pos);
    }

    for (uint8_t x = 0; x < maze._Size; x++)
    {
        for (uint8_t y = 0; y < maze._Size; y++)
        {
            grid_[x][y].x = x;
            grid_[x][y].y = y;
            grid_[x][y].atr = maze._grid[x][y].atr;
        }
    }
};
