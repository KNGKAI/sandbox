#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3.h"

class Transform
{
    public:
		Transform() { return; }
		Transform(Vector3 position) : position(position) { return; }
		Transform(Vector3 position, Vector3 rotation) : position(position), rotation(rotation) { return; }
		Transform(Vector3 position, Vector3 rotation, Vector3 scale) : position(position), rotation(rotation), scale(scale) { return; }
		~Transform() { return; }

        Vector3     position;
        Vector3     rotation;
        Vector3     scale;
};

#endif