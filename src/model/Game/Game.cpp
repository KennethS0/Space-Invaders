#include <model/Game/Game.hpp>

#include <iostream>
#include <thread>

using namespace std;

Game::Game() {
    over = false;
    
    // Initializing aliens
    for (int i = 3; i < COLUMN_SIZE - 3; i++) {

        for (int j = 0; j < 4; j++) {
            aliens.push_back(Alien(j, i));
        };
    };

    // Initializing Player
    player = Player(ROW_SIZE - 1, (int) (COLUMN_SIZE / 2 - 1), 3);

    // Initializing Board
    board = Board();

    // Setting the aliens in the board
    for (auto &it : aliens) {
       board.getBoard()[it.getPosY()][it.getPosX()] = (Entity *)&it;
    };

    // Setting the player in the board
    board.getBoard()[player.getPosY()][player.getPosX()] = &player;
}

void Game::movePlayer() {
            
    char keyPressed;

    while (!over){
        int x = player.getPosX();

        keyPressed = getchar();

        if (keyPressed == 'a') {
            // Moves the player to the left
            player.moveLeft();
            board.changePos(player, x, player.getPosY());
        } 
        else if (keyPressed == 'd') {
            // Moves the player to the right
            player.moveRight();
            board.changePos(player, x, player.getPosY());
        }
        else if (keyPressed == ' ') {
            // Shoots
            Bullet shot = player.shoot();
            shot.setFromPlayer(true);
            bullets.push_back(shot);

            board.getBoard()[shot.getPosY()][shot.getPosX()] = &shot;
        }
    }
}


void Game::startGame() {
    // Initial game set up

    thread movement(&Game::movePlayer, this);
    movement.detach();

    while (!over) {
        // Keeps refreshing the screen
        board.printBoard();
        
        system("clear");
    }   
}

void Game::setOver(bool pOver) {
    over = pOver;
}

bool Game::isOver() {
    return over;
}