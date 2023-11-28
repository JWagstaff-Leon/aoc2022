#pragma once

#include <cstdint>
#include <utility>

#include "Slice.h"

class SandSlice
{
    public:
        SandSlice(std::pair<int32_t, int32_t> sandSource);

        void newRockAt(std::pair<int32_t, int32_t> coord);
        void blockToCoord(std::pair<int32_t, int32_t> coord);
        bool pourSandAndCheckSettles();

    private:
        Slice slice_;
        std::pair<int32_t, int32_t> lastCoord_;
        std::pair<int32_t, int32_t> sandSource_;
};