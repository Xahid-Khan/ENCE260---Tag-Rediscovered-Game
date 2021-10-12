#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "cpu.h"
#include "player.h"

/*removes enemy and increases score when a tag has occured, 
takes the player position and the enemy positions as well as the number of enemies*/
bool Tag(Position_t* enemies, player_t* player, uint8_t enemyNumber);

/*Checks for if the player has run out of time and initiates the game over screen*/
void gameOver(player_t player);

#endif
