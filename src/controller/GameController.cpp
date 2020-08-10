#include <controller/GameController.hpp>
#include <view/GameWindow.hpp>
#include <model/Game/Game.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>

#include <iostream>
using namespace std;

//General Variables Definition
#define Screen_Width 920 // 20 Colummns
#define Screen_Height 720 // 16 Rows

GameController::GameController() {
    sf::RenderWindow si_window(sf::VideoMode(Screen_Width, Screen_Height), "Space Invaders");
    Game model = Game();
    GameWindow view = GameWindow();

    bool gameStarted = false;
    // bool startedThread = false;

    view.loadMenu(si_window);

    while (si_window.isOpen()){
        sf::Event event;
        while (si_window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) si_window.close();

            if (!gameStarted) {
                // Menu options
                if (event.type == sf::Event::KeyPressed) {
                    // ESC
                    if (event.key.code == sf::Keyboard::Escape) {
                        si_window.close();
                    }
                    // ENTER (LOADS NEW WINDOW)
                    else if (event.key.code == sf::Keyboard::Return) {
                        view.loadGame(si_window);
                        si_window.display();

                        model.setOver(false);
                        gameStarted = true;
                        model.startGame(false);
                    }
                }
            } else {
                // Game logic and redrawing
                if(model.isOver()) {
                    si_window.close();
                } 

                // if (!startedThread) {
                //     thread refresherThread(&GameController::refreshGame, this, ref(si_window));
                //     refresherThread.detach(); 
                // }

                if (event.type == sf::Event::KeyPressed) {
                    // int x = model.getPlayer().getPosX();

                    // Right movement
                    if (event.key.code == sf::Keyboard::A) {
                        model.getPlayer().moveLeft();
                        // model.getBoard().changePos(model.getPlayer(), x, model.getPlayer().getPosY());
                        
                    } else if (event.key.code == sf::Keyboard::D) {
                        model.getPlayer().moveRight();
                        // model.getBoard().changePos(model.getPlayer(), x, model.getPlayer().getPosY());

                    } else if (event.key.code == sf::Keyboard::Space) {
                        Bullet shot = model.getPlayer().shoot();
                        shot.setFromPlayer(true);
                        model.getPlayer().shoot();
                        model.getBullets().push_back(shot);
                        // model.getBoard().getBoard()[shot.getPosX()][shot.getPosY()] = &shot;


                    } else if (event.key.code == sf::Keyboard::Escape) {
                        si_window.close();
                    }
                }
                // refreshGame(si_window);
            }
        }
    }
}


void GameController::refreshGame(sf::RenderWindow& pWindow) {
    // Loads image files
    sf::Texture EnemyImage;
    sf::Texture PlayerImage;
    sf::Texture BulletImage;

    if(!PlayerImage.loadFromFile("src/view/Ship.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!EnemyImage.loadFromFile("src/view/Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!BulletImage.loadFromFile("src/view/Bullet.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    
    //Needs loadFromFile for Bullet Image
    EnemyImage.setSmooth(true);
    PlayerImage.setSmooth(true);
    BulletImage.setSmooth(true);

        
    while (!model.isOver()) {
        pWindow.clear();
    
    // Loop through model
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            // NULLPTR IS FOUND
            cout << i << j << endl;

            if (model.getBoard().getBoard()[i][j] == nullptr) {
                    // Change texture of sprite
                    // sf::Sprite a = view.getBoard()[j][i];

            } else {
                if (model.getBoard().getBoard()[i][j]->getSymbol() == 'U') {
    //                 view.getBoard()[i][j].setTexture(EnemyImage);
    //                 view.getBoard()[i][j].setScale(0.1, 0.1);
                } else if (model.getBoard().getBoard()[i][j]->getSymbol() == 'M') {
                    // cout<< "PLAYER" << model.getPlayer().getPosX() << endl;                    
                } else if (model.getBoard().getBoard()[i][j]->getSymbol() == '*') {
    //                 // cout<< "BULLET" << endl;
                }
        
            }
    //         pWindow.draw(view.getBoard()[i][j]);
        }
    }
        pWindow.display();

        this_thread::sleep_for(chrono::milliseconds(107));
    }        
}
