#include <model/Alien/Alien.hpp>
#include <program.hpp>
#include <iostream>

using namespace std;

int main()
{
   Alien myEnt = Alien(48, 48);
   myEnt.moveLeft();


   cout << myEnt.getPosX() << "," << myEnt.getPosY() << endl;

   return 0;
}
