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

EntityType Character::getType()
{
    return (_entityType);
}