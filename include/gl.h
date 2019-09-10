#ifndef GL_H
#define GL_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GL(x) GLClearError();x;ASSERT(GLLogError(#x, __FILE__, __LINE__));

void GLClearError();

bool GLLogError(const char* function, const char* file, int line);

#endif
