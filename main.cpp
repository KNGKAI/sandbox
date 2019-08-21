#include <iostream>

#include "sandbox.h"
#include "scene.h"

Scene scene("scene/scene.json");
IEntity *player;
IEntity *monkey;

void start()
{
	player = new Object("Player");
	player->mesh = Mesh::Reader::loadMesh("mesh/cube.obj");
	player->mesh.color = Vector3(0.5, 0.5, 1.0);
	scene.addObject(player);
	monkey = scene.getObject("monkey_object");
}

void update()
{
    double speed;

    speed = 5;
	if (Input::getKey(Key_Up, Key_State_Hold)) { player->transform.position.z += speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_Down, Key_State_Hold)) { player->transform.position.z -= speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_Right, Key_State_Hold)) { player->transform.position.x += speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_Left, Key_State_Hold)) { player->transform.position.x -= speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_Q, Key_State_Down)) { player->rigidbody.velocity.y = speed * 2; }

	if (Input::getKey(Key_P, Key_State_Hold)) { Camera::surface.z += Sandbox::deltaTime(); }
	if (Input::getKey(Key_O, Key_State_Hold)) { Camera::surface.z -= Sandbox::deltaTime(); }
	
	if (Input::getKey(Key_W, Key_State_Hold)) { Renderer::sun.z += Sandbox::deltaTime(); }
	if (Input::getKey(Key_S, Key_State_Hold)) { Renderer::sun.z -= speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_D, Key_State_Hold)) { Renderer::sun.x += speed * Sandbox::deltaTime(); }
	if (Input::getKey(Key_A, Key_State_Hold)) { Renderer::sun.x -= speed * Sandbox::deltaTime(); }

	monkey->transform.rotation.y += 30 * Sandbox::deltaTime();
}

int main(int ac, char ** av)
{
    Sandbox::init();
	start();
	while (Sandbox::running())
    {
		update();
        Sandbox::process(&scene);
    }
    return (0);
}