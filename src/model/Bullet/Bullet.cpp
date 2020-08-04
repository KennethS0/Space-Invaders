#include <model/Bullet/Bullet.hpp>

void Bullet::moveUp() {
    this->setPosY(this->getPosY() - 1);
}

void Bullet::moveDown() {
    this->setPosY(this->getPosY() + 1);
}

bool Bullet::isFromPlayer() {
    return fromPlayer;
}

void Bullet::setFromPlayer(bool pFromPlayer) {
    fromPlayer = pFromPlayer;
}
