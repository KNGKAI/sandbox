#ifndef OBJECT_H
#define OBJECT_H

#include "icomponent.h"
#include "model.h"
#include "transform.h"
#include "system.h"

class IObject : public IComponent
{
    public:
        IObject() : name("object") { return; }
        IObject(std::string name) : name(name) { return; }
        ~IObject() { return; }

        string          name;
        Transform       transform;
		Model			model;
        
        virtual void    start() { return; }
        virtual void    update() { return; }
};

#endif