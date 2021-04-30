#include "TextureManager.h"

#include <fstream>

#include "json/json.h"

#include "gl/texture/Texture.h"

#include "stb_image.h"

using namespace std;
using namespace Json;
using namespace gl;

TextureManager::TextureManager(RenderEngine & engine): engine(engine)
{

}

TextureManager::~TextureManager()
{
    for(auto & texture : textures)
    {
        delete texture.second;
        texture.second = nullptr;
    }
}

void TextureManager::initializeTextures()
{
    ifstream in("../config/textures.json");
    Value root;
    in >> root;

    unsigned int size = root["data"].size();
    for(int i = 0; i < size; ++i)
    {
        //Loading the texture

        auto data = root["data"][i];
        std::string id = data["id"].asString();
        std::string path = data["path"].asString();
        std::string format = data["format"].asString();

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *image_data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        auto* texture = new Texture(Texture::TextureType::DIM2);
        texture->setFilterMode(Texture::FilterType::MINIFYING, Texture::FilterMode::NEAREST);
        texture->setFilterMode(Texture::FilterType::MAGNIFYING, Texture::FilterMode::NEAREST);
        texture->setTextureImage2D(0,
                                   format == "rgba"? Texture::FormatType::RGBA : Texture::FormatType::RGB,
                                   width, height,
                                   format == "rgba"? Texture::FormatType::RGBA : Texture::FormatType::RGB,
                                   TypeEnum::UNSIGNED_BYTE, image_data);
        texture->generateMipmap();
        texture->setWrappingMode(Texture::AxisType::S, Texture::WrappingMode::REPEAT);
        texture->setWrappingMode(Texture::AxisType::T, Texture::WrappingMode::REPEAT);
        stbi_image_free(image_data);

        textures[id] = texture;
    }
}

bool TextureManager::hasTextureFor(const std::string &name) const
{
    if(textures.count(name) == 0)
        return false;
    return textures.at(name) != nullptr;
}

gl::Texture* TextureManager::getTextureFor(const std::string &name) const
{
    return textures.at(name);
}
