#include "MonkeyFunctionFactory.h"

#include <string>
// #include <iostream>

#include "Item.h"



std::function<Item(Item)> MonkeyFunctionFactory::makeLessWorriedFunction(std::string input)
{
    std::string lhs, opSymbol, rhs;

    lhs = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    opSymbol = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    rhs = input;

    return [lhs, opSymbol, rhs] (Item old) -> Item
    {
        Item left, right;
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

        Item result = 0;
        switch (opSymbol[0])
        {
            case '+':
                result = left + right;
                break;

            case '*':
                result = left * right;
                break;
            
            default:
                break;
        }

        result = result / 3;
        return result;
    };
};



std::function<Item(Item)> MonkeyFunctionFactory::makeMoreWorriedFunction(std::string input)
{
    std::string lhs, opSymbol, rhs;

    lhs = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    opSymbol = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);

    rhs = input;

    return [lhs, opSymbol, rhs] (Item old) -> Item
    {
        Item left, right;
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

        Item result = 0;
        switch (opSymbol[0])
        {
            case '+':
                result = left + right;
                break;

            case '*':
                result = left * right;
                break;
            
            default:
                break;
        }
        return result;
    };
};



std::function<bool(Item)> MonkeyFunctionFactory::makeTestFunction(std::string input)
{
    int divisor = std::stoi(input);
    return [divisor] (Item value) -> bool
    {
        return ((value / divisor) * divisor) == value;
    };
};