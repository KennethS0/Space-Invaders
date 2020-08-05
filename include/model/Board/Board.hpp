#include <model/Entity/Entity.hpp>

#ifndef BOARD_HPP
#define BOARD_HPP

#define COLUMN_SIZE 20
#define ROW_SIZE 16

class Board {
    private:
        Entity*** board= new Entity** [ROW_SIZE];
        int score;    
        int lives;

    public:
        Board();

        int getScore();
        void setScore(int pScore);

        void printBoard();      

        void changePos(Entity& pEnt, int pOldX, int pOldY);
        void clearPos(int pOldX, int pOldY);

        Entity*** getBoard();

        int getLives();
        void setLives(int pLives);
        void loseLife();
        
};


#endif