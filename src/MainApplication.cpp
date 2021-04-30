#include "MainApplication.h"

#include <iostream>
#include <thread>
#include <cmath>
#include <random>
#include <fstream>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "gl/shader/ShaderProgram.h"
#include "gl/texture/Texture.h"
#include "gl/object/VertexArrayObject.h"
#include "gl/object/BufferObject.h"
#include "gl/GLCpp.h"

#include "gl/extra/wrapper/VertexArrayWithBuffer.h"
#include "gl/extra/wrapper/GraphicsProgram.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

#include "open-craft/client/OpenCraftClient.h"
#include "open-craft/renderer/RenderEngine.h"
#include "open-craft/renderer/texture/TextureManager.h"

using namespace gl;
using namespace gl::extra;

MainApplication::~MainApplication()
{
    delete renderEngine;
    delete openCraftClient;
}

MainApplication::MainApplication() : windowTitle("OpenCraft")
{
    cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    mix_para = 1.0f;
    cameraSpeed = 0.10f;
    windowWidth = 1024;
    windowHeight = 720;
    windowInstance = nullptr;
    mouseX = 0.0f;
    mouseY = 0.0f;
    windowHasEverGotFocus = false;
    sensitivity = 0.05f;
    yaw = -90.0f;
    pitch = 0.0f;
}

