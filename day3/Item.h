#ifndef ITEM_H
#define ITEM_H



class Item
{
    public:
        Item();
        Item(char itemValue);

        virtual int getPriority() const;

        friend bool operator<  (const Item lhs, const Item rhs);
        friend bool operator== (const Item lhs, const Item rhs);

    private:
        char value_;
};

#endif