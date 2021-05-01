#ifndef OPEN_CRAFT_OPEN_CRAFT_CLIENT_H
#define OPEN_CRAFT_OPEN_CRAFT_CLIENT_H

class World;

class Player;

class MainApplication;

class BlockManager;

class OpenCraftClient
{
private:
    MainApplication &main;
    World *world;
    BlockManager *blockManager;
public:
    explicit OpenCraftClient(MainApplication &);

    ~OpenCraftClient();

public:
    void initialize();

    void createWorld();

    void tick();

    World *getWorld() const;

    BlockManager *getBlockManager() const;
};


#endif //OPEN_CRAFT_OPEN_CRAFT_CLIENT_H
