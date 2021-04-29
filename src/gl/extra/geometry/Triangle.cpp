#include "Triangle.h"

#include <algorithm>

gl::extra::Triangle::Triangle(const gl::extra::Vertex &v_1, const gl::extra::Vertex &v_2, const gl::extra::Vertex &v_3)
{
    vertices[0] = v_1;
    vertices[1] = v_2;
    vertices[2] = v_3;
}

gl::extra::Triangle::Triangle(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y,
                              float v3z)
{
    vertices[0] = {v1x, v1y, v1z};
    vertices[1] = {v2x, v2y, v2z};
    vertices[2] = {v3x, v3y, v3z};
}

gl::extra::Triangle::Triangle(const gl::extra::Vertex &v_1, const gl::extra::Vertex &v_2, const gl::extra::Vertex &v_3,
                              bool flipped) : Triangle(v_1, v_2, v_3)
{
    if (flipped)
        flip();
}

gl::extra::Triangle::Triangle(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y,
                              float v3z, bool flipped)
        : Triangle(v1x, v1y, v1z, v2x, v2y, v2z, v3x, v3y, v3z)
{
    if (flipped)
        flip();
}

std::vector<gl::extra::VertexDataRef> gl::extra::Triangle::getVerticesData() const
{
    return {VertexDataRef(vertices[0], nullptr, nullptr)};
}

int gl::extra::Triangle::getVerticesCount() const
{
    return 3;
}

gl::extra::VertexDataRef gl::extra::Triangle::getVertexData(int i) const
{
    return VertexDataRef(vertices[i], nullptr, nullptr);
}

void gl::extra::Triangle::flip()
{
    //TODO: swap -> flag
    std::swap(vertices[0], vertices[2]);
    std::swap(commonExtra[0], commonExtra[2]);
    std::swap(textureExtra[0], textureExtra[2]);
}

int gl::extra::Triangle::getVertexDataSize() const
{
    //TODO: 3 + what
    return 3;
}
