#ifndef INPUT_H
#define INPUT_H

#include "list.h"

enum EKeycode
{
    Key_Up,
    Key_Down,
    Key_Left,
    Key_Right,
    Key_Esc,
	Key_A,
	Key_B,
	Key_C,
	Key_D,
	Key_E,
	Key_F,
	Key_G,
	Key_H,
	Key_I,
	Key_J,
	Key_K,
	Key_L,
	Key_M,
	Key_N,
	Key_O,
	Key_P,
	Key_Q,
	Key_R,
	Key_S,
	Key_T,
	Key_U,
	Key_V,
	Key_W,
	Key_X,
	Key_Y,
	Key_Z
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
        static List<Key*>		_keys;
    public:
        static void         	press(EKeycode key);
        static void         	process();
        static bool         	getKey(EKeycode key, EKeycodeState state);
        static List<Key*>*		keys();
};

#endif