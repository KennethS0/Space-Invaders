#include <model/Entity/Entity.hpp>

// Constructor method
Entity::Entity() {
}

Entity::Entity(int pPosX, int pPosY) {
    posx = pPosX;
    posy = pPosY;
    symbol = ' ';
}

// Setters
void Entity::setPosX(int pPosX) {
    posx = pPosX;
}

void Entity::setPosY(int pPosY) {
    posy = pPosY;
}

void Entity::setSymbol(char pSymbol){
    symbol = pSymbol;
}

// Getters
int Entity::getPosX() {
    return posx;
}

int Entity::getPosY() {
    return posy;
}

char Entity::getSymbol(){
    return symbol;
}