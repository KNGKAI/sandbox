#include <iostream>

#include "sandbox.h"
#include "scene.h"

Sandbox sandbox;

int main(int ac, char ** av)
{
    Scene scene("scene/scene.json");
    
    while (true)
    {
        sandbox.process(&scene);
    }
    return (0);
}