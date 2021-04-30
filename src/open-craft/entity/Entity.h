#ifndef OPEN_CRAFT_ENTITY_H
#define OPEN_CRAFT_ENTITY_H

#include <string>

#include "../util/Vec3.h"
#include "../util/Vec2.h"

class World;
class Entity
{
protected:
    const std::string id;
    World& world;
    Vec3 position;
    Vec2 facing;
public:
    Entity(std::string id, World&);
    virtual ~Entity();

    virtual Vec3 getPos() const;
    virtual Vec2 getFacing() const;
    virtual void travel(Vec3 const&);
    virtual void turn(Vec2 const&);
    virtual void travelTo(Vec3 const&);
    virtual void turnTo(Vec2 const&);
};


#endif //OPEN_CRAFT_ENTITY_H
