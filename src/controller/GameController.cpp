#include <controller/GameController.hpp>

GameController::GameController(Game pModel, GameWindow pView) {
    model = pModel;
    view = pView;

    // Detach a thread for player movement
    thread playerMovement(&GameController::movePlayer, this);
    playerMovement.detach();

    // Start the game (not in terminal)
    model.startGame(false);

    while (!model.isOver()) {
        // Refresh game window
    }

}

void GameController::movePlayer() {
    


}