#include "Compartment.h"

#include <set>
#include <memory.h>

#include "Item.h"
#include "NullItem.h"



Compartment::Compartment()
: data_(std::set<Item>()) {};



Compartment::Compartment(std::set<Item> newData)
: data_(newData) {};



void Compartment::insert(Item newItem)
{
    data_.insert(newItem);
};



Compartment Compartment::junction(const Compartment& compare) const
{
    Compartment junctionSet;
    for (auto it = data_.cbegin(); it != data_.cend(); it++)
    {
        for (auto jt = compare.data_.cbegin(); jt != compare.data_.cend(); jt++)
        {
            if (it->getPriority() == jt->getPriority())
            {
                junctionSet.data_.insert(*it);
            }
        }
    }
    return junctionSet;
};


std::unique_ptr<Item> Compartment::getOnlyItemOrNull()
{
    std::unique_ptr<Item> onlyItem = std::make_unique<NullItem>();
    if (data_.size() == 1)
    {
        onlyItem = std::make_unique<Item>(*data_.begin());
    }
    return onlyItem;
};