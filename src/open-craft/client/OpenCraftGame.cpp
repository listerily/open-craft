#include "OpenCraftGame.h"

#include "../world/World.h"
#include "../entity/mob/player/Player.h"
#include "../block/BlockManager.h"

OpenCraftGame::OpenCraftGame(MainApplication &main) : main(main)
{
    world = nullptr;
    blockManager = nullptr;
}

OpenCraftGame::~OpenCraftGame()
{
    delete world;
    delete blockManager;
}

void OpenCraftGame::createWorld()
{
    world = new World(*this);
}

void OpenCraftGame::tick()
{
    if (world)
        world->tick();
}

void OpenCraftGame::initialize()
{
    blockManager = new BlockManager(*this);
    blockManager->initBlocks();
}

World *OpenCraftGame::getWorld() const
{
    return world;
}

BlockManager *OpenCraftGame::getBlockManager() const
{
    return blockManager;
}
