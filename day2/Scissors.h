#ifndef SCISSORS_H
#define SCISSORS_H

#include "Throw.h"



class Scissors : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::Scissors; };
        inline ThrowType    getType()  override { return ThrowType::Scissors;  };
        inline OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif