#ifndef BOMB_H
#define BOMB_H

#include "ientity.h"

enum eBombType
{
    DEFAULT
};

class Bomb : public IEntity
{
    private:
        unsigned int         _blastRadius;
        unsigned int         _id;
        eBombType            _bombType;
        EntityType           _entityType;

    public:
        Bomb(eBombType type, unsigned int id);
        ~Bomb();
        
        void                setID(unsigned int id);
        unsigned int        getID() const;
        void                setBlastRadius(unsigned int radius);
        unsigned int        getBlastRadius() const;
        void                detonate();
        eBombType           getBombType() const;
        virtual EntityType  getType();
};
        
#endif