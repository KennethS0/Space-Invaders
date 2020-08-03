#include <model/Entity/Entity.hpp>

// Constructor method
Entity::Entity() {
}

Entity::Entity(int pPosX, int pPosY, char pSymbol) {
    posx = pPosX;
    posy = pPosY;
    symbol = pSymbol;
}

// Setters
void Entity::setPosX(int pPosX) {
    posx = pPosX;
}

void Entity::setPosY(int pPosY) {
    posy = pPosY;
}

void Entity::setSymol(char pSymbol){
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