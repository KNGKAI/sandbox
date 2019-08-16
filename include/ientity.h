#ifndef IENTITY_H
#define IENTITY_H

#include <string>
#include "transform.h"
#include "mesh.h"
#include "rigidbody.h"

enum EntityType
{
    Static,
    Render,
    Physic
};

class IEntity
{
    protected:
        std::string     _name;
    public:
        Transform       transform;
		Rigidbody		rigidbody;
		Mesh			mesh;
        std::string     name() { return(_name); }
        
        virtual void            start() { return; }
        virtual void            update() { return; }

        virtual EntityType     getType() = 0;
};

#endif