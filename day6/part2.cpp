#include <iostream>
#include <fstream>
#include <vector>

#include "CharacterBuffer.h"



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

    const int SIZE = 14;
    CharacterBuffer characterGroup(SIZE);
    int answer = -1;
    int characterCount = 0;
    while (!fin.eof() && answer < 0)
    {
        char input = fin.get();
        characterCount += 1;
        characterGroup.insertCharacter(input);
        if(characterGroup.allUnique())
        {
            answer = characterCount;
        }
    }
    fin.close();
    
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}