#ifndef THROWFACTORY_H
#define THROWFACTORY_H

#include <memory>

#include "Throw.h"

class ThrowFactory
{
    public:
        static std::unique_ptr<Throw> makeThrowFromCode(char throwCode);

    private:
        ThrowFactory();
};

#endif