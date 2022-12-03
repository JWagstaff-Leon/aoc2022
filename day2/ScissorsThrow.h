#ifndef SCISSORS_H
#define SCISSORS_H

#include "Throw.h"



class ScissorsThrow : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::ScissorsScore; };
        inline ThrowType    getType()  override { return ThrowType::Scissors;  };
               OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif