<<<<<<< HEAD
#include "Entity_Internal.h"

//Constructor
Entity* EntityCreate(int posx, int posy) {
	Entity* newEntity = malloc(sizeof(Entity));
	EntityInitialize(newEntity);
	return newEntity;
}

void EntityInitialize(Entity* this, int posx, int posy) {
	this->posx = posx;
	this->posy = posy;
}

//setters
void EntitySetPosx(Entity* this, int posx) {
	this->posx = posx;
}

void EntitySetPosy(Entity* this, int posy) {
	this->posy = posy;
}

//getters
int EntityGetPosx() {
	return posx;
}

int EntityGetPosy() {
	return posy;
}

//cleaning memory
void EntityFree(Entity* this) {
	free(this);
}
=======
#include "Entity_Internal.h"

//Constructor
Entity * EntityCreate(int posx, int posy) {
	Entity * newEntity = malloc(sizeof(Entity));
	EntityInitialize(newEntity);
	return newEntity;
}

void EntityInitialize(Entity * this, int posx, int posy) {
	this->posx = posx;
	this->posy = posy;
}

//setters
void EntitySetPosx(Entity * this, int posx) {
	this->posx = posx;
}

void EntitySetPosy(Entity * this, int posy) {
	this->posy = posy; 
}

//getters
int EntityGetPosx() {
	return posx;
}

int EntityGetPosy() {
	return posy;
}

//cleaning memory
void EntityFree(Entity* this) {
	free(this);
}
>>>>>>> master
