#include <model/Game/Game.hpp>
#include <view/GameWindow.hpp>
#include <controller/GameController.hpp>

#include <program.hpp>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>


using namespace std;

int main()
{
   // ===== FOR COMMAND LINE GAME ======

   // Lines from 18 through 33, and lines 38 through 40 were obtained from: https://shtrom.ssji.net/skb/getc.html

   // Disables buffered input
   struct termios old_tio, new_tio;

   // get the terminal settings for stdin
   tcgetattr(STDIN_FILENO, &old_tio);

   // we want to keep the old setting to restore them at the end
   new_tio = old_tio;

   // disable cannonical mode (buffered i/o) and local echo
   new_tio.c_lflag &=(~ICANON & ~ECHO);

   // set the new settings immediatley
   tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

   Game si = Game();
   si.startGame(true);

   // sets the old file settings
   tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
   return 0;
}