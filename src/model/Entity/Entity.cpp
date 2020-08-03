#include <model/Entity/Entity.hpp>

// Constructor method
Entity::Entity(char pPosX, char pPosY) {
    posx = pPosX;
    posy = pPosY;
}

Entity::Entity() {
    posx = 0;
    posy = 0;
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