<<<<<<< HEAD

#include "Player_Internal.h"


//Constructor
Entity* PlayerCreate(int posx, int posy, int lives) {
	Player* newPlayer = malloc(sizeof(Player));

	PlayerInitialize(newPlayer * this, int posx, int posy, int lives);

	return Player;
}

void PlayerInitialize(Player* this, int posx, int posy, int lives) {
	PlayerInitialize(this, posx, posy);
	this->lives = lives;
}

//Setters
void PlayerSetLives(Entity* this, int lives) {
	this->lives = lives;
}

//getters
int PlayerGetLives() {
	return lives;
}

//cleaning memory
void PlayerFree(Player* this) {
	free(this);
=======
#include "Player_Internal.h"

//Constructor
Entity * PlayerCreate(int posx, int posy, int lives) {
	Player * newPlayer = malloc(sizeof(Player));

	PlayerInitialize(newPlayer * this, int posx, int posy, int lives);

	return Player;
}

void PlayerInitialize(Player * this, int posx, int posy, int lives) {
	PlayerInitialize(this, posx, posy);
	this->lives = lives;
}

//Setters
void PlayerSetLives(Entity * this, int lives) {
	this->lives = lives;
}

//getters
int PlayerGetLives() {
	return lives;
}

//cleaning memory
void PlayerFree(Player * this) {
	free(this);
>>>>>>> master
}