#include "Valve.h"

Valve::Valve(std::string name, uint32_t flowRate)
: name_(name), flowRate_(flowRate) { /* Intentionally empty */ };



bool Valve::isOpen() const
{
    return open_;
};



void Valve::open()
{
    open_ = true;
};



void Valve::close()
{
    open_ = false;
};



std::string Valve::getName() const
{
    return name_;
};



uint32_t Valve::getFlowRate() const
{
    return flowRate_;
};



uint32_t getCurrentFlowRate() const
{
    return (isOpen() ? getFlowRate() : 0);
};