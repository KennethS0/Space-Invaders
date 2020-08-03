#include <model/Entity/Entity.hpp>
#include <model/Bullet/Bullet.hpp>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player: public Entity{
    private:
        char lives;

    public:
        Player(char pPosX, char pPosY, char pLives) : Entity (pPosX, pPosY) {
            lives = pLives;
        };

        void moveLeft();
        void moveRight();

        Bullet shoot();

        void loseLife();

        // Setters
        void setLives(char pLives);

        // Getters
        char getLives();
};

#endif