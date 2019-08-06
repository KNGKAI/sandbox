#ifndef CAMERA_H
#define CAMERA_H

#include "transform.h"

class Camera : public Transform
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