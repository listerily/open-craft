#ifndef OPEN_CRAFT_TESSELLATION_MODEL_H
#define OPEN_CRAFT_TESSELLATION_MODEL_H

#include <vector>
#include <string>
#include <memory>

#include "TessellationModelPart.h"

class TessellationModel
{
private:
    std::vector<std::shared_ptr<TessellationModelPart>> modelParts;
    std::string id;
public:
    explicit TessellationModel(std::string id, unsigned int size);

    ~TessellationModel();

    std::string const &getID() const;

    unsigned int size() const;

    TessellationModelPart &getModelPart(unsigned int index) const;

    void addModelPart(std::shared_ptr<TessellationModelPart> const &);
};


#endif //OPEN_CRAFT_TESSELLATION_MODEL_H
