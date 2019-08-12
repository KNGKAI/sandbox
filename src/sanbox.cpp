#include <iostream>

#include "sandbox.h"

Scene *Sandbox::_scene = nullptr;

double Sandbox::_deltaTime = 0;

bool Sandbox::_running = false;

void Sandbox::init()
{
    if (Sandbox::running()) { return; }
    Sandbox::_running = true;
    Renderer::init();
}

void Sandbox::process(Scene *scene)
{
    float t;

    if (!Sandbox::running()) { return; }
    t = Sandbox::time();
    Sandbox::_scene = scene;
    Input::process();
    Renderer::render();
    Sandbox::_deltaTime = Sandbox::time() - t;
}

void Sandbox::destroy()
{
    if (!Sandbox::running()) { return; }
    Sandbox::_running = false;
    Renderer::destroy();
}

bool Sandbox::running() { return (Sandbox::_running); }

double Sandbox::time() { return (Sandbox::running() ? glfwGetTime() : 0); }

double Sandbox::deltaTime() { return (Sandbox::running() ? Sandbox::_deltaTime : 0); }

Scene *Sandbox::scene() { return (Sandbox::running() ? Sandbox::_scene : 0); }
