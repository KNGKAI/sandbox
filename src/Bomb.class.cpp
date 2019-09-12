#include "Bomb.class.hpp"

Bomb::Bomb(eBombType type, unsigned int id) :
    _bombType(type),  _id(id)
{

}

Bomb::~Bomb()
{

}

void Bomb::setID(unsigned int id)
{
    this->_id = id;
}

unsigned int Bomb::getID() const
{
    return (this->_id);
}

void Bomb::setBlastRadius(unsigned int radius)
{
    _blastRadius = radius;   
}

unsigned int Bomb::getBlastRadius() const
{
    return (_blastRadius);
}

void Bomb::detonate()
{
    return;
}

EntityType Bomb::getType()
{
    return (_entityType);
}

eBombType   Bomb::getBombType() const
{
    return (this->_bombType);
}