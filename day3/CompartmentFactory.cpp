#include "CompartmentFactory.h"

#include "Item.h"



Compartment CompartmentFactory::fromString(std::string compartmentString)
{
    Compartment newCompartment;
    for (int c = 0; c < compartmentString.length(); c++)
    {
        newCompartment.insert(Item(compartmentString[c]));
    }
    return newCompartment;
};