/** @file game.c
    @author Zahid Khan
    @date 05 October 2021
    @brief This module is used for displaing messages on the LED mat.
*/

#include "system.h"
#include "player.h"
#include "cpu.h"
// #include <stdlib.h>




player_t player_init(void)
{
    player_t newplayer;
    // newplayer.name = "Tiger"
    newplayer.score = 0;
    newplayer.time = 300;
    newplayer.x = 2;
    newplayer.y = 3;

    return newplayer;
}



void move_up(player_t* player)
{
    if (player->y != 0) {
        player->y = (player->y - 1) % 7;
    } else {
        player->y = 6;
    }
}

void move_down(player_t* player)
{
    player->y = (player->y + 1) % 7;
}

void move_left(player_t* player)
{
    if (player->x == 0) {
        player->x -= 1;
    }
    player->x = (player->x - 1 ) % 5;
}

void move_right(player_t* player)
{
    player->x = (player->x + 1 ) % 5;
}


void update_score(player_t* player)
{
    player->score += 5;
}

void update_time(player_t* player)
{
    player->time += 30;
}
