#include "RopeGrid.h"

#include "Position.h"



RopeGrid::RopeGrid()
{
    visitedPositions_.insert(tail_.getPosition());
};


#include <iostream>
void RopeGrid::doSteps(char direction, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        switch(direction)
        {
            case 'U':
                head_.moveBy(Position(0, 1));
                break;
            
            case 'L':
                head_.moveBy(Position(-1, 0));
                break;
            
            case 'R':
                head_.moveBy(Position(1, 0));
                break;
            
            case 'D':
                head_.moveBy(Position(0, -1));
                break;
            
            default:
                break;
        }
        tail_.moveTowards(head_.getPosition());
        visitedPositions_.insert(tail_.getPosition());
    }
};