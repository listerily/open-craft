#ifndef GL_EXTRA_GEOMETRY_H
#define GL_EXTRA_GEOMETRY_H

#include <vector>

namespace gl::extra
{
    class VertexDataRef;

    class Geometry
    {
    public:
        Geometry();

        ~Geometry() = default;

    public:
        virtual std::vector<VertexDataRef> getVerticesData() const = 0;

        virtual int getVerticesCount() const = 0;

        virtual VertexDataRef getVertexData(int) const = 0;

        virtual int getVertexDataSize() const;

        virtual bool hasCommonExtra() const = 0;

        virtual bool hasTextureExtra() const = 0;

        virtual int getCommonExtraSize() const = 0;

        virtual int getTextureExtraSize() const = 0;
    };
}

#endif //GL_EXTRA_GEOMETRY_H
