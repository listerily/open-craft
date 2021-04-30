#ifndef OPEN_CRAFT_RENDER_ENGINE_H
#define OPEN_CRAFT_RENDER_ENGINE_H


class MainApplication;
class RenderLayer;
class World;
class TessellationModelManager;
class TextureManager;
class RenderEngine
{
private:
    MainApplication& main;
    RenderLayer* worldLayer;
    RenderLayer* guiLayer;
    TextureManager* textureManager;
    TessellationModelManager* tessellationModelManager;
public:
    explicit RenderEngine(MainApplication&);
    ~RenderEngine();

    RenderLayer& getWorldLayer();
    const RenderLayer& getWorldLayer() const;
    RenderLayer& getGuiLayer();
    const RenderLayer& getGuiLayer() const;
    TextureManager& getTextureManager();
    const TextureManager& getTextureManager() const;
    TessellationModelManager & getTessellationModelManager();
    const TessellationModelManager & getTessellationModelManager() const;

    void renderTick();
    void initialize();
};


#endif //OPEN_CRAFT_RENDER_ENGINE_H
