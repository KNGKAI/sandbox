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
            int                 _id;
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

            eCharacterType      getCharacterType() const;

    };
#endif