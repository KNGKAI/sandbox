#ifndef __CHARACTER_FACTORY__
#define __CHARACTER_FACTORY__

#include "Character.class.hpp"

class CharacterFactory
{
    private:
        static unsigned _charactersMade;

    public:
        CharacterFactory(/* args */);
        ~CharacterFactory();

        Character * newCharacter(std::string name, eCharacterType type);
};


#endif