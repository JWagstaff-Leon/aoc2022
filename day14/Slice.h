#pragma once

#include <cstdint>
#include <utility>
#include <set>

class Slice
{
    public:
        Slice();

        void block(std::pair<int32_t, int32_t> coord);
        bool isLowest(std::pair<int32_t, int32_t> coord);
        bool isBlocked(std::pair<int32_t, int32_t> coord);

    private:
        std::set<std::pair<int32_t, int32_t>> blocked_;
        int32_t lowestPoint_;
};