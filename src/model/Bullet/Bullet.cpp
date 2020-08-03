#include <model/Bullet/Bullet.hpp>
#include <iostream>
using namespace std;

void Bullet::moveUp() {
    this->setPosY(this->getPosY() - 1);
}

void Bullet::moveDown() {
    this->setPosY(this->getPosY() + 1);
}

void printBullet(){
    cout<<'|';
}