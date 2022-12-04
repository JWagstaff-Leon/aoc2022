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
        // std::cout << "Read compartment pair" << std::endl;
        // std::cout.flush();
        firstCompartmentContents  = currentLine.substr(0, currentLine.length() / 2);
        secondCompartmentContents = currentLine.substr(currentLine.length() / 2, currentLine.length() / 2);
        // std::cout << "Contents: " << currentLine << std::endl << firstCompartmentContents << " | " << secondCompartmentContents << std::endl;
        firstCompartment  = CompartmentFactory::fromString(firstCompartmentContents );
        secondCompartment = CompartmentFactory::fromString(secondCompartmentContents);
        unionCompartment = firstCompartment.junction(secondCompartment);
        std::unique_ptr<Item> duplicateItem = unionCompartment.getOnlyItemOrNull();
        // std::cout << "Added priority: " << duplicateItem->getPriority() << std::endl;
        prioritySum += duplicateItem->getPriority();
        // system("PAUSE");
    }

    std::cout << "Answer: " << prioritySum << std::endl;

    return 0;
}