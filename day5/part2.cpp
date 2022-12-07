#include <iostream>
#include <fstream>
#include <stack>

#include "CrateStacks.h"
#include "Crate.h"



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

    std::string currentLine;
    std::stack<std::string> crateInput;

    std::getline(fin, currentLine);
    while (currentLine.length() > 0)
    {
        crateInput.push(currentLine);
        std::getline(fin, currentLine);
    }
    CrateStacks crateStacks(crateInput);

    int moveAmount, sourceStack, destinationStack;
    while (!fin.eof())
    {
        fin.ignore(5);
        fin >> moveAmount;
        fin.ignore(5);
        fin >> sourceStack;
        fin.ignore(3);
        fin >> destinationStack;

        sourceStack      -= 1;
        destinationStack -= 1;

        crateStacks.moveAllOfAmountOfCratesFromStackToStack(moveAmount, sourceStack, destinationStack);
    }
    fin.close();

    std::cout << "Answer: " << crateStacks.getTopOfStacks() << std::endl;

    return 0;
}