//Includes added
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include "GameWindow.hpp"

using namespace std;

//General Variables Definition
#define Screen_Width 900
#define Screen_Height 600



void Game::run()
{
    sf::RenderWindow gameWindow(sf::VideoMode(Screen_Width, Screen_Height), "Space Invaders");
    sf::Texture EnemyImage;
    sf::Texture PlayerImage;
    if(!EnemyImage.loadFromFile("Player.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!EnemyImage.loadFromFile("Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    sf::Sprite Enemy1(EnemyImage);
    sf::Sprite Enemy2(EnemyImage);
    sf::Sprite Enemy3(EnemyImage);
    sf::Sprite Enemy4(EnemyImage);
    sf::Sprite Player(PlayerImage);


    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;
    

    //Scaling Functionalities
    sizeOfWindow = gameWindow.getSize();

    float ScaleX = 0.1;
	float ScaleY = 0.1; 

    Enemy1.setScale(ScaleX, ScaleY);
    Enemy2.setScale(ScaleX, ScaleY);
    Enemy3.setScale(ScaleX, ScaleY);
    Enemy4.setScale(ScaleX, ScaleY);

    
    Enemy2.setPosition(60,0);
    Enemy3.setPosition(120,0);
    Enemy4.setPosition(180,0);
    Player.setPosition(450, 500);

    


    //Main Window Loop
    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
        }  

    //Window actions
    gameWindow.clear();
    gameWindow.draw(Enemy1);
    gameWindow.draw(Enemy2);
    gameWindow.draw(Enemy3);
    gameWindow.draw(Enemy4);
    gameWindow.draw(Player);
    gameWindow.display();
    }
	// Leaving the scope of 'Application' will cleanup the engine
}