/** @file game.c
    @author Zahid Khan
    @date 12 October 2021
    @brief This module is used for displaing messages on the LED mat.
*/

#include "system.h"
#include "navswitch.h"
#include "pacer.h"
#include "tinygl.h"
#include "display_message.h"
#include "player.h"
#include "cpu.h"


#define NAVSWITCH_TASK_RATE (PACER_RATE / 100)
#define DISPLAY_TASK_RATE (PACER_RATE / 250)
#define PACER_RATE 500


/** This method will take the current position of the payer and
    update it on the LED_MAT
    @pram tinygl_point_t
    */
static void play_display_update (tinygl_point_t pos)
{
    tinygl_clear();
    tinygl_update();
    tinygl_draw_point (pos, 1);
}


/** This Method will update the position of the player based on the input from
    JOY_STICK
    @pram player_t
    */
void move_player(player_t* player)
{
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        move_up(player);
    }
    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        move_down(player);
    }
    if (navswitch_push_event_p (NAVSWITCH_EAST)) {
        move_right(player);
    }
    if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        move_left(player);
    }
}


/** This is the main game loop */
void play (void)
{
    system_init ();
    pacer_init(PACER_RATE);
    // welcome_message_display();
    startup_count();

    player_t player = player_init();
    // position_t cpu_1 = ;
    // position_t cpu_2 = ;

    // system_init ();
    tinygl_init (DISPLAY_TASK_RATE);
    navswitch_init();
    tinygl_point_t pos;
    play_display_update(tinygl_point(player.x, player.y));

    while (1)
    {
        navswitch_update();
        tinygl_update();
        move_player(&player);

        /** update the position of the player on the grid */
        pos = tinygl_point(player.x, player.y);
        play_display_update(pos);

    }
    game_over_message(player.score);
}
