#include <iostream>
#include "gl.h"

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

void GLLogError(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::string err;
		switch (error)
		{
			case GL_INVALID_ENUM: err = "GL_INVALID_ENUM"; break;
			case GL_INVALID_VALUE: err = "GL_INVALID_VALUE"; break;
			case GL_INVALID_OPERATION: err = "GL_INVALID_OPERATION"; break;
			case GL_INVALID_FRAMEBUFFER_OPERATION: err = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
			case GL_OUT_OF_MEMORY: err = "GL_OUT_OF_MEMORY"; break;
			default: break;
		}
		std::cout << "OPENGL_ERR " << err << " " << function << ", line:" << line << std::endl;
	}
}
