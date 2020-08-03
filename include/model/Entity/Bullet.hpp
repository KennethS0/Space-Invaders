#include "Entity.hpp"

class Bullet: public Entity{
    private:
    int velocity;

    public:
    Bullet(int pPosX, int pPosY, int pVelocity){

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