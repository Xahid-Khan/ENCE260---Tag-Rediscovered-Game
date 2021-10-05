/** @file game.c
    @author Zahid Khan
    @date 01 October 2021
    @brief The start/entery to the game.
*/

#ifndef PLAYER_H
#define PLAYER_H


typedef struct {
    char name[30];
    int16_t score;
    int16_t time;
    uint8_t x;
    uint8_t y;
} player_t;

/* This method will create and return a new player */
player_t palyer_init();

/* check if player is moving and update accordingly */
void move_up(player_t* player);

void move_down(player_t* player);

void move_left(player_t* player);

void move_right(player_t* player);

/* update score when a tag is successful */
void update_score();

/* returns the player's current score */
int16_t get_score();

/* add extra time (3 seconds) to the remaining time */
int16_t update_time();

/* return the remaining time */
int16_t check_time();


#endif
