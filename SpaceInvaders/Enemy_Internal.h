#pragma once
#include "Enemy.h"
#include "Entity_internal.h"

struct Enemy {
	Entity base;
	int velocidad;
};

void EnemyInitialize(Enemy* this, int posx, int posy, int velocidad);


