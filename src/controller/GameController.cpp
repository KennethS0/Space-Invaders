#include <controller/GameController.hpp>
#include <view/GameWindow.hpp>
#include <model/Game/Game.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
                if (event.type == sf::Event::KeyPressed) {
                    
                    // Right movement
                    if (event.key.code == sf::Keyboard::A) {
                        std::cout<<"A"<<endl;
                    } else if (event.key.code == sf::Keyboard::D) {
                        std::cout<<"D"<<endl;
                    } else if (event.key.code == sf::Keyboard::Space) {
                        std::cout<<"Space"<<endl;
                    } else if (event.key.code == sf::Keyboard::Escape) {
                        view.loadMenu(si_window);
                        si_window.display();

                        // Ends game and shows menu
                        gameStarted = false;
                        model.setOver(true);
                    }
                }
            }
        }
    }
}