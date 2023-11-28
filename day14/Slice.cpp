#include "Slice.h"

#include <cstdint>
#include <utility>

Slice::Slice()
: lowestPoint_(0)
{ /* Intentionally empty */ };



void Slice::block(std::pair<int32_t, int32_t> coord)
{
    if(coord.second > lowestPoint_)
        lowestPoint_ = coord.second;
    
    blocked_.insert(coord);
};



bool Slice::isLowest(std::pair<int32_t, int32_t> coord)
{
    return coord.second > lowestPoint_;
};



bool Slice::isBlocked(std::pair<int32_t, int32_t> coord)
{
    return blocked_.find(coord) != blocked_.end();
};