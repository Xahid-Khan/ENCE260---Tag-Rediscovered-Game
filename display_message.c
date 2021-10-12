/** @file game.c
    @author Zahid Khan ZKH22
    @author Thomas Mander TCM56
    @date 05 October 2021
    @brief This module is used for displaying messages on the LED mat.
*/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "../fonts/font3x5_1.h"
#include <stdio.h>

#define TINYGL_PACER_RATE 500
#define TINYGL_MESSAGE_RATE 15

/**
    "welcome_message_display" is a method which shows a welcome message to the player and keeps displying the message in a loop until a navswitch is pushed in the center to start the game. This method takes no arguments and returns void.
    @pram void
    @return void
*/
void welcome_message_display (void)
{
    system_init();

    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font3x5_1);
    tinygl_text_speed_set(TINYGL_MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);

    tinygl_text(" WELCOME TO TAG RE-DISCOVERED ");
    pacer_init (TINYGL_PACER_RATE);
    navswitch_init();

    while(1)
    {
        pacer_wait();
        navswitch_update();
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            break;
        }
        tinygl_update();
    }
}


/* This method "startup_count" shows a count down from 3 to 1 and ends, takes no parameters and return void
    @pram void
    @retrn void
    */
void startup_count(void)
{
    system_init();

    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(20);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_NORMAL);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);

    tinygl_text("321 ");
    pacer_init (TINYGL_PACER_RATE);
    uint16_t counter = 0;

    while(1){
        pacer_wait();
        tinygl_update();
        counter ++;
        if (counter > 1000) {
            break;
        }
    }
}


/** This method "game_over_message" displays game over on LED mat and players' total SCORE at the end of the game.
    if player pushes the middle of navswitch the game will re-starts
    @pram unit16_t SCORE
    @return 1
    */
uint8_t game_over_message(uint16_t score)
{
    system_init();
    char message[10] = "GAME OVER";
    char number[5];
    sprintf(number, "%u", score);

    char last_message[16];
    sprintf(last_message, "%s %s",  message, number);
    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font3x5_1);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);
    tinygl_text_speed_set(TINYGL_MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    tinygl_text(last_message);
    pacer_init (TINYGL_PACER_RATE);
    navswitch_init();

    while(1)
    {
        pacer_wait();
        navswitch_update();
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            break;
        }
        tinygl_update();
    }
    return 1;
}
