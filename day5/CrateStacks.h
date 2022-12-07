#ifndef CRATE_STACKS_H
#define CRATE_STACKS_H

#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include "Crate.h"



class CrateStacks
{
    public:
        CrateStacks(std::stack<std::string> crateInput);
        void        moveAmountOfCratesFromStackToStack(int amount, int sourceStack, int destinationStack);
        void        moveAllOfAmountOfCratesFromStackToStack(int amount, int sourceStack, int destinationStack);
        std::string getTopOfStacks() const;

    private:
        std::vector<char> readLineOfCharacters(std::string line);

        std::vector<std::stack<Crate>> crateStacks_;

};


#endif