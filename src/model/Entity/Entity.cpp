#include <include/model/Entity/Entity.hpp>
using namespace std;
// Constructor method
Entity(char pPosX, char pPosY) {
    posx = pPosX;
    posy = pPosY;
}

// Setters
void setPosX(char pPosX) {
    posx = pPosX;
}

void setPosY(char pPosY) {
    posy = pPosY;
}

// Getters
char getPosX() {
    return posx;
}

char getPosY() {
    return posy;
}