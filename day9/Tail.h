#ifndef TAIL_H
#define TAIL_H

#include <memory>

#include "Position.h"
#include "Head.h"
#include "Tail.h"


class Tail
{
    public:
        inline Tail(int x = 0, int y = 0) :position_(x, y) {};

        void moveTowards(Position target);
        inline Position getPosition() { return position_; };

    private:
        Position position_;
};

#endif