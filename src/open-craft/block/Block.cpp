#include "Block.h"

Block::Block(BlockManager&, std::string id) : id(std::move(id))
{

}

Block::~Block() = default;

bool Block::isDestroyable() const
{
    return true;
}

bool Block::isSolid() const
{
    return true;
}

std::string Block::getTessellationModelID() const
{
    return "model/tessellation/undefined";
}

std::string Block::getDisplayName() const
{
    return "display/block/name/undefined";
}

std::string Block::getID() const
{
    return id;
}

std::string Block::getDescription() const
{
    return "display/block/description/undefined";
}

bool Block::isVisible() const
{
    return true;
}
