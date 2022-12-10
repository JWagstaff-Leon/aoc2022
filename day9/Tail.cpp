#include "Tail.h"

#include <memory>

#include "Position.h"
#include "Head.h"
#include "Tail.h"



inline int makeMatchingSignOneOrZero(int value)
{
    if (value == 0)
    {
        return 0;
    }
    return value > 0 ? 1 : -1;
};



void Tail::moveTowards(Position target)
{
    int xDistance = abs(std::get<0>(target) - std::get<0>(getPosition()));
    int yDistance = abs(std::get<1>(target) - std::get<1>(getPosition()));

    if (xDistance > 1 || yDistance > 1)
    {
        int targetX = std::get<0>(target) - std::get<0>(getPosition());
        int targetY = std::get<1>(target) - std::get<1>(getPosition());

        int xDelta = makeMatchingSignOneOrZero(targetX);
        int yDelta = makeMatchingSignOneOrZero(targetY);

        std::get<0>(position_) += xDelta;
        std::get<1>(position_) += yDelta;
    }
};