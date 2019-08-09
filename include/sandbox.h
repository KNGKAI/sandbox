#ifndef SANDBOX_H
#define SANDBOX_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "camera.h"
#include "mesh.h"
#include "scene.h"

class Sandbox
{
    private:
        GLFWwindow* _window;
        Scene       *_scene;

        double      _deltaTime;

        void    input();
        void    renderClear();
        void    renderBackground();
        void    renderMesh(Mesh m);
        void    renderGUI();
        void    renderDebug();

    public:
        Sandbox();
        ~Sandbox();

        void    openWindow();
        void    closeWindow();
        void    process(Scene *scene);

        double      time();
        double      deltaTime();
};


#endif