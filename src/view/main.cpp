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
    sf::Texture EnemyImage;
    if (!EnemyImage.loadFromFile("Enemy.png")){
        std::cout << "Error Loading Image!" << std::endl;
    }
    sf::Sprite Enemy1(EnemyImage);
    sf::Sprite Enemy2(EnemyImage);
    sf::Sprite Enemy3(EnemyImage);
    sf::Sprite Enemy4(EnemyImage);


    sf::Vector2u sizeOfWindow;
    sf::Vector2u sizeOfTexture;
    

    //Scaling Functionalities
    sizeOfWindow = window.getSize();

    float ScaleX = 0.1;
	float ScaleY = 0.1; 

    Enemy1.setScale(ScaleX, ScaleY);
    Enemy2.setScale(ScaleX, ScaleY);
    Enemy3.setScale(ScaleX, ScaleY);
    Enemy4.setScale(ScaleX, ScaleY);

    
    Enemy2.setPosition(60,0);
    Enemy3.setPosition(120,0);
    Enemy4.setPosition(180,0);




    //Main Window Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }  

    //Window actions
    window.clear();
    window.draw(Enemy1);
    window.draw(Enemy2);
    window.draw(Enemy3);
    window.draw(Enemy4);
    window.display();
    }
    return 0;
}