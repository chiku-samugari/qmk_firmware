/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"
#include "config.h"
#include "debug.h"

enum layer_ids {
    BASE = 0,
    SELECTOR,
    MOD_US,
    MOD_US_ON_JIS,
    SHIFT_MOD_US_ON_JIS,
    US_ON_JIS,
    SHIFT_US_ON_JIS,
    ARROW,
    SYMB_AND_FN,
    MOUSE,
    REFERENCE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer BASE: Default Layer
     * Fn0: Activates SYMB_AND_FN Layer on hold, toggles ARROW layer on
     *      TAPPING_TOGGLE times tap.
     * Fn1: Activates SYMB_AND_FN Layer on hold, switches on SELECTOR
     *      layer on TAPPING_TOGGLE times tap. Beforehand, layer_state
     *      is cleared on first tap.
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | BS    |BS |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | BS    |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | \     | Fn1 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | Fn0  | LAlt | ******* Space ******* | `    | RGUI |
            |------+------+-----------------------+------+------|
    */

  [BASE] = KEYMAP(
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSPC, \
  KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,           \
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSLS,  KC_FN1,                      \
                    KC_FN0,  KC_LALT,      KC_SPC,      KC_GRV,   KC_RGUI),

  /* Layer SELECTOR: pick a layer that is thought as an independent
   *                 keyboard such as US_ON_JIS or MOUSE.
   */
  [SELECTOR] = KEYMAP(
  KC_TRNS, KC_FN6, KC_FN7, KC_FN8, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_FN9, KC_FN10, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               \
                    KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS),


    /* Layer MOD_US: LShift + Semicolon issues KC_QUOTE, Quote issues
     *               LShift and Semicolon. My favorite setup and I
     *               normally achieve it by xmodmap.
    */

  [MOD_US] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_FN4,  KC_FN4,  KC_TRNS,                   \
  KC_FN4,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   \
                    KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS),


    /* Layer US_ON_JIS : The layer behaves as an US keyboard when the
     *                   keyboard is recognized as a JIS keyboard. Since
     *                   this layer is not for me, the layout is HHKB
     *                   Pro 2 original layout with DIP 3,4, and 5 are
     *                   on.
     * Fn2: register/unregister left shift modifier and on/off
     *      SHIFT_US_ON_JIS layer. Please be aware that the Right Shift
     *      also works as a Left Shift key.
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
                 | **** | **** | ******************** | RAlt | RGUI |
                 |------+------+----------------------+------+------+

     */

  [US_ON_JIS] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_MINS), KC_JYEN, S(KC_LBRC), \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RBRC, KC_BSLS, KC_BSPC,          \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_7), KC_TRNS,                   \
  KC_FN2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_FN2,  KC_TRNS,                   \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_RALT, KC_RGUI),


    /* Layer SHIFT_US_ON_JIS: The layer behaves as an US keyboard
     *                        modified by the left shift when the
     *                        keyboard is recognized as a JIS keyboard.
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
  S(KC_ESC), S(KC_1), KC_FN3, S(KC_3), S(KC_4), S(KC_5), KC_FN3,  S(KC_6), S(KC_QUOT), S(KC_8), S(KC_9), S(KC_RO), S(KC_SCLN), S(KC_JYEN), S(KC_EQL), \
  S(KC_TAB), S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_RBRC), S(KC_BSLS), S(KC_BSPC),            \
  S(KC_LCTL),S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_FN3, S(KC_2), S(KC_ENT),                             \
  KC_TRNS, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RSFT), KC_TRNS,                     \
                     KC_TRNS, S(KC_LALT),           S(KC_SPC),                S(KC_RALT), S(KC_RGUI)),

  /* Layer MOD_US_ON_JIS: The layer behaves as a right pinky fixed US
   *                      keyboard when the keyboard is recognized as a
   *                      JIS keyboard. Since this layer is for me, the
   *                      position of Backslash key, Grave key,
   *                      Backspace key are changed and right Alt key
   *                      disappeared.
   */
  [MOD_US_ON_JIS] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_MINS), KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RBRC, KC_BSLS, KC_BSPC,          \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   \
  KC_FN5,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_JYEN, KC_TRNS,                   \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                S(KC_LBRC), KC_TRNS),

  [SHIFT_MOD_US_ON_JIS] = KEYMAP( \
  S(KC_ESC), S(KC_1), KC_FN3, S(KC_3), S(KC_4), S(KC_5), KC_FN3,  S(KC_6), S(KC_QUOT), S(KC_8), S(KC_9), S(KC_RO), S(KC_SCLN), S(KC_BSPC), S(KC_BSPC), \
  S(KC_TAB), S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_RBRC), S(KC_BSLS), S(KC_BSPC),             \
  S(KC_LCTL),S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_7), S(KC_2), S(KC_ENT),                             \
  KC_TRNS, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_JYEN), KC_TRNS,                      \
                     KC_TRNS, S(KC_LALT),           S(KC_SPC),                S(KC_EQL), S(KC_RGUI)),


    /* Layer Arrow: Arrow mode. Both HJKL and HHKB original diamond
     *              cursor are available.
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


    /* Layer Symbol and Function: Extended version of HHKB Fn layer.
     *
     *  + Function keys
     *  + Volume Down, Volume Up, Mute
     *  + Power, Print Screen, Pause, Scroll lock, Insert
     *  + Symbols on number keys are located on more easy-to-type keys
     *  + Cursor keys on HJKL
     *
     * TG_M denotes TG(MOUSE), TG_U denotes TG(MOD_US)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | CAPS | VoD | VoU | Mut |    |TG_M|    |    |  (  |  )  | Pscr| Slck | Paus | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |  !  |  @  |  #  | $  | %  |Lef |Dow | Up  | Rig |  +  |  *  | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | TG_U|     |     |    |    | ^  | &  |     |     |  _  |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [SYMB_AND_FN] = KEYMAP(
  KC_PWR,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL, \
  KC_CAPS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS, TG(MOUSE), KC_TRNS,  KC_TRNS,  KC_LPRN,  KC_RPRN,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_BSPC,          \
  KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_ASTR,  KC_PLUS,  KC_PENT,                    \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_CIRC,  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_UNDS,  KC_TRNS,  KC_TRNS,                    \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS),


    /* Layer Mouse : Mouse Cursor, Mouse Wheel, and Mouse buttons
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |MwL |MwD | MwU | MwR |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |McL |McD | McU | McR | McL |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |Mb2 |Mb3 | Mb4 | Mb5 |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** |         Mb1          | **** | **** |
                 |------+------+----------------------+------+------+

                Mc: Mouse Cursor / Mb: Mouse Button / Mw: Mouse Wheel

     */

  [MOUSE] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MS_L, KC_TRNS, KC_TRNS,                   \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS,                   \
                     KC_TRNS, KC_TRNS,           KC_BTN1,                KC_TRNS, KC_TRNS),


    /* REFERENCE:
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LGUI | LAlt | ******* Space ******* | RAlt | RGUI |
            |------+------+-----------------------+------+------|
    */

  [REFERENCE] = KEYMAP(
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_BSLS,  KC_GRV, \
  KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC,          \
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  KC_RCTL,                     \
                    KC_LGUI,  KC_LALT,       KC_SPC,      KC_RALT,  KC_RGUI),
};


enum fn_action_ids {
    TT_HHKB_ARROW = 0,
    TT_HHKB_SELECTOR,
    MOMENTARY_LAYER_AND_SHIFT,
    UNSHIFT,
    FIXED_RIGHT_PINKY,
    SELECT_KEYBOARD,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_TAP(TT_HHKB_ARROW),
    [1] = ACTION_FUNCTION_TAP(TT_HHKB_SELECTOR),
    [2] = ACTION_FUNCTION_OPT(MOMENTARY_LAYER_AND_SHIFT, SHIFT_US_ON_JIS),
    [3] = ACTION_FUNCTION(UNSHIFT),
    [4] = ACTION_FUNCTION(FIXED_RIGHT_PINKY),
    [5] = ACTION_FUNCTION_OPT(MOMENTARY_LAYER_AND_SHIFT, SHIFT_MOD_US_ON_JIS),
    [6] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, MOD_US),
    [7] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, ARROW),
    [8] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, MOUSE),
    [9] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, US_ON_JIS),
    [10] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, MOD_US_ON_JIS),
};

typedef uint8_t Layer;

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

static bool lshift = false;
static uint8_t semicolon = 0;
static uint8_t quote = 0;

void mod_us(const keyrecord_t * const record, uint8_t keycode) {
    switch(keycode) {
        case KC_LSFT:
            if(record->event.pressed) {
                register_mods(MOD_LSFT);
                lshift = true;
            }else {
                unregister_mods(MOD_LSFT);
                lshift = false;
            }
            break;
        case KC_SCLN:
            if(record->event.pressed) {
                if(lshift) {
                    del_mods(MOD_LSFT);
                    add_key(KC_QUOT);
                    semicolon = KC_QUOT;
                }else {
                    add_key(KC_SCLN);
                    semicolon = KC_SCLN;
                }
            }else {
                del_key(semicolon);
                if(lshift) {
                    add_mods(MOD_LSFT);
                }
                semicolon = 0;
            }
            send_keyboard_report();
            break;
        case KC_QUOT:
            if(record->event.pressed) {
                if(lshift) {
                    add_key(KC_QUOT);
                    quote = KC_QUOT;
                }else {
                    add_mods(MOD_LSFT);
                    add_key(KC_SCLN);
                    quote = KC_SCLN;
                }
            }else {
                del_key(quote);
                if(!lshift) {
                    del_mods(MOD_LSFT);
                }
                quote = 0;
            }
            send_keyboard_report();
            break;
    }
}

static uint8_t unshift_count = 0;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case FIXED_RIGHT_PINKY:
            mod_us(record, keymap_key_to_keycode(REFERENCE, record->event.key));
            break;
        case TT_HHKB_ARROW:
            layer_tap_toggle_ab(record, SYMB_AND_FN, ARROW);
            break;
        case TT_HHKB_SELECTOR:
            if(record->event.pressed) {
                layer_on(SYMB_AND_FN);
            }else {
                layer_off(SYMB_AND_FN);
                if(record->tap.count == 1) {
                    layer_clear();
                }
                // This `if` statement should be an independent one
                // because TAPPING_TOGGLE can be 1.
                if(record->tap.count == TAPPING_TOGGLE) {
                    layer_on(SELECTOR);
                }
            }
            break;
        case SELECT_KEYBOARD:
            if(record->event.pressed) {
                layer_off(SELECTOR);
                layer_on(opt);
            }
            break;
        case MOMENTARY_LAYER_AND_SHIFT:
            unshift_count = 0;
            if(record->event.pressed) {
                layer_on(opt);
                register_mods(MOD_LSFT);
            }else {
                unregister_mods(MOD_LSFT);
                layer_off(opt);
            }
            break;
        case UNSHIFT:
            if(record->event.pressed) {
                del_mods(MOD_LSFT);
                unshift_count += 1;
                switch(keymap_key_to_keycode(REFERENCE, record->event.key)) {
                    case KC_2:      // @
                        add_key(KC_LBRC);
                        break;
                    case KC_6:      // ^
                        add_key(KC_EQL);
                        break;
                    case KC_SCLN:   // :
                        add_key(KC_QUOT);
                        break;
                }
            } else {
                unshift_count -= 1;
                switch(keymap_key_to_keycode(REFERENCE, record->event.key)) {
                    case KC_2:
                        del_key(KC_LBRC);
                        break;
                    case KC_6:
                        del_key(KC_EQL);
                        break;
                    case KC_SCLN:
                        del_key(KC_QUOT);
                        break;
                }
                if(unshift_count == 0) {
                    add_mods(MOD_LSFT);
                }
            }
            send_keyboard_report();
            break;
    }
}
