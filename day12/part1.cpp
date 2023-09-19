#include <iostream>
#include <utility>
#include <cstdint>
#include <fstream>
#include <vector>
#include <functional>
#include <queue>
#include <set>
#include <map>
#include <string>

class Coordinate
{
    public:
        Coordinate() { Coordinate(0, 0); };
        Coordinate(int32_t x, int32_t y) : pair_(std::make_pair(x, y)) {};
    
        int32_t x() const { return pair_.first; };
        int32_t y() const { return pair_.second; };

    private:
        std::pair<int32_t, int32_t> pair_;
};



bool operator== (const Coordinate& lhs, const Coordinate& rhs)
{
    return (lhs.x() == rhs.x() && lhs.y() == rhs.y());
};



bool operator!= (const Coordinate& lhs, const Coordinate& rhs)
{
    return (lhs.x() != rhs.x() || lhs.y() != rhs.y());
};



bool operator< (const Coordinate& lhs, const Coordinate& rhs)
{
    return (lhs.y() < rhs.y() || lhs.y() == rhs.y() && lhs.x() < rhs.x());
};



std::ostream& operator<< (std::ostream& sout, Coordinate coord)
{
    sout << "(" << coord.y() + 1 << ", " << coord.x() + 1 << ")";
    return sout;
};



Coordinate findFirstInstance(unsigned char target, std::vector<std::vector<unsigned char>> nodes)
{
    uint32_t x = 0, y = 0;
    for (auto currentRow : nodes)
    {
        x = 0;
        for (auto currentNode : currentRow)
        {
            if (currentNode == target)
            {
                return Coordinate(x, y);
            }
            x++;
        }
        y++;
    }
    return Coordinate(-1, -1);
};



struct AStarNode
{
    Coordinate coordinate;
    uint32_t f, g;
};



bool operator== (AStarNode lhs, AStarNode rhs)
{
    return lhs.coordinate == rhs.coordinate;
}



bool operator< (AStarNode lhs, AStarNode rhs)
{
    return lhs.f < rhs.f;
};



uint32_t distanceFunc(Coordinate start, Coordinate end)
{
    uint32_t x_dist, y_dist;

    if (end.x() >= start.x())
    {
        x_dist = end.x() - start.x();
    }
    else
    {
        x_dist = start.x() - end.x();
    }

    if (end.y() >= start.y())
    {
        y_dist = end.y() - start.y();
    }
    else
    {
        y_dist = start.y() - end.y();
    }

    return x_dist + y_dist;
};



class FScoreCompare
{
    public:
        FScoreCompare(const bool& greaterThan = false) : gt_(greaterThan) {};
        bool operator()(AStarNode lhs, AStarNode rhs) const
        {
            if (gt_)
            {
                return lhs.f > rhs.f;
            }
            return lhs.f < rhs.f;
        };

    private:
        bool gt_;
};


