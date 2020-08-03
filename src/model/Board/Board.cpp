#include <model/Board/Board.hpp>
#include <model/Entity/Entity.hpp>

Board::Board() {
    score = 0;
}

int Board::getScore() {
    return score;
}

void Board::setScore(int pScore) {
    score = pScore;
}