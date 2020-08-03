#include <model/Board/Board.hpp>
#include <model/Entity/Entity.hpp>

Board::Board() {
    score = 0;
    for (int i = 0; i < ROW_SIZE; i++) {
        board[i] = new Entity[ROW_SIZE];
    };
}

int Board::getScore() {
    return score;
}

void Board::setScore(int pScore) {
    score = pScore;
}

Entity** Board::getBoard() {
    return board;
}