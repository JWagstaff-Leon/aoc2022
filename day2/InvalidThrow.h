#ifndef INVALID_THROW_H
#define INVALID_THROW_H

#include "Throw.h"



class InvalidThrow : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::None; };
        inline ThrowType    getType()  override { return ThrowType::None;  };
        inline OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif