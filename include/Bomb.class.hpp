#ifndef BOMB_H
#define BOMB_H

#include "ientity.h"

class Bomb : public IEntity
{
    private:
        int         _blastRadius;
        int         _id;

    public:
        Bomb(/* args */);
        ~Bomb();

        void    setBlastRadius();
        int     getBlastRadius();
        void    detonate();
};
        
#endif