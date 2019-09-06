#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector.h"

class Transform
{
	public:
		Transform() : position(0, 0, 0), rotation(0, 0, 0), scale(0, 0, 0) { return; }
		Transform(vec3 position) : position(position), rotation(0, 0, 0), scale(0, 0, 0) { return; }
		Transform(vec3 position, vec3 rotation) : position(position), rotation(0, 0, 0), scale(0, 0, 0) { return; }
		Transform(vec3 position, vec3 rotation, vec3 scale) : position(position), rotation(rotation), scale(scale) { return; }
		~Transform() { return; }

		vec3     position;
		vec3     rotation;
		vec3     scale;
};

#endif