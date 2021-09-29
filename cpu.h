#ifndef CPU_H
#define CPU_H

struct Position {
   uint8_t x;
   uint8_t y;
} Position_t 

/*Moves enemy to adjacent square provided it is in LED matrix and is not occupied*/
void moveEnemy(int* enemyPositions, int playerPosition);

/*Spawns one enemy ensuring it is on a non-occupied LED*/
void spawnEnemy(Position_t* enemyPositions, Position_t playerPosition);

#endif
