#ifndef FS_ENTITY_H
#define FS_ENTITY_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>



class FSEntity
{
    public:
        virtual std::string                            getName         ()                                   const = 0;
        virtual int                                    getSize         ()                                   const = 0;
        virtual int                                    getDirectorySize()                                   const = 0;
        virtual std::vector<std::shared_ptr<FSEntity>> getChildren     ()                                   const = 0;
        virtual std::shared_ptr<FSEntity>              getChildByName  (std::string name)                   const = 0;
        virtual void                                   addChild        (std::shared_ptr<FSEntity> newChild)       = 0;
        inline  std::ostream&                          writeFileTreeTo (std::ostream& sout, int indent = 0) const {
            sout << this->getName() << std::endl;
            if (this->getChildren().size() > 0)
            {
                for (auto it : this->getChildren())
                {
                    for (int i = 0; i < indent + 1; i++)
                    {
                        sout << "-";
                    }
                    it->writeFileTreeTo(sout, indent + 1);
                    sout << "\n";
                }
            }
            return sout;
            };
};

#endif