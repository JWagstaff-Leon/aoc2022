#include "MonkeyFunctionFactory.h"

#include <string>
#include <iostream>

#include "bigint/bigint.h"



std::function<bigint(bigint)> MonkeyFunctionFactory::makeLessWorriedFunction(std::string input)
{
    std::string lhs, opSymbol, rhs;

    lhs = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    opSymbol = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    rhs = input;

    return [lhs, opSymbol, rhs] (bigint old) -> bigint
    {
        bigint left, right;
        if (lhs == "old")
        {
            left = old;
        }
        else
        {
            left = std::stoull(lhs);
        }

        if (rhs == "old")
        {
            right = old;
        }
        else
        {
            right = std::stoull(rhs);
        }

        bigint result = 0;
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



std::function<bigint(bigint)> MonkeyFunctionFactory::makeMoreWorriedFunction(std::string input)
{
    std::string lhs, opSymbol, rhs;

    lhs = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    opSymbol = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    rhs = input;

    return [lhs, opSymbol, rhs] (bigint old) -> bigint
    {
        bigint left, right;
        if (lhs == "old")
        {
            left = old;
        }
        else
        {
            left = std::stoull(lhs);
        }

        if (rhs == "old")
        {
            right = old;
        }
        else
        {
            right = std::stoull(rhs);
        }

        bigint result = 0;
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
        if (lhs == "old" && result < left || rhs == "old" && result < right)
        {
            std::cout << "Overflow...\n" << left << opSymbol << right << "=" << result << "\n";
        }
        return result;
    };
};



std::function<bool(bigint)> MonkeyFunctionFactory::makeTestFunction(std::string input)
{
    bigint divisor = std::stoull(input);
    return [divisor] (bigint value) -> bool
    {
        return ((value / divisor) * divisor) == value;
    };
};