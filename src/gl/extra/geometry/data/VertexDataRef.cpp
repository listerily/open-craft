#include "VertexDataRef.h"

gl::extra::VertexDataRef::VertexDataRef(const Vertex & v)
{
    vertex = &v;
    textureExtra = nullptr;
    commonExtra = nullptr;
}

gl::extra::VertexDataRef::VertexDataRef(const Vertex & v, const TextureExtra * t)
{
    vertex = &v;
    textureExtra = t;
    commonExtra = nullptr;
}

gl::extra::VertexDataRef::VertexDataRef(const Vertex & v, const CommonExtra * c)
{
    vertex = &v;
    textureExtra = nullptr;
    commonExtra = c;
}

gl::extra::VertexDataRef::VertexDataRef(const Vertex & v, const TextureExtra * t, const CommonExtra * c)
{
    vertex = &v;
    textureExtra = t;
    commonExtra = c;
}
