#include "config_common.h"
#include "../../config.h"

#ifndef USER_CONFIG_H
#define USER_CONFIG_H

// Personal Settings
#define KVM_USE         // Add in KVM compatibilities and hotkeys

// Tapping behavior -- dual purpose keys with behavior based on a "tap" vs a "hold"
#define TAPPING_TERM 210    // ms to hold a tap key to switch to modifier
#undef  PERMISSIVE_HOLD     // translates an ordered w/ dual purpose first as a
                            //   modifier even if under tap term
#undef  IGNORE_MOD_TAP_INTERRUPT
                            // treat out of order key press with tap key as a tap of both
                            //   only applies to modifiers (not layers)
#undef  TAPPING_FORCE_HOLD  // tapping followed by a hold are differentiated
#define RETRO_TAPPING       // a tap modifier without another key press is always a tap
#undef  HOLD_ON_OTHER_KEY_PRESS
                            // switch to hold functionality if another key is pressed
                            // while held down

// Layer RGB Settings
// Reactive Orange
#define BASE_RGB            10, 0xFF, 0xFF
#define BASE_RGB_MODE       RGB_MATRIX_SOLID_REACTIVE_WIDE
// Reactive Azure
#define NO_DUALS_RGB        132, 0xC8, 0xC8
#define NO_DUALS_RGB_MODE   RGB_MATRIX_SOLID_REACTIVE_WIDE
// Breathing Magenta
#define EXTENDED_RGB        213, 0xFF, 0xC8
#define EXTENDED_RGB_MODE   RGB_MATRIX_BREATHING
// Breathing Green
#define SPECIAL_RGB         64, 0xFF, 0xC8
#define SPECIAL_RGB_MODE    RGB_MATRIX_BREATHING

// Per Key RGB
#define RGB_MATRIX_KEYPRESSES   // enables reactive key LED values on keypress
#undef  RGB_MATRIX_FRAMEBUFFER_EFFECTS
                                // enable fancy animation manipulations
#undef  DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// set default mode to the base reactive mode
#define RGB_MATRIX_STARTUP_MODE BASE_RGB_MODE
// set default HUE, SAT, Brightness value
#define RGB_MATRIX_STARTUP_HUE  10
#define RGB_MATRIX_STARTUP_SAT  0xFF
#define RGB_MATRIX_STARTUP_VAL  0xC8

// RGB Matrix Startup Animation
#undef  DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define STARTUP_ANIMATION RGB_MATRIX_CYCLE_LEFT_RIGHT
#define STARTUP_ANIMATION_DURATION 2500

#endif
