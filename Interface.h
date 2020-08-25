//
// Created by Liad Gez on 21/08/2020.
//
#include "Maze2d.h"
#include <filesystem>
#ifndef MAZE_TEST_MASTER_INTERFACE_H
#define MAZE_TEST_MASTER_INTERFACE_H

class Interface
{
public:
    string getName();
    vector<int> genMenu();
    void print(Maze2d to_print);
    void afterSave();
    void showFiles();
    void printName(Maze2d to_print);
    void mazeSize(Maze2d to_print);
    void fileSize(vector<int>);
};

#endif //MAZE_TEST_MASTER_INTERFACE_H
