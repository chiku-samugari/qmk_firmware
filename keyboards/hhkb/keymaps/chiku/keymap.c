/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"
#include "config.h"

#define BASE 0
#define US_ON_JIS 1
#define SHIFT_US_ON_JIS 2
#define ARROW 3
#define HHKB 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     * Fn0: Activates HHKB Layer on hold, toggles ARROW layer on
     *      TAPPING_TOGGLE times tap.
     * Fn1: Activates HHKB Layer on hold, toggles US_ON_JIS layer on
     *      TAPPING_TOGGLE times tap.
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | BS    |BS |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | \     |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn1 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | Fn0  | LAlt | ******* Space ******* | `    | RGUI |
            |------+------+-----------------------+------+------|
    */

  [BASE] = KEYMAP(  //  default layer
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_BSPC, KC_BSPC, \
  KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,          \
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  KC_FN1,                      \
                    KC_FN0,  KC_LALT,    /*        */ KC_SPC,      KC_GRV,   KC_RGUI),


    /* Layer US_ON_JIS : The layer behaves as an US keyboard when the
     * keyboard is recognized as a JIS keyboard.
     * Fn2: register/unregister shift modifier and on/off
     *      SHIFT_US_ON_JIS layer.
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     | S(-)  | YEN   |S([) |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     | ]   | \     | BS    |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     | S(7)|       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Fn2  |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [US_ON_JIS] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_MINS), KC_JYEN, S(KC_LBRC), \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RBRC, KC_BSLS, KC_BSPC,          \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_7), KC_TRNS,                   \
  KC_FN2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS),


    /* Layer SHIFT_US_ON_JIS : The layer behaves as an US keyboard
     * modified by the left shift when the keyboard is recognized as a
     * JIS keyboard.
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | S(1)| [   | S(3)|S(4)|S(5)| =  |S(6)| S(')| S(8)| S(9)|S(RO)| S(;)  | S(YEN)|S(=) |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | S(Q)| S(W)| S(E)|S(R)|S(T)|S(Y)|S(U)| S(I)| S(O)| S(P)| S([)| S(\)  |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | S(A)| S(S)| S(D)|S(F)|S(G)|S(H)|S(J)| S(K)| S(L)| '   | S(2)|       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | S(Z)| S(X)| S(C)|S(V)|S(B)|S(N)|S(M)| S(,)| S(.)| S(/)|     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [SHIFT_US_ON_JIS] = KEYMAP( \
  KC_TRNS, S(KC_1), KC_FN3, S(KC_3), S(KC_4), S(KC_5), KC_FN3,  S(KC_6), S(KC_QUOT), S(KC_8), S(KC_9), S(KC_RO), S(KC_SCLN), S(KC_JYEN), S(KC_EQL), \
  KC_TRNS, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_RBRC), S(KC_BSLS), KC_TRNS,          \
  KC_TRNS, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_FN3, S(KC_2), KC_TRNS,                   \
  KC_TRNS, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), KC_TRNS, KC_TRNS,                   \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS),


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
      | CAPS | VoD | VoU | Mut |    |    |    |    |  (  |  )  | Psc | Pus | Slck  | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |  !  |  @  |  #  | $  | %  |Lef |Dow | Up  | Rig |  +  |  *  | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | ^  | &  |     |     |  _  |     |       |       |     |
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
    [1] = ACTION_FUNCTION_TAP(1),
    [2] = ACTION_FUNCTION(2),
    [3] = ACTION_FUNCTION(3),
};

static uint8_t unshift_count = 0;

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
        case 1:
            if(record->event.pressed) {
                layer_on(HHKB);
            }else {
                layer_off(HHKB);
                if(record->tap.count == TAPPING_TOGGLE) {
                    layer_invert(US_ON_JIS);
                }
            }
            break;
        case 2:
            unshift_count = 0;
            if(record->event.pressed) {
                register_mods(MOD_LSFT);
                layer_on(SHIFT_US_ON_JIS);
            }else {
                unregister_mods(MOD_LSFT);
                layer_off(SHIFT_US_ON_JIS);
            }
            break;
        case 3:
            if(record->event.pressed) {
                unregister_mods(MOD_LSFT);
                unshift_count += 1;
                switch(keymap_key_to_keycode(BASE, record->event.key)) {
                    case KC_2:      // @
                        register_code(KC_LBRC);
                        break;
                    case KC_6:      // ^
                        register_code(KC_EQL);
                        break;
                    case KC_SCLN:   // :
                        register_code(KC_QUOT);
                        break;
                }
            } else {
                unshift_count -= 1;
                switch(keymap_key_to_keycode(BASE, record->event.key)) {
                    case KC_2:
                        unregister_code(KC_LBRC);
                        break;
                    case KC_6:
                        unregister_code(KC_EQL);
                        break;
                    case KC_SCLN:
                        unregister_code(KC_QUOT);
                        break;
                }
                if(unshift_count == 0) {
                   register_mods(MOD_LSFT);
                }
            }
            break;
    }
}
