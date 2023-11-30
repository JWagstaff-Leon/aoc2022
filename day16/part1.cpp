#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Simulation.h"
#include "ValveMap.h"

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

    ValveMap map;
    std::vector<std::pair<std::string, std::vector<std::string>>> valveNameConnectionsPairs;
    while(!fin.eof())
    {
        std::string valveInfo, connectionInfo, valveName;
        uint32_t flowRate;
        std::getline(fin, valveInfo, ';');
        std::getline(fin, connectionInfo);

        valveName.reserve(3);
        sscanf(valveInfo.c_str(), "Valve %s has flow rate=%u", valveName.c_str(), &flowRate);

        std::vector<std::string> connections;
        for(int c = 24; c < connectionInfo.length(); c += 2)
        {
            std::string connectionName;
            while(connectionInfo[c] != ',')
                connectionName += connectionInfo[c++];
            
            connections.push_back(std::move(connectionName));
        }

        map.addValve(valveName, flowRate);
        valveNameConnectionsPairs.push_back(std::make_pair(std::move(valveName), std::move(connections)));
    }
    fin.close();

    for(auto valveConnection : valveNameConnectionsPairs)
        for(auto connection : valveConnection.second)
            map.addConnection(valveConnection.first, connection);
    
    Simulation simulation(map);
    
    // figure out a way to do 30 steps to maximize flow rate
    // maybe as a distance x flow rate?
    
    return 0;
}