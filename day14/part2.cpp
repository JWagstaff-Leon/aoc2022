#include <iostream>
#include <cctype>
#include <cstdint>
#include <fstream>
#include <string>
#include <utility>

#include "SandSlice.h"

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

    SandSlice sandSlice(std::make_pair<int32_t, int32_t>(500, 0));
    std::string currentRock;
    while(!fin.eof())
    {
        std::getline(fin, currentRock);
        
        int32_t x = 0, y = 0;
        int c = 0;
        bool firstRock = true;
        while(c < currentRock.length())
        {
            x = 0;
            while(isdigit(currentRock[c])) // read x
            {
                x *= 10;
                x += currentRock[c] - '0';
                c++;
            }
            c += 1; // consume ','

            y = 0;
            while(isdigit(currentRock[c])) // read y
            {
                y *= 10;
                y += currentRock[c] - '0';
                c++;
            }
            c += 4; // consume ' -> '

            std::pair<int32_t, int32_t> readCoord = std::pair<int32_t, int32_t>(x, y);
            if(firstRock)
            {
                sandSlice.newRockAt(readCoord);
                firstRock = false;
            }
            else
            {
                sandSlice.blockToCoord(readCoord);
            }
        }
    }
    fin.close();

    sandSlice.setBlockVoid(true);
    
    int answer = 0;
    while(!sandSlice.pourSandAndCheckSourceBlocked())
    {
        answer += 1;
    }

    answer += 1;

    
    std::cout << "Answer: " << answer << std::endl;
    return 0;
}