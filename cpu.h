/** @file       cpu.h
    @author     Thomas Mander - TCM56
    @author     Zahid Khan - ZKH22
    @date       18 October 2021
    @brief      This module is the header file to spawn and update enemies when
    tagged
*/


#ifndef CPU_H
#define CPU_H

#include "player.h"

//Declares a struct holding the positions of enemies
typedef struct {
    uint8_t x;
    uint8_t y;
} Position_t;

/*Spawns one enemy ensuring it is on a non-occupied LED
@pram pointer to array of enemies (Position_t*)
@pram pointer to player (Player_t*)
@pram position in enemy array for new enemy to replace (uint8_t)
@pram number of enemies in game (uint8_t)
@return void*/
void spawnEnemy(Position_t* enemyPositions, Player_t* playerPosition, uint8_t newPosition, uint8_t wantedEnemies);

/* if the player is at the same position as any enemy in an array
@pram pointer to an array of enemies (Position_t*)
@pram pointer to the players (Player_t*)
@pram number of enemies in the game (uint8_t)
@return void*/
void Tag(Position_t* enemies, Player_t* player, uint8_t wantedEnemies);

#endif
