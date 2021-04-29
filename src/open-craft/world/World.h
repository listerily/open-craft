#ifndef OPEN_CRAFT_WORLD_H
#define OPEN_CRAFT_WORLD_H

class Player;
class WorldBlockSource;

class World
{
private:

public:
    const Player& getPlayer() const;
    Player& getPlayer();
    const WorldBlockSource& getWorldBlockSource() const;
    WorldBlockSource& getWorldBlockSource();
    void tick();
};


#endif //OPEN_CRAFT_WORLD_H
