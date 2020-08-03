#include <model/Entity/Entity.hpp>
#include <program.hpp>
#include <iostream>

using namespace std;

int main()
{
   Entity myEnt = Entity(48, 48);

   cout << myEnt.getPosX() << "," << myEnt.getPosY() << endl;

   return 0;
}
