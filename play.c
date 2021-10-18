/** @file play.c
    @author Zahid Khan ZKH22
    @author Thomas Mander TCM56
    @date 18 October 2021
    @brief This module provides a timeline for the game and calls required
    functions in order to play the game.
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
#define ONE_SECOND 31250

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
    @pram Player_t
    @return void
    */
void move_player(Player_t* player)
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



/** This is the main game loop which initiates required modules and call the
    required funcitons in an order and keep updating the LED mat if the
    navswitch is pressed.
    @pram void
    @return void*/
void play (void)
{
    //initialise variables and fun kit counters/navswitch
    system_init ();
    navswitch_init();
    tinygl_init (DISPLAY_TASK_RATE);
    uint16_t cycle_counter = 0;

    //Declare array of enemies
    Position_t enemyPositions[wantedEnemies];
    tinygl_point_t cpuPoints[wantedEnemies];

    //Welcome message
    welcome_message_display();
    startup_count();

    //Initialise player
    Player_t player = player_init();
    tinygl_point_t playerPosition = tinygl_point(player.x, player.y);

    //spawn enemies and store in array
    for(uint8_t i = 0; i <= wantedEnemies; i++) {
        spawnEnemy(enemyPositions, &player, i, wantedEnemies);
    }


    timer_init();
    while (cycle_counter < player.time)
    {
        //check for input and move player accordingly
        tinygl_update();
        navswitch_update();
        move_player(&player);

        /** update the position of the player on the grid */
        playerPosition = tinygl_point(player.x, player.y);

        //ensure the timer counts approximately once a second
        if (timer_get() >= ONE_SECOND) {
            cycle_counter++;
            timer_init();

            //respawn enemies every 3 seconds and store in array
            if (cycle_counter % 2 == 0) {

                for(uint8_t i = 0; i <= wantedEnemies; i++) {
                    spawnEnemy(enemyPositions, &player, i, wantedEnemies);
                }
            }
        }

        //Update enemy positions at ~10kHz
        if  (timer_get() % 3 == 0) {
            for(uint8_t i = 0; i < wantedEnemies; i++) {
                cpuPoints[i] = tinygl_point(enemyPositions[i].x, enemyPositions[i].y);
            }
        }

        //check for tag and update display
        Tag(enemyPositions, &player, wantedEnemies);
        play_display_update(playerPosition, cpuPoints);
    }


    //display the game over message and score
    if (game_over_message(player.score) == 1) {
        play();
    }

}
