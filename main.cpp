#include <iostream>

#include "sandbox.h"
#include "scene.h"

Scene *scene;
IObject* obj;

void Update()
{
	float speed = 5;
	obj->transform.rotation.y += 3;
	if (Input::getKey(Key_A, Key_State_Hold)) { scene->camera()->transform.position.x -= speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_D, Key_State_Hold)) { scene->camera()->transform.position.x += speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_W, Key_State_Hold)) { scene->camera()->transform.position.z += speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_S, Key_State_Hold)) { scene->camera()->transform.position.z -= speed * Sandbox::deltaTime(); }
}

int main(int ac, char ** av)
{
    Sandbox::init();
	scene = new Scene("assets/scenes/scene.json");
	obj = scene->getObject("cyborg");
	while (Sandbox::running())
    {
		Update();
        Sandbox::process(scene);
    }
	Sandbox::destroy();
    return (0);
}