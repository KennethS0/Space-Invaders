#include <model/Alien/Alien.hpp>
#include <model/Board/Board.hpp>
#include <model/Bullet/Bullet.hpp>
#include <model/Entity/Entity.hpp>
#include <model/Player/Player.hpp>
#include <program.hpp>
#include <iostream>

using namespace std;

int main()
{
   Bullet myEnt = Bullet(48, 48);
   myEnt.moveDown();


   cout << myEnt.getPosX() << "," << myEnt.getPosY() << endl;

   return 0;
}
