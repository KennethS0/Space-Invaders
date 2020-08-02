#include "Disparo_Internal.h"

//Constructor
Entity * DisparoCreate(int posx, int posy, int velocidad) {
	Disparo* newDisparo = malloc(sizeof(Disparo));

	DisparoInitialize(newDisparo * this, int posx, int posy, int velocidad);

	return Disparo;
}

void DisparoInitialize(Disparo* this, int posx, int posy, int velocidad) {
	EntityInitialize(this, posx, posy);
	this->velocidad = velocidad;
}

//Setters
void DisparoSetVelocidad(Entity* this, int velocidad) {
	this->velocidad = velocidad;
}

//getters
int DisparoGetVelocidad() {
	return velocidad;
}

//cleaning memory
void DisparoFree(Disparo* this) {
	free(this);
}