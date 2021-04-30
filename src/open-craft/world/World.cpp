#include "World.h"

#include "../entity/mob/player/Player.h"
#include "blocksource/WorldBlockSource.h"

const Player &World::getPlayer() const
{
    return *player;
}

Player &World::getPlayer()
{
    return *player;
}

const WorldBlockSource &World::getWorldBlockSource() const
{
    return *worldBlockSource;
}

WorldBlockSource &World::getWorldBlockSource()
{
    return *worldBlockSource;
}

void World::tick()
{

}

World::World(OpenCraftClient & client) : client(client)
{
    player = new Player(*this);
    worldBlockSource = new WorldBlockSource(*this);
}

World::~World()
{
    delete player;
}
