#ifndef SANDBOX_H
#define SANDBOX_H

#include "camera.h"
#include "mesh.h"
#include "scene.h"
#include "renderer.h"
#include "input.h"
#include "transform.h"
#include "iobject.h"
#include "vector.h"
#include "physics.h"
#include "system.h"

class Sandbox
{
    private:
        static Scene*       _scene;

        static double       _deltaTime;
		static bool         _running;
		static bool         _pause;

    public:
        static void     init();
        static void     process(Scene *scene);
        static void     destroy();

		static void		togglePause();

        static bool         running();
		static bool			paused();
        static double       time();
        static double       deltaTime();

        static Scene*       scene();
};

#endif