#include <model/Board/Board.hpp>
#include <model/Entity/Entity.hpp>
#include <model/Alien/Alien.hpp>

#include <iostream>

using namespace std;

Board::Board() {
    score = 0;
    lives = 3;
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

void Board::changePos(Entity& pEnt, int pOldX, int pOldY) {
    // Removes the pointer
    this->getBoard()[pOldY][pOldX] = nullptr;

    // Creates a pointer at a new position
    this->getBoard()[pEnt.getPosY()][pEnt.getPosX()] = &pEnt;
}

void Board::clearPos(int pOldX, int pOldY) {
    // Removes the pointer
    this->getBoard()[pOldY][pOldX] = nullptr;
}

void Board::printBoard() {
    for (int i = 0; i < ROW_SIZE; i++) {
        cout << '|';

        for (int j = 0; j < COLUMN_SIZE; j++) {
            // NULLPTR IS FOUND
            if (board[i][j] == nullptr) {
                cout << ' ';
            } else {
                cout << board[i][j]->getSymbol();
            };
        };

        cout<< '|' << endl;
    };
    cout << "\nScore:" << score << endl;
    cout << "Lives:" << lives << endl;
}


void Board::setLives(int pLives) {
    this->lives = pLives;
}

int Board::getLives() {
    return lives;
}

void Board::loseLife() {
    this->setLives(this->getLives() - 1);
}
