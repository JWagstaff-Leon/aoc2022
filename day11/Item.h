#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <ostream>



class Item
{
    public:
        Item();
        Item(std::vector<int> reverseTenThousandPlaces, bool isNegative);

        Item& operator+(const Item& rhs) const; 
        // Item& operator-(const Item& rhs) const;
        Item& operator*(const Item& rhs) const; 
        Item& operator/(int rhs) const; 
        
        Item& operator=(const Item& rhs); 

        friend std::ostream& operator<< (std::ostream& sout, const Item& out);

    private:
        std::vector<int> reverseTenThousandsPlaces_;
        bool             isNegative;
};

#endif