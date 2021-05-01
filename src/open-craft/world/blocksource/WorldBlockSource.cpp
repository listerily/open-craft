#include "WorldBlockSource.h"

#include "block/BlockManager.h"
#include "util/Vec3.h"
#include "world/World.h"

WorldBlockSource::WorldBlockSource(World &world) : world(world)
{

}

WorldBlockSource::~WorldBlockSource() = default;

World &WorldBlockSource::getWorld() const
{
    return world;
}

Block &WorldBlockSource::getBlockAt(int, int y, int) const
{
    if (y < 5)
        return *world.getBlockManager().lookup("block/stone");
    return *world.getBlockManager().lookup("block/air");
}

Block &WorldBlockSource::getBlockAt(const Vec3 &v) const
{
    return getBlockAt(static_cast<int>(v.x),
                      static_cast<int>(v.y),
                      static_cast<int>(v.z));
}

void WorldBlockSource::setBlockAt(int, int, int)
{

}

void WorldBlockSource::setBlockAt(const Vec3 &)
{

}

void WorldBlockSource::tick()
{

}
