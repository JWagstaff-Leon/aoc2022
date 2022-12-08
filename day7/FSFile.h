#ifndef FS_FILE_H
#define FS_FILE_H

#include "FSEntity.h"

#include <vector>
#include <memory>
#include <string>



class FSFile : public FSEntity
{
    public:
        inline FSFile(std::string name, int size) :name_(name), size_(size) {};

        inline std::string                            getName         ()                                   const override { return name_; };
        inline int                                    getSize         ()                                   const override { return size_; };
        inline int                                    getDirectorySize()                                   const override { return 0; };
        inline std::vector<std::shared_ptr<FSEntity>> getChildren     ()                                   const override { return std::vector<std::shared_ptr<FSEntity>>{}; };
        inline std::shared_ptr<FSEntity>              getChildByName  (std::string name)                   const override { return std::shared_ptr<FSEntity>{}; };
        inline void                                   addChild        (std::shared_ptr<FSEntity> newChild)       override {  };

    private:
        std::string name_;
        int         size_;
};

#endif