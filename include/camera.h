#ifndef CAMERA_H
#define CAMERA_H

#include "system.h"
#include "transform.h"

class Camera
{
public:
	Camera();

	Transform	transform;
	float		nearPlane;
	float		farPlane;
	float		zoom;

	mat4 GetViewMatrix();
};

#endif