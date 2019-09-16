#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "system.h"
#include "iobject.h"
#include "camera.h"
#include "skybox.h"

class Scene
{
    private:
		Camera				_camera;
        std::string         _name;
        vector<IObject *>	_objects;
		Skybox				_skybox;
		vec3				_sun;

		void	setName(Json::Value name);
		void	setCamera(Json::Value camera);
		void	addObjects(Json::Value objects);

    public:
		Scene(std::string path);
		~Scene();

		Camera*				camera();
		std::string			name();
		vector<IObject*>*	objects();
		Skybox*				skybox();
		vec3				sun();

		void				addObject(IObject *object);
		IObject*			getObject(std::string name);
};

#endif