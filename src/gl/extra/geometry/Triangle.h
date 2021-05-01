#ifndef GL_EXTRA_TRIANGLE_H
#define GL_EXTRA_TRIANGLE_H

#include "Geometry.h"
#include "./data/VertexDataRef.h"

#include <vector>

namespace gl::extra
{
    class Triangle : public Geometry
    {
    private:
        Vertex vertices[3];
        TextureExtra textureExtra[3];
        CommonExtra commonExtra[3];
    public:
        Triangle() = default;

        Triangle(float, float, float, float, float, float, float, float, float);

        Triangle(Vertex const &, Vertex const &, Vertex const &);

        Triangle(float, float, float, float, float, float, float, float, float, bool flipped);

        Triangle(Vertex const &, Vertex const &, Vertex const &, bool flipped);

    public:

        std::vector<VertexDataRef> getVerticesData() const override;

        int getVerticesCount() const override;

        VertexDataRef getVertexData(int i) const override;

        void flip();

        int getVertexDataSize() const override;
    };
}


#endif //GL_EXTRA_TRIANGLE_H
