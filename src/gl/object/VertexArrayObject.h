#ifndef GL_VERTEX_ARRAY_OBJECT_H
#define GL_VERTEX_ARRAY_OBJECT_H

#include <memory>

#include "../TypeEnum.h"
#include "BufferObject.h"

namespace gl
{
    class VertexArrayObject
    {
    private:
        unsigned int arrayID;
        BufferObject *vertexBuffer = nullptr;
        BufferObject *elementBuffer = nullptr;
        int count;
    public:
        VertexArrayObject &bindBuffer(BufferObject &buffer);

        VertexArrayObject &
        vertexAttribPointer(int index, int size, TypeEnum type, bool normalized, int stride,
                            int offset);

    public:
        explicit VertexArrayObject(int count);

        VertexArrayObject(const VertexArrayObject &) = delete;

        VertexArrayObject &operator=(const VertexArrayObject &) = delete;

        ~VertexArrayObject();

        unsigned int getArrayID() const;

    private:
        friend class GLCpp;
    };
}
#endif //GL_VERTEX_ARRAY_OBJECT_H
