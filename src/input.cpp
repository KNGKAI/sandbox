#include "input.h"

List<Key*> *Input::_keys = new List<Key*>();

void Input::press(EKeycode key)
{
    for (int i = 0; i < _keys->length(); i++)
    {
        if (_keys->get(i)->val == key)
        {
            if (_keys->get(i)->state == Key_State_Up) { _keys->get(i)->setState(Key_State_Hold); }
            return;
        }
    }
    _keys->add(new Key(key, Key_State_Down));
}

void Input::process()
{
    for (int i = _keys->length() - 1; i >= 0; i--)
    {
        if (_keys->get(i)->state == Key_State_Down) { _keys->get(i)->setState(Key_State_Hold); }
        else if (_keys->get(i)->state == Key_State_Hold) { _keys->get(i)->setState(Key_State_Up); }
        else if (_keys->get(i)->state == Key_State_Up) { _keys->remove(i); }
    }
}

bool Input::getKey(EKeycode key, EKeycodeState state)
{
    for (int i = 0; i < _keys->length(); i++)
    {
        if (_keys->get(i)->val == key)
        {
            if (_keys->get(i)->state == state) { return (true); }
        }
    }
    return (false);
}

List<Key*> *Input::keys() { return (Input::_keys); }