#ifndef OPEN_CRAFT_WORLD_BLOCK_SOURCE_H
#define OPEN_CRAFT_WORLD_BLOCK_SOURCE_H

class World;

class Block;

class Vec3;

class WorldBlockSource
{
private:
    World &world;
public:
    explicit WorldBlockSource(World &);

    ~WorldBlockSource();

public:
    World &getWorld() const;

    Block &getBlockAt(int, int, int) const;

    Block &getBlockAt(Vec3 const &) const;

    void setBlockAt(int, int, int);

    void setBlockAt(Vec3 const &);

    void tick();
};


#endif //OPEN_CRAFT_WORLD_BLOCK_SOURCE_H
