#ifndef TRANFORM_H
#define TRANFORM_H

#include <string>

#include "object.h"
#include "vector3.h"

class Tranform : public Object
{
    public:
        Tranform() { return; }
        ~Tranform() { return; }
        Vector3     position;
};

#endif