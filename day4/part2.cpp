#include <iostream>
#include <fstream>

#include <string>

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

    int         firstElfRange[2]  = {0, 0};
    int         secondElfRange[2] = {0, 0};
    std::string readNumber;

    int partialOverlaps = 0;

    while (!fin.eof())
    {
        std::getline(fin, readNumber, '-');
        firstElfRange[0] = std::stoi(readNumber);
        std::getline(fin, readNumber, ',');
        firstElfRange[1] = std::stoi(readNumber);
        std::getline(fin, readNumber, '-');
        secondElfRange[0] = std::stoi(readNumber);
        std::getline(fin, readNumber, '\n');
        secondElfRange[1] = std::stoi(readNumber);

        if (firstElfRange[0] >= secondElfRange[0] && firstElfRange[0] <= secondElfRange[1] || secondElfRange[0] >= firstElfRange[0] && secondElfRange[0] <= firstElfRange[1])
        {
            partialOverlaps += 1;
        }
    }

    std::cout << "Answer: " << partialOverlaps << std::endl;

    fin.close();
}