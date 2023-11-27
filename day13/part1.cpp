#include <iostream>
#include <fstream>
#include <string>

#include "Packet.h"

ListPacket* stringToList(std::string string)
{
    ListPacket* outList = new ListPacket;
    for(int i = 1; i < string.length() - 1; i++)
    {
        if(string[i] == '[')
        {
            std::string substring;
            int j, depth;
            for(
                j = i + 1, depth = 1;
                j < string.length() - 1 && depth > 0;
                j++
            )
            {
                if(string[j] == '[')
                {
                    depth += 1;
                }
                if(string[j] == ']')
                {
                    depth -= 1;
                }
            }
            substring = string.substr(i, j - i); // start after '['; end before ']'
            outList->addData(static_cast<Packet*>(stringToList(substring)));
        }

        if(string[i] >= '0' && string[i] <= '9')
        {
            int value = 0;
            for(/* no init */; string[i] >= '0' && string[i] <= '9' && i < string.length(); i++)
            {
                value *= 10;
                value += string[i] - '0';
            }

            IntegerPacket* valuePacket = new IntegerPacket(value);
            outList->addData(static_cast<Packet*>(valuePacket));
        }
    }

    return outList;
};



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

    int answer = 0;
    int index = 1;

    while(!fin.eof())
    {
        std::string list1String, list2String;
        std::getline(fin, list1String);
        std::getline(fin, list2String);

        ListPacket* list1 = stringToList(list1String);
        ListPacket* list2 = stringToList(list2String);
        if(packetLessThan(list1, list2))
        {
            answer += index;
        }
        delete list1;
        delete list2;

        std::getline(fin, list1String); // consume blank line
        index++;
    }

    std::cout << "Answer: " << answer << std::endl;

    fin.close();
    return 0;
}