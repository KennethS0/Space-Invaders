#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
  private:
    int posx;
    int posy;
    char symbol;
  
  public:
    Entity();
    Entity(int pPosX, int pPosY, char pSymbol);

    void setPosX(int pPosX);
    void setPosY(int pPosY);
    void setSymol(char pSymbol);

    int getPosX();
    int getPosY();
    char getSymbol();
};

#endif