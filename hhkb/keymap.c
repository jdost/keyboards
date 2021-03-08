#include QMK_KEYBOARD_H

/***
 Happy Hacking Keyboard w/ hasu controller
 Topre switches in a 60% layout with some customizations
 ***/

#define KVM_USE 1

//Layer Aliases
enum Layer {
   BASE,       // Base QWERTY layer
   NO_DUALS,   // Modified Base with no dual purpose keys
   EXPANDED,   // Normal keys that don't fit on the base
   SPECIAL,    // Special actions based on firmware functionality
   NOTHING
};

#define ________ KC_TRNS
#define ___XX___ KC_NO
#define DK_CLESC LCTL_T(KC_ESC)
#define DK_SPCL1 LT(EXPANDED, KC_SPC)
#define KC_L1 MO(EXPANDED)
#define KC_L2 MO(SPECIAL)

enum CUSTOM_KEYCODES {
   CK_KVML1 = SAFE_RANGE,  // KVM: Switch to input 1
   CK_KVML2,  // KVM: Switch to input 2
   CK_KVML3,  // KVM: Switch to input 3
   CK_KVML4,  // KVM: Switch to input 4
   CK_LYSWP,  // Swaps the default layer between BASE and NO_DUALS
   CK_MPRV,   // Use KVM safe alias for KC_MPRV
   CK_MPLY,   // Use KVM safe alias for KC_MPLY
   CK_MNXT,   // Use KVM safe alias for KC_MNXT
   CK_MUTE,   // Use KVM safe alias for KC_MUTE
   CK_VOLD,   // Use KVM safe alias for KC_VOLD
   CK_VOLU    // Use KVM safe alias for KC_VOLU
};
// If in KVM mode, the advanced keycodes don't go through, so remap them to some
//  macros that do go through and get interpretted by the OS
#ifdef KVM_USE
#undef  KC_MPRV
#define KC_MPRV CK_MPRV
#undef  KC_MPLY
#define KC_MPLY CK_MPLY
#undef  KC_MNXT
#define KC_MNXT CK_MNXT
#undef  KC_MUTE
#define KC_MUTE CK_MUTE
#undef  KC_VOLD
#define KC_VOLD CK_VOLD
#undef  KC_VOLU
#define KC_VOLU CK_VOLU
#else
// If not in KVM mode, the expanded layer is not used, just remap the switching key
//  to L1
#undef  KC_L2
#define KC_L2 KC_L1
#endif

#define KVM_MOD SS_TAP(X_SLCK) SS_DELAY(5) SS_TAP(X_SLCK) SS_DELAY(5)
#define MACRO_SEND_STRING(STR) \
if (record->event.pressed) { \
   SEND_STRING(STR); \
} \
break;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case CK_KVML1:
         MACRO_SEND_STRING(KVM_MOD "1");
      case CK_KVML2:
         MACRO_SEND_STRING(KVM_MOD "2");
      case CK_KVML3:
         MACRO_SEND_STRING(KVM_MOD "3");
      case CK_KVML4:
         MACRO_SEND_STRING(KVM_MOD "4");
      case CK_LYSWP:
         if (record->event.pressed) {
            // We turn the `NO_DUALS` layer on and off since it takes precedence
            layer_invert(NO_DUALS);
         }
         return false;
      case CK_MPRV:
         MACRO_SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
      case CK_MPLY:
         MACRO_SEND_STRING(SS_LGUI(SS_TAP(X_DOWN)));
      case CK_MNXT:
         MACRO_SEND_STRING(SS_LGUI(SS_TAP(X_RGHT)));
      case CK_MUTE:
         MACRO_SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_DOWN))));
      case CK_VOLD:
         MACRO_SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_LEFT))));
      case CK_VOLU:
         MACRO_SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_RGHT))));
   }
   return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* TEMPLATE LAYER
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │      │   │   │   │   │   │   │   │   │   │   │   │        │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 │        │   │   │   │   │   │   │   │   │   │   │      │   │
 └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
       │   │     │                       │     │   │
       └───┴─────┴───────────────────────┴─────┴───┘
   */
   [NOTHING] = LAYOUT(
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
                ________, ________, ________,                                                   ________, ________ \
   ),
   /* BASE LAYER
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ L1│BSp│
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │CtlEsc│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ L2│
 └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
       │Mod│ Alt │      SpaceL1          │ Alt │Mod│
       └───┴─────┴───────────────────────┴─────┴───┘
   */
   [BASE] = LAYOUT(
      KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_L1  , KC_BSPC, \
      KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS, \
      DK_CLESC, KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  , \
      KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_L2   , \
                KC_LGUI , KC_LALT , DK_SPCL1,                                                   KC_RALT , KC_RGUI  \
   ),
   /* NO DUAL PURPOSE VARIANT OF BASE
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ ` │BSp│
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ L1│
 └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
       │Alt│ Mod │      Space            │ Mod │Alt│
       └───┴─────┴───────────────────────┴─────┴───┘
   */
   [NO_DUALS] = LAYOUT(
      KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_GRV , KC_BSPC, \
      KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS, \
      KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  , \
      KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_L1   , \
                KC_LGUI , KC_LALT , KC_SPC  ,                                                   KC_RALT , KC_RGUI  \
   ),
   /* EXPANDED KEYSET LAYER
    *   For common keys that don't fit on the base layer
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │Del│
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 │Caps │   │   │   │   │   │Hom│PgD│PgU│End│   │   │   │ Ins │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │      │   │   │   │   │   │Lft│Dwn│Up │Rgt│   │   │SwapBase│
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 │        │MPr│MPl│MNx│   │   │   │Vmt│V- │V+ │   │      │   │
 └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
       │   │     │                       │     │   │
       └───┴─────┴───────────────────────┴─────┴───┘
   */
   [EXPANDED] = LAYOUT(
      ________, KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , ________, KC_DEL  , \
      KC_CAPS , ________, ________, ________, ________, ________, KC_HOME , KC_PGDN , KC_PGUP , KC_END  , ________, ________, ________, KC_INS  , \
      ________, ________, ________, ________, ________, ________, KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, ________, ________, CK_LYSWP, \
      ________, KC_MPRV , KC_MPLY , KC_MNXT , ________, ________, ________, KC_MUTE , KC_VOLD , KC_VOLU , ________, ________, ________, \
                ________, ________, ________,                                                   ________, ________ \
   ),
   /* SPECIAL KEYSET LAYER
    *   For additional functionality keys
 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 │   │KV1│KV2│KV3│KV4│   │   │   │   │   │   │   │   │   │   │
 ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
 ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 │      │   │   │   │   │   │   │   │   │   │   │   │        │
 ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 │        │   │   │   │   │   │   │   │   │   │   │      │   │
 └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘
       │   │     │                       │     │   │
       └───┴─────┴───────────────────────┴─────┴───┘
   */
   [SPECIAL] = LAYOUT(
      ________, CK_KVML1, CK_KVML2, CK_KVML3, CK_KVML4, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, CK_LYSWP, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
                ________, ________, ________,                                                   ________, ________ \
   ),
};
