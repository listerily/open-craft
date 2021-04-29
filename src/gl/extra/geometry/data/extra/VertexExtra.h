#ifndef GL_EXTRA_BASE_EXTRA_H
#define GL_EXTRA_BASE_EXTRA_H

#include <vector>

namespace gl::extra
{
    class VertexExtra
    {
    public:
        virtual int size() const;
        virtual float& operator[](int i) = 0;
        virtual float const& operator[](int i) const = 0;
    };
}


#endif //GL_EXTRA_BASE_EXTRA_H
