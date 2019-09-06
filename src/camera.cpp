#include "camera.h"

Transform Camera::transform = Transform(vec3(0, 4, -10));

vec3 Camera::surface = vec3(0 , 0, 1);

double Camera::fov = 0;
double Camera::nearPlane = 0.1;
double Camera::farPlane = 1000;

bool Camera::enabled = true;