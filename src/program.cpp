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

   Alien myAlien = Alien(1, 1);

   myBoard.getBoard()[myAlien.getPosX()][myAlien.getPosY()] = &myAlien;

   cout << myBoard.getBoard()[1][1]->getPosX() << "," << myBoard.getBoard()[1][1]->getPosY();

   return 0;
}
