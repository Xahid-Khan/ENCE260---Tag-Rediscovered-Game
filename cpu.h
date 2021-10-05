#ifndef CPU_H
#define CPU_H

typedef struct {
    uint8_t x;
    uint8_t y;
} Position_t;

/*Removes all existing enemies*/
void deleteEnemies(Position_t* enemyPositions, uint8_t* enemies);

/*Spawns one enemy ensuring it is on a non-occupied LED*/
void spawnEnemy(Position_t* enemyPositions, Position_t playerPosition);

#endif
