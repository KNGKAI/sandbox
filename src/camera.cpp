#include "camera.h"

Transform Camera::transform = Transform(Vector3(0, 4, -10));

Vector3 Camera::surface = Vector3(0 , 0, 1);

double Camera::fov = 0;

bool Camera::enabled = true;