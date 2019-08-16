#ifndef RENDERER_H
#define RENDERER_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "camera.h"
#include "mesh.h"
#include "scene.h"

class Renderer
{
    private:
        static GLFWwindow*  _window;

        static void     input();
        static void     renderScene();
        static void     renderGUI();
        static void     renderDebug();
        static int          compileShader(const std::string &src, unsigned int type);
        static unsigned int createShader(const std::string &vertexShader, const std::string &fragShader);
        static std::string  loadShader(const std::string path);

    public:
        static void     init();
        static void     render();
        static void     destroy();

        static GLFWwindow*  window();
};

#endif