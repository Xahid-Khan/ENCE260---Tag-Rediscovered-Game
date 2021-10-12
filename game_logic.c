#include "system.h"
#include "game_logic.h"
#include "pacer.h"
#include "cpu.h"
#include "display_message.h"
#include "player.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/*Takes the positions of the enemies, the number of enemies and the player struct and
deletes an enemy if the player and it are on the same space.*/
bool Tag(Position_t* enemies, player_t* player, uint8_t enemyNumber)
{
    /*Runs through all enemies and checks if theire positions are the same as the player*/
    for(uint8_t i = 0; i < enemyNumber; i++) {
        bool isSameX = enemies[i].x == player->x;
        bool isSameY = enemies[i].y == player->y;
        /*If positions are the same, remove the enemy and increase the score*/        
        if(isSameX && isSameY) {
            update_score(player);
            deleteEnemy(enemies[i], enemyNumber);
        }
    }
}


/*When the players timer reaches 0, show the end message screen and score*/
void gameOver(player_t playerInfo)
{
    if(playerInfo.time <= 0) {
        game_over_message(playerInfo.score);
    }
}




