#include "system.h"
#include "cpu.h"
#include "pacer.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t wantedEnemies = 2;

/*Spawns one enemy ensuring it is on a non-occupied LED, takes the enemy positions, the player positions and the number of enemies*/
void spawnEnemy(Position_t* enemyPositions, player_t playerPosition, uint8_t* enemyNumber)
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
        for(uint8_t i = 0; i < *enemyNumber; i++) {
            bool isSameX = (enemy.x == enemyPositions[i].x);
            bool isSameY = (enemy.y == enemyPositions[i].y);
            /*if the area is occupied by an existing enemy set the boolean for this as true*/            
            if(isSameX && isSameY) {
                isOccupied = true;      
            }
        }
        /*Checks the new enemy position against the player position*/
        bool isSameX = (enemy.x == playerPosition.x);
        bool isSameY = (enemy.y == playerPosition.y);
        /*if the area is occupied by the player set the boolean for this as true*/  
        if(isSameX && isSameY) {
            isOccupied = true;      
        }
    } while(isOccupied);

    /*add new enemy to array and increase the number of enemies*/
    enemyPositions[*enemyNumber] = enemy;
    *enemyNumber += 1;
}



/*Takes all enemies, a position in the enemy array and the number of enemies and removes the specified enemy from the array while decreasing the number of enemies by 1*/
void deleteEnemy(Position_t enemyPositions, uint8_t* enemyNumber)
{
    *enemyNumber -= 1;    
    enemyPositions[enemy] = NULL;
}

/*To be handled by game.c, just testing for now*/
int main(void)
{
    system_init ();
    uint8_t enemies = 0;
    /*Creates an array to hold the wanted number of enemies*/
    Position_t enemyPositions[wantedEnemies];
    pacer_init(2000);
    while (1)
    {
        /*Creates the wanted number of enemies and stores them in array*/
        for(uint8_t i = 0; i < wantedEnemies; i++) {
            spawnEnemy(enemyPositions, playerPosition, &enemyNumber);
        }
        /*waits 2 seconds before deleting*/
        pacer_wait();
        /*Deletes the wanted number of enemies and removes them from array*/
        for(uint8_t i = 0; i < wantedEnemies; i++) {
            deleteEnemies(enemyPositions[enemy], &enemyNumber);
        }
    }
}
