#include "Ranges.h"

#include <algorithm>
#include <vector>

using namespace range;

uint32_t Ranges::addRange(Range newRange)
{
    std::vector<Range>::iterator startIt, endIt;
    uint32_t oldSize = count();

    for(startIt = ranges_.begin(); startIt != ranges_.end(); startIt++)
    {
        if(startIt->first <= newRange.first && newRange.first <= startIt->second)
        {
            newRange.first = startIt->first;
            if(startIt->second > newRange.second)
                newRange.second = startIt->second;
            break;
        }
    }
    
    // check to make sure new range end isn't inside another range
    for(endIt = startIt; endIt != ranges_.end(); endIt++)
    {
        if(endIt->first <= newRange.second && newRange.second <= endIt->second)
        {
            newRange.second = endIt->second;
            break;
        }
    }

    if(startIt != ranges_.end() && endIt != ranges_.end())
        ranges_.erase(startIt, endIt);
    else if(startIt != ranges_.end())
    {
        ranges_.erase(startIt);
    }
    else if(endIt != ranges_.end())
    {
        ranges_.erase(endIt);
    }
    ranges_.push_back(newRange);
    std::sort(ranges_.begin(), ranges_.end(), RangeComparator);

    return count() - oldSize;
};



uint32_t Ranges::addCenteredRange(int32_t center, uint32_t size)
{
    Range centeredRange;
    int32_t start, end;

    start = center - (size / 2);
    end = center + (size / 2);

    centeredRange.first = start;
    centeredRange.second = end;

    return addRange(centeredRange);
};



uint32_t Ranges::count() const
{
    uint32_t total = 0;
    for(auto range : ranges_)
        total += range.second - range.first;
    return total;
};