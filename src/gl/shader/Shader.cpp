#include "Shader.h"

#include <glad/glad.h>
#include <istream>

namespace gl
{
    Shader::Shader(Type type, std::string const &source) : type(type)
    {
        shaderID = glCreateShader(typeToGLShaderID(type));
        compile(source);
    }

    Shader::Shader(Type type, std::istream &in) : type(type)
    {
        shaderID = glCreateShader(typeToGLShaderID(type));
        compile(in);
    }

    Shader &Shader::compile(const std::string &source)
    {
        const char *code = source.c_str();
        glShaderSource(shaderID, 1, &code, nullptr);
        glCompileShader(shaderID);
        int status;
        char log[1 << 10];
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
        if (!status)
        {
            glGetShaderInfoLog(shaderID, 1 << 10, nullptr, log);
            throw CompileError(log);
        }
        return *this;
    }

    Shader &Shader::compile(std::istream &in)
    {
        char buffer[in.tellg().operator long()];
        in.read(buffer, in.tellg());
        std::string source(buffer);
        compile(source);
        return *this;
    }

    Shader::~Shader()
    {
        glDeleteShader(shaderID);
    }

    Shader::Type Shader::getType() const
    {
        return type;
    }

    int Shader::typeToGLShaderID(Type type)
    {
        switch (type)
        {
            case Type::FRAGMENT:
                return GL_FRAGMENT_SHADER;
            case Type::GEOMETRY:
                return GL_GEOMETRY_SHADER;
            case Type::VERTEX:
                return GL_VERTEX_SHADER;
            case Type::NONE:
                return -1;
        }
        return -1;
    }

    Shader::CompileError::CompileError(const std::string &message)
    {
        this->message = message;
    }

    const char *Shader::CompileError::what() const noexcept
    {
        return message.c_str();
    }
}