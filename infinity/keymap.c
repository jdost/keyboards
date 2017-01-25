#include "keymap_common.h"

#define BASE_LAYER 0
#define SPACEFN_LAYER 1
#define MOD_LAYER1 2
#define MOD_LAYER2 3
#define NUMPAD_LAYER 4
#define MOUSE_LAYER 5

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer: Base Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|BSp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * | Ctrl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * | Shift  |Fn5|  X|  C|  V|  B|  N|  M|  ,|  .|Fn6| Shift|Fn1|
     * |-----------------------------------------------------------|
     * |Fn0  |Gui|Alt  |         Space         |Alt  |Gui|Fn0| Ctrl|
     * `-----------------------------------------------------------'
     */
    [BASE_LAYER] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV,BSPC,  \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, ENT,           \
           LSFT,FN5, X,   C,   V,   B,   N,   M,   COMM,DOT, FN6, RSFT, FN1,           \
           FN0, LGUI,LALT,          SPC,                RALT,RGUI, FN0,RCTL),

    /* Layer: SpaceFn Layer
     * ,-----------------------------------------------------------.
     * |  `|   |   |   |   |   |   |   |   |   |   |   |   |Fn8|   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |CrlEsc|   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------|
     * |     |   |     |      SpaceFn          |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [SPACEFN_LAYER] = \
    KEYMAP(GRV ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN8,TRNS,   \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           FN2 ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,           FN3,               TRNS,TRNS,TRNS,TRNS),

    /* Layer: Mod Layer 1
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * | Cap |   |Up |   |   |   |   |Hom|PgD|PgU|End|   |   |     |
     * |-----------------------------------------------------------|
     * |      |Lft|Dow|Rgt|   |   |   |Lft|Dow|Up |Rgt|   |  Fn4   |
     * |-----------------------------------------------------------|
     * |        |MPv|MPP|MNt|   |   |   |   |Mut|VoD|VoU|      |   |
     * |-----------------------------------------------------------|
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [MOD_LAYER1] = \
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           CAPS,TRNS, UP, TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS,TRNS,       \
           TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN, UP, RGHT,TRNS,TRNS,FN4 ,            \
           TRNS,MPRV,MPLY,MNXT,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,RSFT,TRNS,            \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),
    /* Layer 2: Mod Layer 2
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |WSh|WHm|   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |WBk|WSt|WRf|WFd|   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------|
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [MOD_LAYER2] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WSCH,WHOM,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WSTP,WREF,WFWD,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),
    /* Layer 3: Numpad Layer
     * ,-----------------------------------------------------------.
     * |   | / | * | - |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     | 7 | 8 | 9 | + |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |NumLck| 4 | 5 | 6 |Ent|   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        | 1 | 2 | 3 | . |   |   |   |   |   |   |      |Fn7|
     * |-----------------------------------------------------------|
     * |     |   |  0  |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [NUMPAD_LAYER] = \
    KEYMAP(TRNS,PSLS,PAST,PMNS,PEQL, NO ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
           TRNS, P7 , P8 , P9 ,PPLS, NO ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           NLCK, P4 , P5 , P6 ,PENT, NO ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS, P1 , P2 , P3 ,PDOT, NO ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN7 ,             \
           TRNS,TRNS, P0 ,          TRNS,               TRNS,TRNS,TRNS,TRNS),
    /* Layer 4: Mouse Layer
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |Fn8|   |
     * |-----------------------------------------------------------|
     * |     |MwU|McU|MwD|   |   |   |Ac0|Ac1|Ac2|   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |McL|McD|McR|   |   |   |Mb1|Mb2|Mb3|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------|
     * |     |   |     |          Mb1          |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [MOUSE_LAYER] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN8,TRNS,   \
           TRNS,WH_U,MS_U,WH_D,TRNS,TRNS,TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,          BTN1,               TRNS,TRNS,TRNS,TRNS),
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
     * |-----------------------------------------------------------|
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [X] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),
#endif
};

const action_t fn_actions[] = {
     [0] = ACTION_LAYER_MOMENTARY(MOD_LAYER1),
     [1] = ACTION_LAYER_TAP_TOGGLE(NUMPAD_LAYER),
     [2] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
     [3] = ACTION_LAYER_TAP_KEY(MOD_LAYER1, KC_SPACE),
     [4] = ACTION_DEFAULT_LAYER_BIT_XOR((SPACEFN_LAYER)/4, 1<<(SPACEFN_LAYER % 4)),
     [5] = ACTION_LAYER_TAP_KEY(MOD_LAYER2, KC_Z),
     [6] = ACTION_LAYER_TAP_KEY(MOD_LAYER2, KC_SLSH),
     [7] = ACTION_LAYER_TOGGLE(NUMPAD_LAYER),
     [8] = ACTION_LAYER_TOGGLE(MOUSE_LAYER),
};
