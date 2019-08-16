#include <iostream>

#include "sandbox.h"
#include "scene.h"

Scene scene("scene/scene.json");
IEntity *player;
/*
void start()
{
	player = new Object("Player");
	player->mesh.verticies.clear();
	player->mesh.triangles.clear();
	player->mesh.verticies.add();
	player->mesh.triangles.add();
	player->transform.position.y = 0.5;
	scene.objects()->add(player);
}*/

void update()
{
    double speed;

    speed = 5;
	//if (
	if (glfwWindowShouldClose(Renderer::window())) { std::exit(0); }
}

int main(int ac, char ** av)
{
	//start();
    Sandbox::init();
    while (Sandbox::running())
    {
        Sandbox::process(&scene);
		update();
    }
    return (0);
}