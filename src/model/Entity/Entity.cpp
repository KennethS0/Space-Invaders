#include <model/Entity/Entity.hpp>

// Constructor method
Entity::Entity(char pPosX, char pPosY) {
    posx = pPosX;
    posy = pPosY;
}

// Setters
void Entity::setPosX(char pPosX) {
    posx = pPosX;
}

void Entity::setPosY(char pPosY) {
    posy = pPosY;
}

// Getters
char Entity::getPosX() {
    return posx;
}

char Entity::getPosY() {
    return posy;
}