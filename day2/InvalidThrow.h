#ifndef INVALID_THROW_H
#define INVALID_THROW_H

#include "Throw.h"



class InvalidThrow : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::NoScore; };
        inline ThrowType    getType()  override { return ThrowType::Invalid;  };
               OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif