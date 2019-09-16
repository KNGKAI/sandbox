#include "scene.h"

Scene::Scene(std::string path) : _sun(-0.3, -0.5, 0.2)
{
	std::ifstream   ifs(path);
	Json::Reader    reader;
	Json::Value     file;
	Json::Value     objects;

	message("opening scene: " + path);
	reader.parse(ifs, file);
	this->_skybox = Skybox();
	this->setName(file["name"].empty() ? "undefined" : file["name"].asString());
	if (!file["camera"].empty()) { this->setCamera(file["camera"]); }
	if (!file["objects"].empty()) { this->addObjects(file["objects"]); }
}

void Scene::setName(Json::Value name)
{
	this->_name = name.asString();
	message("scene name set: " + name.asString());
}

void Scene::addObjects(Json::Value objects)
{
	IObject			*obj;
	std::string		name;

	for (int i = 0; i < (int)objects.size(); i++)
	{
		name = objects[i]["name"].empty() ? "object" : objects[i]["name"].asString();
		obj = new IObject(name);
		if (!objects[i]["position"].empty()) { obj->transform.position = vec3(objects[i]["position"][0].asFloat(), objects[i]["position"][1].asFloat(), objects[i]["position"][2].asFloat()); }
		if (!objects[i]["rotation"].empty()) { obj->transform.rotation = vec3(objects[i]["rotation"][0].asFloat(), objects[i]["rotation"][1].asFloat(), objects[i]["rotation"][2].asFloat()); }
		if (!objects[i]["scale"].empty()) { obj->transform.scale = vec3(objects[i]["scale"][0].asFloat(), objects[i]["scale"][1].asFloat(), objects[i]["scale"][2].asFloat()); }
		if (!objects[i]["model"].empty())
		{
			obj->model.gammaCorrection = true;
			obj->model.loadModel(objects[i]["model"].asString());
		}
		else
		{
			obj->model.enabled = false;
		}
		Scene::addObject(obj);
	}
}

void Scene::setCamera(Json::Value camera)
{
	this->_camera = Camera();
	this->_camera.transform.position = vec3(camera["position"][0].asDouble(), camera["position"][1].asDouble(), camera["position"][2].asDouble());
	this->_camera.transform.rotation = vec3(camera["rotation"][0].asDouble(), camera["rotation"][1].asDouble(), camera["rotation"][2].asDouble());
	this->_camera.nearPlane = camera["nearPlane"].asFloat();
	this->_camera.farPlane = camera["farPlane"].asFloat();
	this->_camera.zoom = camera["zoom"].asFloat();
	message("scene camera enabled");
}

Scene::~Scene() { return; }

Camera* Scene::camera() { return (&this->_camera); }

std::string Scene::name() { return (this->_name); }

vector<IObject *> *Scene::objects() { return (&this->_objects); }

Skybox* Scene::skybox() { return (&this->_skybox); }

vec3 Scene::sun() { return (this->_sun); }

void Scene::addObject(IObject *object)
{
	this->_objects.push_back(object);
	message(object->name + ", was added to scene: " + this->_name);
}

IObject *Scene::getObject(std::string name)
{
	IObject *obj;

	for (auto i = this->_objects.begin(); i != this->_objects.end(); i++)
	{
		obj = *i;
		if (obj->name == name) return (obj);
	}
	
	return (nullptr);
}