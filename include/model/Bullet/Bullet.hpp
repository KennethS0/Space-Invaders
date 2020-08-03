#include <model/Entity/Entity.hpp>

#ifndef BULLET_HPP
#define BULLET_HPP

class Bullet: public Entity{
    private:

    public:
    Bullet(int pPosX, int pPosY) : Entity(pPosX, pPosY){};

    void moveUp();
    void moveDown();

};

#endif