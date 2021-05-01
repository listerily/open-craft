#include "ShaderProgram.h"

#include <glad/glad.h>

#include "Shader.h"
#include "./uniform/UniformParameters.h"

namespace gl
{
    ShaderProgram::ShaderProgram()
    {
        programID = glCreateProgram();
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(programID);
    }

    ShaderProgram &ShaderProgram::bindUniform(const std::string &uniformName, const UniformParameters &parameters)
    {
        glUseProgram(programID);
        int uniformLocation;
        if (uniformIDLookupMap.count(uniformName) == 0)
        {
            uniformLocation = glGetUniformLocation(programID, uniformName.c_str());
            uniformIDLookupMap[uniformName] = uniformLocation;
        } else
        {
            uniformLocation = uniformIDLookupMap[uniformName];
        }

        switch (parameters.parameterType)
        {
            case UniformParameters::ParameterType::NONE:
                break;
            case UniformParameters::ParameterType::F4:
                glUniform4f(uniformLocation, parameters.value4f[0], parameters.value4f[1], parameters.value4f[2],
                            parameters.value4f[3]);
                break;
            case UniformParameters::ParameterType::F3:
                glUniform3f(uniformLocation, parameters.value3f[0], parameters.value3f[1], parameters.value3f[2]);
                break;
            case UniformParameters::ParameterType::F2:
                glUniform2f(uniformLocation, parameters.value2f[0], parameters.value2f[1]);
                break;
            case UniformParameters::ParameterType::F1:
                glUniform1f(uniformLocation, parameters.value1f[0]);
                break;
            case UniformParameters::ParameterType::FV4:
                glUniform4fv(uniformLocation, parameters.value_fv.size, parameters.value_fv.ptr);
                break;
            case UniformParameters::ParameterType::FV3:
                glUniform3fv(uniformLocation, parameters.value_fv.size, parameters.value_fv.ptr);
                break;
            case UniformParameters::ParameterType::FV2:
                glUniform2fv(uniformLocation, parameters.value_fv.size, parameters.value_fv.ptr);
                break;
            case UniformParameters::ParameterType::FV1:
                glUniform1fv(uniformLocation, parameters.value_fv.size, parameters.value_fv.ptr);
                break;
            case UniformParameters::ParameterType::UI4:
                glUniform4ui(uniformLocation, parameters.value4ui[0], parameters.value4ui[1], parameters.value4ui[2],
                             parameters.value4ui[3]);
                break;
            case UniformParameters::ParameterType::UI3:
                glUniform3ui(uniformLocation, parameters.value3ui[0], parameters.value3ui[1], parameters.value3ui[2]);
                break;
            case UniformParameters::ParameterType::UI2:
                glUniform2ui(uniformLocation, parameters.value2ui[0], parameters.value2ui[1]);
                break;
            case UniformParameters::ParameterType::UI1:
                glUniform1ui(uniformLocation, parameters.value1ui[0]);
                break;
            case UniformParameters::ParameterType::UIV4:
                glUniform4uiv(uniformLocation, parameters.value_uiv.size, parameters.value_uiv.ptr);
                break;
            case UniformParameters::ParameterType::UIV3:
                glUniform3uiv(uniformLocation, parameters.value_uiv.size, parameters.value_uiv.ptr);
                break;
            case UniformParameters::ParameterType::UIV2:
                glUniform2uiv(uniformLocation, parameters.value_uiv.size, parameters.value_uiv.ptr);
                break;
            case UniformParameters::ParameterType::UIV1:
                glUniform1uiv(uniformLocation, parameters.value_uiv.size, parameters.value_uiv.ptr);
                break;
            case UniformParameters::ParameterType::I4:
                glUniform4i(uniformLocation, parameters.value4i[0], parameters.value4i[1], parameters.value4i[2],
                            parameters.value4i[3]);
                break;
            case UniformParameters::ParameterType::I3:
                glUniform3i(uniformLocation, parameters.value3i[0], parameters.value3i[1], parameters.value3i[2]);
                break;
            case UniformParameters::ParameterType::I2:
                glUniform2i(uniformLocation, parameters.value2i[0], parameters.value2i[1]);
                break;
            case UniformParameters::ParameterType::I1:
                glUniform1i(uniformLocation, parameters.value1i[0]);
                break;
            case UniformParameters::ParameterType::IV4:
                glUniform4iv(uniformLocation, parameters.value_iv.size, parameters.value_iv.ptr);
                break;
            case UniformParameters::ParameterType::IV3:
                glUniform3iv(uniformLocation, parameters.value_iv.size, parameters.value_iv.ptr);
                break;
            case UniformParameters::ParameterType::IV2:
                glUniform2iv(uniformLocation, parameters.value_iv.size, parameters.value_iv.ptr);
                break;
            case UniformParameters::ParameterType::IV1:
                glUniform1iv(uniformLocation, parameters.value_iv.size, parameters.value_iv.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_4:
                glUniformMatrix4fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                   parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_4X3:
                glUniformMatrix4x3fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                     parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_4X2:
                glUniformMatrix4x2fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                     parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_3:
                glUniformMatrix3fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                   parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_3X2:
                glUniformMatrix3x2fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                     parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_3X4:
                glUniformMatrix3x4fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                     parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_2:
                glUniformMatrix2fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                   parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_2X3:
                glUniformMatrix2x3fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                     parameters.value_matrix.ptr);
                break;
            case UniformParameters::ParameterType::MATRIX_2X4:
                glUniformMatrix2x4fv(uniformLocation, parameters.value_matrix.size, parameters.value_matrix.transpose,
                                     parameters.value_matrix.ptr);
                break;
        }
        return *this;
    }

    ShaderProgram &ShaderProgram::attachShader(Shader &shader)
    {
        switch (shader.getType())
        {
            case Shader::Type::VERTEX:
                vertexShader = &shader;
                break;
            case Shader::Type::GEOMETRY:
                geometryShader = &shader;
                break;
            case Shader::Type::FRAGMENT:
                fragmentShader = &shader;
                break;
            case Shader::Type::NONE:
                break;
        }
        glAttachShader(programID, shader.shaderID);
        return *this;
    }

    ShaderProgram &ShaderProgram::linkProgram()
    {
        glLinkProgram(programID);

        int status = 0;
        glGetProgramiv(programID, GL_LINK_STATUS, &status);
        if (!status)
        {
            char buffer[1 << 10];
            glGetProgramInfoLog(programID, 1 << 10, nullptr, buffer);
            throw Exception(buffer);
        }
        return *this;
    }

    ShaderProgram &ShaderProgram::detachShader(Shader &shader)
    {
        switch (shader.getType())
        {
            case Shader::Type::VERTEX:
                vertexShader = nullptr;
                break;
            case Shader::Type::GEOMETRY:
                geometryShader = nullptr;
                break;
            case Shader::Type::FRAGMENT:
                fragmentShader = nullptr;
                break;
            case Shader::Type::NONE:
                break;
        }
        glDetachShader(programID, shader.shaderID);
        return *this;
    }

    bool ShaderProgram::shaderAttached(const Shader &shader) const
    {
        switch (shader.getType())
        {
            case Shader::Type::VERTEX:
                return vertexShader != nullptr;
            case Shader::Type::GEOMETRY:
                return geometryShader != nullptr;
            case Shader::Type::FRAGMENT:
                return fragmentShader != nullptr;
            case Shader::Type::NONE:
                break;
        }
        return false;
    }

    const char *ShaderProgram::Exception::what() const noexcept
    {
        return message.c_str();
    }

    ShaderProgram::Exception::Exception(const std::string &message)
    {
        this->message = message;
    }
}