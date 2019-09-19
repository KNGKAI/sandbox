#ifndef CHARACTER_H
#define CHARACTER_H

#include "ientity.h"

    enum eCharacterType
    {
        PLAYER,
        AI
    };

    class Character : public IEntity
    {
        private:
            unsigned int		_id;
            eCharacterType      _type;
            EntityType          _entityType;

        public:
            Character(int id, eCharacterType type, std::string name);
            ~Character();

            virtual void        start();
            virtual void        update();
            virtual EntityType  getType();

            void                setName(std::string name);
            std::string         getName() const;

            void                setPosition(Vector3 position);
            Vector3             getPostion() const;
            
            void                moveUp(unsigned int units);
            void                moveDown(unsigned int units);
            void                moveRight(unsigned int units);
            void                moveLeft(unsigned int units);
            eCharacterType      getCharacterType() const;
			unsigned int 		getID() const;
    };
#endif