#include "RopeGrid.h"

#include "Position.h"



RopeGrid::RopeGrid(int tails)
{
    tails_.push_back(Tail());
    for (int i = 1; i < tails; i++)
    {
        tails_.push_back(Tail());
    }
    visitedPositions_.insert(tails_[tails_.size() - 1].getPosition());
};


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
        tails_[0].moveTowards(head_.getPosition());
        for (int i = 1; i < tails_.size(); i++)
        {
            tails_[i].moveTowards(tails_[i - 1].getPosition());
        }
        visitedPositions_.insert(tails_[tails_.size() - 1].getPosition());
    }
};