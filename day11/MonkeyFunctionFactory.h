#ifndef MONKEY_FUNCTION_FACTORY_H
#define MONKEY_FUNCTION_FACTORY_H

#include <functional>
#include <string>



class MonkeyFunctionFactory
{
    public:
        static std::function<int(int)>                                makeLessWorriedFunction(std::string input);
        static std::function<unsigned long long(unsigned long long)>  makeMoreWorriedFunction(std::string input);
        static std::function<bool(int)>                               makeTestFunction       (std::string input);

    private:
        MonkeyFunctionFactory();
};

#endif