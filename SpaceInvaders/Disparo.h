typedef struct Disparo Disparo;
Disparo * DisparoCreate(int posx, int posy, int velocidad);
void DisparoSetVelocidad(Disparo * this, int velocidad);
void DisparoFree(Disparo * this);


