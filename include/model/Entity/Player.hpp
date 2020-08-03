#include "Entity.hpp"

class Player: public Entity{
    private:
    int lives;

    public:
    Player(int pPosX, int pPosY, int pLives){

        lives = pLives;
        Entity myEnt = Entity(pPosX, pPosY);
    }

//setters
    void setLives(int pLives){
        lives = pLives;
    } 

//getters
    int getLives(){
        return lives;
    }
};