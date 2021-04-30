#include "Mob.h"

Mob::Mob(std::string id, World &world) : Entity(std::move(id), world)
{

}

Mob::~Mob() = default;
