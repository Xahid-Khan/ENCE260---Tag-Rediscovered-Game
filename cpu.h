#ifndef CPU_H
#define CPU_H

#include "player.h"

typedef struct {
    uint8_t x;
    uint8_t y;
} Position_t;

/*Takes all enemies, a position in the enemy array and the number of enemies and removes the specified enemy from the array while decreasing the number of enemies by 1*/
void deleteEnemies(Position_t* enemyPositions, uint8_t* enemyNumber, uint8_t enemy);

/*Spawns one enemy ensuring it is on a non-occupied LED, takes the enemy positions, the player positions and the number of enemies*/
void spawnEnemy(Position_t* enemyPositions, player_t*, uint8_t* enemyNumber);

#endif
