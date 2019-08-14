#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <iostream>
#include "json/json.h"

#include "ientity.h"
#include "list.h"
#include "object.h"
#include "mesh.h"
#include "transform.h"
#include "camera.h"

class Scene
{
    private:
        std::string         _name;
        List<IEntity *>*    _objects;

		void	setName(Json::Value name);
		void	setCamera(Json::Value camera);
		void	addObjects(Json::Value objects);

    public:
		Scene(std::string path); 
		~Scene();

		std::string     name();
		List<IEntity *>    *objects();
};

#endif