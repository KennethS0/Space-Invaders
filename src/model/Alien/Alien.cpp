#include <model/Alien/Alien.hpp>
#include <model/Bullet/Bullet.hpp>
#include <model/Board/Board.hpp>

// Movement
void Alien::moveDown() {
    this->setPosY(this->getPosY() + 1);
}

void Alien::moveRight() {
    if(this->getPosX() + 1 > COLUMN_SIZE - 1) {
        return;
    }
    this->setPosX(this->getPosX() + 1);
}

void Alien::moveLeft() {
    if (this-> getPosX() - 1 < 0) {
        return;
    }
    this->setPosX(this->getPosX() - 1);
}

Bullet Alien::shoot() {
    return Bullet(this->getPosX(), this->getPosY() + 1);
}
