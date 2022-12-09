#include <iostream>
#include <fstream>

#include <vector>
#include <string>



int getScenicScore(int y, int x, const std::vector<std::vector<int>> trees)
{
    int topScore    = 0;
    int leftScore   = 0;
    int rightScore  = 0;
    int bottomScore = 0;

    int treeHeight = trees[y][x];

    for (int i = y - 1; i >= 0; i--)
    {
        topScore += 1;
        if (trees[i][x] >= treeHeight)
        {
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        leftScore += 1;
        if (trees[y][i] >= treeHeight)
        {
            break;
        }
    }

    for (int i = y + 1; i < trees.size(); i++)
    {
        bottomScore += 1;
        if (trees[i][x] >= treeHeight)
        {
            break;
        }
    }

    for (int i = x + 1; i < trees[y].size(); i++)
    {
        rightScore += 1;
        if (trees[y][i] >= treeHeight)
        {
            break;
        }
    }

    int scenicScore = topScore * leftScore * rightScore * bottomScore;
    return scenicScore;
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
            int scenicScore = getScenicScore(y, x, trees);
            if (scenicScore > answer)
            {
                answer = scenicScore;
            }
        }
    }

    std::cout << "Answer: " << answer << std::endl;
    return 0;
}