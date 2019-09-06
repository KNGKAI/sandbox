#include "input.h"

vector<Key *> Input::_keys = vector<Key *>();

void Input::press(EKeycode key)
{
    Key *k;

    for (auto i = Input::_keys.begin(); i != Input::_keys.end(); i++)
    {
        k = *i;
        if (k->val == key)
        {
            if (k->state == Key_State_Up) { k->setState(Key_State_Hold); }
            return;
        }
    }
    Input::_keys.push_back(new Key(key, Key_State_Down));
}

void Input::process()
{
    Key *k;
    
    for (auto i = Input::_keys.begin(); i != Input::_keys.end(); i++)
    {
        k = *i;
        switch (k->state)
        {
        case Key_State_Down: k->setState(Key_State_Hold); break;
        case Key_State_Hold: k->setState(Key_State_Hold); break;
        case Key_State_Up: Input::_keys.erase(i); break;
        default: break;
        }
    }
}

bool Input::getKey(EKeycode key, EKeycodeState state)
{
    Key *k;
    
    for (auto i = Input::_keys.begin(); i != Input::_keys.end(); i++)
    {
        k = *i;
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

vector<Key*> *Input::keys() { return (&Input::_keys); }