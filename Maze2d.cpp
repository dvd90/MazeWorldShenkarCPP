#include "Maze2d.h"

std::vector<int> Maze2d::compress(Maze2d data)
{

    std::vector<int> compressedMazeData;

    compressedMazeData.push_back(data._Start.x); //for x index of start position
    compressedMazeData.push_back(data._Start.y); //for y index of start position
    compressedMazeData.push_back(data._End.x);   //for x index of end position
    compressedMazeData.push_back(data._End.y);   //for y index of end position
    compressedMazeData.push_back(data._Size);    //for maze size

    int numOfOccurrencesInARow = 1;

    for (int x = 0; x < data._Size; x++)
    {
        for (int y = 0; y < data._Size; y++)
        {
            if (data._grid[x][y].atr == data._grid[x][y + 1].atr)
            {
                numOfOccurrencesInARow++;
            }
            else
            {
                if (data._grid[x][y].atr == Wall)
                {
                    compressedMazeData.push_back(1);
                    compressedMazeData.push_back(numOfOccurrencesInARow);
                }
                if (data._grid[x][y].atr == Open || data._grid[x][y].atr == Enter || data._grid[x][y].atr == Exit)
                {
                    compressedMazeData.push_back(0);
                    compressedMazeData.push_back(numOfOccurrencesInARow);
                }
                numOfOccurrencesInARow = 1;
            }
        }
    }

    return compressedMazeData;
}

Position Maze2d::getStartPosition()
{
    return _Start;
}

Position Maze2d::getGoalPosition()
{
    return _End;
}

string Maze2d::getNAme()
{
    return _name;
}

vector<vector<Position>> Maze2d::getData()
{
    return _grid;
}
