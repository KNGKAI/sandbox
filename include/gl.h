#ifndef GL_H
#define GL_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void GLClearError();

void GLLogError(const char* function, const char* file, int line);

#define GL(x) GLClearError();x;GLLogError(#x, __FILE__, __LINE__);

#endif
