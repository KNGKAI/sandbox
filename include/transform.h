#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector.h"

class Transform
{
public:
    Transform();
    ~Transform();

    vec3 position;
    vec3 rotation;
};


#endif