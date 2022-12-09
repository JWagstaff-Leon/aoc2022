#include <iostream>
#include <fstream>

#include <string>
#include <memory>
#include <stack>

#include "FSEntity.h"
#include "FSFile.h"
#include "FSDirectory.h"



void putAllSubDirectoriesInList(std::shared_ptr<FSEntity> directory, std::vector<std::shared_ptr<FSEntity>> &outlist)
{
    outlist.push_back(directory);
    for (auto it : directory->getChildren())
    {
        putAllSubDirectoriesInList(it, outlist);
    }
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

    std::vector<std::shared_ptr<FSEntity>> allDirectories;
    putAllSubDirectoriesInList(root, allDirectories);

    int freeSpace     = 70000000 - root->getDirectorySize();
    int requiredSpace = 30000000 - freeSpace;

    std::shared_ptr<FSEntity> answerDirectory;
    for (auto it : allDirectories)
    {
        if (it->getDirectorySize() > requiredSpace)
        {
            if (answerDirectory.get() == nullptr || it->getDirectorySize() < answerDirectory->getDirectorySize())
            {
                answerDirectory = it;
            }
        }
    }

    int answer = answerDirectory->getDirectorySize();
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}