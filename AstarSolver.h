#ifndef MAZE_TEST_MASTER_ASTARSOLVER_H
#define MAZE_TEST_MASTER_ASTARSOLVER_H

#include "Searchable.h"
#include <iostream>
#include <utility>
#include <array>
#include <map>

class AstarSolver : public Searchable
{
private:
    std::pair<int, int> start_, goal_;
    std::multimap<double, ListInfo> priority_list_;
    std::map<std::pair<int, int>, ListInfo> open_list_, closed_list_;

public:
    virtual Maze2d Solve(Maze2d data);

    ~AstarSolver();

    std::pair<int, int> Up(std::pair<int, int> node) const;

    void setStart(Position pos);

    void setGoal(Position pos);

    std::pair<int, int> Right(std::pair<int, int> node) const;

    std::pair<int, int> Left(std::pair<int, int> node) const;

    std::pair<int, int> Down(std::pair<int, int> node) const;

    const int TakeDecision1(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                            const std::pair<int, int> &parent_node);

    const int TakeDecision2(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                            const std::pair<int, int> &parent_node);

    int Action();

    const double CalculateDistance(std::pair<int, int> current_node) const;

    bool IsNotObstacle(std::pair<int, int> node) const;

    bool IsWithinRegion(std::pair<int, int> node) const;

    void PlotTrajectory();
};

#endif //MAZE_TEST_MASTER_ASTARSOLVER_H
