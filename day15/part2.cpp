#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "Ranges.h"

using Ranges = range::Ranges;
using Range = range::Range;

uint32_t taxiDistance(std::pair<int32_t, int32_t> p1, std::pair<int32_t, int32_t> p2)
{
    uint32_t xDist = (p1.first > p2.first ? p1.first - p2.first : p2.first - p1.first);
    uint32_t yDist = (p1.second > p2.second ? p1.second - p2.second : p2.second - p1.second);

    return xDist + yDist;
};



uint32_t apparentRangeSize(int32_t y1, int32_t y2, uint32_t size)
{
    uint32_t heightDifference = (y1 > y2 ? y1 - y2 : y2 - y1);
    uint32_t sizeShrinkAmount = heightDifference * 2;
    if(sizeShrinkAmount > size)
        return 0;

    return size - sizeShrinkAmount;
};



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <input filename>" << std::endl;
        return 0;
    }

    std::ifstream fin(argv[1]);
    if (fin.fail())
    {
        std::cout << "Could not open file " << argv[1] << std::endl;
        return 0;
    }

    std::string currentLine;
    std::vector<std::pair<std::pair<int32_t, int32_t>, uint32_t>> sensorsWithDistances;
    while(!fin.eof())
    {
        std::pair<int32_t, int32_t> sensor, beacon;
        std::getline(fin, currentLine);
        sscanf(currentLine.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &sensor.first, &sensor.second, &beacon.first, &beacon.second);

        uint32_t distance = taxiDistance(sensor, beacon);
        sensorsWithDistances.push_back(std::pair<std::pair<int32_t, int32_t>, uint32_t>(sensor, distance));
    }
    fin.close();

    uint64_t answer = 0;
    for(int y = 0; y <= 4000000 && answer <= 0; y++)
    {
        Ranges ranges;
        for(auto sensorAndDistance : sensorsWithDistances)
        {
            uint32_t size = apparentRangeSize(sensorAndDistance.first.second, y, (sensorAndDistance.second * 2) + 1);
            if(size > 0)
                ranges.addCenteredRange(sensorAndDistance.first.first, size);
        }
        std::vector<range::Range> gaps = ranges.getGaps();
        for(auto gap : gaps)
        {
            if(gap.second == gap.first && gap.first > 0 && gap.first <= 4000000)
                answer = gap.first * (uint64_t)4000000 + y;
        }
    }
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}