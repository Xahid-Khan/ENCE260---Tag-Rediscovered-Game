/** @file game.c
    @author Zahid Khan
    @date 05 October 2021
    @brief The start/entery to the game.
*/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define TINYGL_PACER_RATE 500
#define TINYGL_MESSAGE_RATE 10

void welcome_message_display (void)
{
    system_init();

    /* TODO: Initialise tinygl. */
    tinygl_init(TINYGL_PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(TINYGL_MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    /* TODO: Set the message using tinygl_text().  */
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
        if (counter > 4) {
            break;
        }
    }
}

void game_over_message(uint16_t* score);
