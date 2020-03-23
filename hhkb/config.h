#include "config_common.h"
#include "../../config.h"

// Tapping behavior
#undef  TAPPING_TERM
#undef  TAPPING_TOGGLE
#undef  ONESHOT_TIMEOUT

#define TAPPING_TERM 150   // ms to hold a tap key to switch to modifier
#define TAPPING_TOGGLE 3   // press count to toggle a feature
#define ONESHOT_TIMEOUT 150   // ms for oneshots to be valid
