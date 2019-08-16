#include "scene.h"

Scene::Scene(std::string path)
{
	std::ifstream   ifs(path);
	Json::Reader    reader;
	Json::Value     file;
	Json::Value     objects;

	std::cout << "opening " << path << std::endl;
	reader.parse(ifs, file);
	this->setName(file["name"].asString());
	this->setCamera(file["camera"]);
	this->addObjects(file["objects"]);
}

void Scene::setName(Json::Value name) { this->_name = name.asString(); }

void Scene::addObjects(Json::Value objects)
{
	IEntity			*obj;
	std::string		name;

	this->_objects = new List<IEntity *>();
	for (int i = 0; i < (int)objects.size(); i++)
	{
		name = objects[i]["name"].empty() ? "object" : objects[i]["name"].asString();
		obj = new Object(name);
		if (!objects[i]["position"].empty()) { obj->transform.position = Vector3(objects[i]["position"][0].asDouble(), objects[i]["position"][1].asDouble(), objects[i]["position"][2].asDouble()); }
		if (!objects[i]["rigidbody"].empty())
		{
			obj->rigidbody.useGravity = objects[i]["rigidbody"]["useGravity"].empty() ? false : objects[i]["rigidbody"]["useGravity"].asBool();
			obj->rigidbody.mass = objects[i]["rigidbody"]["mass"].empty() ? 1 : objects[i]["rigidbody"]["mass"].asDouble();
		}
		else
		{
			obj->rigidbody.enabled = false;
		}
		this->_objects->add(obj);
		std::cout << obj->name() << " was added to scece" << std::endl;
	}
}

void Scene::setCamera(Json::Value camera)
{
	if (camera.empty())
	{
		Camera::enabled = false;
		return;
	}
	Camera::transform.position = Vector3(camera["position"][0].asDouble(), camera["position"][1].asDouble(), camera["position"][2].asDouble());
	Camera::transform.rotation = Vector3(camera["rotation"][0].asDouble(), camera["rotation"][1].asDouble(), camera["rotation"][2].asDouble());
	Camera::surface = Vector3(camera["surface"][0].asDouble(), camera["surface"][1].asDouble(), camera["surface"][2].asDouble());
	Camera::fov = camera["fov"].asDouble();
}

Scene::~Scene() { return; }

std::string Scene::name() { return (this->_name); }

List<IEntity *> *Scene::objects() { return (this->_objects); }