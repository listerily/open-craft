#include "Geometry.h"

gl::extra::Geometry::Geometry() = default;

int gl::extra::Geometry::getVertexDataSize() const
{
    return 3 + getTextureExtraSize() + getCommonExtraSize();
}
