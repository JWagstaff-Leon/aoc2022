#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Computer.h"



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

    std::vector<std::string> instructions;
    std::string              currentLine;
    while (!fin.eof())
    {
        std::getline(fin, currentLine);
        instructions.push_back(currentLine);
    }
    fin.close();
    
    Computer computer(instructions);
    std::string answer = computer.getVisualOutput();

    std::cout << "Answer: \n" << answer << std::endl;
    return 0;
}