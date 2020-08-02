#include "Player.h"
#include "Entity_internal.h"

struct Player {
	Entity base;
	int lives;
};

void PlayerInitialize(Player * this, int posx, int posy, int lives);
