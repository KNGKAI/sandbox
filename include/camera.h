#ifndef CAMERA_H
#define CAMERA_H

#include "icomponent.h"
#include "transform.h"

class Camera
{
    public:
		static Transform transform;
		static Vector3 surface;
		static double fov;
        static bool enabled;
};

#endif