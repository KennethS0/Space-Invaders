#include <model/Entity/Entity.hpp>
#include <model/Bullet/Bullet.hpp>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player: public Entity{
    private:
        int lives;

    public:
        Player();

        Player(int pPosX, int pPosY) : Entity (pPosX, pPosY) {
            this->setSymbol('M');
        };

        void moveLeft();
        void moveRight();

        Bullet shoot();
};

#endif