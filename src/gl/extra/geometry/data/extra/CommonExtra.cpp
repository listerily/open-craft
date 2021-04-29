#include "CommonExtra.h"

float &gl::extra::CommonExtra::operator[](int i)
{
    return data[i];
}

const float &gl::extra::CommonExtra::operator[](int i) const
{
    return data[i];
}

int gl::extra::CommonExtra::size() const
{
    return data.size();
}

gl::extra::CommonExtra::CommonExtra() = default;

gl::extra::CommonExtra::CommonExtra(float f1)
{
    data = {f1};
}

gl::extra::CommonExtra::CommonExtra(float f1, float f2)
{
    data = {f1, f2};
}

gl::extra::CommonExtra::CommonExtra(float f1, float f2, float f3)
{
    data = {f1, f2, f3};
}

gl::extra::CommonExtra::CommonExtra(float f1, float f2, float f3, float f4)
{
    data = {f1, f2, f3, f4};
}

gl::extra::CommonExtra::CommonExtra(float f1, float f2, float f3, float f4, float f5)
{
    data = {f1, f2, f3, f4, f5};
}

gl::extra::CommonExtra::CommonExtra(float f1, float f2, float f3, float f4, float f5, float f6)
{
    data = {f1, f2, f3, f4, f5, f6};
}

gl::extra::CommonExtra::CommonExtra(float * f, int size)
{
    for(int i = 0; i < size; ++i)
    {
        data.push_back(f[i]);
    }
}
