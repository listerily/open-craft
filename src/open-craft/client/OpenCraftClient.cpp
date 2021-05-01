#include "OpenCraftClient.h"

#include "../world/World.h"
#include "../entity/mob/player/Player.h"
#include "../block/BlockManager.h"

OpenCraftClient::OpenCraftClient(MainApplication &main) : main(main)
{
    world = nullptr;
    blockManager = nullptr;
}

OpenCraftClient::~OpenCraftClient()
{
    delete world;
    delete blockManager;
}

void OpenCraftClient::createWorld()
{
    world = new World(*this);
}

void OpenCraftClient::tick()
{
    if (world)
        world->tick();
}

void OpenCraftClient::initialize()
{
    blockManager = new BlockManager(*this);
    blockManager->initBlocks();
}

World *OpenCraftClient::getWorld() const
{
    return world;
}

BlockManager *OpenCraftClient::getBlockManager() const
{
    return blockManager;
}
