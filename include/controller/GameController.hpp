#include <view/GameWindow.hpp>
#include <model/Game/Game.hpp>

#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

class GameController{
    private:
        Game model;
        GameWindow view;

    public:
        GameController(Game pModel, GameWindow pView);
        void movePlayer();
};

#endif