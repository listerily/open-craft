#include "MainApplication.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

MainApplication app;
void framebuffer_size_callback(GLFWwindow * w, int x, int y)
{
    app.framebuffer_size_callback(w, x, y);
}

void mouse_callback(GLFWwindow * w, double x, double y)
{
    app.mouse_callback(w, x, y);
}

int main(int argc, char **argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(app.getWindowWidth(), app.getWindowHeight(),
                                          app.getTitle().c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD." << std::endl;
        return -1;
    }

    try
    {
        glViewport(0, 0, app.getWindowWidth(), app.getWindowHeight());
        glfwSetFramebufferSizeCallback(window, &framebuffer_size_callback);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetCursorPosCallback(window, &mouse_callback);

        app.initialize(window);

        glEnable(GL_DEPTH_TEST);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CW);

        while (!glfwWindowShouldClose(window))
        {
            app.beforeRenderLoop();
            app.renderLoop();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwTerminate();
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}