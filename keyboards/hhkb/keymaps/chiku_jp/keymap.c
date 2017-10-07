#include "hhkb.h"
#include "config.h"

#define _______ KC_TRNS

typedef uint8_t Layer;

enum layer_ids {
    BASE = 0,
    SELECTOR,
    AUXILIARY,
    REFERENCE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap ASCII Art Template
     * ,--------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     * |--------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |
     * |------------------------------------------------------------------\       |
     * |       |    |    |    |    |    |    |    |    |    |    |    |    |      |
     * |--------------------------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |    |    |    |     |    |    |
     * |--------------------------------------------------------------------------|
     * |    | |    |    |    |    |          |    |    |    |    | |    |    |    |
     * `--------------------------------------------------------------------------'
     *
     * Keymap Template
     * [] = KEYMAP_JP(
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     *   _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
     * ),
     */

    /* Layer BASE: Default Layer
     *
     * Fn0: Activates AUXILIARY Layer on hold, toggles AUXILIARY layer
     *      on TAPPING_TOGGLE times tap.
     *
     * ,--------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Yen |BSp |
     * |--------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |       |
     * |------------------------------------------------------------------\ Enter |
     * |L-Ctrl |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  ` |      |
     * |--------------------------------------------------------------------------|
     * |L-Shift |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  \  | Up |RSft|
     * |--------------------------------------------------------------------------|
     * |    | | Fn0|LGUI|LAlt|  = |  Space   |  ` |RSft|RAlt| Fn0| |Left|Down|Rght|
     * `--------------------------------------------------------------------------'
     */

  [BASE] = KEYMAP_JP(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_JYEN,  KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,   KC_RO,   KC_UP, KC_RSFT,
    _______,KC_FN0, KC_LGUI, KC_LALT,  KC_EQL,         KC_SPC,     KC_GRV,  KC_RALT, _______,  KC_FN0, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Layer Auxiliary: Extended version of HHKB Fn layer.
   *
   *  + Function keys
   *  + Volume Down, Volume Up, Mute
   *  + Power, Print Screen, Pause, Scroll lock, Insert
   *  + Symbols on number keys are located on more easy-to-type keys
   *  + Cursor keys on HJKL
   *
   * ,--------------------------------------------------------------------------.
   * |Powr| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F0 | F11| F12| Ins| Del|
   * |--------------------------------------------------------------------------|
   * |Caps  |VoDw|VoUp|Mute|    |    |    |    |  ( |  ) |PrSc|ScLk|Paus|       |
   * |------------------------------------------------------------------\ Enter |
   * |       |  ! |  @ |  # |  $ |  % |Left|Rght| Up| Down|  + |  * |    |      |
   * |--------------------------------------------------------------------------|
   * |        |    |    |    |    |    |  ^ |  & |    |    |  _ |     |    |    |
   * |--------------------------------------------------------------------------|
   * |    | |    |    |    |    |          |    |    |    |    | |    |    |    |
   * `--------------------------------------------------------------------------'
   */

  [AUXILIARY] = KEYMAP_JP(
    KC_PWR,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSCR, KC_SLCK, KC_PAUS,
    _______, KC_EXLM, KC_AT,   KC_HASH,  KC_PWR, KC_PERC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ASTR, KC_PLUS, _______, KC_PENT,
    _______, _______, _______, _______, _______, _______, KC_CIRC, KC_AMPR, _______, _______, KC_UNDS, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t macro_id, uint8_t opt) {
  return MACRO_NONE;
}

enum fn_action_ids {
    HOLD_AUXILIARY_TAP_AUXILIARY = 0,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_TAP(HOLD_AUXILIARY_TAP_AUXILIARY),
};

// Momentary swtich to layer ``hold'', toggles layer ``tap'' on tap.
void layer_tap_toggle_ab(const keyrecord_t * const record, Layer hold, Layer tap) {
    if(record->event.pressed) {
        layer_on(hold);
    }else {
        layer_off(hold);
        if(record->tap.count == TAPPING_TOGGLE) {
            layer_invert(tap);
        }
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case HOLD_AUXILIARY_TAP_AUXILIARY:
            layer_tap_toggle_ab(record, AUXILIARY, AUXILIARY);
            break;
    }
}
