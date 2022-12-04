#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include <set>
#include <memory>

#include "Item.h"



class Compartment
{
    public:
        Compartment();
        Compartment(std::set<Item> newData);

        void        insert    (Item newItem);
        Compartment junction(const Compartment& compare) const;

        std::unique_ptr<Item> getOnlyItemOrNull();

    private:
        std::set<Item> data_;
};

#endif