std::vector<Coordinate> a_star(Coordinate start, Coordinate end, std::vector<std::vector<unsigned char>> nodes, std::function<uint32_t(Coordinate, Coordinate)> distanceFunc)
{
    std::map<Coordinate, Coordinate> parentMap;

    std::map<Coordinate, int32_t> gScoresMap;
    gScoresMap[start] = 0;

    std::priority_queue<AStarNode, std::vector<AStarNode>, FScoreCompare> processQueue;
    std::set<Coordinate> inQueue;
    AStarNode startNode;
    startNode.coordinate = start;
    startNode.g = 0;
    startNode.f = distanceFunc(start, end);
    processQueue.push(startNode);
    inQueue.insert(startNode.coordinate);

    int nodesProcessed = 0;
    while (!processQueue.empty())
    {
        AStarNode currentBest = processQueue.top();
        if (currentBest.coordinate == end)
        {
            std::vector<Coordinate> rBestPath;
            Coordinate nextCoord = currentBest.coordinate;
            std::map<Coordinate, Coordinate>::iterator it;

            do
            {
                rBestPath.push_back(nextCoord);
                it = parentMap.find(nextCoord);
                nextCoord = it->second;
            } while (it != parentMap.end() && it->second != start);
            
            std::vector<Coordinate> bestPath;
            for (auto it = rBestPath.rbegin(); it != rBestPath.rend(); it++)
            {
                bestPath.push_back(*it);
            }
            return bestPath;
        }

        processQueue.pop();
        inQueue.erase(currentBest.coordinate);

        std::vector<std::pair<int, int>> offsets;
        offsets.push_back(std::make_pair( 0,  1));
        offsets.push_back(std::make_pair( 0, -1));
        offsets.push_back(std::make_pair( 1,  0));
        offsets.push_back(std::make_pair(-1,  0));
        for (std::pair<int, int> offset : offsets)
        {
            int x = offset.first;
            int y = offset.second;
            Coordinate neighbor(currentBest.coordinate.x() + x, currentBest.coordinate.y() + y);

            bool neighborInBoundsY = neighbor.y() >= 0 && neighbor.y() < nodes.size();
            bool neighborInBounds = neighborInBoundsY && neighbor.x() >= 0 && neighbor.x() < nodes.at(neighbor.y()).size();
            if (!neighborInBounds)
            {
                continue;
            }

            unsigned char currentHeight = nodes.at(currentBest.coordinate.y()).at(currentBest.coordinate.x());
            unsigned char neighborHeight = nodes.at(neighbor.y()).at(neighbor.x());
            if (currentHeight == 'S')
            {
                currentHeight = 'a';
            }
            if (currentHeight == 'E')
            {
                currentHeight = 'z';
            }
            if (neighborHeight == 'S')
            {
                neighborHeight = 'a';
            }
            if (neighborHeight == 'E')
            {
                neighborHeight = 'z';
            }
            bool neighborAccessible = currentHeight >= neighborHeight - 1;
            if (!neighborAccessible)
            {
                continue;
            }

            AStarNode neighborNode;
            neighborNode.coordinate = neighbor;
            neighborNode.g = currentBest.g + 1;
            neighborNode.f = neighborNode.g + distanceFunc(neighborNode.coordinate, end);
            
            if (gScoresMap.find(neighborNode.coordinate) == gScoresMap.end() ||
                neighborNode.g < gScoresMap.at(neighborNode.coordinate))
            {
                gScoresMap[neighborNode.coordinate] = neighborNode.g;
                parentMap[neighborNode.coordinate] = currentBest.coordinate;
                if (inQueue.find(neighborNode.coordinate) == inQueue.end())
                {
                    processQueue.push(neighborNode);
                    inQueue.insert(neighborNode.coordinate);
                }
            }
        }
    }

    return std::vector<Coordinate>();
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

    std::vector<std::vector<unsigned char>> nodes;

    while (!fin.eof())
    {
        std::string currentLine;
        std::getline(fin, currentLine);
        std::vector<unsigned char> currentVector;

        for (char currentChar : currentLine)
        {
            currentVector.push_back(currentChar);
        }
        nodes.push_back(currentVector);
    }

    fin.close();

    Coordinate startPosition = findFirstInstance('S', nodes);
    Coordinate endPosition = findFirstInstance('E', nodes);

    if (startPosition.x() < 0 || startPosition.y() < 0)
    {
        std::cout << "Error: could not find start position\n";
        return 0;
    }

    if(endPosition.y() < 0 || endPosition.y() < 0)
    {
        std::cout << "Error: could not find end position\n";
        return 0;
    }

    std::vector<Coordinate> bestPath = a_star(startPosition, endPosition, nodes, &distanceFunc);

    if (bestPath.size() < 1)
    {
        std::cout << "Error: Unable to find a path\n";
        return 0;
    }

    std::cout << "Answer: " << bestPath.size() << std::endl;
    std::cout << "Path:\n";
    for (Coordinate coord : bestPath)
    {
        std::cout << nodes.at(coord.y()).at(coord.x()) << " " << coord << std::endl;
    }

    return 0;
}