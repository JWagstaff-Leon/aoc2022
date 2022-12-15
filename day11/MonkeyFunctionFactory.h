#ifndef MONKEY_FUNCTION_FACTORY_H
#define MONKEY_FUNCTION_FACTORY_H

#include <functional>
#include <string>

#include "Item.h"



class MonkeyFunctionFactory
{
    public:
        static std::function<Item(Item)> makeLessWorriedFunction(std::string input);
        static std::function<Item(Item)> makeMoreWorriedFunction(std::string input);
        static std::function<bool(Item)> makeTestFunction       (std::string input);

    private:
        MonkeyFunctionFactory();
};

#endif