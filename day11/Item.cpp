#include "Item.h"
#include <iostream>
#include <iomanip>



Item::Item()
: reverseTenThousandsPlaces_{0}
{
    reverseTenThousandsPlaces_.reserve(500000);
};



Item::Item(int value)
{
    while (value > 0)
    {
        reverseTenThousandsPlaces_.push_back(value % 10000);
        value /= 10000;
    }
    reverseTenThousandsPlaces_.reserve(500000);
};



Item::Item(const Item& sourceItem)
{
    this->reverseTenThousandsPlaces_ = sourceItem.reverseTenThousandsPlaces_;
    reverseTenThousandsPlaces_.reserve(500000);
};




Item::Item(const std::vector<int> &reverseTenThousandPlaces)
: reverseTenThousandsPlaces_(reverseTenThousandPlaces)
{
    reverseTenThousandsPlaces_.reserve(500000);
};



Item Item::operator+(const Item& rhs) const
{
    int i;
    int carry = 0;
    std::vector<int> result;
    // std::cout << "Entering add case with " << *this << " + " << rhs << "...\n";
    for (i = 0; i < this->reverseTenThousandsPlaces_.size() && i < rhs.reverseTenThousandsPlaces_.size(); i++)
    {
        int leftValue  = this->reverseTenThousandsPlaces_[i];
        int rightValue = rhs.reverseTenThousandsPlaces_[i];
        int sum = leftValue + rightValue + carry;
        result.push_back(abs(sum % 10000));
        carry = sum / 10000;
    }

    std::vector<int> longerNum;
    if (this->reverseTenThousandsPlaces_.size() > rhs.reverseTenThousandsPlaces_.size())
    {
        longerNum = this->reverseTenThousandsPlaces_;
    }
    else
    {
        longerNum = rhs.reverseTenThousandsPlaces_;
    }

    for (i; i < longerNum.size(); i++)
    {
        int sum = longerNum[i] + carry;
        result.push_back(abs(sum % 10000));
        carry = sum / 10000;
    }

    if (carry > 0)
    {
        result.push_back(carry);
    }

    // std::cout << "Exiting add case with " << Item(result) << "...\n";
    return Item(result);
};



Item Item::operator+(const int rhs) const
{
    // std::cout << "Entering add case with " << *this << " + " << rhs << "...\n";
    std::vector<int> result;
    int carry = rhs;
    for (int i = 0; i < this->reverseTenThousandsPlaces_.size(); i++)
    {
        int sum = this->reverseTenThousandsPlaces_[i] + carry;
        result.push_back(sum % 10000);
        carry = sum / 10000;
    }
    if (carry > 0)
    {
        result.push_back(carry);
    }
    // std::cout << "Exiting add case with " << Item(result) << "...\n";
    return Item(result);
};



Item Item::operator*(const Item& rhs) const
{
    // std::cout << "Entering times case with " << *this << " * " << rhs << "...\n";
    Item result;

    for (int i = 0; i < rhs.reverseTenThousandsPlaces_.size(); i++)
    {
        // std::cout << "Digit " << i + 1 << " of rhs...\n";
        std::vector<int> subtotalData;
        for (int j = 0; j < i; j++)
        {
            subtotalData.push_back(0);
        }
        int carry = 0;
        for (int j = 0; j < this->reverseTenThousandsPlaces_.size(); j++)
        {
            // std::cout << "Digit " << j + 1 << " of lhs...\n";
            int leftValue  = this->reverseTenThousandsPlaces_[j];
            int rightValue = rhs.reverseTenThousandsPlaces_[i];
            int product    = leftValue * rightValue + carry;
            // std::cout << "Product was " << product << "...\n";
            subtotalData.push_back(product % 10000);
            carry = product / 10000;
        }
        if (carry > 0)
        {
            subtotalData.push_back(carry);
        }
        // std::cout << "Updating result...\n";
        result = result + subtotalData;
    }
    // std::cout << "Exiting times case with " << result << "...\n";
    return result;
};



