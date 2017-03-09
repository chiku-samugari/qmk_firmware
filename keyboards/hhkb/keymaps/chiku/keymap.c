/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"
#include "config.h"

#define BASE 0
#define ARROW 1
#define HHKB 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     * Fn0: Activates HHKB Layer on hold, toggle ARROW layer on
     *      TAPPING_TOGGLE times tap.
     * MO: Activates HHKB Layer on hold.
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | BS    |BS |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | \     |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | MO   | LAlt | ******* Space ******* | `    | RGUI |
            |------+------+-----------------------+------+------|
    */

  [BASE] = KEYMAP(  //  default layer
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_BSPC, KC_BSPC, \
  KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,          \
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  KC_FN0,                      \
                    MO(HHKB),  KC_LALT,  /*        */ KC_SPC,      KC_GRV,   KC_RGUI),


    /* Layer Arrow : Arrow mode. Both HJKL and HHKB original diamond
     *               cursor are available.
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     | Up  |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |Lef |Dow | Up  | Rig | Lef | Rig |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [ARROW] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,          \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_LEFT, KC_RGHT, KC_TRNS,                   \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS, KC_TRNS,                   \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS),

    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | CAPS |     |     |     |    |    |    |    | Sh 9| Sh0 | Psc | Pus | Slck  | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    |Lef |Dow | Up  | Rig | Sh =| Sh 8| Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | Sh 1| Sh 2| Sh 3|Sh 4|Sh 5|Sh 6|Sh 7|     |     | Sh -|     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [HHKB] = KEYMAP(
  KC_PWR,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL, \
  KC_CAPS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LPRN,  KC_RPRN,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_BSPC,          \
  KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_ASTR,  KC_PLUS,  KC_PENT,                    \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_CIRC,  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_UNDS,  KC_TRNS,  KC_TRNS,                    \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS)};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_TAP(0),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 0:
            if(record->event.pressed) {
                layer_on(HHKB);
            }else {
                layer_off(HHKB);
                if(record->tap.count == TAPPING_TOGGLE) {
                    layer_invert(ARROW);
                }
            }
            break;
    }
}

// This macro is said to be *careless* because it does not care of
// simultaneous use with other keys. The Left Shift key is kept
// registered during the key is pressed. There are several phenomenon
// observed which might be not expected or not predicted.
// The keycode argument must be 8 bit. See he defintion of register_code
// and unregister_code.
#define CARELESS_SHIFT(keycode) case keycode:\
    if(record->event.pressed) {\
        register_code(KC_LSFT);\
        register_code(keycode);\
    }else {\
        unregister_code(keycode);\
        unregister_code(KC_LSFT);\
    }\
break;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
          CARELESS_SHIFT(KC_1);
          CARELESS_SHIFT(KC_2);
          CARELESS_SHIFT(KC_3);
          CARELESS_SHIFT(KC_4);
          CARELESS_SHIFT(KC_5);
          CARELESS_SHIFT(KC_6);
          CARELESS_SHIFT(KC_7);
          CARELESS_SHIFT(KC_8);
          CARELESS_SHIFT(KC_9);
          CARELESS_SHIFT(KC_0);
          CARELESS_SHIFT(KC_MINS);
          CARELESS_SHIFT(KC_EQL);
          CARELESS_SHIFT(KC_BSLS);
          CARELESS_SHIFT(KC_GRV);
      }
    return MACRO_NONE;
};
