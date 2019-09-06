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
	IObject			*obj;
	std::string		name;

	for (int i = 0; i < (int)objects.size(); i++)
	{
		name = objects[i]["name"].empty() ? "object" : objects[i]["name"].asString();
		obj = new IObject(name);
		if (!objects[i]["position"].empty()) { obj->transform.position = vec3(objects[i]["position"][0].asDouble(), objects[i]["position"][1].asDouble(), objects[i]["position"][2].asDouble()); }
		if (!objects[i]["rotation"].empty()) { obj->transform.rotation = vec3(objects[i]["rotation"][0].asDouble(), objects[i]["rotation"][1].asDouble(), objects[i]["rotation"][2].asDouble()); }
		if (!objects[i]["rigidbody"].empty())
		{
			//obj->rigidbody.useGravity = objects[i]["rigidbody"]["useGravity"].empty() ? false : objects[i]["rigidbody"]["useGravity"].asBool();
			//obj->rigidbody.mass = objects[i]["rigidbody"]["mass"].empty() ? 1 : objects[i]["rigidbody"]["mass"].asDouble();
		}
		else
		{
			//obj->rigidbody.enabled = false;
		}
		if (!objects[i]["mesh"].empty())
		{
			//obj->mesh = Mesh::Reader::loadMesh(objects[i]["mesh"].asString());
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
	if (camera.empty())
	{
		Camera::enabled = false;
		return;
	}
	Camera::transform.position = vec3(camera["position"][0].asDouble(), camera["position"][1].asDouble(), camera["position"][2].asDouble());
	Camera::transform.rotation = vec3(camera["rotation"][0].asDouble(), camera["rotation"][1].asDouble(), camera["rotation"][2].asDouble());
	Camera::surface = vec3(camera["surface"][0].asDouble(), camera["surface"][1].asDouble(), camera["surface"][2].asDouble());
	Camera::fov = camera["fov"].asDouble();
}

Scene::~Scene() { return; }

std::string Scene::name() { return (this->_name); }

vector<IObject *> *Scene::objects() { return (&this->_objects); }

void Scene::addObject(IObject *object)
{
	this->_objects.push_back(object);
	std::cout << object->name << " was added to scene: " << this->_name << std::endl;
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