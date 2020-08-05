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

#define Sprite_Speed 1



void Game::run()
{
    sf::RenderWindow gameWindow(sf::VideoMode(Screen_Width, Screen_Height), "Space Invaders");
    sf::Texture EnemyImage;
    sf::Texture PlayerImage;
    if(!PlayerImage.loadFromFile("Player.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!EnemyImage.loadFromFile("Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    EnemyImage.setSmooth(true);
    PlayerImage.setSmooth(true);


    bool Up = false;
    bool Down = false;
    bool Left = false;
    bool Right = false;

    int x;
    int y;


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
    Player.setScale(ScaleX, ScaleY);
    
    Enemy1.setPosition(100,0);
    Enemy2.setPosition(160,0);
    Enemy3.setPosition(220,0);
    Enemy4.setPosition(280,0);


    


    //Main Window Loop
    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
            if (event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::W:
                        Up = true;
                        break;
                    case sf::Keyboard::S:
                        Down = true;
                        break;
                    case sf::Keyboard::A:
                        Left = true;
                        break;
                    case sf::Keyboard::D:
                        Right = true;
                        break;
                }
            }

            if (event.type == sf::Event::KeyReleased){
                switch(event.key.code){
                    case sf::Keyboard::W:
                        Up = false;
                        break;
                    case sf::Keyboard::S:
                        Down = false;
                        break;
                    case sf::Keyboard::A:
                        Left = false;
                        break;
                    case sf::Keyboard::D:
                        Right = false;
                        break;      
                }
            }
        }  

       // Update coordinates
        if (Left) x-=Sprite_Speed;
        if (Right) x+=Sprite_Speed;
        if (Up) y-=Sprite_Speed;
        if (Down) y+=Sprite_Speed;
    Player.setPosition(x, y);
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