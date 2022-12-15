#ifndef MONKEY_FUNCTION_FACTORY_H
#define MONKEY_FUNCTION_FACTORY_H

#include <functional>
#include <string>

#include "bigint/bigint.h"



class MonkeyFunctionFactory
{
    public:
        static std::function<bigint(bigint)> makeLessWorriedFunction(std::string input);
        static std::function<bigint(bigint)> makeMoreWorriedFunction(std::string input);
        static std::function<bool(bigint)>   makeTestFunction       (std::string input);

    private:
        MonkeyFunctionFactory();
};

#endif