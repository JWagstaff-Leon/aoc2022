#ifndef FS_DIRECTORY_H
#define FS_DIRECTORY_H

#include "FSEntity.h"

#include <vector>
#include <memory>
#include <string>



class FSDirectory : public FSEntity
{
    public:
        FSDirectory(std::string name);
    
        inline std::string                            getName         ()                                   const override { return name_; };
        inline int                                    getSize         ()                                   const override { return 0; };
               int                                    getDirectorySize()                                   const override;
        inline std::vector<std::shared_ptr<FSEntity>> getChildren     ()                                   const override { return children_; };
               std::shared_ptr<FSEntity>              getChildByName  (std::string name)                   const override;
               void                                   addChild        (std::shared_ptr<FSEntity> newChild)       override;

    private:
        std::string name_;
        std::vector<std::shared_ptr<FSEntity>> children_;
};

#endif