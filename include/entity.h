#ifndef ENTITY_H
#define ENTITY_H

enum Entity_Type
{
    T_Object,
    T_Transform,
    T_Mesh
};

class IEntity
{
    public:
        virtual Entity_Type     getType() = 0;
        virtual void            start();
        virtual void            update();
};

#endif