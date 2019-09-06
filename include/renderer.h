#ifndef RENDERER_H
#define RENDERER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "camera.h"
#include "iobject.h"
#include "scene.h"

class Renderer
{
    private:
        static GLFWwindow*  _window;

        static void     input();
		static void		renderSceneObject(const IObject &object, const Shader &shader);
		static void		renderSceneObjects();
        static void     renderScene();
        static void     renderGUI();
        static int          compileShader(const std::string &src, unsigned int type);
        static unsigned int createShader(const std::string &vertexShader, const std::string &fragShader);
        static std::string  loadShader(const std::string path);
		
		//test
		static Shader ourShader;
		static Model ourModel;

    public:
        static void     init();
        static void     render();
        static void     destroy();

        static GLFWwindow*  window();
		static vec3		    sun;
};

#endif