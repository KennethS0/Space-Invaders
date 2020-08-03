#include <model/Entity/Entity.hpp>
#include <model/Bullet/Bullet.hpp>

#ifndef ALIEN_HPP
#define ALIEN_HPP

class Alien: public Entity{
    private:

    public:
        Alien(int pPosX, int pPosY) : Entity(pPosX, pPosY){};
        
        Bullet shoot();

        void moveDown();
        void moveRight();
        void moveLeft();
};

#endif