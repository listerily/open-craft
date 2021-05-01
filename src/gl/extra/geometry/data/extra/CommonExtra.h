#ifndef GL_EXTRA_VERTEX_EXTRA_H
#define GL_EXTRA_VERTEX_EXTRA_H

#include "VertexExtra.h"


namespace gl::extra
{
    class CommonExtra : public VertexExtra
    {
    private:
        std::vector<float> data;
    public:
        CommonExtra();

        explicit CommonExtra(float);

        CommonExtra(float, float);

        CommonExtra(float, float, float);

        CommonExtra(float, float, float, float);

        CommonExtra(float, float, float, float, float);

        CommonExtra(float, float, float, float, float, float);

        CommonExtra(float *, int size);

    public:
        float &operator[](int i) override;

        int size() const override;

        const float &operator[](int i) const override;
    };
}


#endif //GL_EXTRA_VERTEX_EXTRA_H
