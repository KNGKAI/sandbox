#include "camera.h"

Transform Camera::transform = Transform();

Vector3 Camera::surface = Vector3(1, 1, 1);

double Camera::fov = 0;

bool Camera::enabled = true;