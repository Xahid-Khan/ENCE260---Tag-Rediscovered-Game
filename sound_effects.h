#ifndef SOUND_EFFECTS_H
#define SOUND_EFFECTS_H

#include <stdint.h>

/* This will be called on start-up */
void start_up_effect();

/* A beep sound will be made on every movement NSEW */
void movement_beep();

/* A cheer effect on every successfull tag */
void successful_tag();

/* Sound effect for GAME-OVER*/
void game_over_effect();

#endif
