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

		vec3    position;
		vec3    rotation;
		vec3	scale;

		vec3	forward()
		{
			glm::vec3 front;

			front.x = cos(radians(this->rotation.y + 90.0f)) * cos(radians(this->rotation.x));
			front.y = sin(radians(this->rotation.x));
			front.z = sin(radians(this->rotation.y + 90.0f)) * cos(radians(this->rotation.x));
			return (normalize(front));
		}
		vec3	right()
		{
			return (normalize(cross(this->forward(), vec3(0.0f, 1.0f, 0.0f))));
		}
		vec3	up()
		{
			return (normalize(cross(this->right(), this->forward())));
		}
};

#endif