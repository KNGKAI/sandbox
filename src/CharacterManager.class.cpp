#include "CharacterManager.class.hpp"


CharacterManager::CharacterManager() 
{
    _factory = new CharacterFactory();
}

CharacterManager::~CharacterManager()
{
    if (_characters.empty() == false) 
    {
        _characters.clear();
    }
}

void CharacterManager::addCharacter(eCharacterType type, std::string name) 
{
    Character *newCharacter = _factory->newCharacter(name, type);
    _characters.push_back(newCharacter);
}

std::list<Character *> CharacterManager::getCharacters() const
{
    return (_characters);
} 

Character * CharacterManager::getCharacter(unsigned int id) 
{
    for ( Character * character : _characters)
    {
        if (character->getID() ==  id)
        {
            _characters.remove(character);
        }
    }
}