#include <iostream>

#include "sandbox.h"

Sandbox::Sandbox() { return; }

Sandbox::~Sandbox() { return; }

Scene *Sandbox::_scene = nullptr;

double Sandbox::_deltaTime = 0;

bool Sandbox::_running = false;

void Sandbox::init()
{
    if (Sandbox::running()) { return; }
    Sandbox::_running = true;
    Render::init();
}

void Sandbox::process(Scene *scene)
{
    double t;

    if (!Sandbox::running()) { return; }
    t = Sandbox::time();
    Sandbox::_scene = scene;
    Input::process();
    Render::render();
    Sandbox::_deltaTime = Sandbox::time() - t;
}

void Sandbox::destroy()
{
    if (!Sandbox::running()) { return; }
    Sandbox::_running = false;
    Render::destroy();
    return;
}

bool Sandbox::running()
{
    return (Sandbox::_running);
}

double Sandbox::time()
{
    if (!Sandbox::running()) { return(0); }
    return (glfwGetTime());
}

double Sandbox::deltaTime()
{
    if (!Sandbox::running()) { return(0); }
    return (Sandbox::_deltaTime);
}

Scene *Sandbox::scene()
{
    if (!Sandbox::running()) { return (nullptr); }
    return (Sandbox::_scene);
}
