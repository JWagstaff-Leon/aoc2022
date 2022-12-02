#ifndef ELF_H
#define ELF_H

#include <vector>

class Elf
{
    public:
        double getCalorieCount()            const;
        void   addCalories(double calories)      ;

    private:
        std::vector<double> calories_;
};

#endif