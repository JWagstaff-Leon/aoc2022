#include "Monkey.h"

#include <queue>
#include <functional>

#include "bigint/bigint.h"



Monkey::Monkey(std::queue<bigint> items, std::function<bigint(bigint)> worryFunction, std::function<bool(bigint)> testFunction)
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
        bigint worry = worryFunction_(items_.front());
        
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



void Monkey::acceptItem(bigint item)
{
    items_.push(item);
};



void Monkey::throwItemTo(bigint item, Monkey* target)
{
    target->acceptItem(item);
};