#ifndef OPEN_CRAFT_MOB_H
#define OPEN_CRAFT_MOB_H

#include "../Entity.h"

class World;
class Mob : public Entity
{
public:
    Mob(std::string id, World&);
    ~Mob() override;
};


#endif //OPEN_CRAFT_MOB_H
