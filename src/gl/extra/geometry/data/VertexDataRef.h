#ifndef GL_EXTRA_VERTEX_DATA_TUPLE_H
#define GL_EXTRA_VERTEX_DATA_TUPLE_H

#include <vector>

#include "./extra/TextureExtra.h"
#include "./extra/CommonExtra.h"
#include "Vertex.h"

namespace gl::extra
{
    class VertexDataRef
    {
    public:
        const Vertex* vertex;
        const TextureExtra* textureExtra;
        const CommonExtra* commonExtra;
    public:
        VertexDataRef(const Vertex &, const TextureExtra *, const CommonExtra *);
        VertexDataRef(const Vertex &, const CommonExtra *);
        VertexDataRef(const Vertex &, const TextureExtra *);
        VertexDataRef(const Vertex &);
    };
}


#endif //GL_EXTRA_VERTEX_DATA_TUPLE_H
