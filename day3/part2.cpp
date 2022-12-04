#include <iostream>
#include <fstream>
#include <set>

#include <string>

#include "CompartmentFactory.h"



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
    Compartment firstElf, secondElf, thirdElf, unionCompartment;
    int prioritySum = 0;

    while (!fin.eof())    
    {
        std::getline(fin, currentLine);
        firstElf  = CompartmentFactory::fromString(currentLine);
        std::getline(fin, currentLine);
        secondElf = CompartmentFactory::fromString(currentLine);
        std::getline(fin, currentLine);
        thirdElf  = CompartmentFactory::fromString(currentLine);
        
        unionCompartment = firstElf.junction(secondElf);
        unionCompartment = unionCompartment.junction(thirdElf);
        std::unique_ptr<Item> duplicateItem = unionCompartment.getOnlyItemOrNull();

        prioritySum += duplicateItem->getPriority();
    }
    fin.close();

    std::cout << "Answer: " << prioritySum << std::endl;

    return 0;
}