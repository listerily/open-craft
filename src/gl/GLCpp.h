#ifndef GL_GLCPP_H
#define GL_GLCPP_H


#include "object/VertexArrayObject.h"
#include "object/BufferObject.h"


namespace gl
{
    class ShaderProgram;

    class VertexArrayObject;

    class Texture;

    class GLCpp
    {
    public:
        static void useShaderProgram(const ShaderProgram &);

        static int getProgramID(const ShaderProgram &);

        static void bindVertexArrayObject(const VertexArrayObject &);

        static unsigned int getBufferID(const BufferObject &);

        static void bindTexture(const Texture &);
    };
}


#endif //GL_GLCPP_H
