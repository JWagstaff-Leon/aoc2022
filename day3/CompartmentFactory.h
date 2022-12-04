#ifndef COMPARTMENT_FACTORY_H
#define COMPARTMENT_FACTORY_H

#include <string>

#include "Compartment.h"



class CompartmentFactory
{
    public:
        static Compartment fromString(std::string compartmentString);

    private:
        CompartmentFactory();
};

#endif