void MainApplication::processInput()
{
    if (glfwGetKey(windowInstance, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(windowInstance, true);
    if (glfwGetKey(windowInstance, GLFW_KEY_DOWN) == GLFW_PRESS)
        if (mix_para > 0)
            mix_para -= 0.001;
    if (glfwGetKey(windowInstance, GLFW_KEY_UP) == GLFW_PRESS)
        if (mix_para < 1)
            mix_para += 0.001;
    if (glfwGetKey(windowInstance, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * glm::normalize(glm::vec3(cameraFront.x, 0.0f, cameraFront.z));
    if (glfwGetKey(windowInstance, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * glm::normalize(glm::vec3(cameraFront.x, 0.0f, cameraFront.z));
    if (glfwGetKey(windowInstance, GLFW_KEY_SPACE) == GLFW_PRESS)
        cameraPos += cameraSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
    if (glfwGetKey(windowInstance, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        cameraPos -= cameraSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
    if (glfwGetKey(windowInstance, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos += glm::normalize(cameraRight) * cameraSpeed;
    if (glfwGetKey(windowInstance, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos -= glm::normalize(cameraRight) * cameraSpeed;

    generateCameraVectors();
}

//std::shared_ptr<Texture> MainApplication::generateTexture(const std::string &path)
//{
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
//    auto texture = std::make_shared<Texture>(Texture::TextureType::DIM2);
//    texture->setFilterMode(Texture::FilterType::MINIFYING,
//                           Texture::FilterMode::NEAREST)
//            .setFilterMode(Texture::FilterType::MAGNIFYING,
//                           Texture::FilterMode::NEAREST)
//            .setTextureImage2D(0, Texture::FormatType::RGBA, width, height,
//                               Texture::FormatType::RGBA,
//                               TypeEnum::UNSIGNED_BYTE, data)
//            .generateMipmap()
//            .setWrappingMode(Texture::AxisType::S, Texture::WrappingMode::REPEAT)
//            .setWrappingMode(Texture::AxisType::T, Texture::WrappingMode::REPEAT);
//
//    stbi_image_free(data);
//    return texture;
//}

void MainApplication::prepareTriangleProgram()
{
    std::stringstream vertexShaderSource;
    vertexShaderSource << std::ifstream("../shader/vertex.shader").rdbuf();
    auto vertexShader = std::make_shared<Shader>(Shader::Type::VERTEX, vertexShaderSource.str());

    std::stringstream fragmentShaderSource;
    fragmentShaderSource << std::ifstream("../shader/fragment.shader").rdbuf();
    auto fragmentShader = std::make_shared<Shader>(Shader::Type::FRAGMENT, fragmentShaderSource.str());

    program = std::make_shared<GraphicsProgram>();
    program->program().attachShader(*vertexShader);
    program->program().attachShader(*fragmentShader);
    program->program().linkProgram();

    program->uniform("texture1", 0);
    program->uniform("texture2", 1);

    program->texture(*texture1, 0);
    program->texture(*texture2, 1);

    //TODO: shared_ptr to bare instance
}

void MainApplication::makeVertexArrayObject()
{
    std::array<float, 180> vertices = {
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    };

//    std::array indices = { // 注意索引从0开始!
//            0, 1, 3, // 第一个三角形
//            1, 2, 3,  // 第二个三角形
//    };

    auto vertexBuffer = std::make_shared<BufferObject>(BufferObject::BufferType::VERTEX);
    vertexBuffer->bufferData(sizeof(vertices), vertices.data(), BufferObject::DrawType::STATIC);

//    vertexBuffer = std::make_shared<BufferObject>(BufferObject::BufferType::ELEMENT);
//    elementBuffer->bufferData(sizeof(indices), indices.data(), BufferObject::DrawType::STATIC);

    vertexArray = std::make_shared<VertexArrayWithBuffer>(1);
    vertexArray->bindBuffer(vertexBuffer);
    //.bindBuffer(*elementBuffer)
    vertexArray->getVertexArrayObject().vertexAttribPointer(0, 3,
                                                            TypeEnum::FLOAT,
                                                            false,
                                                            5 * sizeof(float), 0);
    vertexArray->getVertexArrayObject().vertexAttribPointer(1, 2,
                                                            TypeEnum::FLOAT,
                                                            false,
                                                            5 * sizeof(float), 3 * sizeof(float));
}

void MainApplication::renderGraphics()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderEngine->renderTick();

    static const std::array<glm::vec3, 9> positions = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(-1.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f),
            glm::vec3(1.0f, 0.0f, -1.0f),
    };

    program->uniform("mixd", mix_para);

    auto view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1024.0f / 720.0f, 0.1f, 100.0f);
    program->uniform("view",
                     UniformParameters(UniformParameters::MatrixType::MATRIX_4, 1, false, glm::value_ptr(view)));
    program->uniform("projection", UniformParameters(UniformParameters::MatrixType::MATRIX_4, 1, false,
                                                     glm::value_ptr(projection)));
    program->source(vertexArray->getVertexArrayObject(), 36);
    for (auto position : positions)
    {
        glm::mat4 model(1.0f);
        model = glm::translate(model, position);
        program->uniform("model", UniformParameters(UniformParameters::MatrixType::MATRIX_4, 1, false,
                                                    glm::value_ptr(model)));

        program->draw(GraphicsProgram::DrawMode::ARRAYS);
    }
}

void MainApplication::renderLoop()
{
    renderGraphics();
}

void MainApplication::initialize(GLFWwindow *window)
{
    openCraftClient = new OpenCraftClient(*this);
    renderEngine = new RenderEngine(*this);

    renderEngine->initialize();

    texture1 = renderEngine->getTextureManager().getTextureFor("texture/block/clay");
    texture2 = renderEngine->getTextureManager().getTextureFor("texture/block/stone");

    prepareTriangleProgram();
    makeVertexArrayObject();
    windowInstance = window;
}

int MainApplication::getWindowWidth() const
{
    return windowWidth;
}

int MainApplication::getWindowHeight() const
{
    return windowHeight;
}

void MainApplication::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
    windowWidth = width;
    windowHeight = height;
}

void MainApplication::beforeRenderLoop()
{
    processInput();
}

void MainApplication::afterRenderLoop()
{

}

std::string MainApplication::getTitle() const
{
    return windowTitle;
}

void MainApplication::mouse_callback(GLFWwindow *window, double xPos, double yPos)
{
    mouseEvent(xPos, yPos);
}

void MainApplication::mouseEvent(double x, double y)
{
    if (!windowHasEverGotFocus)
    {
        windowHasEverGotFocus = true;
        mouseX = x;
        mouseY = y;
    }

    auto xOffset = static_cast<float>(x - mouseX);
    auto yOffset = static_cast<float>(mouseY - y);
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    mouseX = x;
    mouseY = y;

    glm::vec3 front;
    front.x = static_cast<float>(cos(glm::radians(pitch)) * cos(glm::radians(yaw)));
    front.y = static_cast<float>(sin(glm::radians(pitch)));
    front.z = static_cast<float>(cos(glm::radians(pitch)) * sin(glm::radians(yaw)));
    cameraFront = glm::normalize(front);

    generateCameraVectors();
}

void MainApplication::generateCameraVectors()
{
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraDirection = cameraFront;
    cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    cameraUp = glm::cross(cameraDirection, cameraRight);
}