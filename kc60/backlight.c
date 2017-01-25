/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "backlight.h"

#define PWM_RESOLUTION 0xff
#define PWM_PERIOD F_CPU/(PWM_RESOLUTION*64)

uint8_t duty_cycle = 0;
uint8_t tick = 0;

static const uint8_t breathing_table[64] PROGMEM = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 6, 10,
15, 23, 32, 44, 58, 74, 93, 113, 135, 157, 179, 199, 218, 233, 245, 252,
255, 252, 245, 233, 218, 199, 179, 157, 135, 113, 93, 74, 58, 44, 32, 23,
15, 10, 6, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
bool breathing = false;
uint8_t breathing_index = 0;

// LED Control
__attribute__ ((weak))
void led_off(void) {
    PORTB &= ~(1<<6);
}
__attribute__ ((weak))
void led_on(void) {
    PORTB |= (1<<6);
}
// PWM Control
void pwm_enable(void) {
    TIMSK1 |= _BV(OCIE1A);
}
void pwm_disable(void) {
    TIMSK1 &= ~_BV(OCIE1A);
}
void backlight_init_pwm(void) {
    TCCR1B |= _BV(WGM12);
    TCCR1B |= _BV(CS10);

    uint8_t sreg = SREG;
    cli();
    OCR1AH = (PWM_PERIOD>>8)&0xff;
    OCR1AL = PWM_PERIOD&0xff;
    SREG = sreg;
}

void backlight_set(uint8_t level) {
    if (!level || level == BACKLIGHT_LEVELS)
       pwm_disable();
    else
       pwm_enable();

    if (!level)
       led_off();
    else
       led_on();

    if (BREATHING_ENABLED) {
        if (level == 1) {
            breathing = true;
        } else {
            breathing = false;
            duty_cycle = (level - 1) *PWM_RESOLUTION/(BACKLIGHT_LEVELS - 1);
        }
    } else {
        duty_cycle = level*PWM_RESOLUTION/BACKLIGHT_LEVELS;
    }
}

ISR(TIMER1_COMPA_vect) {
    tick++;
    if (tick == 0) {
        led_on();

        if (breathing) {
           breathing_index++;
           duty_cycle = pgm_read_byte(&breathing_table[breathing_index/4]);
        }
    }

    if (tick == duty_cycle) {
        led_off();
    }
};
