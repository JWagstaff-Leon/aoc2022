#include "elf.h"



double Elf::getCalorieCount() const
{
    double calorieCount = 0;
    for (auto it = calories_.cbegin(); it != calories_.cend(); it++)
    {
        calorieCount += *it;
    }
    return calorieCount;
};



void Elf::addCalories(double calories)
{
    calories_.push_back(calories);
};