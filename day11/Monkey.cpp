#include "Monkey.h"

#include <queue>
#include <functional>

#include "Item.h"
// #include <iostream>



Monkey::Monkey(std::queue<Item> items, std::function<Item(Item)> worryFunction, std::function<bool(Item)> testFunction)
: items_(items),
  worryFunction_(worryFunction),
  testFunction_(testFunction),
  trueCaseTarget_(nullptr),
  falseCaseTarget_(nullptr),
  itemsProcessed_(0)
{};

void Monkey::processItems()
{
    // std::cout << "Entering process items for " << items_.size() << " items...\n";
    while (!items_.empty())
    {
        // std::cout << "Next item " << items_.front() << "...\n";
        Item worry = worryFunction_(items_.front());
        
        Monkey* target;
        if (testFunction_(worry))
        {
            // std::cout << "True case...\n";
            target = trueCaseTarget_;
        }
        else
        {
            // std::cout << "False case...\n";
            target = falseCaseTarget_;
        }
        throwItemTo(worry, target);

        items_.pop();
        itemsProcessed_++;
        // std::cout << "Items processed is now " << itemsProcessed_ << "...\n";
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



void Monkey::acceptItem(Item item)
{
    items_.push(item);
};



void Monkey::throwItemTo(Item item, Monkey* target)
{
    target->acceptItem(item);
};