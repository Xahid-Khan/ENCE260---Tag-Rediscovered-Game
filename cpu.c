#include "system.h"
#include "cpu.h"
#include "pacer.h"


/*Spawns one enemy ensuring it is on a non-occupied LED*/
void spawnEnemy(Position_t* enemyPositions, player_t playerPosition, int enemies)
{
    bool isSamePosition;
    Position_t enemy;
    do {
        isSamePosition = false;
        enemy.x = 1+rand()%5;
        enemy.y = 1+rand()%7;
        for(uint8_t i = 0; i < *enemies; i++) {
            bool isSameX = (enemy.x == enemyPositions[i].x);
            bool isSameY = (enemy.y == enemyPositions[i].y);
            if(isSameX && isSameY) {
                isSamePosition = true;      
            }
        }
        bool isSameX = (enemy.x == playerPosition.x);
        bool isSameY = (enemy.y == playerPosition.y);
        if(isSameX && isSameY) {
            isSamePosition = true;      
        }
    } while(isSamePosition);

    enemyPositions[*enemies] = enemy;
    *enemies += 1;
}

void deleteEnemies(Position_t* enemyPositions, uint8_t* enemies)
{
    *enemyPositions = NULL;
    *enemies = 0;
}

int main (void)
{
    system_init ();
    uint8_t enemies = 0;
    Position_t enemyPositions[2];
    pacer_init(2000);
    while (1)
    {
        for (uint8_t j = 0; j < 2; j++) {
            spawnEnemy(enemyPositions, &enemies);
        }
        pacer_wait()
        deleteEnemies(enemyPositions, &enemies);
    }
}
