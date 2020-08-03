#include <model/Player/Player.hpp>
#include <model/Bullet/Bullet.hpp>

void Player::moveLeft() {
    this->setPosX(this->getPosX() - 1);
}

void Player::moveRight() {
    this->setPosX(this->getPosX() + 1);
}

Bullet Player::shoot() {
    return Bullet(this->getPosX(), this->getPosY() - 1);
}

void Player::setLives(int pLives) {
    this->lives = pLives;
}

int Player::getLives() {
    return lives;
}

void Player::loseLife() {
    this->setLives(this->getLives() - 1);
}