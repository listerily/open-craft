#ifndef GL_EXTRA_VERTEX_H
#define GL_EXTRA_VERTEX_H


namespace gl::extra
{
    class Vertex
    {
    public:
        float x, y, z;

        Vertex();
        Vertex(float, float, float);
    };
}


#endif //GL_EXTRA_VERTEX_H
