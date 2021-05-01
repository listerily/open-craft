#ifndef GL_EXTRA_VERTEX_ARRAY_FACTORY_H
#define GL_EXTRA_VERTEX_ARRAY_FACTORY_H

#include <memory>

namespace gl::extra
{
    class Geometry;

    class VertexArrayWithBuffer;

    class VertexArrayFactory
    {
    private:
        Geometry const &geometry;
    public:
        explicit VertexArrayFactory(Geometry const &);

    public:
        std::shared_ptr<VertexArrayWithBuffer> getWithBuffer() const;
    };
}


#endif //GL_EXTRA_VERTEX_ARRAY_FACTORY_H
