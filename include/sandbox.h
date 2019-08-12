#ifndef SANDBOX_H
#define SANDBOX_H

#include "camera.h"
#include "mesh.h"
#include "scene.h"
#include "renderer.h"
#include "input.h"
#include "transform.h"
#include "object.h"
#include "vector3.h"
#include "list.h"
#include "ientity.h"

class Sandbox
{
    private:
        static Scene*       _scene;

        static double       _deltaTime;
        static bool         _running;

    public:
        static void     init();
        static void     process(Scene *scene);
        static void     destroy();

        static bool         running();
        static double       time();
        static double       deltaTime();

        static Scene*       scene();
};

#endif