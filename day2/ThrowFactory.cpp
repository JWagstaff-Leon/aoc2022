#include "ThrowFactory.h"

#include <memory>

#include "Throw.h"
#include "RockThrow.h"
#include "PaperThrow.h"
#include "ScissorsThrow.h"
#include "InvalidThrow.h"



std::unique_ptr<Throw> makeThrow(char throwCode)
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