#ifndef CHARACTER_H
#define CHARACTER_H

#include "ientity.h"
#include "characterType.enum.hpp"

    class Character : public IEntity
    {
        private:
            int                 _id;
            std::string         _name;
            Vector3             _position;
            eCharacterType      _type;

        public:
            Character(int id, eCharacterType type, std::string name);
            ~Character();
            virtual void        start();
            virtual void        update();
            virtual EntityType  getType();

            void                setName(std::string name);
            std::string         getName() const;

            void                setPosition();
            Vector3             getPostion() const;

            eCharacterType      getCharacterType();

    };
#endif