#include "Monkey.h"

#include <queue>
#include <functional>

#include "Item.h"



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
    while (!items_.empty())
    {
        Item worry = worryFunction_(items_.front());
        
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