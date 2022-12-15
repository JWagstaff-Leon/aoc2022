#ifndef MONKEY_H
#define MONKEY_H

#include <queue>
#include <functional>

#include "bigint/bigint.h"

class Monkey
{
    public:
        Monkey(std::queue<bigint> items, std::function<bigint(bigint)> worryFunction, std::function<bool(bigint)> testFunction);

        void processItems();
        void setTrueCaseTarget (Monkey* target);
        void setFalseCaseTarget(Monkey* target);

        void acceptItem (bigint item);

        inline int getProcessedItemsCount() { return itemsProcessed_; };

    private:
        std::queue<bigint>            items_;
        std::function<bigint(bigint)> worryFunction_;
        std::function<bool(bigint)>   testFunction_;
        Monkey*                       trueCaseTarget_;
        Monkey*                       falseCaseTarget_;

        void throwItemTo (bigint item, Monkey* target);

        int itemsProcessed_;
};

#endif