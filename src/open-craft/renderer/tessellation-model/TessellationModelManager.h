#ifndef OPEN_CRAFT_RENDER_MODEL_MANAGER_H
#define OPEN_CRAFT_RENDER_MODEL_MANAGER_H

#include <unordered_map>

#include "TessellationModel.h"

class RenderEngine;
namespace Json { class Value; }
class TessellationModelManager
{
private:
    RenderEngine &engine;
    std::unordered_map<std::string, TessellationModel *> models;
private:
    static void initializeModel(Json::Value const &, TessellationModel *);

public:
    explicit TessellationModelManager(RenderEngine &);

    ~TessellationModelManager();

    void initializeModels();

    const TessellationModel *getModelFor(std::string const &) const;

    bool hasModelFor(std::string const &) const;
};


#endif //OPEN_CRAFT_RENDER_MODEL_MANAGER_H
