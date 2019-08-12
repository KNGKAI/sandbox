#ifndef OBJECT_H
#define OBJECT_H

#include "ientity.h"

class Object : public IEntity
{
    public:
        Object(){ return; }
        Object(std::string name) { this->_name = name; }
        ~Object() { return; }

        EntityType getType() { return(Static); }
};

#endif