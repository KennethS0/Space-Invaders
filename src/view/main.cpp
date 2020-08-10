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


//Main function of the program
int main()
{
    

   

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
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Return:{
                        //Play Game
                        cout << "Running Game..." << endl;
                        window.close();
                        // auto game = GameWindow{};
                        // game.run();
                        break;
                    }
                    case sf::Keyboard::Escape:{
                        //exit Game
                        cout << "Quitting Game..." << endl;
                        window.close();
                        break;
                    }
                    default:
                        break;
                    }
            }
        }  

    }
    return 0;
}