#include "WorldBlockSource.h"

WorldBlockSource::WorldBlockSource(World & world) : world(world)
{

}

WorldBlockSource::~WorldBlockSource() = default;

World &WorldBlockSource::getWorld() const
{
    return world;
}

Block &WorldBlockSource::getBlockAt(int, int, int) const
{
    //TODO: return the block placed here
}

Block &WorldBlockSource::getBlockAt(const Vec3 &) const
{
    //TODO: return the block placed here
}

void WorldBlockSource::setBlockAt(int, int, int)
{

}

void WorldBlockSource::setBlockAt(const Vec3 &)
{

}
