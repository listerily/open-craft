#include "TessellationModel.h"

#include <utility>

#include "TessellationModelPart.h"

TessellationModel::TessellationModel(std::string id, unsigned int size) : id(std::move(id))
{
    modelParts.resize(size);
}

TessellationModel::~TessellationModel() = default;

std::string const &TessellationModel::getID() const
{
    return id;
}

unsigned int TessellationModel::size() const
{
    return modelParts.size();
}

TessellationModelPart &TessellationModel::getModelPart(unsigned int index) const
{
    return *modelParts[index];
}

void TessellationModel::addModelPart(const std::shared_ptr<TessellationModelPart> &p)
{
    modelParts[p->getIndex()] = p;
}
