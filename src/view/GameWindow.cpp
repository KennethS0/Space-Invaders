//Includes added
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <view/GameWindow.hpp>

using namespace std;

//General Variables Definition
#define Screen_Width 920 // 20 Colummns
#define Screen_Height 720 // 16 Rows
#define COLUMN_NUM 20
#define ROW_NUM 15

#define Screen_Width_Menu 900
#define Screen_Height_Menu 600

void GameWindow::run(){
    sf::RenderWindow gameWindow(sf::VideoMode(Screen_Width_Menu, Screen_Height_Menu), "Space Invaders");
    loadMenu(gameWindow);

    while (gameWindow.isOpen()){
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
               gameWindow.close();
    //             //Window actions
    //             gameWindow.clear();
    //             for(int i = 0; i<ROW_NUM; i++){
    //             for(int j = 0; j<COLUMN_NUM; j++){
    //                 //This is where the validation whether is an enemy, a bullet or player is set.
    //                 gameWindow.draw(Board[i][j]);
    //             }
    //         }
    //         gameWindow.display();
    //     }
	//     // Leaving the scope of 'Application' will cleanup the engine
        }
    }
}


void GameWindow::loadMenu(sf::RenderWindow& pWindow) {
    sf::Texture BackgroundTexture;
    sf::Sprite background;

    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;

    sf::Font MyFont;
    if(!MyFont.loadFromFile("/home/kenneth/Documents/GitHub/Space-Invaders/src/view/SPACEMAN.TTF")) return;

    sf::Text title;
    title.setFont(MyFont);
    title.setCharacterSize(55);
    title.setStyle(sf::Text::Bold);
    title.setString("SPACE INVADERS");
    title.setPosition(sf::Vector2f(80,80));

    sf::Text play;
    play.setFont(MyFont);
    play.setCharacterSize(25);
    play.setStyle(sf::Text::Bold);
    play.setString("Press 'ENTER' to play");
    play.setPosition(sf::Vector2f(120,250));

    sf::Text leave;
    leave.setFont(MyFont);
    leave.setCharacterSize(25);
    leave.setStyle(sf::Text::Bold);
    leave.setString("Press 'ESC' to quit");
    leave.setPosition(sf::Vector2f(155,370));
    
    if(!BackgroundTexture.loadFromFile("/home/kenneth/Documents/GitHub/Space-Invaders/src/view/background.jpg")){
        return;

    } else{
        sizeOfTexture = BackgroundTexture.getSize();
        sizeOfWindow = pWindow.getSize();

        float ScaleX = (float) sizeOfWindow.x / sizeOfTexture.x;
        float ScaleY = (float) sizeOfWindow.y / sizeOfTexture.y;

        background.setTexture(BackgroundTexture);
        background.setScale(ScaleX, ScaleY);
    }   

     //Scaling Functionalities
    sizeOfWindow = pWindow.getSize();

    // float ScaleX = 0.1;
	// float ScaleY = 0.1; 

    //Window actions
    pWindow.draw(background);
    pWindow.draw(title);
    pWindow.draw(play);
    pWindow.draw(leave);
    pWindow.display();
}


// void GameWindow::loadGame(sf::RenderWindow& pWindow) {
//     sf::Texture EnemyImage;
//     sf::Texture PlayerImage;
//     sf::Texture BulletImage;


//     sf::Texture BackgroundTexture;

//     if(!PlayerImage.loadFromFile("Ship.png")){
//         std::cout << "Error Loading Image!" << std::endl;
//     }
//     if (!EnemyImage.loadFromFile("Enemy.png")){
//         std::cout << "Error Loading Image!" << std::endl;
//     }
//     if (!BulletImage.loadFromFile("Bullet.png")){
//         std::cout << "Error Loading Image!" << std::endl;
//     }
//     //Needs loadFromFile for Bullet Image
//     EnemyImage.setSmooth(true);
//     PlayerImage.setSmooth(true);
//     BulletImage.setSmooth(true);


//     vector <sf::Texture> gameObjects;
//     gameObjects.push_back(PlayerImage);
//     gameObjects.push_back(EnemyImage);
//     gameObjects.push_back(BulletImage);


//     vector<vector<sf::Sprite>> Board;

//     int x = 0;
//     int y = -45;


//     for(int i = 0; i<ROW_NUM; i++)
//     {
//         y += 45;
//         x = 0;
//         vector<sf::Sprite> Row;
//         for(int j = 0; j<COLUMN_NUM; j++)
//         {
//             sf::Sprite nullSprite;
//             nullSprite.setPosition(x, y);
//             //nullSprite.scale();
//             Row.push_back(nullSprite);
//             x += 45;
//         }
//         Board.push_back(Row);
//     }
    
//     sf::Vector2u sizeOfWindow;
//     sf::Vector2u sizeOfTexture;

//     //Main Window Loop
// }