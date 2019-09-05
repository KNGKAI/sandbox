#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "transform.h"
#include "mesh.h"
#include "rigidbody.h"

class Object
{
    protected:
        std::string     _name;
    public:
        Object(){ return; }
        Object(std::string name) { this->_name = name; }
        ~Object() { return; }
        Transform       transform;
		Rigidbody		rigidbody;
		Mesh			mesh;
        std::string     name() { return(_name); }
        
        virtual void            start() { return; }
        virtual void            update() { return; }

        virtual EntityType     getType() = 0;
};

#endif