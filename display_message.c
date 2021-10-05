/** @file game.c
    @author Zahid Khan
    @date 05 October 2021
    @brief This module is used for displaing messages on the LED mat.
*/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define TINYGL_PACER_RATE 500
#define TINYGL_MESSAGE_RATE 20

/**
    "welcome_message_display" is a method which shows a welcome message to the player and keeps displying the message in a loop until a navswitch is pushed in the center to start the game. This method takes no arguments and returns void.
*/
void welcome_message_display (void)
{
    system_init();

    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(TINYGL_MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

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
    startup_count();
}


/* This method "startup_count" shows a count down from 3 to 1 and ends, takes no parameters and return void */
void startup_count(void)
{
    system_init();

    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(TINYGL_MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);

    tinygl_text("321 ");
    pacer_init (TINYGL_PACER_RATE);
    uint8_t counter = 0;

    while(1){
        pacer_wait();
        tinygl_update();
        counter ++;
        if (counter > 3) {
            break;
        }
    }
}


/* This method "game_over_message" displays game over on LED mat and players' total SCORE at the end of the game. if player pushes the middle of navswitch the game will re-starts*/
void game_over_message(uint16_t score)
{
    system_init();
    char message[10] = "GAME OVER";
    char number[4];
    sprintf(number, "%d", score);

    char last_message[25];
    sprintf(last_message, "%s %s",  message, number);
    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font5x7_1);
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
}
