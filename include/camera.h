#ifndef CAMERA_H
#define CAMERA_H

#include "icomponent.h"
#include "transform.h"

class Camera
{
    public:
        static bool enabled;
		static Transform transform;
		static Vector3 surface;
		static double fov;
		static double nearPlane;
		static double farPlane;
};

#endif