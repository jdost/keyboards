#include "config_common.h"
#include "../../config.h"

#ifndef USER_CONFIG_H
#define USER_CONFIG_H

// Reset previously defined constants
#undef  TAPPING_TERM

// Tapping behavior
#define TAPPING_TERM 200    // ms to hold a tap key to switch to modifier
#define TAPPING_TOGGLE 3    // press count to toggle a feature
#define ONESHOT_TIMEOUT 200 // ms for oneshots to be valid
#define PERMISSIVE_HOLD     // translates an ordered w/ dual purpose first as a
                            //   modifier even if under tap term
#define IGNORE_MOD_TAP_INTERRUPT
                            // treat out of order key press with tap key as a tap of both
#define RETRO_TAPPING       // a tap modifier without another key press is always a tap
#define TAPPING_FORCE_HOLD  // tapping followed by a hold are differentiated

#endif
