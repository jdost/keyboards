#include "config_common.h"
#include "../../config.h"

#ifndef USER_CONFIG_H
#define USER_CONFIG_H

// Tapping behavior -- dual purpose keys with behavior based on a "tap" vs a "hold"
#define TAPPING_TERM 220   // ms to hold a tap key to switch to modifier
#undef  PERMISSIVE_HOLD    // translates an ordered w/ dual purpose first as a
                           //   modifier even if under tap term
#undef  IGNORE_MOD_TAP_INTERRUPT
                           // treat out of order key press with tap key as a tap of both
#define RETRO_TAPPING      // a tap modifier without another key press is always a tap
#define TAPPING_FORCE_HOLD // tapping followed by a hold are differentiated

#endif
