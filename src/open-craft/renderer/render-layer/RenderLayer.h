#ifndef OPEN_CRAFT_RENDER_LAYER_H
#define OPEN_CRAFT_RENDER_LAYER_H

class RenderEngine;

class RenderLayer
{
protected:
    RenderEngine &engine;
public:
    explicit RenderLayer(RenderEngine &);

    ~RenderLayer();

    virtual void renderTick() = 0;
};


#endif //OPEN_CRAFT_RENDER_LAYER_H
