#include "GraphicsProgram.h"

#include <glad/glad.h>

#include "../../texture/Texture.h"
#include "../../object//VertexArrayObject.h"

gl::extra::GraphicsProgram::GraphicsProgram() = default;

void gl::extra::GraphicsProgram::uniform(const std::string & name, const gl::UniformParameters & value)
{
    p.bindUniform(name, value);
}

void gl::extra::GraphicsProgram::source(const gl::VertexArrayObject & v, int c)
{
    count = c;
    vertexSource = &v;
}

void gl::extra::GraphicsProgram::texture(const gl::Texture & texture, int id)
{
    textures[id] = &texture;
}

gl::ShaderProgram &gl::extra::GraphicsProgram::program()
{
    return p;
}

const gl::ShaderProgram &gl::extra::GraphicsProgram::program() const
{
    return p;
}

void gl::extra::GraphicsProgram::draw(gl::extra::GraphicsProgram::DrawMode draw)
{
    static const int GL_TEXTURE_ID[32] =
            {
                    GL_TEXTURE0, GL_TEXTURE1, GL_TEXTURE2, GL_TEXTURE3, GL_TEXTURE4, GL_TEXTURE5, GL_TEXTURE6,
                    GL_TEXTURE7, GL_TEXTURE8, GL_TEXTURE9, GL_TEXTURE10, GL_TEXTURE11, GL_TEXTURE12, GL_TEXTURE13,
                    GL_TEXTURE14, GL_TEXTURE15, GL_TEXTURE16, GL_TEXTURE17, GL_TEXTURE18, GL_TEXTURE19, GL_TEXTURE20,
                    GL_TEXTURE21, GL_TEXTURE22, GL_TEXTURE23, GL_TEXTURE24, GL_TEXTURE25, GL_TEXTURE26, GL_TEXTURE27,
                    GL_TEXTURE28, GL_TEXTURE29, GL_TEXTURE30, GL_TEXTURE31
            };
    for(int i = 0; i < 32; ++i)
    {
        if(textures[i])
        {
            glActiveTexture(GL_TEXTURE_ID[i]);
            glBindTexture(GL_TEXTURE_2D, textures[i]->getTextureID());
        }
    }

    glBindVertexArray(vertexSource->getArrayID());
    switch (draw)
    {
        case DrawMode::ARRAYS:
            glDrawArrays(GL_TRIANGLES, 0, count);
            break;
        case DrawMode::ELEMENTS:
            glDrawElements(GL_TRIANGLES, count, 0, nullptr);
            break;
    }
    glBindVertexArray(0);
}
