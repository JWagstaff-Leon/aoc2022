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

    std::string currentLine, firstCompartmentContents, secondCompartmentContents;
    Compartment firstCompartment, secondCompartment, unionCompartment;
    int prioritySum = 0;

    while (!fin.eof())    
    {
        std::getline(fin, currentLine);
        
        firstCompartmentContents  = currentLine.substr(0, currentLine.length() / 2);
        secondCompartmentContents = currentLine.substr(currentLine.length() / 2, currentLine.length() / 2);

        firstCompartment  = CompartmentFactory::fromString(firstCompartmentContents );
        secondCompartment = CompartmentFactory::fromString(secondCompartmentContents);
        unionCompartment = firstCompartment.junction(secondCompartment);
        
        std::unique_ptr<Item> duplicateItem = unionCompartment.getOnlyItemOrNull();
        prioritySum += duplicateItem->getPriority();
    }
    fin.close();

    std::cout << "Answer: " << prioritySum << std::endl;

    return 0;
}