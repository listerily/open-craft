#ifndef OPEN_CRAFT_STONE_BLOCK_H
#define OPEN_CRAFT_STONE_BLOCK_H

#include "../Block.h"

class BlockManager;

class StoneBlock : public Block
{
public:
    explicit StoneBlock(BlockManager &);

    ~StoneBlock() override;

    std::string getTessellationModelID() const override;

    std::string getDisplayName() const override;

    std::string getDescription() const override;
};


#endif //OPEN_CRAFT_STONE_BLOCK_H
