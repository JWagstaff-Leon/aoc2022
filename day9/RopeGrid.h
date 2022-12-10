#ifndef ROPE_GRID_H
#define ROPE_GRID_H

#include <tuple>
#include <set>

#include "Head.h"
#include "Tail.h"
#include "Position.h"



class RopeGrid
{
    public:
        RopeGrid();
        
               void doSteps(char direction, int amount);
        inline int  getVisitedPositions() { return visitedPositions_.size(); };

    private:
        Head head_;
        Tail tail_;
        std::set<Position> visitedPositions_;
};

#endif