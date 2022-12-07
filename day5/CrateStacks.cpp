#include "CrateStacks.h"

#include <string>
#include <vector>
#include <stack>
#include <cctype>



CrateStacks::CrateStacks(std::stack<std::string> crateInput)
{
    crateInput.pop(); // Pop line consisting of crate numbers
    while (!crateInput.empty())
    {
        std::string currentLine = crateInput.top();
        std::vector<char> readValues = readLineOfCharacters(currentLine);
        for (int stackIndex = 0; stackIndex != readValues.size(); stackIndex++)
        {
            if (crateStacks_.size() <= stackIndex)
            {
                crateStacks_.push_back(std::stack<Crate>());
            }

            if (readValues.at(stackIndex) != '\0')
            {
                crateStacks_.at(stackIndex).push(Crate(readValues.at(stackIndex)));
            }
        }
        crateInput.pop();
    }
}



std::vector<char> CrateStacks::readLineOfCharacters(std::string line)
{
    std::vector<char> lineValues;
    for (int c = 1; c < line.length(); c += 4)
    {
        if (std::isalpha(line.at(c)))
        {
            lineValues.push_back(line.at(c));
        }
        else
        {
            lineValues.push_back('\0');
        }
    }
    return lineValues;
};



void CrateStacks::moveAmountOfCratesFromStackToStack(int amount, int sourceStack, int destinationStack)
{
    for (int i = 0; i < amount; i++)
    {
        crateStacks_.at(destinationStack).push(crateStacks_.at(sourceStack).top());
        crateStacks_.at(sourceStack).pop();
    }
};



void CrateStacks::moveAllOfAmountOfCratesFromStackToStack(int amount, int sourceStack, int destinationStack)
{
    std::stack<Crate> reversalStack;
    for (int i = 0; i < amount; i++)
    {
        reversalStack.push(crateStacks_.at(sourceStack).top());
        crateStacks_.at(sourceStack).pop();
    }
    for (int i = 0; i < amount; i++)
    {
        crateStacks_.at(destinationStack).push(reversalStack.top());
        reversalStack.pop();
    }
};


std::string CrateStacks::getTopOfStacks() const
{
    std::string tops;
    for (int i = 0; i < crateStacks_.size(); i++)
    {
        tops += crateStacks_.at(i).top().getValue();
    }
    return tops;
};