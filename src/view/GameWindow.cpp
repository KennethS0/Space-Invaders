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
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) gameWindow.close();

            if (event.type == sf::Event::KeyPressed) {
                // ESC
                if (event.key.code == sf::Keyboard::Escape) {
                    gameWindow.close();
                }
                // ENTER (LOADS NEW WINDOW)
                else if (event.key.code == sf::Keyboard::Return) {
                    gameWindow.clear();

                    // Loads the game window
                    sf::RenderWindow gameWindow(sf::VideoMode(Screen_Width, Screen_Height), "Space Invaders");
                    loadGame(gameWindow);


                }

            }
        }
    }
}


void GameWindow::loadMenu(sf::RenderWindow& pWindow) {
    sf::Texture BackgroundTexture;
    sf::Sprite background;

    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;

    sf::Font MyFont;
    if(!MyFont.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/SPACEMAN.TTF")) return;

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
    
    if(!BackgroundTexture.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/background.jpg")){
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

    //Window actions
    pWindow.draw(background);
    pWindow.draw(title);
    pWindow.draw(play);
    pWindow.draw(leave);
    pWindow.display();
}


void GameWindow::loadGame(sf::RenderWindow& pWindow) {

    sf::Texture EnemyImage;
    sf::Texture PlayerImage;
    sf::Texture BulletImage;

    sf::Texture BackgroundTexture;


    if(!PlayerImage.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/Ship.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!EnemyImage.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    if (!BulletImage.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/Bullet.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }

    sf::Font MyFont;
    if(!MyFont.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/SPACEMAN.TTF")) return;

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
        }    sf::Font MyFont;
    if(!MyFont.loadFromFile("/home/ifrann/Documents/TEC/I SEM/Arqui/SpaceInvaders_Project/Space-Invaders/src/view/SPACEMAN.TTF")) return;

        Board.push_back(Row);
    }
    
        for(int i = 0; i < ROW_NUM; i++){
        for(int j = 0; j < COLUMN_NUM; j++){
            Board[i][j].setTexture(EnemyImage);
            Board[i][j].setScale(0.1, 0.1);
        }

    }
    for(int j = 0; j < COLUMN_NUM; j++){
        Board[14][j].setColor(sf::Color::Transparent);
    }
    int scoreNum = 123456; // the score to print
    
    string scoreStr = to_string(scoreNum);

    sf::Text Score;
    Score.setFont(MyFont);
    Score.setCharacterSize(25);
    Score.setStyle(sf::Text::Bold);
    Score.setString("Score: " + scoreStr);
    Score.setPosition(sf::Vector2f(20,655));

    int livesNum = 3;

    string livesStr = to_string(livesNum);

    sf::Text Lives;
    Lives.setFont(MyFont);
    Lives.setCharacterSize(25);
    Lives.setStyle(sf::Text::Bold);
    Lives.setString("Lives: " + livesStr);
    Lives.setPosition(sf::Vector2f(700,655));


    //Main Window Loop
    
    for(int i = 0; i<ROW_NUM; i++){
        for(int j = 0; j<COLUMN_NUM; j++)
        {
            //This is where the validation whether is an enemy, a bullet or player is set.
            pWindow.draw(Board[i][j]);
        }
    }
    pWindow.draw(Score);
    pWindow.draw(Lives);
    pWindow.display();
}