#include "Ranges.h"

#include <algorithm>
#include <vector>

using namespace range;

uint32_t Ranges::addRange(Range newRange)
{
    uint32_t oldSize = count();

    for(auto it = ranges_.rbegin(); it != ranges_.rend(); it++)
    {
        // match to start
        if(it->first <= newRange.first && newRange.first <= it->second)
            newRange.first = it->first;
        
        // match to end
        if(it->first <= newRange.second && newRange.second <= it->second)
            newRange.second = it->second;
        
        // remove overlap
        if(newRange.first <= it->first && it->second <= newRange.second)
            ranges_.erase(std::next(it).base());
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



bool Ranges::coversValue(int32_t value) const
{
    for(auto range : ranges_)
        if(range.first <= value && value <= range.second)
            return true;

    return false;
};



std::vector<Range> Ranges::getGaps() const
{
    std::vector<Range> gaps;
    for(int i = 0; i < ranges_.size() - 1; i++)
        gaps.push_back(Range(ranges_[i].second + 1, ranges_[i + 1].first - 1));
    
    return gaps;
};