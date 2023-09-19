#ifndef MONKEY_H
#define MONKEY_H

#include <queue>
#include <functional>

#include "Item.h"

class Monkey
{
    public:
        Monkey(std::queue<Item> items, std::function<Item(Item)> worryFunction, std::function<bool(Item)> testFunction);

        void processItems();
        void setTrueCaseTarget (Monkey* target);
        void setFalseCaseTarget(Monkey* target);

        void acceptItem(Item item);

        inline int getProcessedItemsCount() { return itemsProcessed_; };

    private:
        std::queue<Item>          items_;
        std::function<Item(Item)> worryFunction_;
        std::function<bool(Item)> testFunction_;
        Monkey*                   trueCaseTarget_;
        Monkey*                   falseCaseTarget_;

        void throwItemTo (Item item, Monkey* target);

        int itemsProcessed_;
};

#endif