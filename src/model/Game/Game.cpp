#include <model/Game/Game.hpp>

#include <iostream>

using namespace std;

Game::Game() {

    // Initializing aliens
    for (int i = 3; i < COLUMN_SIZE - 3; i++) {

        for (int j = 0; j < 4; j++) {
            aliens.push_back(Alien(j, i));
        };
    };

    // Initializing Player
    player = Player(ROW_SIZE - 1, (int) (COLUMN_SIZE / 2), 3);

    // Initializing Board
    board = Board();

    // Setting the aliens in the board
    for (auto it : aliens) {
       board.getBoard()[it.getPosX()][it.getPosY()] = &it;
    };

    // Setting the player in the board
    board.getBoard()[player.getPosX()][player.getPosY()] = &player;
    board.printBoard();
}