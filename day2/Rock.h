#ifndef ROCK_H
#define ROCK_H

#include "Throw.h"



class Rock : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::Rock; };
        inline ThrowType    getType()  override { return ThrowType::Rock;  };
        inline OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif