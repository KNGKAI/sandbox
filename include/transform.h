#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>

#include "object.h"
#include "vector3.h"

class Transform : public Object
{
    public:
        Transform() { return; }
        Transform(std::string name)
        {
            this->_name = name;
            return;
        }
        ~Transform() { return; }
        Vector3     position;
        Vector3     rotation;
        Vector3     scale;

        Object_Type type() { return(T_Transform); }
};

#endif