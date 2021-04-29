#include "VertexArrayObject.h"

#include <glad/glad.h>

namespace gl
{
    VertexArrayObject::VertexArrayObject(int count)
    {
        arrayID = 0;
        glGenVertexArrays(1, &arrayID);
        this->count = count;
        vertexBuffer = nullptr;
        elementBuffer = nullptr;
    }

    VertexArrayObject::~VertexArrayObject()
    {
        glDeleteVertexArrays(count, &arrayID);
    }

    VertexArrayObject &VertexArrayObject::vertexAttribPointer(int index, int size,
                                                              TypeEnum type,
                                                              bool normalized, int stride,
                                                              int offset)
    {
        auto glNormalized = (normalized ? GL_TRUE : GL_FALSE);
        glBindVertexArray(arrayID);
        glVertexAttribPointer(index, size, typeEnumToGLEnum(type), glNormalized, stride,
                              reinterpret_cast<void *>(offset));
        glEnableVertexAttribArray(index);
        return *this;
    }

    VertexArrayObject &VertexArrayObject::bindBuffer(BufferObject &buffer)
    {
        int glBufferType = 0;
        switch (buffer.type)
        {
            case BufferObject::BufferType::VERTEX:
                glBufferType = GL_ARRAY_BUFFER;
                break;
            case BufferObject::BufferType::ELEMENT:
                glBufferType = GL_ELEMENT_ARRAY_BUFFER;
                break;
        }
        glBindVertexArray(arrayID);
        glBindBuffer(glBufferType, buffer.bufferID);
        switch (buffer.type)
        {
            case BufferObject::BufferType::VERTEX:
                vertexBuffer = &buffer;
                break;
            case BufferObject::BufferType::ELEMENT:
                elementBuffer = &buffer;
                break;
        }
        return *this;
    }

    unsigned int VertexArrayObject::getArrayID() const
    {
        return arrayID;
    }
}