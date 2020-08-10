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

    view.loadMenu(si_window);

    while (si_window.isOpen()){
        sf::Event event;
        while (si_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) si_window.close();

            if (event.type == sf::Event::KeyPressed) {
                // ESC
                if (event.key.code == sf::Keyboard::Escape) {
                    si_window.close();
                }
                // ENTER (LOADS NEW WINDOW)
                else if (event.key.code == sf::Keyboard::Return) {
                    view.loadGame(si_window);
                    si_window.display();

                }
            }
        }
    }
}