#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
  private:
    char posx;
    char posy;
  
  public:
    Entity();
    Entity(char pPosX, char pPosY);

    void setPosX(char pPosX);
    void setPosY(char pPosY);

    char getPosX();
    char getPosY();
};

#endif