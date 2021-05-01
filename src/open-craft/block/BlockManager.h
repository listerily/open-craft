#ifndef OPEN_CRAFT_BLOCK_MANAGER_H
#define OPEN_CRAFT_BLOCK_MANAGER_H

#include <string>
#include <unordered_map>

class OpenCraftGame;

class Block;

class BlockManager
{
private:
    OpenCraftGame &game;
    std::unordered_map<std::string, Block *> lookupMap;
public:
    explicit BlockManager(OpenCraftGame &);

    ~BlockManager();

public:
    void initBlocks();

    Block *lookup(std::string const &) const;

    template<typename BlockType, typename ...Args>
    void registerBlock(Args &&...);
};


#endif //OPEN_CRAFT_BLOCK_MANAGER_H
