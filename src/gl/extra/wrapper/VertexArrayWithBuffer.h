#ifndef GL_EXTRA_VERTEX_ARRAY_BUFFER_OBJECT_H
#define GL_EXTRA_VERTEX_ARRAY_BUFFER_OBJECT_H

#include "../../object/VertexArrayObject.h"
#include "../../object/BufferObject.h"

#include <memory>

namespace gl::extra
{
    class VertexArrayWithBuffer
    {
    private:
        VertexArrayObject vertexArrayObject;
        std::shared_ptr<BufferObject> vertexBufferObject;
        std::shared_ptr<BufferObject> elementBufferObject;
    public:
        explicit VertexArrayWithBuffer(int count = 1);
        VertexArrayWithBuffer(VertexArrayWithBuffer const&) = delete;
        void bindBuffer(std::shared_ptr<BufferObject> const&);
    public:
        VertexArrayObject& getVertexArrayObject();
        const VertexArrayObject& getVertexArrayObject() const;
        std::shared_ptr<BufferObject>& getVertexBufferObject();
        const std::shared_ptr<BufferObject>& getVertexBufferObject() const;
        std::shared_ptr<BufferObject>& getElementBufferObject();
        const std::shared_ptr<BufferObject>& getElementBufferObject() const;
    };
}


#endif //GL_EXTRA_VERTEX_ARRAY_BUFFER_OBJECT_H
