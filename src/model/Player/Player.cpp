#include <model/Player/Player.hpp>
#include <model/Bullet/Bullet.hpp>
#include <model/Board/Board.hpp>

Player::Player(){}

void Player::moveLeft() {
    if (this->getPosX() - 1 < 0) {
        return;
    }
    this->setPosX(this->getPosX() - 1);
}

void Player::moveRight() {
    if (this->getPosX() + 1 > COLUMN_SIZE - 1) {
        return;
    }
    this->setPosX(this->getPosX() + 1);
}

Bullet Player::shoot() {
    return Bullet(this->getPosY() - 1, this->getPosX());
}
