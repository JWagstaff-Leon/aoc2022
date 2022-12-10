#ifndef HEAD_H
#define HEAD_H

#include "Position.h"



class Head
{
    public:
        inline Head(int x = 0, int y = 0) :position_(x, y) {};

        inline void moveBy(Position moveAmount)
        {
            std::get<0>(position_) += std::get<0>(moveAmount);
            std::get<1>(position_) += std::get<1>(moveAmount);
        };
        inline Position getPosition() { return position_; };

    private:
        Position position_;
};

#endif