#include "hhkb.h"
#include "config.h"

#define _______ KC_TRNS

typedef uint8_t Layer;

enum layer_ids {
    BASE = 0,
    SELECTOR,
    FIXED_RIGHT_PINKY_ON_ASCII,
    AUXILIARY,
    MOUSE,
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
     * Fn1: same as Fn0
     * Fn2: Activates AUXILIARY Layer on hold, switches on SELECTOR
     *      layer on TAPPING_TOGGLE times tap. Beforehand, layer_state
     *      is cleared on first tap.
     *
     * ,--------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |BSpc|BSpc|BSpc|
     * |--------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |       |
     * |------------------------------------------------------------------\ Enter |
     * |L-Ctrl |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' | Ent|      |
     * |--------------------------------------------------------------------------|
     * |L-Shift |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  \  | Up |RSft|
     * |--------------------------------------------------------------------------|
     * | Fn0| | Fn1|LGUI|LAlt|  = |  Space   |  ` |RSft|RAlt| Fn2| |Left|Down|Rght|
     * `--------------------------------------------------------------------------'
     */

  [BASE] = KEYMAP_JP(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS, KC_BSPC, KC_BSPC, KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,  KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,   KC_UP, KC_RSFT,
    KC_FN0, KC_FN1, KC_LGUI, KC_LALT,  KC_EQL,         KC_SPC,     KC_GRV,  KC_RSFT, KC_RALT,  KC_FN2, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Layer SELECTOR:
   *   pick a layer that is thought as an independent keyboard such as
   *   FIXED_RIGHT_PINKY_ON_ASCII or MOUSE.
   *
   * Fn6: activates FIXED_RIGHT_PINKY_ON_ASCII and deactivates SELECTOR
   * Fn7: activated MOUSE and deactivates SELECTOR
   * Fn8:activates FIXED_RIGHT_PINKY_ON_JIS and deactivates SELECTOR
   */

  [SELECTOR] = KEYMAP_JP(
    _______,  KC_FN6,  KC_FN7, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
  ),

  /* Layer FIXED_RIGHT_PINKY_ON_ASCII:
   *    Left Shift key + Semicolon key issues KC_QUOTE without Left
   *    Shift bit, Quote key issues KC_LSFT and KC_SCLN. My favorite
   *    setup and I normally achieve it by xmodmap. This layer is
   *    intended to be activated when I have to work on computers that
   *    I do not have such kind of control. Even in such situation,
   *    the keyboard layout is expected to be correctly recognized.
   *
   * ,--------------------------------------------------------------------------.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   * |--------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |
   * |------------------------------------------------------------------\       |
   * |       |    |    |    |    |    |    |    |    |    | Fn4| Fn4|    |      |
   * |--------------------------------------------------------------------------|
   * |  Fn4   |    |    |    |    |    |    |    |    |    |    |     |    |    |
   * |--------------------------------------------------------------------------|
   * |    | |    |    |    |    |          |    |    |    |    | |    |    |    |
   * `--------------------------------------------------------------------------'
   */

  [FIXED_RIGHT_PINKY_ON_ASCII] = KEYMAP_JP(
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_FN4,  KC_FN4, _______, _______,
        KC_FN4, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______, _______, _______
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
  ),

    /* Layer MOUSE: Mouse Cursor, Mouse Wheel, and Mouse Buttons
     * ,--------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     * |--------------------------------------------------------------------------|
     * |      |    |    |    |    |    | MwL| MwD| MwU| MwR|    |    |    |       |
     * |------------------------------------------------------------------\       |
     * |       | Mb5| Mb4| Mb3| Mb2|    | McL| McD| McU| McR|    |    |    |      |
     * |--------------------------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |    |    |    |     | McU|    |
     * |--------------------------------------------------------------------------|
     * |    | |    |    |    |    |   Mb1    |    |    |    |    | | McL| McD| McR|
     * `--------------------------------------------------------------------------'
     */

     [MOUSE] = KEYMAP_JP(
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______,
       _______, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______,
       _______, _______, _______, _______, _______,     KC_BTN1     , _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
     ),

    /* Layer REFERENCE: A utility layer to locate which of phisical key
     * was actually operated. We can use keymap_key_to_keycode function
     * offered by Q.M.K to locate the phisical key because all the keys
     * of this layer issues unique keycode. It is quite convenient to
     * implement UNSHIFT action.
     *
     *  Let me explain about how I decide keycodes. Almost all key is
     *  based on HHKB Pro2 layout. If a phisical key exists in both of
     *  HHKB Pro2 and and HHKB JP, then the keycode issued by the key on
     *  HHKB Pro2 keyboard is mapped to that key. The lowest row is
     *  based on HHKB JP keyboard because there are too many keys
     *  compared to HHKB Pro2. Fn0 and Fn1 are replaced by Del and RGUI.
     *  KC_ZKHK is replaced by Backspace because KC_ZKHK is identical to
     *  KC_GRAVE and that is already on the right upper corner. Yen and
     *  RO are used to fill middle line and one below line.
     *
     * ,--------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  \ |  ` |
     * |--------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |       |
     * |------------------------------------------------------------------\ Enter |
     * |L-Ctrl |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' | Yen|      |
     * |--------------------------------------------------------------------------|
     * |L-Shift |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  RO | Up |RSft|
     * |--------------------------------------------------------------------------|
     * | Del| |BSpc|LGUI|LAlt|MHEN|  Space   |HENK|KANA|RAlt|RGUI| |Left|Down|Rght|
     * `--------------------------------------------------------------------------'
     */

  [REFERENCE] = KEYMAP_JP(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL, KC_JYEN, KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_BSLS,  KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,   KC_RO,   KC_UP, KC_RSFT,
     KC_DEL, KC_GRAVE, KC_LGUI, KC_LALT, KC_MHEN,      KC_SPC   , KC_HENK,  KC_KANA, KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

enum fn_action_ids {
    HOLD_AUXILIARY_TAP_AUXILIARY = 0,
    HOLD_AUXILIARY_TAP_SELECTOR,
    FIXED_RIGHT_PINKY,
    SELECT_KEYBOARD,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_TAP(HOLD_AUXILIARY_TAP_AUXILIARY),
    [1] = ACTION_FUNCTION_TAP(HOLD_AUXILIARY_TAP_AUXILIARY),
    [2] = ACTION_FUNCTION_TAP(HOLD_AUXILIARY_TAP_SELECTOR),
    [4] = ACTION_FUNCTION(FIXED_RIGHT_PINKY),
    [6] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, FIXED_RIGHT_PINKY_ON_ASCII),
    [7] = ACTION_FUNCTION_OPT(SELECT_KEYBOARD, MOUSE),
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

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case HOLD_AUXILIARY_TAP_AUXILIARY:
            layer_tap_toggle_ab(record, AUXILIARY, AUXILIARY);
            break;
        case HOLD_AUXILIARY_TAP_SELECTOR:
            if(record->event.pressed) {
                layer_on(AUXILIARY);
            }else {
                layer_off(AUXILIARY);
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
        case FIXED_RIGHT_PINKY:
            mod_us(record, keymap_key_to_keycode(REFERENCE, record->event.key));
            break;
        case SELECT_KEYBOARD:
            if(record->event.pressed) {
                layer_off(SELECTOR);
                layer_on(opt);
            }
            break;
    }
}
