#include <model/Game/Game.hpp>

#include <iostream>
#include <thread>
#include <cstdlib>
#include <unistd.h>

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
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }
}


void Game::alienMovement() {
    // 0 Leftmost
    // 0 Rightmost
    int boundaries[2] = {-1, -1};

    // false -> (move right)
    // true <- (move left)
    bool direction = false;
    while (!over) {

        // Finds the boundaries
        for (auto &it: aliens) {
            if (it.getPosX() < boundaries[0] || boundaries[0] == -1) {
                // Finds the leftmost
                boundaries[0] = it.getPosX();
            }
            if (it.getPosX() > boundaries[1] || boundaries[1] == -1) {
                // Finds the rightmost
                boundaries[1] = it.getPosX();
            }
            if (it.getPosY() == ROW_SIZE - 1) {
                over = true;
                continue;
            }
            board.getBoard()[it.getPosY()][it.getPosX()] = nullptr;
        };

        if (boundaries[0] == 0 || boundaries[1] == COLUMN_SIZE - 1) {
            for (auto &it: aliens) {
                it.moveDown();
            }
            direction = !direction;
        }

        // Moving every alien
        for (auto &it: aliens) {
            if (!direction) {
                it.moveRight();
            } else {
                it.moveLeft();
            }     
        }

        // Redrawing the aliens
        for (auto &it: aliens) {
            board.getBoard()[it.getPosY()][it.getPosX()] = (Entity*) &it;
        };

        this_thread::sleep_for(chrono::milliseconds(900));
        boundaries[0] = -1;
        boundaries[1] = -1;   
    }
}


void Game::bulletMovement() {
    while (!over) {
        if (bullets.size() != 0) {
            for (auto &it: bullets) {
                int posX = it.getPosX();
                int posY = it.getPosY();

                if (it.isFromPlayer()) {
                    it.moveUp();
                } else {
                    it.moveDown();
                }
                
                if (board.getBoard()[it.getPosY()][it.getPosX()] == nullptr) {
                    board.changePos(it, posX, posY);
                
                } else {
                    // Remove alien from vector
                    if(board.getBoard()[it.getPosY()][it.getPosX()] != nullptr){
                        (board.getBoard()[it.getPosY()][it.getPosX()] = nullptr);
                        board.clearPos(it, posX, posY);
                       
                    }
                    // Remove bullet from vector

                    // Remove both pointers
                }
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
}


void Game::startGame(bool inTerminal) {
    // Initial game set up
    thread playerMovement(&Game::movePlayer, this);
    playerMovement.detach();

    thread alienMovement(&Game::alienMovement, this);
    alienMovement.detach();

    thread bulletMovement(&Game::bulletMovement, this);
    bulletMovement.detach();

    while (!over && inTerminal) {
        // Keeps refreshing the screen
        board.printBoard();
        this_thread::sleep_for(chrono::milliseconds(37));
        system("clear");
    }   
}


void Game::setOver(bool pOver) {
    over = pOver;
}


bool Game::isOver() {
    return over;
}