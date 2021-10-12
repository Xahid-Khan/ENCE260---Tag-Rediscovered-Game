/** @file game.c
    @author Zahid Khan
    @date 01 October 2021
    @brief The start/entery to the game.
*/

#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    // char* name[8];
    uint16_t score;
    uint32_t time;
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

/* add extra time (3 seconds) to the remaining time */
void update_time(player_t* player);


#endif
