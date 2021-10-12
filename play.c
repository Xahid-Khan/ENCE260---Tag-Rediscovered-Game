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


// #define NAVSWITCH_TASK_RATE (PACER_RATE / 100)
#define DISPLAY_TASK_RATE (PACER_RATE / 250)
#define PACER_RATE 250

static uint8_t wantedEnemies = 2;
/** This method will take the current position of the payer and
    update it on the LED_MAT
    @pram tinygl_point_t
    */
static void play_display_update (tinygl_point_t playerPosition, tinygl_point_t* cpuPoints)
{
    tinygl_clear();
    tinygl_draw_point (playerPosition, 1);
    for(uint8_t i = 0; i < wantedEnemies; i++) {
        tinygl_draw_point(cpuPoints[i], 1);
    }
    tinygl_update();
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
    navswitch_init();
    // pacer_init(PACER_RATE);
    tinygl_init (DISPLAY_TASK_RATE);
    uint16_t cycle_counter = 0;
    uint16_t timer_counter = 0;
    Position_t enemyPositions[wantedEnemies];
    tinygl_point_t cpuPoints[wantedEnemies];


    welcome_message_display();
    startup_count();


    player_t player = player_init();
    for(uint8_t i = 0; i < wantedEnemies; i++) {
        spawnEnemy(enemyPositions, &player);
    }


    while (cycle_counter < player.time)
    {
        tinygl_update();
        navswitch_update();
        move_player(&player);

        /** update the position of the player on the grid */
        tinygl_point_t playerPosition = tinygl_point(player.x, player.y);


        if (timer_counter >= 500) {
            for(uint8_t i = 0; i < wantedEnemies; i++) {
                cpuPoints[i] = tinygl_point(enemyPositions[i].x, enemyPositions[i].y);
            }
            cycle_counter++;
            timer_counter = 0;
        }

        Tag(enemyPositions, &player, wantedEnemies);
        play_display_update(playerPosition, cpuPoints);
        timer_counter++;

    }
    game_over_message(player.score);
}
