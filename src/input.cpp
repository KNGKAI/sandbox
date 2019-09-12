#include "input.h"
#include "renderer.h"

List<Key *> Input::_keys = List<Key *>();

vec2 Input::_mousePrev = vec2(0.0f);

vec2 Input::_mouseOffset = vec2(0.0f);

void Input::press(EKeycode key)
{
    Key *k;

    for (int i = 0; i < Input::keys()->length(); i++)
    {
        k = Input::_keys.get(i);
        if (k->val == key)
        {
            if (k->state == Key_State_Up) { k->setState(Key_State_Hold); }
            return;
        }
    }
    Input::_keys.add(new Key(key, Key_State_Down));
}

void Input::process()
{
    Key *k;
    double x;
    double y;
    
    for (int i = Input::keys()->length() - 1; i >= 0; i--)
    {
        k = Input::keys()->get(i);
        switch (k->state)
        {
        case Key_State_Down: k->setState(Key_State_Hold); break;
        case Key_State_Hold: k->setState(Key_State_Up); break;
        case Key_State_Up: Input::_keys.remove(i); break;
        default: break;
        }
    }
    glfwGetCursorPos(Renderer::window(), &x, &y);
    Input::_mouseOffset.x = x - Input::_mousePrev.x;
    Input::_mouseOffset.y = Input::_mousePrev.y - y;
    Input::_mousePrev.x = (float)x;
    Input::_mousePrev.y = (float)y;
}

bool Input::getKey(EKeycode key, EKeycodeState state)
{
    Key *k;
    
    for (int i = Input::keys()->length() - 1; i >= 0; i--)
    {
        k = Input::keys()->get(i);
        if (k->val == key)
        {
            if (k->state == state)
            {
                return (true);
            }
        }
    }
    return (false);
}

float Input::getMouseX() { return (Input::_mouseOffset.x); }

float Input::getMouseY() { return (Input::_mouseOffset.y); }

List<Key*> *Input::keys() { return (&Input::_keys); }