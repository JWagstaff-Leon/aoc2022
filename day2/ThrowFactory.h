#ifndef THROWFACTORY_H
#define THROWFACTORY_H

#include <memory>

#include "Throw.h"

class ThrowFactory
{
    public:
        static std::unique_ptr<Throw> makeThrowFromCode(char throwCode);

        static std::unique_ptr<Throw> makeOutcomeFromCode(char outcomeCode, ThrowType contestingThrow);

        static std::unique_ptr<Throw> makeLosingThrow (ThrowType contestingThrow);
        static std::unique_ptr<Throw> makeDrawThrow   (ThrowType contestingThrow);
        static std::unique_ptr<Throw> makeWinningThrow(ThrowType contestingThrow);

    private:
        ThrowFactory();
};

#endif