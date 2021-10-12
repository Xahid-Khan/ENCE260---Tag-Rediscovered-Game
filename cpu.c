#include "system.h"
#include "cpu.h"
#include "player.h"
#include "pacer.h"
#include <stdlib.h>

static uint8_t enemyNumber = 0;

/*Spawns one enemy ensuring it is on a non-occupied LED, takes the enemy positions, the player positions and the number of enemies*/
void spawnEnemy(Position_t* enemyPositions, player_t* playerPosition)
{
    /*initialises a new enemy and a boolean for if the enenmy is in an occupied position*/
    bool isOccupied;
    Position_t enemy;
    /*While an enemies coordinates have not been generated or they lie on an occupied position, generate new coordinates
    within the LED Matrix*/
    do {
        isOccupied = false;
        enemy.x = 1+rand()%5;
        enemy.y = 1+rand()%7;
        /*Checks the new enemy position against previous enemy positions*/
        for(uint8_t i = 0; i < enemyNumber; i++) {
            bool isSameX = (enemy.x == enemyPositions[i].x);
            bool isSameY = (enemy.y == enemyPositions[i].y);
            /*if the area is occupied by an existing enemy set the boolean for this as true*/
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
    enemyPositions[enemyNumber] = enemy;
    enemyNumber += 1;
}

/*Takes the positions of the enemies, the number of enemies and the player struct and
deletes an enemy if the player and it are on the same space.*/
void Tag(Position_t* enemies, player_t* player, uint8_t enemyNumber)
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

/*Takes all enemies, a position in the enemy array and the number of enemies and removes the specified enemy from the array while decreasing the number of enemies by 1*/
void deleteEnemy(Position_t* enemyPositions, uint8_t* enemyNumber, uint8_t enemy)
{
    *enemyNumber -= 1;
    enemyPositions[enemy].x = NULL;
    enemyPositions[enemy].y = NULL;
}
