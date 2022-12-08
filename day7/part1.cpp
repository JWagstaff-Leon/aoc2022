#include <iostream>
#include <fstream>

#include <string>
#include <memory>
#include <stack>

#include "FSEntity.h"
#include "FSFile.h"
#include "FSDirectory.h"



int getAnswerValueForDirectory(std::shared_ptr<FSEntity> directory)
{
    int answerValue = 0;
    if(directory->getDirectorySize() <= 100000)
    {
        answerValue += directory->getDirectorySize();
    }
    if (!directory->getChildren().empty())
    {
        for (const auto it : directory->getChildren())
        {
            int itValue = getAnswerValueForDirectory(it);
            answerValue += itValue;
        }
    }
    return answerValue;
}



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

    std::string inputLine;
    std::stack<std::shared_ptr<FSEntity>> workingDirectory;
    std::shared_ptr<FSEntity> root = std::make_shared<FSDirectory>("/");
    workingDirectory.push(root);
    while (!fin.eof())
    {
        fin.ignore(2); // ignore "$ "
        fin >> inputLine;

        if (inputLine  == "ls")
        {
            while (fin.peek() != '$' && !fin.eof())
            {
                fin >> inputLine;
                fin.ignore(1); // ignore " "
                if (inputLine == "dir")
                {

                    std::getline(fin, inputLine);
                    workingDirectory.top()->addChild(std::make_shared<FSDirectory>(inputLine));
                }
                else
                {
                    int size = std::stoi(inputLine);
                    std::getline(fin, inputLine);
                    workingDirectory.top()->addChild(std::make_shared<FSFile>(inputLine, size));
                }
            }
        }
        else if (inputLine == "cd")
        {
            fin >> inputLine;
            if (inputLine == "..")
            {
                workingDirectory.pop();
                if(workingDirectory.empty())
                {
                    workingDirectory.push(root);
                }
            }
            else
            {
                std::shared_ptr<FSEntity> changedDirectory = workingDirectory.top()->getChildByName(inputLine);
                if (changedDirectory.get() != nullptr)
                {
                    workingDirectory.push(changedDirectory);
                }
            }
        }
    }
    fin.close();

    int answer = getAnswerValueForDirectory(root);
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}