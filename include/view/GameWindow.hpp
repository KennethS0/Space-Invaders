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
		vector<vector<sf::Sprite>> Board;
	public:
	
		// sf::RenderWindow gameWindow;

		bool started = false;

		void run();

		void loadMenu(sf::RenderWindow& pWindow);
		void loadGame(sf::RenderWindow& pWindow);

		vector<vector<sf::Sprite>> getBoard();
};

#endif