#include <iostream>
#include <fstream>
#include <string>

#include "RopeGrid.h"



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

    char moveDirection;
    int  moveAmount;
    std::string moveAmountInput;
    RopeGrid ropeGrid;
    while(!fin.eof())
    {
        fin >> moveDirection;
        fin.ignore(1);
        std::getline(fin, moveAmountInput);
        moveAmount = std::stoi(moveAmountInput);
        // std::cout << "Read in " << moveDirection << " " << moveAmount << std::endl;
        ropeGrid.doSteps(moveDirection, moveAmount);
        // system("PAUSE");
    }
    fin.close();
    
    int answer = ropeGrid.getVisitedPositions();
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}