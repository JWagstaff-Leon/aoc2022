#include "Slice.h"

#include <cstdint>
#include <utility>

void Slice::block(std::pair<int32_t, int32_t> coord)
{
    blocked_.insert(coord);
};



bool Slice::isBlocked(std::pair<int32_t, int32_t> coord) const
{
    return blocked_.find(coord) != blocked_.end();
};