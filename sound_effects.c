/** @file:      sound_effects.c
    @author     Zahid Khan - ZKH22
    @author     Thomas Mander - TCM56
    @date:      14 OCT 2021
    @brief:     Speaker function in .h format
*/
#include "system.h"
#include "pio.h"
#include "pacer.h"

#define PIEZO1_PIO PIO_DEFINE (PORT_D, 4)
#define PIEZO2_PIO PIO_DEFINE (PORT_D, 6)

/**
 * @brief: Initilise speaker
*/
void init_speaker(void)
{
    pio_config_set (PIEZO1_PIO, PIO_OUTPUT_LOW);
    pio_config_set (PIEZO2_PIO, PIO_OUTPUT_HIGH);
}


/**
 * @brief: Output sound from speaker
*/
void use_speaker(void)
{
    pio_output_toggle (PIEZO1_PIO);
    pio_output_toggle (PIEZO2_PIO);
}
