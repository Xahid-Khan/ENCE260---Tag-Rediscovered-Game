/** @file game.c
    @author Zahid Khan
    @date 01 October 2021
    @brief The start/entery to the game.
*/

#ifndef PLAYER_H
#define PLAYER_H


typedef struct {
    // char* name[8];
    int16_t score;
    int16_t time;
    uint8_t x;
    uint8_t y;
} player_t;

/* This method will create and return a new player */
player_t player_init(void);

/* Move the current position UP by 1 block */
void move_up(player_t* player);

/* Move the current position DOWN by 1 block */
void move_down(player_t* player);

/* Move the current position LEFT by 1 block */
void move_left(player_t* player);

/* Move the current position RIGHT by 1 block */
void move_right(player_t* player);

/* update score when a tag is successful */
void update_score(player_t* player);

/* returns the player's current score */
int16_t get_score(player_t* player);

/* add extra time (3 seconds) to the remaining time */
int16_t update_game_time(player_t* player);



#endif
