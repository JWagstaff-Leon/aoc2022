#include "FSDirectory.h"

#include <vector>
#include <memory>
#include <string>

#include "FSEntity.h"
#include <iostream>



FSDirectory::FSDirectory(std::string name)
: name_(name), children_( std::vector<std::shared_ptr<FSEntity>> {} ) { };


int FSDirectory::getDirectorySize() const
{
    int size = 0;
    for (auto it = children_.cbegin(); it != children_.cend(); it++)
    {
        size += (**it).getSize() + (**it).getDirectorySize();
    }
    return size;
};



std::shared_ptr<FSEntity> FSDirectory::getChildByName(std::string name) const
{
    std::shared_ptr<FSEntity> foundChild;
    for (auto it = children_.cbegin(); it != children_.cend(); it++)
    {
        if ((**it).getName() == name)
        {
            foundChild = *it;
        }
    }
    return foundChild;
};



void FSDirectory::addChild(std::shared_ptr<FSEntity> newChild)
{
    if (newChild != nullptr)
    {
        children_.push_back(newChild);
    }
};