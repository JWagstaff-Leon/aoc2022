#include "Scissors.h"



inline OutcomeScore Scissors::getOutcomeScoreAgainst(ThrowType contestingThrowType)
{
    OutcomeScore result;
    switch(contestingThrowType)
    {
        case ThrowType::Rock:
            result = OutcomeScore::Loss;
            break;
        case ThrowType::Paper:
            result = OutcomeScore::Win;
            break;
        case ThrowType::Scissors:
            result = OutcomeScore::Draw;
            break;
        default:
            result = OutcomeScore::Loss;
            break;
    };
    return result;
};