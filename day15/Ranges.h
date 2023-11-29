#pragma once

#include <cstdint>
#include <utility>
#include <vector>

namespace range
{

using Range = std::pair<int32_t, int32_t>;

struct {
    bool operator() (const Range& lhs, const Range& rhs) { return lhs.first < rhs.first; };
} RangeComparator;

class Ranges
{
    public:
        uint32_t addRange(Range range);
        uint32_t addCenteredRange(int32_t center, uint32_t size);

        uint32_t count() const;
        bool coversValue(int32_t value) const;
        std::vector<Range> getGaps() const;

    private:
        std::vector<Range> ranges_;
};

} // range