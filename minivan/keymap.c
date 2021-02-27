#include QMK_KEYBOARD_H

/***
 Minivan (tv44)
 44 key mini keyboard, split space and no numrow, limited rightside modifiers
 ***/

#define ________ KC_TRNS
#define ___XX___ KC_NO
#define KC_L1 MO(EXTENDED1)
#define KC_L2 MO(EXTENDED2)
#define DK_CLESC LCTL_T(KC_ESC)
#define DK_SPCL2 LT(EXTENDED2, KC_SPC)
#define DK_BSPL1 LT(EXTENDED1, KC_BSPC)
#define DK_QTSFT RSFT_T(KC_QUOT)
#define DK_GRSFT LSFT_T(KC_GRV)

//Layer Aliases
enum Layer {
   BASE,       // Base QWERTY layer
   PROGRAMMER, // Modified QWERTY with dual keys to provide common programming keys
   EXTENDED1,  // Extended keys that don't fit on the base
   EXTENDED2,  // More extended keys that don't fit on the base
   NOTHING
};

enum CUSTOM_KEYCODES {
   CK_LYSWP = SAFE_RANGE,  // Swaps the default layer between BASE and NO_DUALS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case CK_LYSWP:
         if (record->event.pressed) {
            // We turn the `PROGRAMMER` layer on and off since it takes precedence
            layer_invert(PROGRAMMER);
         }
         return false;
   }
   return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* TEMPLATE LAYER
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
 │   │   │   │   │   │   │   │   │   │   │   │      │
 ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
 │    │   │   │   │   │   │   │   │   │   │   │     │
 ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 │      │   │   │   │   │   │   │   │   │   │   │   │
 ├────┬─┴───┼───┴┬──┴───┴─┬─┴───┴─┬─┴──┬┴───┴┬──┴───┤
 │    │     │    │        │       │    │     │      │
 └────┴─────┴────┴────────┴───────┴────┴─────┴──────┘
    */
   [NOTHING] = LAYOUT(
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________,           ________,           ________,           ________, ________, ________  \
   ),
   /* BASE LAYER
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
 │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ BkSpc│
 ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
 │CtEs│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │Enter│
 ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 │Shift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ L2│
 ├────┬─┴───┼───┴┬──┴───┴─┬─┴───┴─┬─┴──┬┴───┴┬──┴───┤
 │ L2 │ Gui │Alt │  L1    │ Space │Alt │ Gui │SwapBs│
 └────┴─────┴────┴────────┴───────┴────┴─────┴──────┘
    */
   [BASE] = LAYOUT(
      KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC , \
      DK_CLESC, KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_ENT  , \
      KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_L2   , \
      KC_L2   , KC_LGUI , KC_LALT ,           KC_L1   ,           KC_SPC  ,           KC_RALT , KC_RGUI , CK_LYSWP  \
   ),
   /* PROGRAMMER LAYER
    *   Modifications to the base to help with programming keystrokes
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
 │   │   │   │   │   │   │   │   │   │   │   │  \   │
 ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
 │    │   │   │   │   │   │   │   │   │   │   │     │
 ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 │`/Shft│   │   │   │   │   │   │   │   │   │   │'/S│
 ├────┬─┴───┼───┴┬──┴───┴─┬─┴───┴─┬─┴──┬┴───┴┬──┴───┤
 │    │     │    │BkSpc/L1│Spac/L2│    │     │      │
 └────┴─────┴────┴────────┴───────┴────┴─────┴──────┘
    */
   [PROGRAMMER] = LAYOUT(
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, KC_BSLS , \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      DK_GRSFT, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, DK_QTSFT, \
      ________, ________, ________,           DK_BSPL1,           DK_SPCL2,           ________, ________, ________  \
   ),
   /* EXTENDED1 LAYER
    *   Common modifiers that don't fit on the 40% format
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
 │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │      │
 ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
 │    │ [ │ ] │ - │ = │ \ │Lft│Dwn│Up │Rgt│ ' │     │
 ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 │      │MPv│MPy│MNx│   │   │   │   │   │   │   │   │
 ├────┬─┴───┼───┴┬──┴───┴─┬─┴───┴─┬─┴──┬┴───┴┬──┴───┤
 │    │     │    │        │       │    │     │      │
 └────┴─────┴────┴────────┴───────┴────┴─────┴──────┘
    */
   [EXTENDED1] = LAYOUT(
      KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , ________, \
      ________, KC_LBRC , KC_RBRC , KC_MINS , KC_EQL  , KC_BSLS , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_QUOT , ________, \
      ________, KC_MPRV , KC_MPLY , KC_MNXT , ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________,           ________,           ________,           ________, ________, ________  \
   ),
   /* EXTENDED2 LAYER
    *   More common modifiers that don't fit on the first or second layer
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
 │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│      │
 ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
 │    │   │   │   │   │   │Hom│PgD│PgU│End│   │     │
 ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 │      │BLT│BL-│BL+│BLB│   │   │   │   │   │   │   │
 ├────┬─┴───┼───┴┬──┴───┴─┬─┴───┴─┬─┴──┬┴───┴┬──┴───┤
 │    │     │    │        │       │    │     │      │
 └────┴─────┴────┴────────┴───────┴────┴─────┴──────┘
    */
   [EXTENDED2] = LAYOUT(
      ________, KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , ________, \
      ________, ________, ________, ________, ________, ________, KC_HOME , KC_PGDN , KC_PGUP , KC_END  , ________, ________, \
      ________, BL_TOGG , BL_DEC  , BL_INC  , BL_BRTG , ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________,           ________,           ________,           ________, ________, ________  \
   ),
};
