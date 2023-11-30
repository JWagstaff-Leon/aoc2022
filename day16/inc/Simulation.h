#pragma once

#include <cstdint>
#include <string>

#include "ValveMap.h"

class Simulation
{
    public:
        Simulation(ValveMap map);

        uint32_t getStepsDone() const;

        uint32_t doStep();
        uint32_t openValveStep();
        uint32_t moveToStep(std::string valveName);

    private:
        uint32_t totalFlow_;
        uint32_t stepsDone_;

        ValveMap map_;
        std::string location_;
        
};