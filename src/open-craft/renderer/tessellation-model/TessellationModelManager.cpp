#include "TessellationModelManager.h"

#include "json/json.h"
#include "gl/object/BufferObject.h"
#include "gl/extra/wrapper/VertexArrayWithBuffer.h"
#include <fstream>

using namespace Json;
using namespace std;
using namespace gl;

TessellationModelManager::TessellationModelManager(RenderEngine &engine) : engine(engine)
{

}

TessellationModelManager::~TessellationModelManager()
{
    for (auto &model : models)
    {
        delete model.second;
    }
}

void TessellationModelManager::initializeModels()
{
    Json::Value root;
    ifstream in("../config/tessellation_models.json");
    unsigned int size = root["data"].size();
    for (int i = 0; i < size; ++i)
    {
        auto const &modelData = root["data"][i];
        auto partsSize = modelData["parts"].size();
        auto id = modelData["id"].asString();

        auto *model = new TessellationModel(id, partsSize);
        initializeModel(modelData, model);
        models[id] = model;
    }
}

void TessellationModelManager::initializeModel(const Value &json, TessellationModel *model)
{
    auto const &parts = json["parts"];
    auto size = model->size();
    for (int i = 0; i < size; ++i)
    {
        auto const &part = parts[i];
        auto primitiveString = part["primitive"];
        auto primitiveType = TessellationModelPart::PrimitiveType::UNDEFINED;
        if (primitiveString == "line")
            primitiveType = TessellationModelPart::PrimitiveType::LINE;
        else if (primitiveString == "triangle")
            primitiveType = TessellationModelPart::PrimitiveType::TRIANGLE;
        auto instance = std::make_shared<TessellationModelPart>(i, primitiveType);

        //Bind Vertex Buffer
        auto vertexBufferSize = part["vertices_buffer"].size();
        auto *vertexBufferMem = new float[vertexBufferSize];
        auto vertexBuffer = std::make_shared<BufferObject>(BufferObject::BufferType::VERTEX);
        vertexBuffer->bufferData(static_cast<int>(vertexBufferSize), vertexBufferMem, BufferObject::DrawType::STATIC);
        instance->bindBuffer(vertexBuffer);
        delete[] vertexBufferMem;

        //Bind Element Buffer
        auto elementBufferSize = part["elements_buffer"].size();
        auto *elementBufferMem = new float[elementBufferSize];
        auto elementBuffer = std::make_shared<BufferObject>(BufferObject::BufferType::ELEMENT);
        vertexBuffer->bufferData(static_cast<int>(elementBufferSize), elementBufferMem, BufferObject::DrawType::STATIC);
        instance->bindBuffer(elementBuffer);
        delete[] elementBufferMem;

        //Set Vertex Attribute Pointer
        instance->getVertexArrayWithBuffer().getVertexArrayObject().vertexAttribPointer(
                0, 3, TypeEnum::FLOAT, false, 5, 0);
        instance->getVertexArrayWithBuffer().getVertexArrayObject().vertexAttribPointer(
                1, 2, TypeEnum::FLOAT, false, 5, 0);

        model->addModelPart(instance);
    }
}

const TessellationModel *TessellationModelManager::getModelFor(const std::string &id) const
{
    return models.at(id);
}

bool TessellationModelManager::hasModelFor(const std::string &id) const
{
    if (models.count(id) == 0)
        return false;
    return models.at(id) != nullptr;
}
