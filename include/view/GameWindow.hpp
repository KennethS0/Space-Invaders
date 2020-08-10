#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;

#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

class GameWindow
{
	private:
		sf::Sprite** Board = new sf::Sprite*[15];
		
	public:

		bool started = false;

		void run(sf::RenderWindow& pWindow);

		void loadMenu(sf::RenderWindow& pWindow);
		void loadGame(sf::RenderWindow& pWindow);

		sf::Sprite **getBoard();
};

#endif