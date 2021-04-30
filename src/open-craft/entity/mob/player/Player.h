#ifndef OPEN_CRAFT_PLAYER_H
#define OPEN_CRAFT_PLAYER_H

#include "../Mob.h"

class World;
class Player : public Mob
{
public:
    explicit Player(World &world);
    ~Player() override;
};


#endif //OPEN_CRAFT_PLAYER_H
