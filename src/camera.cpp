#include "camera.h"

Camera::Camera() : transform(), nearPlane(0.1f), farPlane(100.0f), zoom(60.0f) {}

mat4 Camera::GetViewMatrix() { return glm::lookAt(this->transform.position, this->transform.position + this->transform.forward(), this->transform.up()); }