#include <iostream>

#include "sandbox.h"
#include "scene.h"

int main(int ac, char ** av)
{
    Scene scene("scene/scene.json");
    
    Sandbox::init();
    while (Sandbox::running())
    {
        Sandbox::process(&scene);
    }
    return (0);
}