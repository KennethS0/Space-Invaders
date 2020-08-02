<<<<<<< HEAD
#pragma once
#include "Disparo.h"
#include "Entity_internal.h"

struct Disparo {
	Entity base;
	int velocidad;
};
void DisparoInitialize(Disparo* this, int posx, int posy, int velocidad);

=======
#include "Disparo.h"
#include "Entity_internal.h"

struct Disparo {
	Entity base;
	int velocidad;
};

void DisparoInitialize(Disparo* this, int posx, int posy, int velocidad);
>>>>>>> master
