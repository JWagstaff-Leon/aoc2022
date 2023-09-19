#include "Item.h"
#include <iostream>
#include <iomanip>



Item::Item()
: value_(0) {};



Item::Item(unsigned long long value)
{
    value_ = value % Item::MAX_VALUE;
};



Item::Item(const Item& sourceItem)
{
    value_ = sourceItem.value_;
};



Item Item::operator+(const Item& rhs) const
{
    unsigned long long result = this->value_ + rhs.value_;
    result = result % Item::MAX_VALUE;
    return Item(result);
};



Item Item::operator*(const Item& rhs) const
{
    unsigned long long result = this->value_ * rhs.value_;
    result = result % Item::MAX_VALUE;
    return Item(result);
};



Item Item::operator*(const int rhs) const
{
    unsigned long long result = this->value_ * abs(rhs);
    result = result % Item::MAX_VALUE;
    return Item(result);
};



Item Item::operator/(int rhs) const
{
    unsigned long long result = this->value_ / abs(rhs);
    result = result % Item::MAX_VALUE;
    return Item(result);
};



bool Item::operator==(const Item& rhs) const
{
    return this->value_ == rhs.value_;
};



void Item::operator=(const Item& rhs)
{
    this->value_ = rhs.value_;
};



void Item::operator=(const Item&& rhs)
{
    this->value_ = rhs.value_;
};



std::ostream& operator<<(std::ostream& sout, const Item& out)
{
    sout << out.value_;
    return sout;
}