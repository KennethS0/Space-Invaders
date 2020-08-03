#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
  private:
    int posx;
    int posy;
  
  public:
    Entity();
    Entity(int pPosX, int pPosY);

    void setPosX(int pPosX);
    void setPosY(int pPosY);

    int getPosX();
    int getPosY();
};

#endif