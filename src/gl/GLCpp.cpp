#include "GLCpp.h"

#include <glad/glad.h>

#include "object/VertexArrayObject.h"
#include "shader/ShaderProgram.h"
#include "texture/Texture.h"

namespace gl
{
    void GLCpp::bindVertexArrayObject(const VertexArrayObject &vertexArrayObject)
    {
        glBindVertexArray(vertexArrayObject.arrayID);
    }

    void GLCpp::useShaderProgram(const ShaderProgram &program)
    {
        glUseProgram(program.programID);
    }

    int GLCpp::getProgramID(const ShaderProgram &program)
    {
        return program.programID;
    }

    unsigned int GLCpp::getBufferID(const BufferObject &object)
    {
        return object.bufferID;
    }

    void GLCpp::bindTexture(const Texture &texture)
    {
        glBindTexture(GL_TEXTURE_2D, texture.textureID);
    }
}