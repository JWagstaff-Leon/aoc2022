#ifndef ROCK_H
#define ROCK_H

#include "Throw.h"



class RockThrow : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::RockScore; };
        inline ThrowType    getType()  override { return ThrowType::Rock;  };
               OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif