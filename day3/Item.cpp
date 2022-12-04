#include "Item.h"

#include <cctype>



Item::Item()
: value_('A') {};


Item::Item(char itemValue)
{
    if (!std::isalpha(itemValue))
    {
        itemValue = 'A';
    }
    value_ = itemValue;
};



int Item::getPriority() const
{
    int priority = 0;
    if (std::isupper(value_))
    {
        priority += 26;
    }
    priority += std::toupper(value_) - 64;
    return priority;
};



bool operator< (const Item lhs, const Item rhs)
{
    return lhs.getPriority() < rhs.getPriority();
};



bool operator== (const Item lhs, const Item rhs)
{
    return lhs.getPriority() == rhs.getPriority();
};