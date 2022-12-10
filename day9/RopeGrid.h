#ifndef ROPE_GRID_H
#define ROPE_GRID_H

#include <set>
#include <vector>

#include "Head.h"
#include "Tail.h"
#include "Position.h"



class RopeGrid
{
    public:
        RopeGrid(int tails = 1);
        
               void doSteps(char direction, int amount);
        inline int  getVisitedPositions() { return visitedPositions_.size(); };

    private:
        Head               head_;
        std::vector<Tail>  tails_;
        std::set<Position> visitedPositions_;
};

#endif