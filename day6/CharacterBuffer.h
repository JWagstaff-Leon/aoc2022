#ifndef CHARACTER_GROUP_H
#define CHARACTER_GROUP_H

#include <vector>



class CharacterBuffer
{
    public:
        CharacterBuffer(int size);
        bool allUnique() const;
        void insertCharacter(char value);

    private:
        int               size_;
        std::vector<char> data_;
};

#endif