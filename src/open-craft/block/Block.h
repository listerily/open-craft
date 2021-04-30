#ifndef OPEN_CRAFT_BLOCK_H
#define OPEN_CRAFT_BLOCK_H

#include <string>

class BlockMannager;
class Block
{
protected:
    const std::string id;
public:
    Block(BlockMannager&, std::string id);
    virtual ~Block();
    virtual bool isDestroyable() const;
    virtual bool isSolid() const;
    virtual bool isVisible() const;
    virtual std::string getTessellationModelID() const;
    virtual std::string getDisplayName() const;
    virtual std::string getID() const;
    virtual std::string getDescription() const;
};


#endif //OPEN_CRAFT_BLOCK_H
