#ifndef GL_EXTRA_TEXTURE_EXTRA_H
#define GL_EXTRA_TEXTURE_EXTRA_H

#include "VertexExtra.h"

namespace gl::extra
{
    class TextureExtra : public VertexExtra
    {
    public:
        float u, v;
    public:
        enum class Position : int
        {
            LEFT_TOP, LEFT_BOTTOM, RIGHT_TOP, RIGHT_BOTTOM
        };
    public:
        TextureExtra();
        TextureExtra(float, float);
        explicit TextureExtra(TextureExtra::Position);

        float &operator[](int i) override;

        const float &operator[](int i) const override;

        int size() const override;
    };
}


#endif //GL_EXTRA_TEXTURE_EXTRA_H
