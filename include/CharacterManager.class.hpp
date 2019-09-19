#include <list>
#include "Character.class.hpp"
#include "CharacterFactory.class.hpp"

class CharacterManager 
{
    private:
        std::list<Character *>  _characters;
        CharacterFactory *        _factory;

    CharacterManager();
    ~CharacterManager();
    void addCharacter(eCharacterType type, std::string name);
    void removeCharacter(unsigned int id);
    std::list<Character *> getCharacters() const;
    Character * getCharacter(unsigned int id);
};