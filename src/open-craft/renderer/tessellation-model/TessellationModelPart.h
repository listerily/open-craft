#ifndef OPEN_CRAFT_TESSELLATION_MODEL_PART_H
#define OPEN_CRAFT_TESSELLATION_MODEL_PART_H

#include <memory>

namespace gl
{
    class Texture;

    class BufferObject;
    namespace extra
    {
        class VertexArrayWithBuffer;
    }
}

class TessellationModelPart
{
public:
    enum class PrimitiveType
    {
        UNDEFINED, TRIANGLE, LINE
    };
private:
    gl::extra::VertexArrayWithBuffer *vertexArray;
    const gl::Texture *texture[32] = {};
    unsigned int index;
    int visibilityCheckMode = -1;
    PrimitiveType primitiveType;
public:
    TessellationModelPart(unsigned int index, PrimitiveType);

    ~TessellationModelPart();

public:
    void bindBuffer(const std::shared_ptr<gl::BufferObject> &buffer);

    const gl::extra::VertexArrayWithBuffer &getVertexArrayWithBuffer() const;

    gl::extra::VertexArrayWithBuffer &getVertexArrayWithBuffer();

    void setTexture(const gl::Texture *, unsigned int);

    const gl::Texture *getTexture(unsigned int) const;

    unsigned int getIndex() const;

    void setVisibilityCheckMode(int checkMode);

    int getVisibilityCheckMode() const;

    PrimitiveType getPrimitiveType() const;
};


#endif //OPEN_CRAFT_TESSELLATION_MODEL_PART_H
