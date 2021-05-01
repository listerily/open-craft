#ifndef OPEN_CRAFT_WORLD_RENDER_LAYER_H
#define OPEN_CRAFT_WORLD_RENDER_LAYER_H


#include "../RenderLayer.h"

#include <unordered_map>

class World;

class BlockTessellationCache;

class WorldRenderLayer : public RenderLayer
{
private:
    World &world;
    std::unordered_map<unsigned long long, BlockTessellationCache *> chunkTessellationCache;
private:

public:
    WorldRenderLayer(RenderEngine &, World &);

    ~WorldRenderLayer();

public:
    void renderTick() override;
};


#endif //OPEN_CRAFT_WORLD_RENDER_LAYER_H
