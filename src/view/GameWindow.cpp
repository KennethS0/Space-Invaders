//Includes added
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include "GameWindow.hpp"
//#include "main.cpp"

using namespace std;

//General Variables Definition
#define Screen_Width 920 // 20 Colummns
#define Screen_Height 720 // 16 Rows
#define COLUMN_NUM 20
#define ROW_NUM 15


void Game::run()
{
    sf::RenderWindow gameWindow(sf::VideoMode(Screen_Width, Screen_Height), "Space Invaders");

    sf::Texture EnemyImage;
    sf::Texture PlayerImage;
    sf::Texture BulletImage;


    sf::Texture BackgroundTexture;


    if(!PlayerImage.loadFromFile("Ship.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!EnemyImage.loadFromFile("Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!BulletImage.loadFromFile("Bullet.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    //Needs loadFromFile for Bullet Image
    EnemyImage.setSmooth(true);
    PlayerImage.setSmooth(true);
    BulletImage.setSmooth(true);


    vector <sf::Texture> gameObjects;
    gameObjects.push_back(PlayerImage);
    gameObjects.push_back(EnemyImage);
    gameObjects.push_back(BulletImage);


    vector<vector<sf::Sprite>> Board;

    int x = 0;
    int y = -45;


    for(int i = 0; i<ROW_NUM; i++)
    {
        y += 45;
        x = 0;
        vector<sf::Sprite> Row;
        for(int j = 0; j<COLUMN_NUM; j++)
        {
            sf::Sprite nullSprite;
            nullSprite.setPosition(x, y);
            //nullSprite.scale();
            Row.push_back(nullSprite);
            x += 45;
        }
        Board.push_back(Row);
    }
    for(int i = 0; i < ROW_NUM-1; i++){
        for(int j = 0; j < COLUMN_NUM; j++){
            Board[i][j].setTexture(PlayerImage);
            Board[i][j].setScale(0.1, 0.1);
        }

    }

    
    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;
    

    // if(!BackgroundTexture.loadFromFile("background.jpg")){
    //     cout<<"error";
    // } else{
    //     sizeOfTexture = BackgroundTexture.getSize();
    //     sizeOfWindow = gameWindow.getSize();

    //     float ScaleX = (float) sizeOfWindow.x / sizeOfTexture.x;
    //     float ScaleY = (float) sizeOfWindow.y / sizeOfTexture.y;

    //     sf::Sprite background(BackgroundTexture);
    //     background.setScale(ScaleX, ScaleY);
    // }


    //Main Window Loop
    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
               gameWindow.close();
            // if (event.type == sf::Event::KeyPressed){
            //     switch(event.key.code){
            //         case sf::Keyboard::W:
            //             Up = true;
            //             break;
            //         case sf::Keyboard::S:
            //             Down = true;
            //             break;
            //         case sf::Keyboard::A:
            //             Left = true;
            //             break;
            //         case sf::Keyboard::D:
            //             Right = true;
            //             break;
            //     }
            // }

            // if (event.type == sf::Event::KeyReleased){
            //     switch(event.key.code){
            //         case sf::Keyboard::W:
            //             Up = false;
            //             break;
            //         case sf::Keyboard::S:
            //             Down = false;
            //             break;
            //         case sf::Keyboard::A:
            //             Left = false;
            //             break;
            //         case sf::Keyboard::D:
            //             Right = false;
            //             break;      
            //     }
            // }
        }  

    //    // Update coordinates
    //     if (Left) x-=Sprite_Speed;
    //     if (Right) x+=Sprite_Speed;
    //     if (Up) y-=Sprite_Speed;
    //     if (Down) y+=Sprite_Speed;
    //Player.setPosition(x, y);
    //Window actions
    gameWindow.clear();
    for(int i = 0; i<ROW_NUM; i++){
        for(int j = 0; j<COLUMN_NUM; j++)
        {
            //This is where the validation whether is an enemy, a bullet or player is set.
            gameWindow.draw(Board[i][j]);
        }
    }
    gameWindow.display();
    }
	// Leaving the scope of 'Application' will cleanup the engine
}