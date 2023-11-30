#include "Simulation.h"

Simulation::Simulation(ValveMap map)
: map_(map) { /* Intentionally empty */ };



uint32_t Simulation::getStepsDone() const
{
    return stepsDone_;
};



uint32_t Simulation::doStep()
{
    totalFlow_ += map_.getOverallFlowRate();
    return ++stepsDone_;
};



uint32_t Simulation::openValveStep()
{
    if(map_.openValve(location_))
        return doStep();
    
    return getStepsDone();
};



uint32_t Simulation::moveToStep(std::string valveName)
{
    if(map_.isConnected(location_, valveName))
    {
        location_ = valveName;
        return doStep();
    }

    return getStepsDone();
};