#include "config_common.h"
#include "../../config.h"

// Tapping behavior
#define TAPPING_TERM 160   // ms to hold a tap key to switch to modifier
#undef  PERMISSIVE_HOLD    // translates an out of order press release as two presses
#undef  RETRO_TAPPING      // a tap modifier without another key press is always a tap
