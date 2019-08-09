#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

class Camera
{
    public:
        Camera() 
        {
            this->surface = Vector3(1, 1, 1);
            return;
        }
        ~Camera() { return; }
        Vector3 surface;
};

#endif