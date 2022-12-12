#include "MonkeyFunctionFactory.h"

#include <string>
#include <iostream>



std::function<int(int)> MonkeyFunctionFactory::makeLessWorriedFunction(std::string input)
{
    std::string lhs, opSymbol, rhs;

    lhs = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    opSymbol = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    rhs = input;

    return [lhs, opSymbol, rhs] (int old) -> int
    {
        int left, right;
        if (lhs == "old")
        {
            left = old;
        }
        else
        {
            left = std::stoi(lhs);
        }

        if (rhs == "old")
        {
            right = old;
        }
        else
        {
            right = std::stoi(rhs);
        }

        int result = 0;
        switch (opSymbol[0])
        {
            case '+':
                result = left + right;
                break;

            case '-':
                result = left - right;
                break;

            case '*':
                result = left * right;
                break;

            case '/':
                result = left / right;
                break;
            
            default:
                break;
        }

        result /= 3;
        return result;
    };
};



std::function<unsigned long long(unsigned long long)> MonkeyFunctionFactory::makeMoreWorriedFunction(std::string input)
{
    std::string lhs, opSymbol, rhs;

    lhs = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    opSymbol = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    rhs = input;

    return [lhs, opSymbol, rhs] (unsigned long long old) -> unsigned long long
    {
        unsigned long long left, right;
        if (lhs == "old")
        {
            left = old;
        }
        else
        {
            left = std::stoi(lhs);
        }

        if (rhs == "old")
        {
            right = old;
        }
        else
        {
            right = std::stoi(rhs);
        }

        int result = 0;
        switch (opSymbol[0])
        {
            case '+':
                result = left + right;
                break;

            case '-':
                result = left - right;
                break;

            case '*':
                result = left * right;
                break;

            case '/':
                result = left / right;
                break;
            
            default:
                break;
        }

        return result;
    };
};



std::function<bool(int)> MonkeyFunctionFactory::makeTestFunction(std::string input)
{
    int divisor = std::stoi(input);
    return [divisor] (int value) -> bool
    {
        return value % divisor == 0;
    };
};