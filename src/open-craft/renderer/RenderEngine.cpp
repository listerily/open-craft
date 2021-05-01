#include "RenderEngine.h"

#include "texture/TextureManager.h"
#include "render-layer/world/WorldRenderLayer.h"
#include "tessellation-model/TessellationModelManager.h"

RenderEngine::RenderEngine(MainApplication &main) : main(main)
{
    worldLayer = nullptr;
    guiLayer = nullptr;
    textureManager = new TextureManager(*this);
    tessellationModelManager = new TessellationModelManager(*this);

//    worldLayer = new WorldRenderLayer(*this, world);
}

RenderEngine::~RenderEngine()
{
    delete worldLayer;
    delete guiLayer;
    delete textureManager;
}

RenderLayer &RenderEngine::getWorldLayer()
{
    return *worldLayer;
}

RenderLayer &RenderEngine::getGuiLayer()
{
    return *guiLayer;
}

const RenderLayer &RenderEngine::getWorldLayer() const
{
    return *worldLayer;
}

const RenderLayer &RenderEngine::getGuiLayer() const
{
    return *guiLayer;
}

void RenderEngine::renderTick()
{
    if (worldLayer)
        worldLayer->renderTick();
    if (guiLayer)
        guiLayer->renderTick();
}

TextureManager &RenderEngine::getTextureManager()
{
    return *textureManager;
}

const TextureManager &RenderEngine::getTextureManager() const
{
    return *textureManager;
}

void RenderEngine::initialize()
{
    textureManager->initializeTextures();
    tessellationModelManager->initializeModels();
}

const TessellationModelManager &RenderEngine::getTessellationModelManager() const
{
    return *tessellationModelManager;
}

TessellationModelManager &RenderEngine::getTessellationModelManager()
{
    return *tessellationModelManager;
}
