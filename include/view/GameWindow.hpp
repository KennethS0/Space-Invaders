#include <SFML/Graphics/RenderWindow.hpp>

#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

class GameWindow
{
	private:


	public:
		bool started = false;

		void run();

		void loadMenu(sf::RenderWindow& pWindow);
		void loadGame(sf::RenderWindow& pWindow);
};

#endif