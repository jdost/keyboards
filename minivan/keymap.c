#include "keymap_common.h"

#define BASE_LAYER 0
#define PROGRAMMING_LAYER 1
#define MOD_LAYER1 2
#define MOD_LAYER2 3
#define MOUSE_LAYER 4

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Layer: Base Layer
    * ,-------------------------------------------------.
    * |Tab|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| BSp |
    * |-------------------------------------------------|
    * |CtEs|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|Entr|
    * |-------------------------------------------------|
    * |Shift|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|FN3|
    * |-------------------------------------------------|
    * | FN3| Gui| Alt |  FN2  | Space |Alt | Gui |  FN1 |
    * `-------------------------------------------------'
    */
   [BASE_LAYER] = KEYMAP(
     TAB ,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,  BSPC, \
     FN5  ,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,  ENT, \
     LSFT  ,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH, FN3, \
     FN3 ,  LGUI,  LALT,     FN2,       SPC,   RALT,   RGUI,  FN1   ),

   /* Layer: Programming Layer
    * ,-------------------------------------------------.
    * |   |   |   |   |   |   |   |   |   |   |   |   \ |
    * |-------------------------------------------------|
    * |    |   |   |   |   |   |   |   |   |   |   |    |
    * |-------------------------------------------------|
    * | `/Sh|   |   |   |   |   |   |   |   |   |   |'Sh|
    * |-------------------------------------------------|
    * |    |    |     |BkspFN2|SpcFN3 |    |     |      |
    * `-------------------------------------------------'
    */
   [PROGRAMMING_LAYER] = KEYMAP(
     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  BSLS, \
     TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
     FN11  ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN12, \
     TRNS,  TRNS,  TRNS,     FN9,     FN10,   TRNS,   TRNS,  TRNS  ),

   /* Layer: Function Layer 1
    * ,-------------------------------------------------.
    * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0| Del |
    * |-------------------------------------------------|
    * |    |  [|  ]|  -|  =|   |Lft| Dn| Up| Rt|  '|   \|
    * |-------------------------------------------------|
    * |     |LDT|LD-|LD+|   |   |   |Prv|PlP|Nxt|   |   |
    * |-------------------------------------------------|
    * | FN4|    |     |       |       |    |     |      |
    * `-------------------------------------------------'
    */
   [MOD_LAYER1] = KEYMAP(
     GRV ,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   DEL, \
     TRNS ,LBRC,RBRC,MINS, EQL,TRNS,LEFT,DOWN,  UP,RGHT,QUOT, BSLS, \
     TRNS  , FN6, FN7, FN8,TRNS,TRNS,TRNS,MPRV,MPLY,MNXT,TRNS,TRNS, \
     FN4 ,  TRNS,  TRNS,     FN2,      SPC,   TRNS,   TRNS,  TRNS  ),

   /* Layer: Function Layer 2
    * ,-------------------------------------------------.
    * |Cap| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|     |
    * |-------------------------------------------------|
    * |    |F11|F12|   |   |   |Hom|PgD|PgU|End|   |    |
    * |-------------------------------------------------|
    * |     |   |   |   |   |   |   |Mut|Vl-|Vl+|   |   |
    * |-------------------------------------------------|
    * | FN3|    |     |       |       |    |     |      |
    * `-------------------------------------------------'
    */
   [MOD_LAYER2] = KEYMAP(
     CAPS,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10,  TRNS, \
     TRNS , F11, F12,TRNS,TRNS,TRNS,HOME,PGDN,PGUP, END,TRNS, TRNS, \
     TRNS  ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,TRNS, \
     FN3 ,  TRNS,  TRNS,    TRNS,      TRNS,   TRNS,   TRNS,  TRNS  ),

   /* Layer: Mouse Layer
    * ,-------------------------------------------------.
    * |FN4|   |MUp|   |MWu|   |   |   |   |   |   |     |
    * |-------------------------------------------------|
    * |    |MLt|MDn|MRt|MWd|   |   |Ac0|Ac1|Ac2|   |    |
    * |-------------------------------------------------|
    * |     |   |   |   |   |MB3|   |   |   |   |   |   |
    * |-------------------------------------------------|
    * |    |    |     | MB1   |  MB2  |    |     |      |
    * `-------------------------------------------------'
    */
   [MOUSE_LAYER] = KEYMAP(
     FN4 ,TRNS,MS_U,TRNS,WH_U,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS, \
     TRNS ,MS_L,MS_D,MS_R,WH_D,TRNS,TRNS,ACL0,ACL1,ACL2,TRNS, TRNS, \
     TRNS  ,TRNS,TRNS,TRNS,TRNS,BTN3,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
     TRNS,  TRNS,  TRNS,    BTN1,      BTN2,   TRNS,   TRNS,  TRNS  ),

#if 0
   /* Layer: XX Layer
    * ,-------------------------------------------------.
    * |   |   |   |   |   |   |   |   |   |   |   |     |
    * |-------------------------------------------------|
    * |    |   |   |   |   |   |   |   |   |   |   |    |
    * |-------------------------------------------------|
    * |     |   |   |   |   |   |   |   |   |   |   |   |
    * |-------------------------------------------------|
    * |    |    |     |       |       |    |     |      |
    * `-------------------------------------------------'
    */
   KEYMAP(
     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS, \
     TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
     TRNS  ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
     TRNS,  TRNS,  TRNS,    TRNS,      TRNS,   TRNS,   TRNS,  TRNS  ),
#endif
};

const action_t PROGMEM fn_actions[] = {
   [0]  = ACTION_LAYER_TOGGLE(BASE_LAYER), // Layer 0 (BASE_LAYER)
   [1]  = ACTION_DEFAULT_LAYER_BIT_XOR((PROGRAMMING_LAYER)/4, 1<<(PROGRAMMING_LAYER % 4)), // Layer 1 (PROGRAMMING_LAYER)
   [2]  = ACTION_LAYER_MOMENTARY(MOD_LAYER1), // Layer 2 (MOD_LAYER1)
   [3]  = ACTION_LAYER_MOMENTARY(MOD_LAYER2), // Layer 3 (MOD_LAYER2)
   [4]  = ACTION_LAYER_TAP_TOGGLE(MOUSE_LAYER), // Layer 4 (MOUSE_LAYER)
   [5]  = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC), // Ctrl + Esc
   [6]  = ACTION_BACKLIGHT_TOGGLE(), // LED Toggle
   [7]  = ACTION_BACKLIGHT_DECREASE(), // LED-
   [8]  = ACTION_BACKLIGHT_INCREASE(), // LED+
   [9]  = ACTION_LAYER_TAP_KEY(MOD_LAYER1, KC_BSPC), // MOD_LAYER1 + Backspace
   [10] = ACTION_LAYER_TAP_KEY(MOD_LAYER2, KC_SPC), // MOD_LAYER2 + Space
   [11] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_GRV), // Shift + Grave
   [12] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_QUOT), // Shift + Quote
};
