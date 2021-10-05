#include "system.h"
#include "display_message.h"
#include "player.h"

int main (void)
{
    system_init ();
    welcome_message_display();
    player_t player = player_init();
    game_over_message(400);


    while (1)
    {



    }

}
