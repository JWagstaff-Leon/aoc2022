#include "ThrowFactory.h"

#include <memory>

#include "Throw.h"
#include "RockThrow.h"
#include "PaperThrow.h"
#include "ScissorsThrow.h"
#include "InvalidThrow.h"



std::unique_ptr<Throw> ThrowFactory::makeThrowFromCode(char throwCode)
{
    std::unique_ptr<Throw> madeThrow = std::make_unique<InvalidThrow>();
    switch (throwCode)
    {
        case 'A':
        // Fallthrough
        case 'X':
            madeThrow = std::make_unique<RockThrow>();
            break;

        case 'B':
        // Fallthrough
        case 'Y':
            madeThrow = std::make_unique<PaperThrow>();
            break;

        case 'C':
        // Fallthrough
        case 'Z':
            madeThrow = std::make_unique<ScissorsThrow>();
            break;
            
        default:
            break;
    };
    return madeThrow;
};



std::unique_ptr<Throw> ThrowFactory::makeOutcomeFromCode(char outcomeCode, ThrowType contestingThrow)
{
    std::unique_ptr<Throw> madeThrow = std::make_unique<InvalidThrow>();
    switch (outcomeCode)
    {
        case 'X':
            madeThrow = makeLosingThrow(contestingThrow);
            break;
        case 'Y':
            madeThrow = makeDrawThrow(contestingThrow);
            break;
        case 'Z':
            madeThrow = makeWinningThrow(contestingThrow);
            break;
        default:
            break;
    };
    return madeThrow;
};



std::unique_ptr<Throw> ThrowFactory::makeLosingThrow(ThrowType contestingThrow)
{
    std::unique_ptr<Throw> losingThrow = std::make_unique<InvalidThrow>();
    switch (contestingThrow)
    {
        case ThrowType::Rock:
            losingThrow = std::make_unique<ScissorsThrow>();
            break;
        case ThrowType::Paper:
            losingThrow = std::make_unique<RockThrow>();
            break;
        case ThrowType::Scissors:
            losingThrow = std::make_unique<PaperThrow>();
            break;
        default:
            losingThrow = std::make_unique<InvalidThrow>();
            break;
    };
    return losingThrow;
};



std::unique_ptr<Throw> ThrowFactory::makeDrawThrow(ThrowType contestingThrow)
{
    std::unique_ptr<Throw> drawingThrow = std::make_unique<InvalidThrow>();
    switch (contestingThrow)
    {
        case ThrowType::Rock:
            drawingThrow = std::make_unique<RockThrow>();
            break;
        case ThrowType::Paper:
            drawingThrow = std::make_unique<PaperThrow>();
            break;
        case ThrowType::Scissors:
            drawingThrow = std::make_unique<ScissorsThrow>();
            break;
        default:
            drawingThrow = std::make_unique<InvalidThrow>();
            break;
    };
    return drawingThrow;
};



std::unique_ptr<Throw> ThrowFactory::makeWinningThrow(ThrowType contestingThrow)
{
    std::unique_ptr<Throw> winningThrow = std::make_unique<InvalidThrow>();
    switch (contestingThrow)
    {
        case ThrowType::Rock:
            winningThrow = std::make_unique<PaperThrow>();
            break;
        case ThrowType::Paper:
            winningThrow = std::make_unique<ScissorsThrow>();
            break;
        case ThrowType::Scissors:
            winningThrow = std::make_unique<RockThrow>();
            break;
        default:
            winningThrow = std::make_unique<InvalidThrow>();
            break;
    };
    return winningThrow;
};