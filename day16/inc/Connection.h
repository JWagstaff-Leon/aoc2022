#pragma once

#include "Valve.h"

struct Connection
{
    Valve *end1, *end2;
};

struct ConnectionComparator
{
    bool operator() (const Connection& lhs, const Connection& rhs) const {
        return (
            lhs.end1->getName() < rhs.end1->getName() ||
            lhs.end1->getName() == rhs.end1->getName() && lhs.end2->getName() < rhs.end2->getName()
        );
    };
};