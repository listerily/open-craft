#include "Vertex.h"

namespace gl::extra
{
    Vertex::Vertex(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Vertex::Vertex()
    {
        x = 0;
        y = 0;
        z = 0;
    }
}
