#include <model/Alien/Alien.hpp>
#include <model/Bullet/Bullet.hpp>

// Movement
void Alien::moveDown() {
    this->setPosY(this->getPosY() + 1);
}

void Alien::moveRight() {
    this->setPosX(this->getPosX() + 1);
}

void Alien::moveLeft() {
    this->setPosX(this->getPosX() - 1);
}

Bullet Alien::shoot() {
    return Bullet(this->getPosX(), this->getPosY() + 1, this->getSymbol());
}
