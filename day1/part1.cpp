#include <iostream>
#include <fstream>

#include <vector>
#include <string>

#include "elf.h"

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

    std::string      input = "";
    double           calories  ;
    std::vector<Elf> elfs      ;
    Elf              currentElf;

    while (!fin.eof())
    {
        std::getline(fin, input);
        if (input.length() == 0)
        {
            elfs.push_back(std::move(currentElf));
            currentElf = Elf();
            continue;
        }
        calories = std::stod(input);
        currentElf.addCalories(calories);
    }
    fin.close();

    double highestCalories = 0;

    for(auto it = elfs.cbegin(); it != elfs.cend(); it++)
    {
        if (it->getCalorieCount() > highestCalories)
        {
            highestCalories = it->getCalorieCount();
        }
    }

    std::cout << "Answer: " << highestCalories << std::endl;

    return 0;
}