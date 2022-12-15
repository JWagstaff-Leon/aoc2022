#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

#include "Monkey.h"
#include "MonkeyFunctionFactory.h"
#include "bigint/bigint.h" // big int from https://github.com/square1001/bigint-library


const int ROUND_COUNT = 10000;



std::queue<bigint> getStartingItems(std::string itemsInput)
{
    std::queue<bigint> startingItems;
    while (itemsInput.size() > 0)
    {
        int endOfNumber = itemsInput.find(',');
        if (endOfNumber == std::string::npos)
        {
            startingItems.push(std::stoull(itemsInput));
            itemsInput = "";
        }
        else
        {
            std::string nextNumber = itemsInput.substr(0, endOfNumber);
            startingItems.push(std::stoull(nextNumber));
            itemsInput.erase(0, endOfNumber + 1);
        }
    }
    return startingItems;
};



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <input filename>" << std::endl;
        return 0;
    }

    std::ifstream fin(argv[1]);
    if (fin.fail())
    {
        std::cout << "Could not open file " << argv[1] << std::endl;
        return 0;
    }

    std::vector<Monkey> monkies;
    std::string         currentInput;
    std::vector<int>    trueThrows;
    std::vector<int>    falseThrows;

    while (!fin.eof())
    {
        std::queue<bigint> items;
        std::getline(fin, currentInput);      // Monkey #:
        std::getline(fin, currentInput, ':'); // Starting items:
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // #, #, ... #, #
        std::queue<bigint> startingItems = getStartingItems(currentInput);

        std::getline(fin, currentInput, '='); // Operation: new =
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // ___ _ ___
        std::function<bigint(bigint)> worryFunction = MonkeyFunctionFactory::makeMoreWorriedFunction(currentInput);

        std::getline(fin, currentInput, 'y'); // Test: divisible by
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // #
        std::function<bool(bigint)> testFunction = MonkeyFunctionFactory::makeTestFunction(currentInput);

        std::getline(fin, currentInput, 'y'); // If true: throw to monkey
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // #
        trueThrows.push_back(std::stoi(currentInput));

        std::getline(fin, currentInput, 'y'); // If false: throw to monkey
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // #
        falseThrows.push_back(std::stoi(currentInput));

        std::getline(fin, currentInput);      // <final newline>
        monkies.push_back(Monkey(startingItems, worryFunction, testFunction));
    }
    fin.close();

    for (int i = 0; i < monkies.size(); i++)
    {
        monkies[i].setTrueCaseTarget (&(monkies[trueThrows [i]]));
        monkies[i].setFalseCaseTarget(&(monkies[falseThrows[i]]));
    }

    for (int i = 0; i < ROUND_COUNT; i++)
    {
        std::cout << "Starting round: " << i + 1 << "...\n";
        for (int j = 0; j < monkies.size(); j++)
        {
            monkies[j].processItems();
        }
    }

    unsigned long long highest       = 0;
    unsigned long long secondHighest = 0;

    for (int i = 0; i < monkies.size(); i++)
    {
        unsigned long long monkeyScore = monkies[i].getProcessedItemsCount();
        if (monkeyScore > highest)
        {
            secondHighest = highest;
            highest = monkeyScore;
        }
        else if (monkeyScore > secondHighest)
        {
            secondHighest = monkeyScore;
        }
    }

    unsigned long long answer = highest * secondHighest;
    std::cout << "Answer: " << highest << "*" << secondHighest << " " << answer << "\n";
    return 0;
};