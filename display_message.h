/** @file       display_message.h
    @author     Zahid Khan - ZKH22
    @author     Thomas Mander - TCM56
    @date       05 October 2021
    @brief      The header file for display message module.
*/

#ifndef DISPLAY_MESSAGE_H
#define DISPLAY_MESSAGE_H

/*  This method initiates the tinygl, set the speed, mode, selects the font and
    rotates the direction
    @pram void
    @return void*/
void tinygl_game_init(void);

/*
    "welcome_message_display" is a method which shows a welcome message to the
    player and keeps displying the message in a loop until a navswitch is pushed
    in the center to start the game.
    @pram void
    @return void
*/
void welcome_message_display(void);

/* This method "startup_count" shows a count down from 3 to 1 and ends.
    @pram void
    @retrn void
    */
void startup_count(void);

/*  This method "game_over_message" displays game over on LED mat and players'
    total SCORE at the end of the game. If player pushes the middle of navswitch
    the game will re-starts
    @pram unit16_t SCORE
    @return 1
    */
uint8_t game_over_message(uint16_t score);

#endif
