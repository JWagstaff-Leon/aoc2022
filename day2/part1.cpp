#include <iostream>
#include <fstream>
#include <memory>

#include "ThrowFactory.h"
#include "Throw.h"

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

    int totalScore   = 0;
    int currentScore = 0;
    char input = '\0';
    std::unique_ptr<Throw> enemyThrow;
    std::unique_ptr<Throw> yourThrow;

    while (!fin.eof())
    {
        input = fin.get();
        enemyThrow = ThrowFactory::makeThrowFromCode(input);
        fin.ignore(1);
        input = fin.get();
        yourThrow = ThrowFactory::makeThrowFromCode(input);
        fin.ignore(1);

        currentScore = yourThrow->getScore() + yourThrow->getOutcomeScoreAgainst(enemyThrow->getType());
        totalScore += currentScore;
    }

    std::cout << "Answer: " << totalScore << std::endl;
}