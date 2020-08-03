#ifndef GAME_HPP
#define GAME_HPP

#include <model/Alien/Alien.hpp>
#include <model/Board/Board.hpp>
#include <model/Player/Player.hpp>
#include <thread>
#include <vector>

using namespace std;

class Game {

    private:
        vector<Alien> aliens;
        vector<Bullet> bullets;
        Player player;
        Board board;


    public:
        Game();



};

#endif