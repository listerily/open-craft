#include "UniformParameters.h"

namespace gl
{

    UniformParameters::UniformParameters(float f1, float f2, float f3, float f4)
    {
        value4f[0] = f1;
        value4f[1] = f2;
        value4f[2] = f3;
        value4f[3] = f4;
        parameterType = ParameterType::F4;
    }

    UniformParameters::UniformParameters(float f1, float f2, float f3)
    {
        value3f[0] = f1;
        value3f[1] = f2;
        value3f[2] = f3;
        parameterType = ParameterType::F3;
    }

    UniformParameters::UniformParameters(float f1, float f2)
    {
        value2f[0] = f1;
        value2f[1] = f2;
        parameterType = ParameterType::F2;
    }

    UniformParameters::UniformParameters(float f1)
    {
        value1f[0] = f1;
        parameterType = ParameterType::F1;
    }

    UniformParameters::UniformParameters(int i1, int i2, int i3, int i4)
    {
        value4i[0] = i1;
        value4i[1] = i2;
        value4i[2] = i3;
        value4i[3] = i4;
        parameterType = ParameterType::I4;
    }

    UniformParameters::UniformParameters(int i1, int i2, int i3)
    {
        value3i[0] = i1;
        value3i[1] = i2;
        value3i[2] = i3;
        parameterType = ParameterType::I3;
    }

    UniformParameters::UniformParameters(int i1, int i2)
    {
        value2i[0] = i1;
        value2i[1] = i2;
        parameterType = ParameterType::I2;
    }

    UniformParameters::UniformParameters(int i1)
    {
        value1i[0] = i1;
        parameterType = ParameterType::I1;
    }

    UniformParameters::UniformParameters(unsigned int ui1, unsigned int ui2, unsigned int ui3, unsigned int ui4)
    {
        value4ui[0] = ui1;
        value4ui[1] = ui2;
        value4ui[2] = ui3;
        value4ui[3] = ui4;
        parameterType = ParameterType::UI4;
    }

    UniformParameters::UniformParameters(unsigned int ui1, unsigned int ui2, unsigned int ui3)
    {
        value3ui[0] = ui1;
        value3ui[1] = ui2;
        value3ui[2] = ui3;
        parameterType = ParameterType::UI3;
    }

    UniformParameters::UniformParameters(unsigned int ui1, unsigned int ui2)
    {
        value2ui[0] = ui1;
        value2ui[1] = ui2;
        parameterType = ParameterType::UI2;
    }

    UniformParameters::UniformParameters(unsigned int ui1)
    {
        value1ui[0] = ui1;
        parameterType = ParameterType::UI1;
    }

    UniformParameters::UniformParameters(std::size_t size, int size_p, float *fv)
    {
        value_fv.ptr = fv;
        value_fv.size = size_p;
        switch (size)
        {
            case 1:
                parameterType = ParameterType::FV1;
                break;
            case 2:
                parameterType = ParameterType::FV2;
                break;
            case 3:
                parameterType = ParameterType::FV3;
                break;
            case 4:
                parameterType = ParameterType::FV4;
                break;
            default:
                parameterType = ParameterType::NONE;
        }
    }

    UniformParameters::UniformParameters(std::size_t size, int size_p, int *iv)
    {
        value_iv.ptr = iv;
        value_iv.size = size_p;
        switch (size)
        {
            case 1:
                parameterType = ParameterType::IV1;
                break;
            case 2:
                parameterType = ParameterType::IV2;
                break;
            case 3:
                parameterType = ParameterType::IV3;
                break;
            case 4:
                parameterType = ParameterType::IV4;
                break;
            default:
                parameterType = ParameterType::NONE;
        }
    }

    UniformParameters::UniformParameters(std::size_t size, int size_p, unsigned int *uiv)
    {
        value_uiv.ptr = uiv;
        value_uiv.size = size_p;
        switch (size)
        {
            case 1:
                parameterType = ParameterType::UIV1;
                break;
            case 2:
                parameterType = ParameterType::UIV2;
                break;
            case 3:
                parameterType = ParameterType::UIV3;
                break;
            case 4:
                parameterType = ParameterType::UIV4;
                break;
            default:
                parameterType = ParameterType::NONE;
        }
    }

    UniformParameters::UniformParameters(UniformParameters::MatrixType type, int size, bool transpose, float *matrixFv)
    {
        value_matrix.ptr = matrixFv;
        value_matrix.size = size;
        value_matrix.transpose = transpose;
        switch (type)
        {
            case MatrixType::MATRIX_4:
                parameterType = ParameterType::MATRIX_4;
                break;
            case MatrixType::MATRIX_4X3:
                parameterType = ParameterType::MATRIX_4X3;
                break;
            case MatrixType::MATRIX_4X2:
                parameterType = ParameterType::MATRIX_4X2;
                break;
            case MatrixType::MATRIX_3:
                parameterType = ParameterType::MATRIX_3;
                break;
            case MatrixType::MATRIX_3X2:
                parameterType = ParameterType::MATRIX_3X2;
                break;
            case MatrixType::MATRIX_3X4:
                parameterType = ParameterType::MATRIX_3X4;
                break;
            case MatrixType::MATRIX_2:
                parameterType = ParameterType::MATRIX_2;
                break;
            case MatrixType::MATRIX_2X3:
                parameterType = ParameterType::MATRIX_2X3;
                break;
            case MatrixType::MATRIX_2X4:
                parameterType = ParameterType::MATRIX_2X4;
                break;
        }
    }
}