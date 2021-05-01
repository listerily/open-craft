#ifndef OPEN_CRAFT_MAIN_APPLICATION_H
#define OPEN_CRAFT_MAIN_APPLICATION_H

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

class OpenCraftGame;

class GameThreadHandler;

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
    GLFWwindow *windowInstance;
    double mouseX, mouseY;
    bool windowHasEverGotFocus;
    float yaw, pitch;
    float sensitivity;

    RenderEngine *renderEngine;
    OpenCraftGame *openCraftGame;
    GameThreadHandler *threadHandler;
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
    void beforeRendering();

    void afterRendering();

    void beforeLooping();

    void afterLooping();

    void render();

    void initialize(GLFWwindow *);

    void mouseEvent(double x, double y);

    std::string getTitle() const;

    int getWindowHeight() const;

    int getWindowWidth() const;

    void framebuffer_size_callback(GLFWwindow *, int, int);

    void mouse_callback(GLFWwindow *, double, double);
};

#endif //OPEN_CRAFT_MAIN_APPLICATION_H
