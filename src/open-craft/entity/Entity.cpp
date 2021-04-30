#include "Entity.h"

Entity::Entity(std::string id, World& world) : id(std::move(id)), world(world)
{

}

Entity::~Entity() = default;

Vec3 Entity::getPos() const
{
    return position;
}

Vec2 Entity::getFacing() const
{
    return facing;
}

void Entity::travel(const Vec3 & v)
{
    position += v;
}

void Entity::turn(const Vec2 & v)
{
    facing += v;
}

void Entity::travelTo(const Vec3 & v)
{
    position = v;
}

void Entity::turnTo(const Vec2 & v)
{
    facing = v;
}
