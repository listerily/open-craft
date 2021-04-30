#ifndef OPEN_CRAFT_OPEN_CRAFT_CLIENT_H
#define OPEN_CRAFT_OPEN_CRAFT_CLIENT_H

class World;
class Player;
class MainApplication;

class OpenCraftClient
{
private:
    MainApplication& main;
    World* world;
    Player* player;
public:
    explicit OpenCraftClient(MainApplication&);
    ~OpenCraftClient();
public:
    void createWorld();
    void tick();
};


#endif //OPEN_CRAFT_OPEN_CRAFT_CLIENT_H
