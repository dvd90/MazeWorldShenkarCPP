#include "Maze2dGeneratorAbs.h"

#include <iostream>
#include <unistd.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

void Maze2dGeneratorAbs::measureAlgorithmTime(int x)
{
    //get init time
    if (x == 0)
        _start = high_resolution_clock::now();

    //create maze

    if (x == 1)
    { // catch time after maze creation
        _end = high_resolution_clock::now();

        // save create duration
        auto duration = duration_cast<microseconds>(_start - _end).count();

        // cout
        cout << "Generating a " << (int)SIZE << "x" << (int)SIZE << " maze took " << (duration * -1) << " microseconds."
             << '\n';
    }
}
