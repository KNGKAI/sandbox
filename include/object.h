#ifndef OBJECT_H
#define OBJECT_H

#include <string>

enum Object_Type
{
    T_Object,
    T_Transform,
    T_Mesh
};

class Object
{
    protected:
        std::string     _name;
    public:
        Object() : _name("object") { return; }
        Object(std::string name) : _name(name) { return; }
        ~Object() { return; }
        std::string     name() { return(_name); }

        // virtual void start();
        // virtual void update();
        // virtual void fixeeUpdate();

        virtual Object_Type type() { return(T_Object); }
};

#endif