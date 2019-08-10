#ifndef SANDBOX_H
#define SANDBOX_H

#include "camera.h"
#include "mesh.h"
#include "scene.h"
#include "render.h"
#include "input.h"

class Sandbox
{
    private:
        static Scene*       _scene;

        static double       _t;
        static double       _deltaTime;
        static bool         _running;

    public:
        Sandbox();
        ~Sandbox();

        static void     init();
        static void     process(Scene *scene);
        static void     destroy();

        static bool         running();
        static double       time();
        static double       deltaTime();

        static Scene*       scene();
};

#endif