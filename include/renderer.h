#ifndef RENDERER_H
#define RENDERER_H

#include "filesystem.h"
#include "gl.h"
#include "scene.h"
#include "vector.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

class Renderer
{
    private:
        static GLFWwindow*  _window; 
        static Texture*     _defaultTexture;

		static Shader       skybox;
		static Shader       ourShader;

        static void     input();
		static void		renderSceneObject(IObject *object, Shader *shader);
		static void		renderSceneObjects();
		static void     renderSceneSkybox();
		static void     renderScene();
        static void     renderGUI();
		static void		initSkybox();
		static void		initTexture();

    public:
        static void     init();
        static void     render();
        static void     destroy();

        static GLFWwindow*  window();
        static Texture*     defaultTexture();
		static vec3		    sun;
};

#endif