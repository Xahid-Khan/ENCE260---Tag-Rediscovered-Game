/** @file play.c
    @author Zahid Khan ZKH22
    @author Thomas Mander TCM56
    @date 12 October 2021
    @brief This module is used an entry to the game and calls required functoins in order to play the game.
*/

#include "system.h"
#include "navswitch.h"
#include "timer.h"
#include "tinygl.h"
#include "display_message.h"
#include "player.h"
#include "cpu.h"


#define PACER_RATE 250
#define DISPLAY_TASK_RATE (PACER_RATE / 250)


static uint8_t wantedEnemies = 2;
/** This method will take the current position of the payer and
    update it on the LED_MAT
    @pram tinygl_point_t
    @return void
    */
void play_display_update (tinygl_point_t playerPosition, tinygl_point_t* cpuPoints)
{
    tinygl_clear();
    tinygl_draw_point (playerPosition, 1);
    for(uint8_t i = 0; i <= wantedEnemies; i++) {
        tinygl_draw_point(cpuPoints[i], 1);
    }
}


/** This Method will update the position of the player based on the input from
    JOY_STICK
    @pram player_t
    @return void
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


/** This is the main game loop which initiates required modules and call the required
    funcitons in an order and keep updating the LED mat if the navswitch is pressed.
    @pram void
    @return void*/
void play (void)
{
    system_init ();
    navswitch_init();
    // pacer_init(PACER_RATE);
    tinygl_init (DISPLAY_TASK_RATE);
    uint16_t time_constant = 31250;
    uint16_t cycle_counter = 0;

    Position_t enemyPositions[wantedEnemies];
    tinygl_point_t cpuPoints[wantedEnemies];


    welcome_message_display();
    startup_count();


    player_t player = player_init();
    tinygl_point_t playerPosition = tinygl_point(player.x, player.y);

    for(uint8_t i = 0; i <= wantedEnemies; i++) {
        spawnEnemy(enemyPositions, &player, i, wantedEnemies);
    }

    timer_init();
    while (cycle_counter < player.time)
    {
        tinygl_update();
        navswitch_update();
        move_player(&player);


        /** update the position of the player on the grid */
        playerPosition = tinygl_point(player.x, player.y);
        if (timer_get() >= time_constant) {
            cycle_counter++;
            timer_init();
        }

        if  (timer_get() >= 310) {
            for(uint8_t i = 0; i < wantedEnemies; i++) {
                cpuPoints[i] = tinygl_point(enemyPositions[i].x, enemyPositions[i].y);
            }
        }

        Tag(enemyPositions, &player, wantedEnemies);
        play_display_update(playerPosition, cpuPoints);
    }


    if (game_over_message(player.score) == 1) {
        play();
    }

}
