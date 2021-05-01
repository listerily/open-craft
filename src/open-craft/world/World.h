#ifndef OPEN_CRAFT_WORLD_H
#define OPEN_CRAFT_WORLD_H

class Player;

class WorldBlockSource;

class OpenCraftGame;

class BlockManager;

class World
{
private:
    OpenCraftGame &client;
    Player *player;
    WorldBlockSource *worldBlockSource;
public:
    explicit World(OpenCraftGame &);

    ~World();

    const Player &getPlayer() const;

    Player &getPlayer();

    const WorldBlockSource &getWorldBlockSource() const;

    WorldBlockSource &getWorldBlockSource();

    void tick();

    const BlockManager &getBlockManager() const;
};


#endif //OPEN_CRAFT_WORLD_H
