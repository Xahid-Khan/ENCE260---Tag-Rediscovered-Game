/** @file game.c
    @author Zahid Khan
    @date 12 October 2021
    @brief This module is used for displaing messages on the LED mat.
*/


#ifndef PLAY_H
#define PLAY_H

#include "tinygl.h"
#include "player.h"

/** Updates the LED display on LED_MAT */
static void play_display_update (tinygl_point_t pos);

/** Entry point to the game and keeps the game in the loop */
void play (void);

/** Updates the players position based on the movement of JOY_STICK */
void move_player(player_t);


#endif