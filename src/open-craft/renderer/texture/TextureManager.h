#ifndef OPEN_CRAFT_TEXTURE_MANAGER_H
#define OPEN_CRAFT_TEXTURE_MANAGER_H

#include <string>
#include <unordered_map>

namespace gl { class Texture; }
class RenderEngine;

class TextureManager
{
private:
    RenderEngine &engine;
    std::unordered_map<std::string, gl::Texture *> textures;
public:
    explicit TextureManager(RenderEngine &);

    ~TextureManager();

public:
    void initializeTextures();

    bool hasTextureFor(std::string const &name) const;

    gl::Texture *getTextureFor(std::string const &name) const;
};


#endif //OPEN_CRAFT_TEXTURE_MANAGER_H
