#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <ostream>



class Item
{
    public:
        Item();
        Item(unsigned long long startingNumber);
        Item(const Item& sourceItem);

        Item operator+ (const Item& rhs) const;
        Item operator+ (const int rhs)   const;
        Item operator* (const Item& rhs) const;
        Item operator* (const int rhs)   const;
        Item operator/ (int rhs)         const;
        bool operator==(const Item& rhs) const;
        
        void operator=(const Item& rhs);
        void operator=(const Item&& rhs);

        friend std::ostream& operator<< (std::ostream& sout, const Item& out);

    private:
        unsigned long long value_;
        static const int MAX_VALUE = 9699690;
};

#endif