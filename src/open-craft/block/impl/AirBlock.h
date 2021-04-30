#ifndef OPEN_CRAFT_AIR_BLOCK_H
#define OPEN_CRAFT_AIR_BLOCK_H

#include "../Block.h"

class BlockMannager;

class AirBlock : public Block
{
public:
    explicit AirBlock(BlockMannager &);

    ~AirBlock() override;

    bool isDestroyable() const override;

    bool isSolid() const override;

    bool isVisible() const override;

    std::string getDisplayName() const override;

    std::string getDescription() const override;
};


#endif //OPEN_CRAFT_AIR_BLOCK_H
