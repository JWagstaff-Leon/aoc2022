#include "PaperThrow.h"



inline OutcomeScore PaperThrow::getOutcomeScoreAgainst(ThrowType contestingThrowType)
{
    OutcomeScore result;
    switch (contestingThrowType)
    {
        case ThrowType::Rock:
            result = OutcomeScore::Win;
            break;
        case ThrowType::Paper:
            result = OutcomeScore::Draw;
            break;
        case ThrowType::Scissors:
            result = OutcomeScore::Loss;
            break;
        default:
            result = OutcomeScore::Loss;
            break;
    };
    return result;
};