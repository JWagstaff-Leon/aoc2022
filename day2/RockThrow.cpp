#include "RockThrow.h"



inline OutcomeScore RockThrow::getOutcomeScoreAgainst(ThrowType contestingThrowType)
{
    OutcomeScore result;
    switch (contestingThrowType)
    {
        case ThrowType::Rock:
            result = OutcomeScore::Draw;
            break;
        case ThrowType::Paper:
            result = OutcomeScore::Loss;
            break;
        case ThrowType::Scissors:
            result = OutcomeScore::Win;
            break;
        default:
            result = OutcomeScore::Loss;
            break;
    };
    return result;
};