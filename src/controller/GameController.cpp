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
    view.run(si_window);
}