/** @file       display_message.c
    @author     Zahid Khan - ZKH22
    @author     Thomas Mander - TCM56
    @date       05 October 2021
    @brief      This module is used for displaying messages on the LED mat.
*/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "../fonts/font3x5_1.h"
#include <stdio.h>
#include "sound_effects.h"

#define TINYGL_PACER_RATE 500
#define TINYGL_MESSAGE_RATE 15
#define TONE_FREQUENCY 440
#define LOOP_RATE (TONE_FREQUENCY * 2)

/*  This method initiates the tinygl, set the speed, mode, selects the font and
    rotates the direction
    @pram void
    @return void*/
void tinygl_game_init (void){
    system_init();

    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font3x5_1);
    tinygl_text_speed_set(TINYGL_MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);
}


/*
    "welcome_message_display" is a method which shows a welcome message to the
    player and keeps displying the message in a loop until a navswitch is pushed
     in the center to start the game.
    @pram void
    @return void
*/
void welcome_message_display (void)
{
    tinygl_game_init();
    init_speaker();
    pacer_init(LOOP_RATE);
    int counter = 0;
    // while loop plays 1 beep
    while (counter < 200) {
        pacer_wait();
        use_speaker();
        counter++;
    }

    tinygl_text(" WELCOME TO TAG RE-DISCOVERED ");
    pacer_init (TINYGL_PACER_RATE);
    navswitch_init();

    // displays welcome message in a loop until navswitch is pushed in.
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


/* This method "startup_count" shows a count down from 3 to 1 and ends.
    @pram void
    @retrn void
    */
void startup_count(void)
{
    tinygl_clear();
    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(20);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_NORMAL);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);

    tinygl_text("321 ");
    pacer_init (TINYGL_PACER_RATE);
    uint16_t counter = 0;
    //displays the count down just before the game starts
    while(1){
        pacer_wait();
        tinygl_update();
        counter ++;
        if (counter > 1000) {
            break;
        }
    }


    pacer_init(LOOP_RATE);
    int startup_counter = 0;

    // Play a single been after the count down to let Player know the game has started
    while (startup_counter < 200) {
        pacer_wait();
        use_speaker();
        startup_counter++;
    }
}


/*  This method "game_over_message" displays game over on LED mat and players'
    total SCORE at the end of the game. If player pushes the middle of navswitch
    the game will re-starts
    @pram unit16_t SCORE
    @return 1
    */
uint8_t game_over_message(uint16_t score)
{
    tinygl_game_init();

    pacer_init(LOOP_RATE);
    uint16_t counter = 0;

    // two while loops in a row with some delay to play 2 beeps with gap at the
    // end of the game.
    while (counter < 200) {
        pacer_wait();
        use_speaker();
        counter++;
    }
    pacer_wait();
    pacer_wait();
    counter = 0;
    while (counter < 200) {
        pacer_wait();
        use_speaker();
        counter++;
    }

    char message[10] = "GAME OVER";
    char number[5];
    sprintf(number, "%u", score);

    char last_message[25];
    sprintf(last_message, "%s SCORE-%s",  message, number);

    tinygl_text(last_message);
    pacer_init (TINYGL_PACER_RATE);
    navswitch_init();

    // Displays game over message with score at the end of the game in a loop.
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
