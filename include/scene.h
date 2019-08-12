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

class Scene
{
    private:
        std::string         _name;
        Camera              _camera;
        List<IEntity *>*    _objects;

    public:
        Scene() { return; }
        Scene(std::string path)
        {
            std::ifstream   ifs(path);
            Json::Reader    reader;
            Json::Value     file;
            Json::Value     objects;

            std::cout << "opening " << path << std::endl;
            reader.parse(ifs, file);
            objects = file["objects"];
            this->_name = file["name"].asString();
            this->_objects = new List<IEntity *>();
            for (int i = 0; i < objects.size(); i++)
            {
                if (objects[i]["type"].asString() == "object") { this->_objects->add(new Object(objects[i]["name"].asString())); }
                std:: cout << objects[i]["name"].asString() << " (" << objects[i]["type"].asString() << ") was added to scece" << std::endl;
            }
            return;
        }
        ~Scene()
        {
            return;
        }
        std::string     name()
        {
            return (this->_name);
        }
        List<IEntity *>    *objects()
        {
            return (this->_objects);
        }
        Camera camera()
        {
            return (this->_camera);
        }
};

#endif