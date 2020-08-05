//Includes added
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//General Variables Definition
#define Screen_Width 900
#define Screen_Height 600

//Main function of the program
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(Screen_Width, Screen_Height), "Space Invaders");
    sf::Texture BackgroundTexture;
    sf::Sprite background;

    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;

    sf::Font MyFont;
    if(!MyFont.loadFromFile("SPACEMAN.TTF")) return -1;

    sf::Text title;
    title.setFont(MyFont);
    title.setCharacterSize(55);
    title.setStyle(sf::Text::Bold);
    title.setString("SPACE INVADERS");
    title.setPosition(sf::Vector2f(80,80));

    sf::Text subTitle;
    subTitle.setFont(MyFont);
    subTitle.setCharacterSize(15);
    subTitle.setString("Hecho por Fabio, Francisco y Kenneth");
    subTitle.setPosition(sf::Vector2f(180,150));

    sf::Text play;
    play.setFont(MyFont);
    play.setCharacterSize(25);
    play.setStyle(sf::Text::Bold);
    play.setString("Presione enter para jugar");
    play.setPosition(sf::Vector2f(120,250));

    sf::Text leave;
    leave.setFont(MyFont);
    leave.setCharacterSize(25);
    leave.setStyle(sf::Text::Bold);
    leave.setString("Presione esc para salir");
    leave.setPosition(sf::Vector2f(155,370));
    
    if(!BackgroundTexture.loadFromFile("background.jpg")){
        return -1;
    } else{
        sizeOfTexture = BackgroundTexture.getSize();
        sizeOfWindow = window.getSize();

        float ScaleX = (float) sizeOfWindow.x / sizeOfTexture.x;
        float ScaleY = (float) sizeOfWindow.y / sizeOfTexture.y;

        background.setTexture(BackgroundTexture);
        background.setScale(ScaleX, ScaleY);
    }

    //Scaling Functionalities
    sizeOfWindow = window.getSize();

    float ScaleX = 0.1;
	float ScaleY = 0.1; 

    //Main Window Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Return:
                            //Play Game
                            cout << "Running Game..." << endl;
                            window.close();
                            break;
                        case sf::Keyboard::Escape:
                            //exit Game
                            cout << "Quitting Game..." << endl;
                            window.close();
                            break;
                default:
                        break;
                    }
            }
            
        }  

    //Window actions
    window.clear();
    window.draw(background);
    window.draw(title);
    window.draw(subTitle);
    window.draw(play);
    window.draw(leave);
    window.display();
    }
    return 0;
}