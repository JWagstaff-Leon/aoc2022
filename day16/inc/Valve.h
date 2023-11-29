#pragma once

#include <cstdint>
#include <string>

class Valve
{
    public:
        Valve(std::string name, uint32_t flowRate);

        bool isOpen() const;
        void open();
        void close();

        std::string getName() const;
        uint32_t getFlowRate() const;

        uint32_t getCurrentFlowRate() const;

    private:
        std::string name_;
        uint32_t flowRate_;
        bool open_;
};



struct {
    bool operator() (const Valve& lhs, const Valve& rhs) { return lhs.getName() < rhs.getName(); };
} ValveComparator;