#include "VertexArrayFactory.h"

#include "../wrapper/VertexArrayWithBuffer.h"
#include "../geometry/Geometry.h"
#include "../geometry/data/VertexDataRef.h"

gl::extra::VertexArrayFactory::VertexArrayFactory(const gl::extra::Geometry & geo) : geometry(geo)
{

}

std::shared_ptr<gl::extra::VertexArrayWithBuffer> gl::extra::VertexArrayFactory::getWithBuffer() const
{
    auto vertexArrayWithBuffer = std::make_shared<VertexArrayWithBuffer>(1);
    auto *buffer = new float[geometry.getVertexDataSize() * geometry.getVerticesCount()];
    int i = 0;
    for(auto const& v : geometry.getVerticesData())
    {
        buffer[i++] = v.vertex->x;
        buffer[i++] = v.vertex->y;
        buffer[i++] = v.vertex->z;

        //Copy texture extra data to temporarily buffer
        if(geometry.hasTextureExtra())
        {
            buffer[i++] = v.textureExtra->u;
            buffer[i++] = v.textureExtra->v;
        }

        //Copy geometry extra data to temporarily buffer
        if(geometry.hasCommonExtra())
        {
            int size = v.textureExtra->size();
            for(int j = 0; j < size; ++j)
            {
                buffer[i++] = v.textureExtra->operator[](j);
            }
        }
    }

    auto vertexBuffer = std::make_shared<BufferObject>(BufferObject::BufferType::VERTEX);
    vertexBuffer->bufferData(geometry.getVertexDataSize() * geometry.getVerticesCount() * sizeof(float),
                             buffer,
                             BufferObject::DrawType::STATIC);
    vertexArrayWithBuffer->bindBuffer(vertexBuffer);

    delete[] buffer;
    return vertexArrayWithBuffer;
}
