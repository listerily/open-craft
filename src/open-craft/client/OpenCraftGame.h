#ifndef OPEN_CRAFT_OPEN_CRAFT_GAME_H
#define OPEN_CRAFT_OPEN_CRAFT_GAME_H

class World;

class Player;

class MainApplication;

class BlockManager;

class OpenCraftGame
{
private:
    MainApplication &main;
    World *world;
    BlockManager *blockManager;
public:
    explicit OpenCraftGame(MainApplication &);

    ~OpenCraftGame();

public:
    void initialize();

    void createWorld();

    void tick();

    World *getWorld() const;

    BlockManager *getBlockManager() const;
};


#endif //OPEN_CRAFT_OPEN_CRAFT_GAME_H
