#include "Entity.hpp"

class Alien: public Entity{
    private:
    int velocity;

    public:
    Alien(int pPosX, int pPosY, int pVelocity){

        velocity = pVelocity;
        Entity myEnt = Entity(pPosX, pPosY);
    }

//setters
    void setVelocity(int pVelocity){
        velocity = pVelocity;
    } 

//getters
    int getVelocity(){
        return velocity;
    }
};


