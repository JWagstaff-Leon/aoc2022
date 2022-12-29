#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <ostream>



class Item
{
    public:
        Item();
        Item(int startingNumber);
        Item(const std::vector<int> &reverseTenThousandPlaces);
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
        std::vector<int> reverseTenThousandsPlaces_;
};

#endif