/** @file player.c
    @author Zahid Khan ZKH22
    @author Thomas Mander TCM56
    @date 18 October 2021
    @brief This module is used for initiating PLAYER and contain all the player
    related functions (movement, score, time, etc.).
*/

#include "system.h"
#include "player.h"
#include "cpu.h"



/* This method will create a new player
@pram void
@pram player object (Player_t)*/
Player_t player_init(void)
{
    Player_t newplayer;
    newplayer.score = 0;
    newplayer.time = 10;
    newplayer.x = 2;
    newplayer.y = 3;

    return newplayer;
}


/* Move the current position UP by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_up(Player_t* player)
{
    if (player->y != 0) {
        player->y = (player->y - 1) % 7;
    } else {
        player->y = 6;
    }
}



/* Move the current position DOWN by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_down(Player_t* player)
{
    player->y = (player->y + 1) % 7;
}



/* Move the current position LEFT by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_left(Player_t* player)
{
    if (player->x == 0) {
        player->x -= 1;
    }
    player->x = (player->x - 1 ) % 5;
}



/* Move the current position RIGHT by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_right(Player_t* player)
{
    player->x = (player->x + 1 ) % 5;
}



/* update score when a tag is successful
@pram pointer to player (Player_t*)
@return void*/
void update_score(Player_t* player)
{
    player->score += 5;
}



/* add extra time (1 seconds) to the remaining time
@pram pointer to player (Player_t*)
@return void*/
void update_time(Player_t* player)
{
    player->time += 1;
}
