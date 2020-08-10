#include <controller/GameController.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

GameController::GameController(Game pModel, GameWindow pView) {
    model = pModel;
    view = pView;

    // Detach a thread for player movement
    thread playerMovement(&GameController::movePlayer, this);
    playerMovement.detach();

    // Start the game (not in terminal)
    model.startGame(false);

    // Refreshes the game on the screen
    while (!model.isOver()) {
        for (int i = 0; i < ROW_SIZE; i++) {

            for (int j = 0; j < COLUMN_SIZE; j++) {
                // NULLPTR IS FOUND
                if (model.getBoard().getBoard()[i][j] == nullptr) {
                    // 

                } else {

                };
            };
        };
    }

}

void GameController::movePlayer() {
    sf::Event event;
    
    while(!model.isOver()) {
         if (event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::W:
                        // Tripas aqui
                        break;
                    case sf::Keyboard::S:
                        // Tripas aqui tambien
                        break;
                    case sf::Keyboard::A:
                        // Y aqui
                        break;
                    case sf::Keyboard::D:
                        // Aqui as well
                        break;
                }
            }
    }


}