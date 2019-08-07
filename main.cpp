#include <iostream>
#include "list.h"
#include "sandbox.h"

Sandbox sandbox;

int main(int ac, char ** av)
{
    Mesh m;
    while (true)
    {
        sandbox.render();
    }
    return (0);
}