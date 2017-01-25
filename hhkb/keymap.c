#include "keymap_common.h"

#define SPACEFN_LAYER 0
#define BASE_LAYER 1
#define MOD_LAYER1 2
#define MOD_LAYER2 3
#define NUMPAD_LAYER 4
#define MOUSE_LAYER 5

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
    /* Layer: Base Layer
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| L3|BSp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |CtlEsc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift|   |
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |        Space+L2       |Gui  |Alt|
     *       `-------------------------------------------'
     */
    [SPACEFN_LAYER] = \
    KEYMAP(GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, FN4,BSPC,  \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      \
           FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, ENT,           \
           LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,  NO,           \
           LALT,LGUI,          FN0,                RGUI,RALT),
    /* Layer 1: No SpaceFN Layer
     * ,-----------------------------------------------------------.
     * |Esc|   |   |   |   |   |   |   |   |   |   |   |   |  `|   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * | Ctrl |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      | L2|
     * `-----------------------------------------------------------'
     *       |   |     |       Space           |     |   |
     *       `-------------------------------------------'
     */
    [BASE_LAYER] = \
    KEYMAP(ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, GRV,TRNS,   \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           LCTL,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN3,             \
           TRNS,TRNS,           SPC,               TRNS,TRNS),
    /* Layer 2: Mod Layer 1
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |Del|
     * |-----------------------------------------------------------|
     * |Caps |   | Up|   |   |   |Hom|PgD|PgU|End|   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |Lft|Dwn|Rgt|   |   |Lft|Dwn| Up|Rgt|   |   | L0/L1  |
     * |-----------------------------------------------------------|
     * |        |MPv|MPP|MNt|   |   |   |   |Mut|VoD|VoU|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    [MOD_LAYER1] = \
    KEYMAP(PWR,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,TRNS, DEL,   \
           CAPS,TRNS, UP, TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN, UP, RGHT,TRNS,TRNS, FN2,             \
           TRNS,MPRV,MPLY,MNXT,TRNS,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,             \
           TRNS,TRNS,           FN0,               TRNS,TRNS),
    /* Layer 3: Mouse Layer
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |MwD|McU|MwU|   |   |   |   |Ac0|Ac1|Ac2|   |   |     |
     * |-----------------------------------------------------------|
     * |      |McL|McD|McR|   |   |   |   |Mb1|Mb2|Mb3|   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * `-----------------------------------------------------------'
     *       |   |     |        Mb1            |     |   |
     *       `-------------------------------------------'
     */
    [MOUSE_LAYER] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN4,TRNS,   \
           TRNS,WH_D,MS_U,WH_U,TRNS,TRNS,TRNS,TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,TRNS,        \
           TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,          BTN1,               TRNS,TRNS),
#if 0
    /* Layer X:
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    [X] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,          TRNS,               TRNS,TRNS),
#endif
};

const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
     [0] = ACTION_LAYER_TAP_KEY(MOD_LAYER1, KC_SPACE), // Space+L2
     [1] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC), // Ctrl+Esc
     [2] = ACTION_DEFAULT_LAYER_BIT_XOR((BASE_LAYER)/4, 1<<((BASE_LAYER) % 4)), // L0-L1
     [3] = ACTION_LAYER_MOMENTARY(MOD_LAYER1), // L2
     [4] = ACTION_LAYER_MOMENTARY(MOUSE_LAYER), // L3
};
