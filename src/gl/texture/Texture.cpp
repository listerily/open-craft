#include "Texture.h"

#include <glad/glad.h>

namespace gl
{
    Texture &Texture::setFilterMode(Texture::FilterType filterType,
                                    Texture::FilterMode filterMode)
    {
        glBindTexture(glTextureTag, textureID);
        int glFilterType = 0;
        switch (filterType)
        {
            case FilterType::MAGNIFYING:
                glFilterType = GL_TEXTURE_MAG_FILTER;
                break;
            case FilterType::MINIFYING:
                glFilterType = GL_TEXTURE_MIN_FILTER;
                break;
        }
        int glFilterMode = 0;
        switch (filterMode)
        {
            case FilterMode::LINEAR:
                glFilterMode = GL_LINEAR;
                break;
            case FilterMode::NEAREST:
                glFilterMode = GL_NEAREST;
                break;
            case FilterMode::NEAREST_MIPMAP_NEAREST:
                glFilterMode = GL_NEAREST_MIPMAP_NEAREST;
                break;
            case FilterMode::LINEAR_MIPMAP_NEAREST:
                glFilterMode = GL_LINEAR_MIPMAP_NEAREST;
                break;
            case FilterMode::NEAREST_MIPMAP_LINEAR:
                glFilterMode = GL_NEAREST_MIPMAP_LINEAR;
                break;
            case FilterMode::LINEAR_MIPMAP_LINEAR:
                glFilterMode = GL_LINEAR_MIPMAP_LINEAR;
                break;
        }
        glTexParameteri(glTextureTag, glFilterType, glFilterMode);
        return *this;
    }

    Texture &Texture::setWrappingMode(Texture::AxisType axis,
                                      Texture::WrappingMode wrapping)
    {
        glBindTexture(glTextureTag, textureID);
        int glWrappingMode = 0;
        switch (wrapping)
        {
            case WrappingMode::REPEAT:
                glWrappingMode = GL_REPEAT;
                break;
            case WrappingMode::MIRRORED_REPEAT:
                glWrappingMode = GL_MIRRORED_REPEAT;
                break;
            case WrappingMode::CLAMP_TO_EDGE:
                glWrappingMode = GL_CLAMP_TO_EDGE;
                break;
            case WrappingMode::CLAMP_TO_BORDER:
                glWrappingMode = GL_CLAMP_TO_BORDER;
                break;
        }
        switch (axis)
        {
            case AxisType::S:
                glTexParameteri(glTextureTag, GL_TEXTURE_WRAP_S, glWrappingMode);
                break;
            case AxisType::T:
                glTexParameteri(glTextureTag, GL_TEXTURE_WRAP_T, glWrappingMode);
                break;
            case AxisType::R:
                glTexParameteri(glTextureTag, GL_TEXTURE_WRAP_R, glWrappingMode);
                break;
        }
        return *this;
    }

    Texture &Texture::borderColor(float b1, float b2, float b3, float b4)
    {
        glBindTexture(glTextureTag, textureID);
        float borderColor[] = {b1, b2, b3, b4};
        glTexParameterfv(glTextureTag, GL_TEXTURE_BORDER_COLOR, borderColor);
        return *this;
    }

    Texture &Texture::setTextureImage2D(int mipmapLevel,
                                        Texture::FormatType internalFormat,
                                        int width,
                                        int height,
                                        Texture::FormatType format,
                                        TypeEnum type,
                                        void *data)
    {
        glBindTexture(glTextureTag, textureID);
        auto formatConvert = [](Texture::FormatType formatType)
        {
            switch (formatType)
            {
                case FormatType::RGB:
                    return GL_RGB;
                case FormatType::RGBA:
                    return GL_RGBA;
            }
            return -1;
        };
        int glInternalFormat = formatConvert(internalFormat);
        int glFormat = formatConvert(format);

        if (glTextureTag == GL_TEXTURE_2D)
            glTexImage2D(glTextureTag, mipmapLevel, glInternalFormat, width, height, 0, glFormat,
                         typeEnumToGLEnum(type), data);
        return *this;
    }

    Texture &Texture::generateMipmap()
    {
        glBindTexture(glTextureTag, textureID);
        glGenerateMipmap(glTextureTag);
        return *this;
    }

    Texture::Texture(Texture::TextureType type)
    {
        switch (type)
        {
            case TextureType::DIM2:
                glTextureTag = GL_TEXTURE_2D;
                break;
            case TextureType::DIM3:
                glTextureTag = GL_TEXTURE_3D;
                break;
            case TextureType::DIM1:
                glTextureTag = GL_TEXTURE_1D;
                break;
        }
        textureID = 0;
        count = 1;
        glGenTextures(count, &textureID);
    }

    Texture::~Texture()
    {
        glDeleteTextures(count, &textureID);
    }

    unsigned int Texture::getTextureID() const
    {
        return textureID;
    }
}