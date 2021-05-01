#include "BlockManager.h"

#include "Block.h"

#include "impl/AirBlock.h"
#include "impl/StoneBlock.h"

BlockManager::BlockManager(OpenCraftGame &client) : game(client)
{

}

BlockManager::~BlockManager()
{
    for (auto &block : lookupMap)
    {
        delete block.second;
        block.second = nullptr;
    }
}

void BlockManager::initBlocks()
{
    registerBlock<AirBlock>(*this);
    registerBlock<StoneBlock>(*this);
}

Block *BlockManager::lookup(const std::string &id) const
{
    return lookupMap.at(id);
}

template<typename BlockType, typename...Args>
void BlockManager::registerBlock(Args &&... args)
{
    auto *newBlock = new BlockType(args...);
    lookupMap[newBlock->getID()] = newBlock;
}
