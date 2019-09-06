#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <iostream>
#include "json/json.h"

#include "system.h"
#include "iobject.h"
#include "camera.h"

class Scene
{
    private:
        std::string         _name;
        vector<IObject *>	_objects;

		void	setName(Json::Value name);
		void	setCamera(Json::Value camera);
		void	addObjects(Json::Value objects);

    public:
		Scene(std::string path); 
		~Scene();

		std::string			name();
		vector<IObject *>*	objects();
		void				addObject(IObject *object);
		IObject*			getObject(std::string name);
};

#endif