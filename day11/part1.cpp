#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

#include "Monkey.h"
#include "MonkeyFunctionFactory.h"
#include "Item.h"


const int ROUND_COUNT = 20;



std::queue<Item> getStartingItems(std::string itemsInput)
{
    std::queue<Item> startingItems;
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
            startingItems.push(std::stoi(nextNumber));
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
        std::queue<Item> items;
        std::getline(fin, currentInput);      // Monkey #:
        std::getline(fin, currentInput, ':'); // Starting items:
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // #, #, ... #, #
        std::queue<Item> startingItems = getStartingItems(currentInput);

        std::getline(fin, currentInput, '='); // Operation: new =
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // ___ _ ___
        std::function<Item(Item)> worryFunction = MonkeyFunctionFactory::makeLessWorriedFunction(currentInput);

        std::getline(fin, currentInput, 'y'); // Test: divisible by
        fin.ignore(1);                        // " "

        std::getline(fin, currentInput);      // #
        std::function<bool(Item)> testFunction = MonkeyFunctionFactory::makeTestFunction(currentInput);

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
        for (int j = 0; j < monkies.size(); j++)
        {
            monkies[j].processItems();
        }
    }

    int highest       = -1;
    int secondHighest = -1;

    for (int i = 0; i < monkies.size(); i++)
    {
        int monkeyScore = monkies[i].getProcessedItemsCount();
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

    int answer = highest * secondHighest;
    std::cout << "Answer: " << answer << "\n";
    return 0;
};