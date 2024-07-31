#include QMK_KEYBOARD_H


enum custom_keycodes {
    LANG_TOGGLE = SAFE_RANGE,
};


static bool lng = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LANG_TOGGLE:
            if (lng) {
              if (record->event.pressed) {
                  // Ctrl + Space を送信
                  register_code(KC_LNG1);
              } else {
                  unregister_code(KC_LNG1);
                  lng = !lng;
              }
            } else {
              if (record->event.pressed) {
                  // Ctrl + Space を送信
                  register_code(KC_LNG2);
              } else {
                  unregister_code(KC_LNG2);
                  lng = !lng;
              }
            }
            return false;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_ESC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LALT, KC_SCLN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
    KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_BSPC, KC_QUOT, KC_H, KC_J, KC_K, KC_L, KC_LBRC, KC_RBRC,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(2), MO(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RGUI(RSFT(KC_P)),
    KC_NO, KC_UP, KC_DOWN, KC_LALT, KC_LCTL, KC_SPC, KC_RGUI, KC_ENT, KC_RSFT, LANG_TOGGLE, KC_RALT, KC_LEFT, KC_RGHT, HYPR(KC_NO)
  ),
	
	[1] = LAYOUT(
    KC_MPLY, KC_MNXT, KC_MPRV, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_WH_D, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_BTN3, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LCTL, KC_NO, KC_LGUI, KC_NO, KC_RSFT, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
  ),

	[2] = LAYOUT(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_ESC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LALT, KC_SCLN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
    KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_BSPC, KC_QUOT, KC_H, KC_J, KC_K, KC_L, KC_LBRC, KC_RBRC,
    KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(2), MO(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RGUI(RSFT(KC_P)),
    KC_NO, KC_UP, KC_DOWN, KC_LALT, KC_LCTL, KC_SPC, KC_RGUI, KC_ENT, KC_RSFT, LANG_TOGGLE, KC_RALT, KC_LEFT, KC_RGHT, HYPR(KC_NO)
  )
};
