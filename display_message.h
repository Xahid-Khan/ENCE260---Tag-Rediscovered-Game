/** @file display_message.h
    @author Zahid Khan ZKH22
    @author Thomas Mander TCM56
    @date 05 October 2021
    @brief The header file for display message module.
*/

#ifndef DISPLAY_MESSAGE_H
#define DISPLAY_MESSAGE_H

/* Shows a display message on LED MAT*/
void welcome_message_display(void);

/* Shows countdown from 3 - 1 on LED MAT */
void startup_count(void);

/* Shows the game over message at the end of the game and shows the total score player achieved */
uint8_t game_over_message(uint16_t score);

#endif
