#include <model/Entity/Entity.hpp>
#include <model/Bullet/Bullet.hpp>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player: public Entity{
    private:
        int lives;

    public:
        Player(int pPosX, int pPosY, char pSymbol, int pLives) : Entity (pPosX, pPosY, pSymbol) {
            lives = pLives;
        };

        void moveLeft();
        void moveRight();

        Bullet shoot();

        void loseLife();

        // Setters
        void setLives(int pLives);

        // Getters
        int getLives();

};

#endif