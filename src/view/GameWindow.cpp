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

void GameWindow::loadMenu(sf::RenderWindow& pWindow) {
    sf::Texture BackgroundTexture;
    sf::Sprite background;

    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;

    sf::Font MyFont;
    if(!MyFont.loadFromFile("src/view/SPACEMAN.TTF")) return;

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
    
    if(!BackgroundTexture.loadFromFile("src/view/background.jpg")){
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

    pWindow.clear();
    pWindow.setSize(sf::Vector2u(Screen_Width, Screen_Height));

    sf::Font MyFont;
    if(!MyFont.loadFromFile("src/view/SPACEMAN.TTF")) return;

    int x = 0;
    int y = -45;

    for(int i = 0; i<ROW_NUM; i++)
    {
        y += 45;
        x = 0;

        Board[i] = new sf::Sprite[20];

        for(int j = 0; j<COLUMN_NUM; j++)
        {
            sf::Sprite nullSprite;
            nullSprite.setPosition(x, y);
            //nullSprite.scale();
            Board[i][j] = nullSprite;
            x += 45;
        }    
    }
    
    //     for(int i = 0; i < ROW_NUM; i++){
    //     for(int j = 0; j < COLUMN_NUM; j++){
    //         Board[i][j].setTexture(EnemyImage);
    //         Board[i][j].setScale(0.1, 0.1);
    //     }

    // }
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


    pWindow.draw(Score);
    pWindow.draw(Lives);
}


sf::Sprite** GameWindow::getBoard() {
    return Board;
}