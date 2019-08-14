#ifndef INPUT_H
#define INPUT_H

#include "list.h"

enum EKeycode
{
    Key_Up,
    Key_Down,
    Key_Left,
    Key_Right,
    Key_Esc
};

enum EKeycodeState
{
    Key_State_Down,
    Key_State_Hold,
    Key_State_Up
};

struct Key
{
    EKeycode val;
    EKeycodeState state;

    Key() { return; }
    Key(EKeycode val, EKeycodeState state) : val(val), state(state) { return; }
    ~Key() { return; }

    void setState(EKeycodeState s) { this->state = s; }
};

class Input
{
    private:
        static List<Key*>*   _keys;
    public:
        static void         press(EKeycode key);
        static void         process();
        static bool         getKey(EKeycode key, EKeycodeState state);
        static List<Key*>*  keys();
};

#endif