#include "TessellationModelPart.h"

#include "gl/extra/wrapper/VertexArrayWithBuffer.h"

TessellationModelPart::TessellationModelPart(unsigned int index, PrimitiveType type)
{
    this->index = index;
    vertexArray = new gl::extra::VertexArrayWithBuffer(1);
    primitiveType = type;
}

TessellationModelPart::~TessellationModelPart()
{
    delete vertexArray;
}

void TessellationModelPart::bindBuffer(const std::shared_ptr<gl::BufferObject> &buffer)
{
    vertexArray->bindBuffer(buffer);
}

const gl::extra::VertexArrayWithBuffer &TessellationModelPart::getVertexArrayWithBuffer() const
{
    return *vertexArray;
}

gl::extra::VertexArrayWithBuffer &TessellationModelPart::getVertexArrayWithBuffer()
{
    return *vertexArray;
}

void TessellationModelPart::setTexture(const gl::Texture *t, unsigned int i)
{
    texture[i] = t;
}

const gl::Texture *TessellationModelPart::getTexture(unsigned int i) const
{
    return texture[i];
}

unsigned int TessellationModelPart::getIndex() const
{
    return index;
}

void TessellationModelPart::setVisibilityCheckMode(int checkMode)
{
    TessellationModelPart::visibilityCheckMode = checkMode;
}

int TessellationModelPart::getVisibilityCheckMode() const
{
    return visibilityCheckMode;
}

TessellationModelPart::PrimitiveType TessellationModelPart::getPrimitiveType() const
{
    return primitiveType;
}
