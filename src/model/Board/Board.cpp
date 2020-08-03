#include <model/Board/Board.hpp>
#include <model/Entity/Entity.hpp>
#include <model/Alien/Alien.hpp>

Board::Board() {
    score = 0;
    // Declaring the array
    for (int i = 0; i < ROW_SIZE; i++) {
        board[i] = new Entity* [COLUMN_SIZE];
    };

    // Nulling pointers
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {

            board[i][j] = nullptr;
        }
    }
}

int Board::getScore() {
    return score;
}

void Board::setScore(int pScore) {
    score = pScore;
}

Entity*** Board::getBoard() {
    return board;
}

void changePos(Alien pAlien, int posX, int posY){
    pAlien.setPosX(posX);
    pAlien.setPosY(posY);
}
