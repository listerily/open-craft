#include "WorldRenderLayer.h"

void WorldRenderLayer::renderTick()
{

}

WorldRenderLayer::WorldRenderLayer(RenderEngine &engine, World &world) : world(world), RenderLayer(engine)
{

}

WorldRenderLayer::~WorldRenderLayer() = default;