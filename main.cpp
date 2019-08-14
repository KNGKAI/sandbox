#include <iostream>

#include "sandbox.h"
#include "scene.h"

void update()
{
    double speed;

    speed = 5;
    if (Input::getKey(Key_Up, Key_State_Hold)) { Camera::transform.position.y += speed * Sandbox::deltaTime(); }
    if (Input::getKey(Key_Down, Key_State_Hold)) { Camera::transform.position.y -= speed * Sandbox::deltaTime(); }
    if (Input::getKey(Key_Right, Key_State_Hold)) { Camera::transform.position.x += speed * Sandbox::deltaTime(); }
    if (Input::getKey(Key_Left, Key_State_Hold)) { Camera::transform.position.x -= speed * Sandbox::deltaTime(); }
}

int main(int ac, char ** av)
{
    Scene scene("scene/scene.json");
    
    Sandbox::init();
    while (Sandbox::running())
    {
        update();
        Sandbox::process(&scene);
    }
    return (0);
}