#ifndef CPU_H
#define CPU_H

#include "player.h"

typedef struct {
    uint8_t x;
    uint8_t y;
} Position_t;

/*Spawns one enemy ensuring it is on a non-occupied LED, takes the enemy positions, the player positions and the number of enemies*/
void spawnEnemy(Position_t* enemyPositions, player_t* playerPosition, uint8_t newPosition, uint8_t wantedEnemies);

void Tag(Position_t* enemies, player_t* player, uint8_t wantedEnemies);

#endif
