#include <model/Entity/Entity.hpp>

#ifndef BULLET_HPP
#define BULLET_HPP

class Bullet: public Entity{
    private:
        bool fromPlayer;


    public:
    Bullet(int pPosX, int pPosY) : Entity(pPosX, pPosY){
        this->setSymbol('*');
    };

    void moveUp();
    void moveDown();

    bool isFromPlayer();
    void setFromPlayer(bool pFromPlayer);
};

#endif