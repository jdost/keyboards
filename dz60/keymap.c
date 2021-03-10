#include QMK_KEYBOARD_H

/***
 DZ60 keyboard, purchased via Massdrop (made by KBDFans)
 Hotswap sockets, per key RGB
 ***/

//Layer Aliases
enum Layer {
   BASE,       // Base layer, normal QWERTY
   NO_DUALS,   // Modified Base without DK_* keys
   EXTENDED,   // Extension layer
   SPECIAL,    // Special key layer
   NOTHING
};

//Key aliases
#define DK_CLESC LCTL_T(KC_ESC)
#define DK_SPCL1 LT(EXTENDED, KC_SPC)
#define KC_L1 MO(EXTENDED)
#define KC_L2 MO(SPECIAL)
#define ________ KC_TRNS
#define ___XX___ KC_NO

//Custom Keys
enum CUSTOM_KEYCODES {
    CK_MPRV = SAFE_RANGE, // KVM safe alias for KC_MPRV
    CK_MPLY,              // KVM safe alias for KC_MPLY
    CK_MNXT,              // KVM safe alias for KC_MNXT
    CK_MUTE,              // KVM safe alias for KC_MUTE
    CK_VOLD,              // KVM safe alias for KC_VOLD
    CK_VOLU,              // KVM safe alias for KC_VOLU
    CK_KVML1,             // KVM: Switch to input 1
    CK_KVML2,             // KVM: Switch to input 2
    CK_KVML3,             // KVM: Switch to input 3
    CK_KVML4,             // KVM: Switch to input 4
    CK_LYSWP,             // Swap default layers: BASE <-> NO_DUALS
};

// Macro helper definitions
#define MACRO_SEND_STRING(STR) \
    if (record->event.pressed) { \
        SEND_STRING(STR); \
    } \
    break;
#ifdef KVM_USE
#define KVM_MOD SS_TAP(X_SLCK) SS_DELAY(5) SS_TAP(X_SLCK) SS_DELAY(5)
#define KVM_CMD(STR) MACRO_SEND_STRING(KVM_MOD STR)
#else
#define KVM_CMD(STR) \
    break;
#endif

void start_animation(void);
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_MPLY: // MPLY = GUI + DOWN
            MACRO_SEND_STRING(SS_LGUI(SS_TAP(X_DOWN)));
        case CK_MPRV: // MPRV = GUI + LEFT
            MACRO_SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
        case CK_MNXT: // MNXT = GUI + RIGHT
            MACRO_SEND_STRING(SS_LGUI(SS_TAP(X_RGHT)));
        case CK_MUTE: // MUTE = GUI + SHIFT + DOWN
            MACRO_SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_DOWN))));
        case CK_VOLD: // VOLD = GUI + SHIFT + LEFT
            MACRO_SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_LEFT))));
        case CK_VOLU: // VOLU = GUI + SHIFT + RIGHT
            MACRO_SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_RGHT))));
        case CK_KVML1:
            KVM_CMD("1");
        case CK_KVML2:
            KVM_CMD("2");
        case CK_KVML3:
            KVM_CMD("3");
        case CK_KVML4:
            KVM_CMD("4");
        case CK_LYSWP:
            if (record->event.pressed) {
                // We just enable/disable the higher precedent layer
                layer_invert(NO_DUALS);
            }
            return false;
        case RESET:
            if (record->event.pressed) {
                start_animation();
                rgb_matrix_sethsv_noeeprom(0, 0xFF, 0x80);
                rgb_matrix_mode_noeeprom(1);
                return false;
            } else {
                reset_keyboard();
            }
    }
    return true;
}

