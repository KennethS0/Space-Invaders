#include <model/Game/Game.hpp>
#include <program.hpp>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

extern "C" void printMenu();
extern "C" void printEndGame();

int main()
{
   // ===== FOR COMMAND LINE GAME ====== //
   // Lines from 18 through 31, and lines 38 through 39 were obtained from: https://shtrom.ssji.net/skb/getc.html
   printMenu(); // Function called from assembly file (NASM)
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
 
   printEndGame(); // Function called from assembly file (NASM)

   // sets the old file settings
   tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
   return 0;
}