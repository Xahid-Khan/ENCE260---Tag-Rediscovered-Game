/*  @file       player.c
    @author     Zahid Khan - ZKH22
    @author     Thomas Mander - TCM56
    @date       18 October 2021
    @brief      This module is used for initiating PLAYER and contain all the player
    related functions (movement, score, time, etc.).
*/

#include "system.h"
#include "player.h"
#include "cpu.h"

#define ROWS 7
#define COLUMNS 5
#define INCREMENT 1
#define BOTTOM_ROW 6
#define TOP_ROW 0
#define LEFT_COLUMN 0
#define RIGHT_COLUMN 4
#define SCORE_INCREASE 5
#define TIME_INCREASE 1
#define CENTRE_ROW 3
#define CENTRE_COL 2
#define INITIAL_SCORE 0
#define INITIAL_TIME 10

/*
    This method will create a new player
    @pram void
    @pram player object (Player_t)
*/
Player_t player_init(void)
{
    Player_t newplayer;
    newplayer.score = INITIAL_SCORE;
    newplayer.time = INITIAL_TIME;
    newplayer.x = CENTRE_COL;
    newplayer.y = CENTRE_ROW;

    return newplayer;
}


/*
    Move the current position UP by 1 block
    @pram pointer to player (Player_t*)
    @return void
*/
void move_up(Player_t* player)
{
    if (player->y != TOP_ROW) {
        player->y = (player->y - INCREMENT) % ROWS;
    } else {
        player->y = BOTTOM_ROW;
    }
}



/*
    Move the current position DOWN by 1 block
    @pram pointer to player (Player_t*)
    @return void
*/
void move_down(Player_t* player)
{
    player->y = (player->y + INCREMENT) % ROWS;
}



/*
    Move the current position LEFT by 1 block
    @pram pointer to player (Player_t*)
    @return void
*/
void move_left(Player_t* player)
{
    if (player->x == LEFT_COLUMN) {
        player->x -= INCREMENT;
    }
    player->x = (player->x - INCREMENT) % COLUMNS;
}



/*
    Move the current position RIGHT by 1 block
    @pram pointer to player (Player_t*)
    @return void
*/
void move_right(Player_t* player)
{
    player->x = (player->x + INCREMENT ) % COLUMNS;
}



/*
    Update score when a tag is successful
    @pram pointer to player (Player_t*)
    @return void
*/
void update_score(Player_t* player)
{
    player->score += SCORE_INCREASE;
}



/*
    Add extra time (1 seconds) to the remaining time
    @pram pointer to player (Player_t*)
    @return void
*/
void update_time(Player_t* player)
{
    player->time += TIME_INCREASE;
}
