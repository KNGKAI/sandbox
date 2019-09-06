#include <iostream>

#include "sandbox.h"
#include "scene.h"

Scene scene("scene/scene.json");

int main(int ac, char ** av)
{
    Sandbox::init();
	while (Sandbox::running())
    {
        Sandbox::process(&scene);
    }
    return (0);
}