#ifndef MONKEY_H
#define MONKEY_H

#include <queue>
#include <functional>

class Monkey
{
    public:
        Monkey(std::queue<int> items, std::function<int(int)> worryFunction, std::function<bool(int)> testFunction);

        void processItems();
        void setTrueCaseTarget (Monkey* target);
        void setFalseCaseTarget(Monkey* target);

        void acceptItem        (int item);

        inline int getProcessedItemsCount() { return itemsProcessed_; };

    private:
        std::queue<int>          items_;
        std::function<int(int)>  worryFunction_;
        std::function<bool(int)> testFunction_;
        Monkey*                  trueCaseTarget_;
        Monkey*                  falseCaseTarget_;

        void throwItemTo (int item, Monkey* target);

        int itemsProcessed_;
};

#endif