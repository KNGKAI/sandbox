#include "Character.class.hpp"

Character::Character(int id, eCharacterType type, std::string name) :
    _id(id), _type(type)
{
    _name = name;
    _entityType = Static;

}

Character::~Character()
{
}

void Character::setName(std::string name)
{
    this->_name = name; 
}

std::string Character::getName() const
{
    return (this->_name);
}


void Character::setPosition(Vector3 position)
{
    this->transform.position.x = position.x;
    this->transform.position.y = position.y;
    this->transform.position.z = position.z;
}

Vector3 Character::getPostion() const
{
    return (this->transform.position);
}

eCharacterType Character::getCharacterType() const
{
    return (_type);
}

void Character::moveUp(unsigned int units)
{
    this->transform.position.y += units;
}

void Character::moveDown(unsigned int units)
{
    this->transform.position.y -= units;
}

void Character::moveLeft(unsigned int units)
{
    this->transform.position.x += units;
}

void Character::moveRight(unsigned int units)
{
    this->transform.position.x -= units;
}

EntityType Character::getType()
{
    return (_entityType);
}

unsigned int Character::getID() const
{
    return (this->_id);
}