#include "system.h"
#include "game_logic.h"
#include "pacer.h"
#include "cpu.h"
#include "display_message.h"
#include "player.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


/*When the players timer reaches 0, show the end message screen and score*/
void gameOver(player_t playerInfo)
{
    if(playerInfo.time <= 0) {
        game_over_message(playerInfo.score);
    }
}




