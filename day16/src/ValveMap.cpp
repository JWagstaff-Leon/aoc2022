#include "ValveMap.h"

#include <set>
#include <utility>

bool ValveMap::openValve(std::string valveName)
{
    auto valve = valves_.find(valveName);
    bool found = valve != valves_.end();
    if(found)
        valve->open();

    return found;
};



bool ValveMap::closeValve(std::string valveName)
{
    auto valve = valves_.find(valveName);
    bool found = valve != valves_.end();
    if(found)
        valve->close();

    return found;
};



bool ValveMap::addValve(std::string valveName, uint32_t flowRate)
{
    auto result = valves_.emplace(valveName, flowRate);
    return result.second;
};



ConnectionAddResult ValveMap::addConnection(std::string valve1Name, std::string valve2Name)
{
    auto valve1 = valves_.find(valve1Name);
    auto valve2 = valves_.find(valve2Name);

    if(valve1 == valves_.end() && valve2 == valves_.end())
        return ConnectionAddResult::INVALID_VALVE_BOTH;
    if(valve1 == valves_.end())
        return ConnectionAddResult::INVALID_VALVE_1;
    if(valve2 == valves_.end())
        return ConnectionAddResult::INVALID_VALVE_2;

    Connection newConnection{&*valve1, &*valve2};
    auto result = connections_.insert(newConnection);

    return (result.second ? ConnectionAddResult::SUCCESS : ConnectionAddResult::ALREADY_EXISTS);
};



uint32_t ValveMap::getTotalFlowRate() const
{
    uint32_t total = 0;

    for(auto valve : valves_)
        total += valve.getCurrentFlowRate();

    return total;
};