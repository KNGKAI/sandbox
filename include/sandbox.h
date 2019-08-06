#ifndef SANDBOX_H
#define SANDBOX_H

#include "GLFW/glfw3.h"

#include "camera.h"
#include "mesh.h"

class Sandbox
{
    private:
        GLFWwindow* window;
    public:
        Sandbox();
        ~Sandbox();
        void    render(Mesh m);
        Camera  camera;
};


#endif