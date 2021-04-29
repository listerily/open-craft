#ifndef GL_SHADER_PROGRAM_H
#define GL_SHADER_PROGRAM_H

#include <unordered_map>
#include "uniform/UniformParameters.h"
#include "Shader.h"

namespace gl
{
    class ShaderProgram
    {
    private:
        int programID;
        std::unordered_map<std::string, int> uniformIDLookupMap;
        Shader *vertexShader{};
        Shader *geometryShader{};
        Shader *fragmentShader{};
    public:
        ShaderProgram();

        ShaderProgram(const ShaderProgram &) = delete;

        ~ShaderProgram();

        ShaderProgram &operator=(ShaderProgram const &) = delete;

        ShaderProgram &bindUniform(std::string const &, const UniformParameters &);

        ShaderProgram &detachShader(Shader &shader);

        bool shaderAttached(Shader const &shader) const;

        ShaderProgram &attachShader(Shader &shader);

        ShaderProgram &linkProgram();

        class Exception : public std::exception
        {
            friend class ShaderProgram;

        private:
            std::string message;
        public:
            explicit Exception(std::string const &message);

            const char *what() const noexcept override;
        };

    private:

        friend class GLCpp;
    };
}
#endif //GL_SHADER_PROGRAM_H
