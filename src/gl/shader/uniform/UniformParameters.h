#ifndef GL_UNIFORM_PARAMETERS_H
#define GL_UNIFORM_PARAMETERS_H

#include <cstddef>

namespace gl
{
    class UniformParameters
    {
        friend class ShaderProgram;

    private:
        union
        {
            float value4f[4];
            float value3f[3];
            float value2f[2];
            float value1f[1];
            unsigned int value4ui[4];
            unsigned int value3ui[3];
            unsigned int value2ui[2];
            unsigned int value1ui[1];
            int value4i[4];
            int value3i[3];
            int value2i[2];
            int value1i[1];
            struct
            {
                float *ptr;
                int size;
            } value_fv;
            struct
            {
                unsigned int *ptr;
                int size;
            } value_uiv;
            struct
            {
                int *ptr;
                int size;
            } value_iv;
            struct
            {
                float *ptr;
                bool transpose;
                int size;
            } value_matrix;
        };

        enum class ParameterType : int
        {
            NONE,
            F4, F3, F2, F1, FV4, FV3, FV2, FV1,
            UI4, UI3, UI2, UI1, UIV4, UIV3, UIV2, UIV1,
            I4, I3, I2, I1, IV4, IV3, IV2, IV1,
            MATRIX_4, MATRIX_4X3, MATRIX_4X2,
            MATRIX_3, MATRIX_3X2, MATRIX_3X4,
            MATRIX_2, MATRIX_2X3, MATRIX_2X4
        } parameterType;
    public:
        enum class MatrixType : int
        {
            MATRIX_4, MATRIX_4X3, MATRIX_4X2,
            MATRIX_3, MATRIX_3X2, MATRIX_3X4,
            MATRIX_2, MATRIX_2X3, MATRIX_2X4
        };

        UniformParameters(float, float, float, float);

        UniformParameters(float, float, float);

        UniformParameters(float, float);

        UniformParameters(float);

        UniformParameters(int, int, int, int);

        UniformParameters(int, int, int);

        UniformParameters(int, int);

        UniformParameters(int);

        UniformParameters(unsigned int, unsigned int, unsigned int, unsigned int);

        UniformParameters(unsigned int, unsigned int, unsigned int);

        UniformParameters(unsigned int, unsigned int);

        UniformParameters(unsigned int);

        UniformParameters(std::size_t, int, float *);

        UniformParameters(std::size_t, int, int *);

        UniformParameters(std::size_t, int, unsigned int *);

        UniformParameters(MatrixType, int, bool, float *);
    };
}


#endif //GL_UNIFORM_PARAMETERS_H
