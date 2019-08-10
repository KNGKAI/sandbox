#include <iostream>

#include "sandbox.h"

Sandbox::Sandbox() { return; }

Sandbox::~Sandbox() { return; }

Scene *Sandbox::_scene = nullptr;

double Sandbox::_t = Sandbox::time();
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
    if (!Sandbox::running()) { return; }
    Sandbox::_scene = scene;
    Input::process();
    Render::render();
    Sandbox::_deltaTime = Sandbox::time() - Sandbox::_t;
    Sandbox::_t = Sandbox::time();
}

void Sandbox::destroy()
{
    if (!Sandbox::running()) { return; }
    Sandbox::_running = false;
    Render::destroy();
}

bool Sandbox::running() { return (Sandbox::_running); }

double Sandbox::time() { return (Sandbox::running() ? glfwGetTime() : 0); }

double Sandbox::deltaTime() { return (Sandbox::running() ? Sandbox::_deltaTime : 0); }

Scene *Sandbox::scene() { return (Sandbox::running() ? Sandbox::_scene : 0); }
