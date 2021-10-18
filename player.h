/** @file player.h
    @author Zahid Khan
    @author Thomas Mander TCM56
    @date 18 October 2021
    @brief Header file to declare player struct containing info/positions,
    update info and move.
*/

#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    // char* name[8];
    uint16_t score;
    uint32_t time;
    uint8_t x;
    uint8_t y;
} Player_t;

/* This method will create a new player
@pram void
@pram player object (Player_t)*/
Player_t player_init(void);

/* Move the current position UP by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_up(Player_t* player);

/* Move the current position DOWN by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_down(Player_t* player);

/* Move the current position LEFT by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_left(Player_t* player);

/* Move the current position RIGHT by 1 block
@pram pointer to player (Player_t*)
@return void*/
void move_right(Player_t* player);

/* update score when a tag is successful
@pram pointer to player (Player_t*)
@return void*/
void update_score(Player_t* player);

/* add extra time (1 seconds) to the remaining time
@pram pointer to player (Player_t*)
@return void*/
void update_time(Player_t* player);


#endif
