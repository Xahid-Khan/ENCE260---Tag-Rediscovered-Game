/** @file       play.h
    @author     Zahid Khan - ZKH22
    @author     Thomas Mander - TCM56
    @date       18 October 2021
    @brief      This module is used as the header file to manage the games timeline
*/


#ifndef PLAY_H
#define PLAY_H

#include "tinygl.h"
#include "player.h"
#include "cpu.h"

/* This method will take the current position of the player and
    update it on the LED_MAT
    @pram tinygl_point_t
    @return void
    */
void play_display_update (tinygl_point_t pos);

/*  This is the main game loop which initiates required modules and call the
    required funcitons in an order and keep updating the LED mat if the
    navswitch is pressed.
    @pram void
    @return void*/
void play (void);

/* This Method will update the position of the player based on the input from
    JOY_STICK
    @pram Player_t
    @return void
    */
void move_player(Player_t);


#endif
