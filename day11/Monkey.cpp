#include "Monkey.h"

#include <queue>
#include <functional>



Monkey::Monkey(std::queue<int> items, std::function<int(int)> worryFunction, std::function<bool(int)> testFunction)
: items_(items),
  worryFunction_(worryFunction),
  testFunction_(testFunction),
  trueCaseTarget_(nullptr),
  falseCaseTarget_(nullptr),
  itemsProcessed_(0)
{};


#include <iostream>
void Monkey::processItems()
{
    while (!items_.empty())
    {
        int worry = worryFunction_(items_.front());
        
        Monkey* target;
        if (testFunction_(worry))
        {
            target = trueCaseTarget_;
        }
        else
        {
            target = falseCaseTarget_;
        }
        throwItemTo(worry, target);

        items_.pop();
        itemsProcessed_++;
        std::cout << "Items processed is now " << itemsProcessed_ << "\n";
    }
};



void Monkey::setTrueCaseTarget(Monkey* target)
{
    trueCaseTarget_ = target;
};



void Monkey::setFalseCaseTarget(Monkey* target)
{
    falseCaseTarget_ = target;
};



void Monkey::acceptItem(int item)
{
    items_.push(item);
};



void Monkey::throwItemTo(int item, Monkey* target)
{
    target->acceptItem(item);
};