#include "keymap_common.h"

#define SPACEFN_LAYER 0
#define BASE_LAYER 1
#define MOD_LAYER1 2
#define MOD_LAYER2 4
#define MOUSE_LAYER 5

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer: Default Layer
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSp  |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |CrlEsc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
     * |-----------------------------------------------------------|
     * | L5 |Gui| Alt |      Space+L2         | Alt |Gui| L5 | Ctrl|
     * `-----------------------------------------------------------'
     */
    [SPACEFN_LAYER] = KEYMAP_ANSI(
      GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL,BSPC,  \
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,  \
      FN7, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,      ENT,  \
      LSFT,FN4, X,   C,   V,   B,   N,   M,   COMM,DOT, FN5,           RSFT,  \
      FN3, LGUI,LALT,          FN6,                RALT,RGUI, FN3,     RCTL),

    /* Layer 1: No SpaceFN Layer
     * ,-----------------------------------------------------------.
     * |Esc|   |   |   |   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * | Ctrl |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * | L2 |   |     |        Space          |     |   | L2 |     |
     * `-----------------------------------------------------------'
     */
    [BASE_LAYER] = KEYMAP_ANSI(
      ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
      LCTL,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,   \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,   \
      FN1, TRNS,TRNS,          SPC,                TRNS,TRNS, FN1,     TRNS),

    /* Layer: Mod Layer 1
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
     * |-----------------------------------------------------------|
     * |Caps |   |Up |   |   |   |Hom|PgD|PgU|End|   |   |   |   ` |
     * |-----------------------------------------------------------|
     * |      |Lft|Dow|Rgt|   |   |Lft|Dow|Up |Rgt|   |   | L0/L1  |
     * |-----------------------------------------------------------|
     * |        |MPv|MPP|MNt|   |   |   |   |Mut|VoD|VoU|          |
     * |-----------------------------------------------------------|
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [MOD_LAYER1] = KEYMAP_ANSI(
      PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,   \
      CAPS,TRNS, UP, TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS,GRV,   \
      TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN, UP, RGHT,TRNS,TRNS,FN18,       \
      TRNS,MPRV,MPLY,MNXT,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,            \
      FN1, TRNS,TRNS,          FN6,                TRNS,TRNS,FN1, TRNS),
    /* Layer: Mod Layer 2
     * ,-----------------------------------------------------------.
     * |   |KA1|KA2|   |   |   |   |   |   |   |   |LD-|LD+| LEDT  |
     * |-----------------------------------------------------------|
     * | KVT |KV1|KV2|   |   |   |   |   |WSh|WHm|   |   |   |     |
     * |-----------------------------------------------------------|
     * | KVM  |   |   |   |   |   |   |WBk|WSt|WRf|WFd|   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * | KVS |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [MOD_LAYER2] = KEYMAP_ANSI(
      TRNS,FN11,FN12,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN15,FN16,FN17,   \
      FN10,FN13,FN14,TRNS,TRNS,TRNS,TRNS,TRNS,WSCH,WHOM,TRNS,TRNS,TRNS,TRNS,   \
      FN8, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WSTP,WREF,WFWD,TRNS,TRNS,        \
      TRNS,FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN5, TRNS,             \
      FN9, TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),
    /* Layer: Mouse Layer
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |     |MwU|McU|MwD|   |   |   |Ac0|Ac1|Ac2|   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |McL|McD|McR|   |   |   |Mb1|Mb2|Mb3|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |     |   |     |          Mb1          |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [MOUSE_LAYER] = KEYMAP_ANSI(
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
      TRNS,WH_U,MS_U,WH_D,TRNS,TRNS,TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,TRNS,TRNS,   \
      TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,TRNS,        \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
      FN0, TRNS,TRNS,          BTN1,               TRNS,TRNS, FN0,TRNS),
#if 0
    /* Layer X:
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [X] = \
    KEYMAP_ANSI(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
                TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
                TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
                TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
                TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),
#endif
};

enum macro_id {
   KVM_MOD,
   KVM_HSM,
   KVM_TOGGLE,
   KVM_ALL1,
   KVM_ALL2,
   KVM_V1,
   KVM_V2
};

enum function_id {
   TOGGLE_BASE_LAYER,
};

const action_t PROGMEM fn_actions[] = {
     [0] = ACTION_LAYER_TOGGLE(MOUSE_LAYER),
     [1] = ACTION_LAYER_MOMENTARY(MOD_LAYER1),
     [2] = ACTION_LAYER_MOMENTARY(MOD_LAYER2),
     [3] = ACTION_LAYER_TAP_TOGGLE(MOUSE_LAYER),
     [4] = ACTION_LAYER_TAP_KEY(MOD_LAYER2, KC_Z),
     [5] = ACTION_LAYER_TAP_KEY(MOD_LAYER2, KC_SLSH),
     [6] = ACTION_LAYER_TAP_KEY(MOD_LAYER1, KC_SPACE),
     [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
     [8] = ACTION_MACRO(KVM_MOD),
     [9] = ACTION_MACRO(KVM_HSM),
    [10] = ACTION_MACRO(KVM_TOGGLE),
    [11] = ACTION_MACRO(KVM_ALL1),
    [12] = ACTION_MACRO(KVM_ALL2),
    [13] = ACTION_MACRO(KVM_V1),
    [14] = ACTION_MACRO(KVM_V2),
    [15] = ACTION_BACKLIGHT_DECREASE(),
    [16] = ACTION_BACKLIGHT_INCREASE(),
    [17] = ACTION_BACKLIGHT_TOGGLE(),
    [18] = ACTION_DEFAULT_LAYER_BIT_XOR((BASE_LAYER)/4, 1<<(BASE_LAYER % 4)),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
   switch (id) {
      case KVM_MOD:
         return (record->event.pressed ?
                 MACRO(I(100), T(SLCK), W(10), T(SLCK), I(0), END) :
                 MACRO_NONE );
      case KVM_HSM:
         return (record->event.pressed ?
                 MACRO(I(100), D(NUMLOCK), T(MINUS), U(NUMLOCK), I(0), END) :
                 MACRO_NONE );
      case KVM_TOGGLE:
         return (record->event.pressed ?
                 MACRO(I(100), T(SLCK), W(10), T(SLCK),
                       W(10), T(ENTER), I(0), END) :
                 MACRO_NONE );
      case KVM_ALL1:
         return (record->event.pressed ?
                 MACRO(I(100), T(SLCK), W(10), T(SLCK),
                       W(10), T(1), T(ENTER), I(0), END) :
                 MACRO_NONE );
      case KVM_ALL2:
         return (record->event.pressed ?
                 MACRO(I(100), T(SLCK), W(10), T(SLCK),
                       W(10), T(2), T(ENTER), I(0), END) :
                 MACRO_NONE );
      case KVM_V1:
         return (record->event.pressed ?
                 MACRO(I(100), T(SLCK), W(10), T(SLCK),
                       W(10), T(1), T(K), T(ENTER), I(0), END) :
                 MACRO_NONE );
      case KVM_V2:
         return (record->event.pressed ?
                 MACRO(I(100), T(SLCK), W(10), T(SLCK),
                       W(10), T(2), T(K), T(ENTER), I(0), END) :
                 MACRO_NONE );
   }
   return MACRO_NONE;
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
   switch (id) {
      case TOGGLE_BASE_LAYER:
         if (record->event.pressed) {
            if (default_layer_state == SPACEFN_LAYER) {
               default_layer_set(BASE_LAYER);
            } else if (default_layer_state == BASE_LAYER) {
               default_layer_set(SPACEFN_LAYER);
            }
         }

         break;
    }
}
