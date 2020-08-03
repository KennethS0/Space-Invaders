#include <model/Alien/Alien.hpp>
#include <model/Board/Board.hpp>
#include <model/Bullet/Bullet.hpp>
#include <model/Entity/Entity.hpp>
#include <model/Player/Player.hpp>
#include <model/Board/Board.hpp>
#include <program.hpp>
#include <iostream>

using namespace std;

int main()
{
   Board myBoard = Board();

   cout << myBoard.getBoard();

   return 0;
}
