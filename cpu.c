/** @file       cpu.c
    @author     Thomas Mander - TCM56
    @author     Zahid Khan - ZKH22
    @date       18 October 2021
    @brief      This module is used to spawn and update enemies when tagged
*/

#include "system.h"
#include "cpu.h"
#include "player.h"
#include "pacer.h"
#include <stdlib.h>



/*Spawns one enemy ensuring it is on a non-occupied LED
@pram pointer to array of enemies (Position_t*)
@pram pointer to player (Player_t*)
@pram position in enemy array for new enemy to replace (uint8_t)
@pram number of enemies in game (uint8_t)
@return void*/
void spawnEnemy(Position_t* enemyPositions, Player_t* playerPosition, uint8_t newPosition, uint8_t wantedEnemies)
{
    /*initialises a new enemy and a boolean for if the enenmy is in an occupied
    position*/
    bool isOccupied;
    Position_t enemy;


    /*While an enemies coordinates have not been generated or they lie on an
    occupied position, generate new coordinates
    within the LED Matrix*/
    do {
        isOccupied = false;
        enemy.x = rand()%5;
        enemy.y = rand()%7;

        /*Checks the new enemy position against previous enemy positions*/
        for(uint8_t i = 0; i < wantedEnemies; i++) {
            bool isSameX = (enemy.x == enemyPositions[i].x);
            bool isSameY = (enemy.y == enemyPositions[i].y);

            /*if the area is occupied by an existing enemy set the boolean for
            this as true*/
            if(isSameX && isSameY) {
                isOccupied = true;
            }
        }
        /*Checks the new enemy position against the player position*/
        bool isSameX = (enemy.x == playerPosition->x);
        bool isSameY = (enemy.y == playerPosition->y);

        /*if the area is occupied by the player set the boolean for this as true*/
        if(isSameX && isSameY) {
            isOccupied = true;
        }
    } while(isOccupied);


    /*add new enemy to array and increase the number of enemies*/
    enemyPositions[newPosition] = enemy;
}



/* if the player is at the same position as any enemy in an array
@pram pointer to an array of enemies (Position_t*)
@pram pointer to the players (Player_t*)
@pram number of enemies in the game (uint8_t)
@return void*/
void Tag(Position_t* enemies, Player_t* player, uint8_t wantedEnemies)
{
    /*Runs through all enemies and checks if theire positions are the same as the player*/
    for(uint8_t i = 0; i < wantedEnemies; i++) {
        bool isSameX = enemies[i].x == player->x;
        bool isSameY = enemies[i].y == player->y;

        /*If positions are the same, spawn new enemy and increase the score*/
        if(isSameX && isSameY) {
            update_score(player);
            update_time(player);
            spawnEnemy(enemies, player, i, wantedEnemies);
        }
    }
}
