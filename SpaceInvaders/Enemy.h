<<<<<<< HEAD
#pragma once
typedef struct Enemy Enemy;
Enemy* EnemyCreate(int posx, int posy, int velocidad);
void EnemySetVelocidad(Enemy* this, int velocidad);
void EnemyFree(Enemy* this);

=======
typedef struct Enemy Enemy;
Enemy * EnemyCreate(int posx, int posy, int velocidad);
void EnemySetVelocidad(Enemy* this, int velocidad);
void EnemyFree(Enemy* this);
>>>>>>> master
