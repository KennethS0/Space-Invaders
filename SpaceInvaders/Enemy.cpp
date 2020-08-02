#include "Enemy_Internal.h"

//Constructor
Entity * EnemyCreate(int posx, int posy, int velocidad) {
	Enemy* newEnemy = malloc(sizeof(Enemy));

	EnemyInitialize(newEnemy * this, int posx, int posy, int velocidad);

	return Enemy;
}

void EnemyInitialize(Enemy* this, int posx, int posy, int velocidad) {
	EntityInitialize(this, posx, posy);
	this->velocidad = velocidad;
}

//Setters
void EnemySetVelocidad(Entity* this, int velocidad) {
	this->velocidad = velocidad;
}

//getters
int EnemyGetVelocidad() {
	return velocidad;
}

//cleaning memory
void EnemyFree(Enemy* this) {
	free(this);
}