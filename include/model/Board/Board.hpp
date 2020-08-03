#include <model/Entity/Entity.hpp>

#ifndef BOARD_HPP
#define BOARD_HPP

#define COLUMN_SIZE 20
#define ROW_SIZE 16

class Board {
    private:
        Entity* board[COLUMN_SIZE][ROW_SIZE];
        int score;    

    public:
        Board();

        int getScore();
        void setScore(int pScore);
};


#endif