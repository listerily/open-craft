#ifndef OPEN_CRAFT_WORLD_H
#define OPEN_CRAFT_WORLD_H

class Player;
class WorldBlockSource;
class OpenCraftClient;
class BlockManager;
class World
{
private:
    OpenCraftClient& client;
    Player* player;
    WorldBlockSource* worldBlockSource;
public:
    explicit World(OpenCraftClient&);
    ~World();

    const Player& getPlayer() const;
    Player& getPlayer();
    const WorldBlockSource& getWorldBlockSource() const;
    WorldBlockSource& getWorldBlockSource();

    void tick();

    const BlockManager& getBlockManager() const;
};


#endif //OPEN_CRAFT_WORLD_H
