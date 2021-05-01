#ifndef GL_EXTRA_GRAPHICS_PROGRAM_H
#define GL_EXTRA_GRAPHICS_PROGRAM_H

#include <string>

#include "../../shader/ShaderProgram.h"

namespace gl
{
    class UniformParameters;

    class Texture;

    class VertexArrayObject;
}

namespace gl::extra
{

    class GraphicsProgram
    {
    private:
        ShaderProgram p;
        const VertexArrayObject *vertexSource = nullptr;
        const Texture *textures[32] = {};
        int count = 0;
    public:
        enum class DrawMode : int
        {
            ARRAYS, ELEMENTS
        };
    public:
        GraphicsProgram();

        GraphicsProgram(const GraphicsProgram &) = delete;

        void uniform(std::string const &, UniformParameters const &);

        ShaderProgram &program();

        ShaderProgram const &program() const;

        void source(VertexArrayObject const &, int count);

        void texture(Texture const &, int = 0);

        void draw(DrawMode);
    };
}


#endif //GL_EXTRA_GRAPHICS_PROGRAM_H
