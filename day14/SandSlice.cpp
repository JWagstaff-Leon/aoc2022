#include "SandSlice.h"

#include <assert.h>
#include <cstdint>
#include <utility>

SandSlice::SandSlice(std::pair<int32_t, int32_t> sandSource)
: sandSource_(sandSource), blockVoid_(false)
{ /* Intentionally empty */ };



void SandSlice::newRockAt(std::pair<int32_t, int32_t> coord)
{
    lastCoord_ = coord;
};



void SandSlice::blockToCoord(std::pair<int32_t, int32_t> coord)
{
    if(lastCoord_.first != coord.first && lastCoord_.second != coord.second)
        assert(false);
    
    int32_t y_from, y_to, x_from, x_to;
    if(lastCoord_.first == coord.first)
    {
        x_from = x_to = coord.first;
        if(lastCoord_.second < coord.second)
        {
            y_from = lastCoord_.second;
            y_to = coord.second;
        }
        else
        {
            y_from = coord.second;
            y_to = lastCoord_.second;
        }
    }
    else //if *.second are equal
    {
        y_from = y_to = coord.second;
        if(lastCoord_.first < coord.first)
        {
            x_from = lastCoord_.first;
            x_to = coord.first;
        }
        else
        {
            x_from = coord.first;
            x_to = lastCoord_.first;
        }
    }

    if(y_to > lowestRock_)
        lowestRock_ = y_to;

    for(int32_t x = x_from; x <= x_to; x++)
        for(int32_t y = y_from; y <= y_to; y++)
            slice_.block(std::pair<int32_t, int32_t>(x, y));
    
    lastCoord_ = coord;
};



bool SandSlice::pourSandAndCheckSettles()
{
    std::pair<int32_t, int32_t> settleSpot = pourSand();
    if(settleSpot.second > lowestRock_)
        return false;

    return true;
};



bool SandSlice::pourSandAndCheckSourceBlocked()
{
    std::pair<int32_t, int32_t> settleSpot = pourSand();
    if(settleSpot == sandSource_)
        return true;
    
    return false;
};



void SandSlice::setBlockVoid(bool shouldBlock)
{
    blockVoid_ = shouldBlock;
};



std::pair<int32_t, int32_t> SandSlice::pourSand()
{
    std::pair<int32_t, int32_t> sandCoord = sandSource_;

    std::pair<int32_t, int32_t> below = std::make_pair<int32_t, int32_t>(sandCoord.first + 0, sandCoord.second + 1);
    std::pair<int32_t, int32_t> left = std::make_pair<int32_t, int32_t>(sandCoord.first - 1, sandCoord.second + 1);
    std::pair<int32_t, int32_t> right = std::make_pair<int32_t, int32_t>(sandCoord.first + 1, sandCoord.second + 1);

    while(!slice_.isBlocked(below) || !slice_.isBlocked(left) || !slice_.isBlocked(right))
    {
        if(sandCoord.second > lowestRock_)
            break; // sand fell past the lowest point without settling
        
        if(!slice_.isBlocked(below))
            sandCoord = below;
        else if(!slice_.isBlocked(left))
            sandCoord = left;
        else if(!slice_.isBlocked(right))
            sandCoord = right;

        below = std::make_pair<int32_t, int32_t>(sandCoord.first + 0, sandCoord.second + 1);
        left = std::make_pair<int32_t, int32_t>(sandCoord.first - 1, sandCoord.second + 1);
        right = std::make_pair<int32_t, int32_t>(sandCoord.first + 1, sandCoord.second + 1);
    }

    if(sandCoord.second <= lowestRock_ || blockVoid_)
        slice_.block(sandCoord);

    return sandCoord;
};