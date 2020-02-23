#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layer_ids {
    BASE = 0,
    CORNER,
    NUM_AND_SYM,
    SHIFT_NUM_AND_SYM,
    AUXILIARY,
    MOUSE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ,-------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   *
[] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),
   */

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [    |
   * |-------------------------------------------------------------------------+
   * | Ctrl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  \  |
   * |-------------------------------------------------------------------------+
   * |MOUSE| AUX | Gui | SYM | Fn0  |   Space   |  `   |  =  | Left| Down|Right|
   * `-------------------------------------------------------------------------'
   */

[BASE] = LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  MO(NUM_AND_SYM), MO(AUXILIARY), KC_LGUI, MO(SHIFT_NUM_AND_SYM), KC_FN0, KC_SPC, KC_GRV, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT
),

  /* Corner Layer: In oreder to use ALT+Tab combination.
   * ,-------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */
[CORNER] = LAYOUT(
   KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

  /* Number and Symbols Layer
   * ,-------------------------------------------------------------------------.
   * | Tab  |  1  |  2  |  3  |  4  |     |     |  7  |  8  |  -  |    |BackSpc|
   * |-------------------------------------------------------------------------+
   * |      |     |  1  |  0  |  [  |  5  |  6  |  ]  |  9  |  0 |  -   | Enter|
   * |-------------------------------------------------------------------------+
k  * |       |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | Up  |Delet|
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

[NUM_AND_SYM] = LAYOUT(
   KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4, _______, _______,    KC_7,    KC_8, KC_MINS, _______, KC_BSPC,
  _______, _______,    KC_1,    KC_0, KC_LBRC,    KC_5,    KC_6, KC_RBRC,    KC_9,    KC_0, KC_MINS,  KC_ENT,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_UP,  KC_DEL,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

  /* Shift Symbols Layer
   * ,-------------------------------------------------------------------------.
   * | Tab  |  !  |  @  |  #  |  $  |  [  |  ]  |  &  |  *  |  _  |  ] |BackSpc|
   * |-------------------------------------------------------------------------+
   * |      |  ]  |  1  |  0  |  {  |  %  |  ^  |  }  |  (  |  ) |  -   | Enter|
   * |-------------------------------------------------------------------------+
   * |       |     |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | Up  |Delet|
   * |-------------------------------------------------------------------------+
   * |MO(M)|     |     |     |      |          |   [   |  ]  |     |     |     |
   * `-------------------------------------------------------------------------'
   */

[SHIFT_NUM_AND_SYM] = LAYOUT(
  KC_TAB,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_LBRC, KC_RBRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_RBRC, KC_BSPC,
  _______, KC_RBRC,    KC_1,    KC_0, KC_LCBR, KC_PERC, KC_CIRC, KC_RCBR, KC_LPRN, KC_RPRN, KC_MINS,  KC_ENT,
  _______, _______,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_UP,  KC_DEL,
  MO(MOUSE), _______, _______, _______, _______,     _______,      KC_LBRC, KC_RBRC, _______, _______, _______
),

  /* Auxiliary Layer
   * ,-------------------------------------------------------------------------.
   * |Reset|     |Vol- |Vol+ | Mute|     |  F11| F12 | F13 | F14 |PrtSc|BackSpc|
   * |-------------------------------------------------------------------------+
   * |      |     | F10 | F1  |     |     |Left |Down | Up  |Right|     | Enter|
   * |-------------------------------------------------------------------------+
   * |       |     | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | Up  |Delet|
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

[AUXILIARY] = LAYOUT(
    RESET, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,  KC_F11,  KC_F12,  KC_F13,  KC_F14, KC_PSCR, KC_BSPC,
  _______, _______,  KC_F10,   KC_F1, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,  KC_ENT,
  _______, _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_UP,  KC_DEL,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

  /* Mouse Layer
   * ,-------------------------------------------------------------------------.
   * |     |     |     |     |     |     | WH L| WH D| WH U| WH R|     |       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     | MS L| MS D| MS U| MS R|     |M BTN1|
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     | MS U|     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |  M BTN1  |M BTN2|M BTN3| MS L| MS D| MS R|
   * `-------------------------------------------------------------------------'
   */
[MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, KC_BTN1,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______,
  _______, _______, _______, _______, _______,     KC_BTN1,      KC_BTN2, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R
),
};


enum fn_action_ids {
    LEFT_ALTED_LAYER = 0,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_OPT(LEFT_ALTED_LAYER, CORNER),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case LEFT_ALTED_LAYER:
            if(record->event.pressed) {
                layer_on(opt);
                register_mods(MOD_LALT);
            }else {
                layer_off(opt);
                unregister_mods(MOD_LALT);
            }
            break;
    }
}
