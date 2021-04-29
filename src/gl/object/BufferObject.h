#ifndef GL_BUFFER_OBJECT_H
#define GL_BUFFER_OBJECT_H

#include <cstddef>

namespace gl
{
    class BufferObject
    {
        friend class VertexArrayObject;

        friend class GLCpp;

    public:
        enum class DrawType : int
        {
            STATIC, DYNAMIC, STREAM
        };

        enum class BufferType : int
        {
            VERTEX, ELEMENT
        };
    private:
        unsigned int bufferID;
        BufferType type;
        int count;
    public:
        explicit BufferObject(BufferType);

        ~BufferObject();

        BufferObject(const BufferObject &) = delete;

        BufferObject &operator=(const BufferObject &object) = delete;

    public:
        void bufferData(int size, const void *buffer, DrawType drawType);

        BufferType getType() const;
    };
}

#endif //GL_BUFFER_OBJECT_H
