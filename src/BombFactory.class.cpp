#include "BombFactory.class.hpp"

BombFactory::BombFactory()
{
    bombsCreated = 0;
}

BombFactory::~BombFactory()
{

}

Bomb * BombFactory::createBomb(eBombType type)
{
    return (new Bomb(type, bombsCreated++));
}