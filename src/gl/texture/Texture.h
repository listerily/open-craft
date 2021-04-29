#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H


#include <cstddef>
#include "../TypeEnum.h"

namespace gl
{
    class Texture
    {
    private:
        unsigned int textureID;
        int count;
        int glTextureTag;
    public:
        enum class AxisType : int
        {
            S, T, R
        };

        enum class WrappingMode : int
        {
            REPEAT, MIRRORED_REPEAT, CLAMP_TO_EDGE, CLAMP_TO_BORDER
        };

        enum class FilterType : int
        {
            MAGNIFYING, MINIFYING
        };

        enum class FilterMode : int
        {
            LINEAR, NEAREST,
            NEAREST_MIPMAP_NEAREST,
            LINEAR_MIPMAP_NEAREST,
            NEAREST_MIPMAP_LINEAR,
            LINEAR_MIPMAP_LINEAR
        };

        enum class TextureType : int
        {
            DIM1, DIM2, DIM3
        };

        enum class FormatType : int
        {
            RGB, RGBA
        };
    public:
        explicit Texture(TextureType);

        Texture(const Texture &) = delete;

        Texture &operator=(Texture const &) = delete;

        ~Texture();

        Texture &setWrappingMode(AxisType, WrappingMode);

        Texture &setFilterMode(FilterType, FilterMode);

        Texture &borderColor(float, float, float, float);

        Texture &
        setTextureImage2D(int mipmapLevel, FormatType internalFormat, int width, int height, FormatType format,
                          TypeEnum type,
                          void *data);

        Texture &generateMipmap();

        unsigned int getTextureID() const;

        friend class GLCpp;
    };
}

#endif //GL_TEXTURE_H
