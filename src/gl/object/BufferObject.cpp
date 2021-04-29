#include "BufferObject.h"

#include <glad/glad.h>

namespace gl
{
    BufferObject::BufferObject(BufferType bufferType)
    {
        type = bufferType;
        count = 1;
        bufferID = 0;
        glGenBuffers(count, &bufferID);
    }

    BufferObject::~BufferObject()
    {
        glDeleteBuffers(count, &bufferID);
    }

    void BufferObject::bufferData(int size, const void *buffer, BufferObject::DrawType drawType)
    {
        int glDrawType = 0;
        switch (drawType)
        {
            case DrawType::STATIC:
                glDrawType = GL_STATIC_DRAW;
                break;
            case DrawType::DYNAMIC:
                glDrawType = GL_DYNAMIC_DRAW;
                break;
            case DrawType::STREAM:
                glDrawType = GL_STREAM_DRAW;
                break;
        }

        int glBufferType = 0;
        switch (type)
        {
            case BufferType::VERTEX:
                glBufferType = GL_ARRAY_BUFFER;
                break;
            case BufferType::ELEMENT:
                glBufferType = GL_ELEMENT_ARRAY_BUFFER;
                break;
        }

        glBindBuffer(glBufferType, bufferID);
        glBufferData(glBufferType, size, buffer, glDrawType);
    }

    BufferObject::BufferType BufferObject::getType() const
    {
        return type;
    }
}