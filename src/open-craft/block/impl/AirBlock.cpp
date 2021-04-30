#include "AirBlock.h"

AirBlock::AirBlock(BlockMannager& mgr) : Block(mgr, "block/air")
{

}

bool AirBlock::isDestroyable() const
{
    return Block::isDestroyable();
}

bool AirBlock::isSolid() const
{
    return false;
}

std::string AirBlock::getDisplayName() const
{
    return "display/block/air_block";
}

std::string AirBlock::getDescription() const
{
    return "display/block/description/air_block";
}

bool AirBlock::isVisible() const
{
    return false;
}

AirBlock::~AirBlock() = default;
