#ifndef RENDER_H
#define RENDER_H

#define SCREEN_WIDTH
#define SCREEN_HEIGHT

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

using namespace std;

#include "scene.h"

class Render
{
private:
    static GLFWwindow*  _window;
    
public:
    static void init()
    {
        if (!glfwInit())
        {
            cout << "GLFW init error" << endl;
            exit(EXIT_FAILURE);
        }
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwMakeContextCurrent(Render::_window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    }
    static void render(const Scene &scene)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(Render::_window);
        glfwPollEvents();
    }
    static void destroy()
    {
        glfwTerminate();
    }
};

#endif