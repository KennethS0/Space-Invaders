#ifndef GAME_HPP
#define GAME_HPP

#include <model/Alien/Alien.hpp>
#include <model/Board/Board.hpp>
#include <model/Player/Player.hpp>
#include <thread>
#include <vector>

using namespace std;

class Game {

    private:
        vector<Alien> aliens;
        vector<Bullet> bullets;
        Player player;
        Board board;
        bool over;

    public:
        Game();

        void startGame(bool inTerminal);
        
        void alienMovement();
        void bulletMovement();
        void movePlayer();

        void generateShots();
        void newLevel();

        template <class T>
        void deleteEntity(int posX, int posY, T &pVector, int pVectorPos);

        template <class T>
        void checkVector(T &pVector, int pPosX, int pPosY, int pScore);

        void setOver(bool pOver);
        bool isOver();

        Player getPlayer();

        Board getBoard();
};

#endif