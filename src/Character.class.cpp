#include "Character.class.hpp"

Character::Character(int id, eCharacterType type, std::string name) :
    _id(id), _type(type), _name(name);
{
}

Character::~Character()
{
}
