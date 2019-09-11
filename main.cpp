#include <iostream>

#include "sandbox.h"
#include "scene.h"

Scene *scene;
IObject* obj;

void Update()
{
	vec3 move(0.0f);
	float speed = 5;

	obj->transform.rotation.y += Sandbox::deltaTime() * 30.0f;

	if (Input::getKey(Key_Right, Key_State_Hold)) { scene->camera()->transform.rotation.y += 20 * Sandbox::deltaTime(); }
	if (Input::getKey(Key_Left, Key_State_Hold)) { scene->camera()->transform.rotation.y -= 20 * Sandbox::deltaTime(); }

	if (Input::getKey(Key_D, Key_State_Hold)) { move.x = 1; }
	if (Input::getKey(Key_A, Key_State_Hold)) { move.x = -1; }
	if (Input::getKey(Key_W, Key_State_Hold)) { move.z = 1; }
	if (Input::getKey(Key_S, Key_State_Hold)) { move.z = -1; }
	if (Input::getKey(Key_E, Key_State_Hold)) { move.y = 1; }
	if (Input::getKey(Key_Q, Key_State_Hold)) { move.y = -1; }
	move = scene->camera()->transform.transformDirection(move);
	scene->camera()->transform.position += move * speed * (float)Sandbox::deltaTime();
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