#ifndef PAPER_H
#define PAPER_H

#include "Throw.h"



class PaperThrow : public Throw
{
    public:
        inline ThrowScore   getScore() override { return ThrowScore::PaperScore; };
        inline ThrowType    getType()  override { return ThrowType::Paper;  };
               OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) override;
};

#endif