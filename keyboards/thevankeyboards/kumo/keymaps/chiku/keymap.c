#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

typedef uint8_t Layer;

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
  [] = LAYOUT_arrow_command(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
  ),
  */

  [BASE] = LAYOUT_arrow_command(
     KC_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(NUM_AND_SYM, KC_QUOTE),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    MO(MOUSE), MO(AUXILIARY), KC_FN0, MO(SHIFT_NUM_AND_SYM),    KC_SPC,  KC_GRV,    KC_EQL, KC_BSPC, KC_0, KC_ENT
  ),

  /* In oreder to use Alt+Tab */
  [CORNER] = LAYOUT_arrow_command(
     KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
  ),

  [NUM_AND_SYM] = LAYOUT_arrow_command(
     KC_TAB, _______,  KC_GRV,  KC_EQL, KC_MINS, _______, _______, _______, _______, _______, _______,  KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_LBRC, KC_RBRC,  KC_GRV,  KC_EQL, KC_SCLN,    KC_9,    KC_0, KC_MINS, _______,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8, _______, _______, _______,
    _______, _______, _______, _______,          _______,  KC_EQL,          _______, _______, _______, _______
  ),

  [SHIFT_NUM_AND_SYM] = LAYOUT_arrow_command(
     KC_TAB, _______, _______, _______, _______, _______, _______, KC_TILD, KC_PLUS, KC_UNDS,  KC_ESC, KC_BSPC,
    _______, KC_PIPE, KC_DQUO, KC_LCBR, KC_RCBR, KC_GRV,   KC_EQL, KC_COLN, KC_LPRN, KC_RPRN, KC_MINS,  KC_ENT,
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_AMPR, KC_CIRC, KC_ASTR, _______,   KC_UP, KC_RSFT,

    _______, _______, _______, _______,          _______, KC_PLUS,          _______, _______, _______, _______
  ),

  [AUXILIARY] = LAYOUT_arrow_command(
      RESET, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,  KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,  KC_ENT,
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,   KC_UP, _______,
    _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
  ),

  [MOUSE] = LAYOUT_arrow_command(
    _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, KC_BTN3,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______,
    _______, _______, _______, _______,          KC_BTN1, KC_BTN2,          _______, KC_MS_L, KC_MS_D, KC_MS_R
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
