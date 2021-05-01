#include "StoneBlock.h"

std::string StoneBlock::getTessellationModelID() const
{
    return "model/tessellation/solid_block";
}

std::string StoneBlock::getDisplayName() const
{
    return "display/block/name/stone";
}

std::string StoneBlock::getDescription() const
{
    return "display/block/description/stone";
}

StoneBlock::StoneBlock(BlockManager &mgr) : Block(mgr, "block/stone")
{

}

StoneBlock::~StoneBlock() = default;