Item Item::operator*(const int rhs) const
{
    // std::cout << "Multiplying " << *this << " by " << rhs << "...\n";
    std::vector<int> result;
    int carry = 0;
    for (int i = 0; i < this->reverseTenThousandsPlaces_.size(); i++)
    {
        int product = this->reverseTenThousandsPlaces_[i] * rhs + carry;
        result.push_back(product % 10000);
        carry = product / 10000;
    }
    if (carry > 0)
    {
        result.push_back(carry);
    }
    // std::cout << "Got " << Item(result) << "...\n";
    return Item(result);
};



Item Item::operator/(int rhs) const
{
    // std::cout << "Entering divide case with " << *this << " / " << rhs << "...\n";
    std::vector<int> reverseResult, trimmedReverseResult, result;;
    int remainder = 0;
    for (int i = this->reverseTenThousandsPlaces_.size() - 1; i >= 0; i--)
    {
        int quotient = ((this->reverseTenThousandsPlaces_[i] + remainder) * 10000 / rhs) / 10000;
        // std::cout << "Quotient of " << this->reverseTenThousandsPlaces_[i] << " + " << remainder << " / " << rhs << " = " << quotient << "...\n";
        reverseResult.push_back(quotient);
        remainder = ((this->reverseTenThousandsPlaces_[i] + remainder) - (quotient * rhs)) * 10000;
    }

    bool leadingZeroes = true;
    for (int i = 0; i < reverseResult.size(); i++)
    {
        if (reverseResult[i] != 0)
        {
            leadingZeroes = false;
        }
        if (!leadingZeroes)
        {
            trimmedReverseResult.push_back(reverseResult[i]);
        }
    }
    for (int i = trimmedReverseResult.size() - 1; i >= 0; i--)
    {
        result.push_back(trimmedReverseResult[i]);
    }
    // std::cout << "Exiting divide case with " << Item(result) << "...\n";
    return Item(result);
};



bool Item::operator==(const Item& rhs) const
{
    // std::cout << "Comparing " << *this << " to " << rhs << "...\n";
    if (this->reverseTenThousandsPlaces_.size() != rhs.reverseTenThousandsPlaces_.size())
    {
        // std::cout << "Unequal sizes...\n";
        return false;
    }

    for (int i = 0; i < this->reverseTenThousandsPlaces_.size(); i++)
    {
        if (this->reverseTenThousandsPlaces_[i] != rhs.reverseTenThousandsPlaces_[i])
        {
            // std::cout << "Unequal values " << this->reverseTenThousandsPlaces_[i] << " =!= " <<  rhs.reverseTenThousandsPlaces_[i] << "...\n";
            return false;
        }
    }
    // std::cout << "Equal...\n";
    return true;
};



void Item::operator=(const Item& rhs)
{
    // std::cout << "void Item::operator=(const Item& rhs)...\n";
    // std::cout << "Setting temp = rhs...\n";
    std::vector<int> temp = rhs.reverseTenThousandsPlaces_;
    // std::cout << "Setting lhs = temp...\n";
    this->reverseTenThousandsPlaces_ = temp;
    // std::cout << "Done lhs = rhs...\n";
};



void Item::operator=(const Item&& rhs)
{
    // std::cout << "void Item::operator=(const Item&& rhs)...\n";
    // std::cout << "Setting lhs = rhs...\n";
    this->reverseTenThousandsPlaces_ = std::move(rhs.reverseTenThousandsPlaces_);
    // std::cout << "Done lhs = rhs...\n";
};



std::ostream& operator<<(std::ostream& sout, const Item& out)
{
    char oldWidth = sout.width(0);
    char oldFill  = sout.fill(' '); 
    for (auto it = out.reverseTenThousandsPlaces_.crbegin(); it != out.reverseTenThousandsPlaces_.crend(); it++)
    {
        sout << *it << ' ';
        // sout.width(4);
        // sout.fill('0');
    }
    sout.width(oldWidth);
    sout.fill(oldFill);
    return sout;
}