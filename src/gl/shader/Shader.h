#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <string>

namespace gl
{
    class Shader
    {
        friend class ShaderProgram;

    public:
        enum class Type
        {
            NONE, VERTEX, GEOMETRY, FRAGMENT
        };

        class CompileError : public std::exception
        {
            friend class Shader;

        private:
            std::string message;
        public:
            explicit CompileError(std::string const &message);

            const char *what() const noexcept override;
        };

    private:
        int shaderID;
        Type type;
    public:
        Shader(const Shader &) = delete;

        ~Shader();

        Shader(Type type, std::string const &source);

        Shader(Type type, std::istream &in);

        Shader &operator=(const Shader &) = delete;

    public:
        Type getType() const;

    private:
        static int typeToGLShaderID(Type type);

        Shader &compile(std::string const &source);

        Shader &compile(std::istream &in);
    };
}
#endif //GL_SHADER_H
