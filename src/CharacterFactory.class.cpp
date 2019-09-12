#include "CharacterFactory.class.hpp"

CharacterFactory::CharacterFactory() 
{
    _charactersMade = 0;
}

CharacterFactory::~CharacterFactory()
{
}

Character * CharacterFactory::newCharacter(std::string name, eCharacterType type)
{
    return (new Character(_charactersMade++, type, name));
}