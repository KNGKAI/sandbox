#include "sandbox.h"

Scene *Sandbox::_scene = nullptr;

double Sandbox::_deltaTime = 0;

bool Sandbox::_running = false;

bool Sandbox::_pause = false;

void Sandbox::init()
{
    if (Sandbox::running()) { return; }
    Sandbox::_running = true;
    Renderer::init();
}

void Sandbox::process(Scene *scene)
{
	IObject *obj;
    double t;

    if (!Sandbox::running()) { return; }
    t = Sandbox::time();
    Sandbox::_scene = scene;
    Input::process();
	if (!Sandbox::paused())
	{
		//Physics::process();
        for (auto i = Sandbox::scene()->objects()->begin(); i != Sandbox::scene()->objects()->end(); i++) { (*i)->update(); }
	}
    Renderer::render();
    Sandbox::_deltaTime = Sandbox::time() - t;
}

void Sandbox::destroy()
{
    if (!Sandbox::running()) { return; }
    Sandbox::_running = false;
    Renderer::destroy();
}

void Sandbox::togglePause() { Sandbox::_pause = !Sandbox::_pause; }

bool Sandbox::running() { return (Sandbox::_running); }

bool Sandbox::paused() { return (Sandbox::_pause); }

double Sandbox::time() { return (Sandbox::running() ? glfwGetTime() : 0); }

double Sandbox::deltaTime() { return (Sandbox::running() ? Sandbox::_deltaTime : 0); }

Scene *Sandbox::scene() { return (Sandbox::running() ? Sandbox::_scene : 0); }
