#include "input.h"

List<Key *> Input::_keys = List<Key *>();

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
    
    for (int i = Input::keys()->length() - 1; i >= 0; i--)
    {
        k = Input::keys()->get(i);
        switch (k->state)
        {
        case Key_State_Down: k->setState(Key_State_Hold); break;
        case Key_State_Hold: k->setState(Key_State_Hold); break;
        case Key_State_Up: Input::_keys.remove(i); break;
        default: break;
        }
    }
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

List<Key*> *Input::keys() { return (&Input::_keys); }