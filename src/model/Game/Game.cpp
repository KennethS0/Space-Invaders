#include <model/Game/Game.hpp>

#include <iostream>
#include <thread>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define MAX_ENEMY_BULLETS 1
#define ALIEN_DEATH 100
#define SHOT_DESTROYED 50
#define ALIEN_SYMBOL 'U'
#define BULLET_SYMBOL '*'


#define DRAW_SPEED 37
#define ALIEN_MOVE_SPEED 600
#define BULLET_SPEED 200

Game::Game() {
    over = false;
    
    // Initializing Player
    player = Player(ROW_SIZE - 1, (int) (COLUMN_SIZE / 2 - 1));

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

        __asm__(
            "mov %0, %%rax;" // Moves saved keyPressed
            
            "leaq %1, %%rbx" // Moves the address of the player
            "pushq %%rbx" // Saves the address of the player

            "cmpq $97, %%rax;" // Value of 'a'
            "je __moveLeft;"

            "cmpq $100, %%rax;" // Value of 'd'
            "je __moveRight;"
            
            "__moveLeft:;"
                "call moveLeft"
            
            "__moveRight:;"
            :
            :"m"(keyPressed), "m"(player)
        );



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
            this_thread::sleep_for(milliseconds(100));
        }
    }
}


void Game::alienMovement() {
    // 0 Leftmost
    // 1 Rightmost
    int boundaries[2] = {-1, -1};

    // false -> (move right)
    // true <- (move left)
    bool direction = false;
    while (!over) {
        
        if(aliens.size() == 0) {
            newLevel();
        }

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
            if (it.getPosY() == ROW_SIZE) {
                over = true;
                break;
            }
            board.getBoard()[it.getPosY()][it.getPosX()] = nullptr;
        };

        if (boundaries[0] == 0 || boundaries[1] == COLUMN_SIZE - 1) {
            for (auto &it: aliens) {
                it.moveDown();
                if (it.getPosY() == ROW_SIZE - 1) {
                    over = true;
                    return;
                }
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

        generateShots();

        this_thread::sleep_for(milliseconds(ALIEN_MOVE_SPEED));
        boundaries[0] = -1;
        boundaries[1] = -1;   
    }
}


void Game::bulletMovement() {
    while (!over) {
        if (bullets.size() != 0) {
            int bulletPos = 0;
            for (auto &it: bullets) {
                
                int posX = it.getPosX();
                int posY = it.getPosY();

                if (it.isFromPlayer()) {
                    it.moveUp();
                    if (it.getPosY() < 0) {
                        deleteEntity(it.getPosX(), it.getPosY() + 1, bullets, bulletPos);
                        break;
                    }

                } else {
                    it.moveDown();
                    if (it.getPosY() > ROW_SIZE - 1) {
                        deleteEntity(it.getPosX(), it.getPosY() - 1, bullets, bulletPos);
                        break;
                    }
                }

                if (board.getBoard()[it.getPosY()][it.getPosX()] == nullptr) {
                    board.changePos(it, posX, posY);
                } else {
                    // Removes pointers from board
                    board.clearPos(posX, posY);
                    char symbol = board.getBoard()[it.getPosY()][it.getPosX()]->getSymbol();

                    if (posY == ROW_SIZE - 2) {
                        board.loseLife();
                        // Removes the bullet that collides with something
                        bullets.erase(bullets.begin() + bulletPos);
                        if (board.getLives() == 0) {
                            over = true;
                        }
                        break;
                    }

                    if (symbol == ALIEN_SYMBOL) {
                        checkVector(aliens, it.getPosX(), it.getPosY(), ALIEN_DEATH);
                     } else if (symbol == BULLET_SYMBOL){
                        checkVector(bullets, it.getPosX(), it.getPosY(), SHOT_DESTROYED);
                    }       

                    // Removes the pointer to the entity removed
                    board.clearPos(it.getPosX(), it.getPosY());

                    // Removes the bullet that collides with something
                    bullets.erase(bullets.begin() + bulletPos);

                    break;
                }
                bulletPos++;
            }
            this_thread::sleep_for(milliseconds(BULLET_SPEED));
        }
    }
}


void Game::startGame(bool inTerminal) {
    // Initial game set up
    if (inTerminal) {
        thread playerMovement(&Game::movePlayer, this);
        playerMovement.detach();
    }
    
    thread alienMovement(&Game::alienMovement, this);
    alienMovement.detach();

    thread bulletMovement(&Game::bulletMovement, this);
    bulletMovement.detach();

    while (!over && inTerminal) {
        // Keeps refreshing the screen
        board.printBoard();
        this_thread::sleep_for(milliseconds(DRAW_SPEED));
        system("clear");
    }   
}


template <class T>
void Game::checkVector(T &pVector, int pPosX, int pPosY, int pScore){
    int entPos = 0;
    for (auto &et : pVector) {
        int x = et.getPosX();
        int y = et.getPosY();
        if (x == pPosX && y == pPosY) {
            pVector.erase(pVector.begin() + entPos);
            board.setScore(board.getScore() + pScore);
            break;
        }
    entPos++;
    }
}


void Game::generateShots() {
    int bulletCount = 0;
    for (auto &it: aliens) {
        if (bulletCount == MAX_ENEMY_BULLETS) {
            return;
        }
        // Generating random boolean
        srand(time(0));
        bool randomCondition = rand() % 2;
    
        int posX = it.getPosX();
        int posY = it.getPosY();
    
        if (aliens.size() == 1) {
            this_thread::sleep_for(milliseconds(1000));
        }

        // Checks if theres an entity in front
        if (board.getBoard()[posY + 1][posX] == nullptr && randomCondition) {
            Bullet shot = it.shoot();
            shot.setFromPlayer(false);
            bullets.push_back(shot);
 
            board.getBoard()[shot.getPosY()][shot.getPosX()] = &shot;
            bulletCount++;
            this_thread::sleep_for(milliseconds(100));
        }
    }
}


template <class T>
void Game::deleteEntity(int posX, int posY, T &pVector, int pVectorPos) {
    board.clearPos(posX, posY);
    pVector.erase(pVector.begin() + pVectorPos);
}   


void Game::newLevel() {
    // Initializing aliens
    for (int i = 3; i < COLUMN_SIZE - 7; i++) {

        for (int j = 0; j < 4; j++) {
            aliens.push_back(Alien(j, i));
        };
    };

    // Adds one life to the player if they lost one
    if (board.getLives() < 3) {
        board.setLives(board.getLives() + 1);
    };

    // Randomizing aliens
    random_shuffle(aliens.begin(), aliens.end());
}


void Game::setOver(bool pOver) {
    over = pOver;
}


bool Game::isOver() {
    return over;
}


Board Game::getBoard() {
    return board;
}


Player Game::getPlayer() {
    return player;
}


vector<Bullet> Game::getBullets(){
    return bullets;
}