#ifndef __BOMB_FACTORY__
#define __BOMB_FACTORY__

#include "Bomb.class.hpp"

class BombFactory
{
    private:
        static int bombsCreated;

    public:
        BombFactory(/* args */);
        ~BombFactory();

        Bomb * createBomb(eBombType type);
};

#endif