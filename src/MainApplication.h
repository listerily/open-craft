#ifndef OPEN_CRAFT_MAINAPPLICATION_H
#define OPEN_CRAFT_MAINAPPLICATION_H

#include <string>
#include <memory>
#include <glm/glm.hpp>

class GLFWwindow;
namespace gl
{
    class ShaderProgram;

    class Texture;

    class BufferObject;

    class VertexArrayObject;

    namespace extra
    {
        class VertexArrayWithBuffer;
        class GraphicsProgram;
    }
}
class RenderEngine;
class OpenCraftClient;
class MainApplication
{
private:
    int windowWidth;
    int windowHeight;
    const std::string windowTitle;
    glm::vec3 cameraFront;
    glm::vec3 cameraPos;
    glm::vec3 cameraUp;
    glm::vec3 cameraRight;
    float cameraSpeed;
    float mix_para;
    gl::Texture* texture1;
    gl::Texture* texture2;
    std::shared_ptr<gl::extra::GraphicsProgram> program;
    std::shared_ptr<gl::extra::VertexArrayWithBuffer> vertexArray;
    GLFWwindow *windowInstance;
    double mouseX, mouseY;
    bool windowHasEverGotFocus;
    float yaw, pitch;
    float sensitivity;

    RenderEngine* renderEngine;
    OpenCraftClient* openCraftClient;
public:
    MainApplication();

    ~MainApplication();

private:
    void processInput();

    void prepareTriangleProgram();

    void makeVertexArrayObject();

    void renderGraphics();

    void generateCameraVectors();

public:
    void beforeRenderLoop();

    void afterRenderLoop();

    void renderLoop();

    void initialize(GLFWwindow *);

    void mouseEvent(double x, double y);

    std::string getTitle() const;

    int getWindowHeight() const;

    int getWindowWidth() const;

    void framebuffer_size_callback(GLFWwindow *, int, int);

    void mouse_callback(GLFWwindow *, double, double);
};

#endif //OPEN_CRAFT_MAINAPPLICATION_H
