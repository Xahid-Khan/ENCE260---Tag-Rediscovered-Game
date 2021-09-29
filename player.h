#ifndef PLAYER_H
#define PLAYER_H


typedef struct {
    char name[30];
    int16_t score;
    int16_t time;
} player_t


/* check if player is moving and update accordingly */
void check_movement();

/* update score when a tag is successful */
void update_score();

/* returns the player's current score */
int16_t get_score();

/* add extra time (3 seconds) to the remaining time */
int16_t update_time();

/* return the remaining time */
int16_t check_time();


#endif
