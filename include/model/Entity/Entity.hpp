#define ENTITY_HPP

class Entity {
  private:
    char posx;
    char posy;
  
  public:
    Entity(char pPosX, char pPosY);

    void setPosX(char pPosX);
    void setPosY(char pPosY);

    char getPosX();
    char getPosY();
  
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
};

