#include "AABB.h"

bool AABB::collide(const AABB &) const
{
    return false;
}

bool AABB::collide(const AABB &, const Vec3 &) const
{
    return false;
}
