#include <controller/GameController.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
using namespace std;

GameController::GameController(Game pModel, GameWindow pView) {
    model = pModel;
    view = pView;

    thread uiRefresher(&GameController::loadUI, this);
    uiRefresher.detach();

    while (!view.started){}

    // Detach a thread for player movement
    thread playerMovement(&GameController::movePlayer, this);
    playerMovement.detach();

    // Start the game (not in terminal)
    model.startGame(false);

    sf::Texture EnemyImage;

    if (!EnemyImage.loadFromFile("src/view/Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }

    // Refreshes the game on the screen
    while (!model.isOver()) {
        for (int i = 0; i < ROW_SIZE; i++) {

            for (int j = 0; j < COLUMN_SIZE; j++) {
                // NULLPTR IS FOUND
                if (model.getBoard().getBoard()[i][j] == nullptr) {
                    view.getBoard()[i][j].setColor(sf::Color::Transparent);               
                } else {
                    view.getBoard()[i][j].setTexture(EnemyImage);
                    view.getBoard()[i][j].setScale(0.1, 0.1);
                };
            };
        };
    };
}


void GameController::loadUI() {
    view.run();
}


void GameController::movePlayer() {
    // sf::Event event;
    
    // while(!model.isOver()) {
    //     if (event.type == sf::Event::KeyPressed){
    //         if (event.key.code == sf::Keyboard::S) {
    //             cout<<"S"<<endl;
    //         }
    //         else if (event.key.code == sf::Keyboard::A) {
    //             cout<<"A"<<endl;
    //         }
    //         else if (event.key.code == sf::Keyboard::Space) {
    //             cout<<"SPACE"<<endl;
    //         }

    //     }
    // }
}