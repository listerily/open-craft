#include "TextureExtra.h"

float &gl::extra::TextureExtra::operator[](int i)
{
    if(i == 1)
        return v;
    return u;
}

const float &gl::extra::TextureExtra::operator[](int i) const
{
    if(i == 1)
        return v;
    return u;
}

gl::extra::TextureExtra::TextureExtra(gl::extra::TextureExtra::Position pos)
{
    switch (pos)
    {
        case Position::LEFT_TOP:
            u = 0.0f;
            v = 0.0f;
            break;
        case Position::LEFT_BOTTOM:
            u = 1.0f;
            v = 0.0f;
            break;
        case Position::RIGHT_TOP:
            u = 0.0f;
            v = 1.0f;
            break;
        case Position::RIGHT_BOTTOM:
            u = 1.0f;
            v = 1.0f;
            break;
    }
}

gl::extra::TextureExtra::TextureExtra(float u, float v)
{
    this->u = u;
    this->v = v;
}

gl::extra::TextureExtra::TextureExtra()
{
    u = 0.0f;
    v = 0.0f;
}

int gl::extra::TextureExtra::size() const
{
    return 2;
}
