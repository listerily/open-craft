#include "VertexArrayWithBuffer.h"

void gl::extra::VertexArrayWithBuffer::bindBuffer(const std::shared_ptr<BufferObject> & bufferObject)
{
    switch ((*bufferObject).getType())
    {
        case BufferObject::BufferType::VERTEX:
            vertexBufferObject = bufferObject;
            break;
        case BufferObject::BufferType::ELEMENT:
            elementBufferObject = bufferObject;
            break;
    }
    vertexArrayObject.bindBuffer(*bufferObject);
}

gl::VertexArrayObject &gl::extra::VertexArrayWithBuffer::getVertexArrayObject()
{
    return vertexArrayObject;
}

const gl::VertexArrayObject &gl::extra::VertexArrayWithBuffer::getVertexArrayObject() const
{
    return vertexArrayObject;
}

std::shared_ptr<gl::BufferObject> &gl::extra::VertexArrayWithBuffer::getVertexBufferObject()
{
    return vertexBufferObject;
}

const std::shared_ptr<gl::BufferObject> &gl::extra::VertexArrayWithBuffer::getVertexBufferObject() const
{
    return vertexBufferObject;
}

std::shared_ptr<gl::BufferObject> &gl::extra::VertexArrayWithBuffer::getElementBufferObject()
{
    return elementBufferObject;
}

const std::shared_ptr<gl::BufferObject> &gl::extra::VertexArrayWithBuffer::getElementBufferObject() const
{
    return elementBufferObject;
}

gl::extra::VertexArrayWithBuffer::VertexArrayWithBuffer(int count) : vertexArrayObject(count)
{
    vertexBufferObject = nullptr;
    elementBufferObject = nullptr;
}
