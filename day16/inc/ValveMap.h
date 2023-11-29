#pragma once

#include <cstdint>
#include <set>
#include <string>

#include "Connection.h"
#include "Valve.h"

enum class ConnectionAddResult
{
    SUCCESS,
    INVALID_VALVE_1,
    INVALID_VALVE_2,
    INVALID_VALVE_BOTH,
    ALREADY_EXISTS
};



class ValveMap
{
    public:
        bool openValve(std::string valveName);
        bool closeValve(std::string valveName);

        bool addValve(std::string valveName, uint32_t flowRate);
        ConnectionAddResult addConnection(std::string valve1Name, std::string valve2Name);

        uint32_t getTotalFlowRate() const;

    private:
        std::set<Valve, ValveComparator> valves_;
        std::set<Connections, ConnectionComparator> connections_;

        uint32_t totalFlow_;
};