#include <iostream>
#include <fstream>

#include <vector>
#include <string>



bool isTreeVisible(int y, int x, const std::vector<std::vector<int>> trees)
{
    bool isVisibleFromTop    = true;
    bool isVisibleFromLeft   = true;
    bool isVisibleFromRight  = true;
    bool isVisibleFromBottom = true;

    int treeHeight = trees[y][x];

    for (int i = y - 1; i >= 0; i--)
    {
        if (trees[i][x] >= treeHeight)
        {
            isVisibleFromTop = false;
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (trees[y][i] >= treeHeight)
        {
            isVisibleFromLeft = false;
        }
    }

    for (int i = y + 1; i < trees.size(); i++)
    {
        if (trees[i][x] >= treeHeight)
        {
            isVisibleFromBottom = false;
        }
    }

    for (int i = x + 1; i < trees[y].size(); i++)
    {
        if (trees[y][i] >= treeHeight)
        {
            isVisibleFromRight = false;
        }
    }

    bool isVisible = isVisibleFromTop || isVisibleFromLeft || isVisibleFromRight || isVisibleFromBottom;
    return isVisible;
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

    std::vector<std::vector<int>> trees;
    std::string currentLine;
    while (!fin.eof())
    {
        std::getline(fin, currentLine);
        std::vector<int> currentTreeLine;
        for (int c = 0; c < currentLine.length(); c++)
        {
            currentTreeLine.push_back(currentLine[c] - 48);
        }
        trees.push_back(currentTreeLine);
    }
    fin.close();

    int answer = 0;
    for (int y = 0; y < trees.size(); y++)
    {
        for (int x = 0; x < trees[y].size(); x++)
        {
            if (isTreeVisible(y, x, trees))
            {
                answer += 1;
            }
        }
    }

    std::cout << "Answer: " << answer << std::endl;
    return 0;
}