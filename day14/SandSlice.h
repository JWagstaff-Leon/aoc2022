#pragma once

#include <cstdint>
#include <fstream>
#include <utility>

#include "Slice.h"

class SandSlice
{
    public:
        SandSlice(std::pair<int32_t, int32_t> sandSource);
        ~SandSlice();

        void newRockAt(std::pair<int32_t, int32_t> coord);
        void blockToCoord(std::pair<int32_t, int32_t> coord);
        
        bool pourSandAndCheckSettles();
        bool pourSandAndCheckSourceBlocked();

        void setBlockVoid(bool shouldBlock);

    private:
        Slice slice_;

        int32_t lowestRock_;
        bool blockVoid_;
        
        std::pair<int32_t, int32_t> lastCoord_;
        std::pair<int32_t, int32_t> sandSource_;

        std::pair<int32_t, int32_t> pourSand();

        std::ofstream rockfout;
        std::ofstream sandfout;
};