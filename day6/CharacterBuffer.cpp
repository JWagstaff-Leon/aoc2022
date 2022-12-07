#include "CharacterBuffer.h"

#include <iostream>
#include <vector>



CharacterBuffer::CharacterBuffer(int size)
: size_(size)
{
    data_.resize(size_);
    for (auto it = data_.begin(); it != data_.end(); it++)
    {
        *it = '\0';
    }
};



bool CharacterBuffer::allUnique() const
{
    bool allUnique = true;
    for (int i = 0; i < size_; i++)
    {
        if (data_[i] == '\0')
        {
            allUnique = false;
        }
        for (int j = i + 1; j < size_; j++)
        {
            if (data_[i] == data_[j])
            {
                allUnique = false;
            }
        }
    }
    return allUnique;
};



void CharacterBuffer::insertCharacter(char value)
{
    for (int i = 0; i < size_ - 1; i++)
    {
        data_[i] = data_[i + 1];
    }
    data_[size_ - 1] = value;
};