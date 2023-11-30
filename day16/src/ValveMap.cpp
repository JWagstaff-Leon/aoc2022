#include "ValveMap.h"

#include <set>
#include <utility>

bool ValveMap::openValve(std::string valveName)
{
    auto findResult = findValve(valveName);
    if(findResult.second)
        const_cast<Valve*>(&*findResult.first)->open();

    return findResult.second;
};



bool ValveMap::closeValve(std::string valveName)
{
    auto findResult = findValve(valveName);
    if(findResult.second)
        const_cast<Valve*>(&*findResult.first)->close();

    return findResult.second;
};



bool ValveMap::isConnected(std::string valve1Name, std::string valve2Name) const
{
    for(auto connection : connections_)
    {
        if(connection.end1->getName() == valve1Name && connection.end2->getName() == valve2Name ||
           connection.end1->getName() == valve2Name && connection.end2->getName() == valve1Name)
        {
           return true;
        }
    }

    return false;
};



bool ValveMap::addValve(std::string valveName, uint32_t flowRate)
{
    auto result = valves_.emplace(valveName, flowRate);
    return result.second;
};



ConnectionAddResult ValveMap::addConnection(std::string valve1Name, std::string valve2Name)
{
    auto valve1Result = findValve(valve1Name);
    auto valve2Result = findValve(valve2Name);

    if(!valve1Result.second && !valve2Result.second)
        return ConnectionAddResult::INVALID_VALVE_BOTH;
    if(!valve1Result.second)
        return ConnectionAddResult::INVALID_VALVE_1;
    if(!valve2Result.second)
        return ConnectionAddResult::INVALID_VALVE_2;

    Connection newConnection{const_cast<Valve*>(&*valve1Result.first), const_cast<Valve*>(&*valve2Result.first)};
    auto result = connections_.insert(newConnection);

    return (result.second ? ConnectionAddResult::SUCCESS : ConnectionAddResult::ALREADY_EXISTS);
};



uint32_t ValveMap::getOverallFlowRate() const
{
    uint32_t total = 0;

    for(auto valve : valves_)
        total += valve.getCurrentFlowRate();

    return total;
};



std::pair<std::set<Valve>::iterator, bool> ValveMap::findValve(std::string valveName)
{
    for(auto it = valves_.begin(); it != valves_.end(); it++)
        if(it->getName() == valveName)
            return std::make_pair(std::move(it), true);
    
    return std::make_pair(valves_.end(), false);
};