#pragma once

#include <cstdint>
#include <utility>
#include <set>

class Slice
{
    public:
        void block(std::pair<int32_t, int32_t> coord);
        bool isBlocked(std::pair<int32_t, int32_t> coord) const;

    private:
        std::set<std::pair<int32_t, int32_t>> blocked_;
        
};