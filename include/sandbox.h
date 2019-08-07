#ifndef SANDBOX_H
#define SANDBOX_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "camera.h"
#include "mesh.h"

class Sandbox
{
    private:
        Camera      camera;
        GLFWwindow* window;
        double      _deltaTime;

        void    input();
        void    renderClear();
        void    renderBackground();
        void    renderMesh(Mesh m);
        void    renderGUI();

    public:
        Sandbox();
        ~Sandbox();

        void    openWindow();
        void    closeWindow();
        void    render();

        double      time();
        double      deltaTime();
};


#endif