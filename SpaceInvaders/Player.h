typedef struct Player Player;
Player * PlayerCreate(int posx, int posy, int lives);
void PlayerSetVelocidad(Player * this, int lives);
void PlayerFree(Player* this);

