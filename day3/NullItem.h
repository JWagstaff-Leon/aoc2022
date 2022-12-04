#ifndef NULL_ITEM_H
#define NULL_ITEM_H

#include "Item.h"

class NullItem : public Item
{
    public:
        inline NullItem() {};
        inline int getPriority() const override { return 0; };
};

#endif