// When this is built for use with a KVM, we need to replace some advanced keycodes
//  for the media keys that get filtered out by the KVM with documented macros that
//  get handled specially in the OS
#ifdef KVM_USE
#  undef KC_MPRV
#  define KC_MPRV CK_MPRV
#  undef KC_MPLY
#  define KC_MPLY CK_MPLY
#  undef KC_MNXT
#  define KC_MNXT CK_MNXT
#  undef KC_MUTE
#  define KC_MUTE CK_MUTE
#  undef KC_VOLD
#  define KC_VOLD CK_VOLD
#  undef KC_VOLU
#  define KC_VOLU CK_VOLU
#endif

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* TEMPLATE LAYER
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │      │   │   │   │   │   │   │   │   │   │   │   │        │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 │        │   │   │   │   │   │   │   │   │   │   │          │
 ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 │    │    │    │                        │    │    │    │    │
 └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
    [NOTHING] = LAYOUT_60_ansi(
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        ________, ________, ________, ________,                                                   ________, ________, ________, ________  \
    ),
    /* BASE LAYER
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │ BkSp  │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │CtlEsc│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift    │
 ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 │Ctrl│Mod │Alt │        SpaceL1         │Alt │Mod │ L2 │Ctrl│
 └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
    [BASE] = LAYOUT_60_ansi(
        KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , \
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS , \
        DK_CLESC, KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  , \
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , \
        KC_LCTL , KC_LGUI , KC_LALT , DK_SPCL1,                                                   KC_RALT , KC_RGUI , KC_L2   , KC_RCTL   \
    ),
    /* NO DUAL PURPOSE LAYER, VARIANT OF BASE
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │ BkSp  │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift    │
 ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 │ L1 │Mod │Alt │         Space          │Alt │Mod │ L2 │ L1 │
 └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
    [NO_DUALS] = LAYOUT_60_ansi(
        KC_GESC , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , \
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS , \
        KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  , \
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , \
        KC_L1   , KC_LGUI , KC_LALT , KC_SPC  ,                                                   KC_RALT , KC_RGUI , KC_L2   , KC_L1     \
    ),
    /* EXTENSION LAYER
     *   Common keys that don't fit on the base layer for a 60%
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Del   │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 │     │   │   │   │   │   │Hme│PgD│PgU│End│   │   │   │ Ins │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │      │   │   │   │   │   │Lft│Dwn│Up │Rgt│   │   │        │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 │        │MPr│MPl│MNx│   │   │   │VMt│V- │V+ │   │          │
 ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 │    │    │    │                        │    │    │    │    │
 └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
    [EXTENDED] = LAYOUT_60_ansi(
        ________, KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DEL  , \
        ________, ________, ________, ________, ________, ________, KC_HOME , KC_PGDN , KC_PGUP , KC_END  , ________, ________, ________, KC_INS  , \
        ________, ________, ________, ________, ________, ________, KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , ________, ________, ________, \
        ________, KC_MPRV , KC_MPLY , KC_MNXT , ________, ________, ________, KC_MUTE , KC_VOLD , KC_VOLU , ________, ________, \
        ________, ________, ________, ________,                                                   ________, ________, ________, ________  \
    ),
    /* SPECIAL KEYSET LAYER
     *   For KVM and LED controls
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 │   │KV1│KV2│KV3│KV4│   │   │   │   │   │   │   │   │       │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │ RSET │   │   │   │   │   │   │   │   │   │   │   │ L0L1SWP│
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 │        │   │   │   │   │   │   │   │   │   │   │          │
 ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 │    │    │    │                        │    │    │    │    │
 └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
    [SPECIAL] = LAYOUT_60_ansi(
        ________, CK_KVML1, CK_KVML2, CK_KVML3, CK_KVML4, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        RESET   , ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, CK_LYSWP, \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
        ________, ________, ________, ________,                                                   ________, ________, ________, ________  \
    ),
};

//RGB LED Matrix
    /* LED INDEXES
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 │ 13│ 12│ 11│ 10│ 9 │ 8 │ 7 │ 6 │ 5 │ 4 │ 3 │ 2 │ 1 │   0   │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 │  27 │ 26│ 25│ 24│ 23│ 22│ 21│ 20│ 19│ 18│ 17│ 16│ 15│ 14  │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │  40  │ 39│ 38│ 37│ 36│ 35│ 34│ 33│ 32│ 31│ 30│ 29│  28    │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 │   52   │ 51│ 50│ 49│ 48│ 47│ 46│ 45│ 44│ 43│ 42│   41     │
 ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 │ 60 │ 59 │ 58 │          57            │ 56 │ 55 │ 54 │ 53 │
 └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */

//Startup Animation Handling
/*
 * For the startup animation, we set the effect in the _begin function and launch
 * a timer.  Then the _running function is put in any callback that manipulates the
 * matrix to skip out if the startup animation is ongoing.  Then the _end function
 * is called to check if the animation has elapsed and then will trigger the short
 * fade out effect before clearing the state.
 */
bool animation;
static uint16_t animation_timer;
void start_animation(void) {
    animation_timer = timer_read();
    animation = 1;
}

void startup_animation_begin(void) {
    start_animation();
    rgb_matrix_mode_noeeprom(STARTUP_ANIMATION);
}

bool startup_animation_running(void) {
    return animation && timer_elapsed(animation_timer) < STARTUP_ANIMATION_DURATION;
}

void startup_animation_end(void) {
    if (!animation)
        return;

    if (timer_elapsed(animation_timer) % 16 == 0) {
        if (timer_elapsed(animation_timer) >= STARTUP_ANIMATION_DURATION) {
            uint8_t v = rgb_matrix_get_val();
            if (v <= 0) {
                animation = 0;
                rgb_matrix_mode(BASE_RGB_MODE);
                rgb_matrix_sethsv(BASE_RGB);
            } else {
                rgb_matrix_sethsv_noeeprom(
                    rgb_matrix_get_hue(), rgb_matrix_get_sat(), v - 1
                );
            }
        }
    }
}

void keyboard_post_init_user(void) {
    startup_animation_begin();
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
    startup_animation_begin();
}

void housekeeping_task_user(void) {
    startup_animation_end();
}

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || rgb_matrix_config.enable) {
        return;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (startup_animation_running())
        return state;

    uint8_t mode = rgb_matrix_get_mode();
    switch(biton32(state)) {
        case BASE:
            rgb_matrix_sethsv(BASE_RGB);
            rgb_matrix_mode(BASE_RGB_MODE);
            break;
        case NO_DUALS:
            rgb_matrix_sethsv_noeeprom(NO_DUALS_RGB);
            rgb_matrix_mode_noeeprom(NO_DUALS_RGB_MODE);
            break;
        case EXTENDED:
            rgb_matrix_sethsv_noeeprom(EXTENDED_RGB);
            rgb_matrix_mode_noeeprom(EXTENDED_RGB_MODE);
            break;
        case SPECIAL:
            rgb_matrix_sethsv_noeeprom(SPECIAL_RGB);
            rgb_matrix_mode_noeeprom(SPECIAL_RGB_MODE);
            break;
        default:
            rgb_matrix_mode(mode);
            break;
    }
    return state;
}
