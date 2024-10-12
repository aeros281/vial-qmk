/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// clang-format off

#include QMK_KEYBOARD_H
#include "oled.c"

#define W_SPACE LT(3, KC_SPC)
#define M_SPACE LT(4, KC_SPC)
#define W_BSPC LT(2, KC_BSPC)
#define M_TMUX LT(6, LCTL(KC_B))
#define MS_ENT LT(5, KC_ENT)

#define W_DELW LCTL(KC_BSPC)
#define W_PREVW LCTL(KC_LEFT)
#define W_NEXTW LCTL(KC_RGHT)
#define W_PREVT LCTL(LSFT(KC_TAB))
#define W_NEXTT LCTL(KC_TAB)

#define M_NEXTT LGUI(LALT(KC_RGHT))
#define M_PREVT LGUI(LALT(KC_LEFT))
#define M_NEXTW LALT(KC_RGHT)
#define M_PREVW LALT(KC_LEFT)
#define M_DELW LALT(KC_BSPC)

#define W_ESC MT(MOD_LCTL, KC_ESC)
#define M_ESC MT(MOD_LGUI, KC_ESC)

#define HOME_A MT(MOD_LGUI, KC_A)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LCTL, KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_K MT(MOD_LCTL, KC_K)
#define HOME_L MT(MOD_LALT, KC_L)
#define HOME_SCLN MT(MOD_LGUI, KC_SCLN)
#define HOME_J LSFT_T(KC_J)

enum custom_keycode {
    KC_GIT = QK_KB_0,
    KC_VIMS,
    VIM_SAVE,
    MAC_ENVI,
    MAC_SCRN, 
};

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
// Win
[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  W_ESC,   HOME_A,   HOME_S,    HOME_D,    HOME_F,    KC_G,                     KC_H,    HOME_J,    HOME_K,    HOME_L, HOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                KC_MUTE ,KC_LGUI,KC_LALT,KC_LCTL, MS_ENT, W_BSPC,      W_SPACE,  M_TMUX, KC_RCTL, KC_RALT, KC_RGUI,
                                                              KC_ENTER, KC_RIGHT, KC_UP, KC_LEFT, KC_DOWN
),

// Mac
[1] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  M_ESC,   HOME_A,   HOME_S,    HOME_D,    HOME_F,    KC_G,                     KC_H,    HOME_J,    HOME_K,    HOME_L, HOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                KC_MUTE ,KC_LGUI,KC_LALT,KC_LCTL, MS_ENT, W_BSPC,      M_SPACE,  M_TMUX, KC_RCTL, KC_RALT, KC_RGUI,
                                                              KC_ENTER, KC_RIGHT, KC_UP, KC_LEFT, KC_DOWN
),

// Lower
[2] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,    KC_F7,     KC_F8,    KC_F9,     KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,     KC_7,      KC_8,     KC_9,      KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_EQL,   KC_LPRN,   KC_RPRN,  KC_LCBR ,  KC_RCBR ,KC_PIPE,
  _______, KC_CIRC, KC_AMPR, KC_LT,   KC_GT,   KC_ASTR,                            KC_PLUS,  KC_LBRC,   KC_RBRC,  _______,   _______, _______,
                         _______,_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, _______, _______
),

// Raise (Win)
[3] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______, _______ , W_PREVT , _______ , W_NEXTT , _______,                           KC_PGUP,  W_PREVW  , KC_UP  ,  W_NEXTW ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , KC_CAPS_LOCK,                      KC_PGDN,  KC_LEFT  , KC_DOWN,  KC_RGHT ,  _______ ,_______,
  _______,_______, KC_VOLD, KC_MUTE, KC_VOLU, _______,                                _______, _______, _______, _______,   _______, _______,
                         _______, _______, _______, _______, CW_TOGG, W_DELW,       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, _______, _______
),

// Raise (Mac)
[4] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______, _______ , M_PREVT , _______ , M_NEXTT , _______,                           KC_PGUP,  M_PREVW  , KC_UP  ,  M_NEXTW ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , KC_CAPS_LOCK,                      KC_PGDN,  KC_LEFT  , KC_DOWN,  KC_RGHT ,  _______ ,_______,
  _______,_______, KC_VOLD, KC_MUTE, KC_VOLU, _______,                                _______, _______, _______, _______,   _______, _______,
                         _______, _______, _______, _______, CW_TOGG, W_DELW,       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, _______, _______
),

// Mouse
[5] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , KC_LGUI,  KC_LALT,   KC_LCTL,  KC_LSFT, XXXXXXX,                     KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                      KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______, _______,     KC_BTN1, _______, KC_BTN3, _______, _______,
                                                              _______, _______, _______, _______, _______
  ),

// Macros
[6] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ , QK_BOOT,
  _______, _______ , VIM_SAVE , _______ , _______ , _______,                           _______,  _______  , _______  ,  _______ ,  _______ ,_______,
  _______, _______ , KC_VIMS , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,_______, _______, _______, _______, _______,                           _______, KC_GIT , _______, _______,   _______, _______,
                         _______,_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, _______, _______
),

// System
[7] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ , QK_BOOT,
  _______, _______ , VIM_SAVE , _______ , _______ , _______,                           _______,  _______  , _______  ,  _______ ,  _______ ,_______,
  _______, _______ , KC_VIMS , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,_______, _______, _______, _______, _______,                           _______, KC_GIT , _______, _______,   _______, _______,
                         _______,_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
                                                              _______, _______, _______, _______, _______
),

};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [6] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [7] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_TMUX:
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_B));
                return false;
            }
            break;
        case KC_GIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -m\"");
            }
            return false;
        case KC_VIMS:
            if (record->event.pressed) {
                SEND_STRING("\\\\s");
            }
            return false;
        case VIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING(":w");
                SEND_STRING("\n");
            }
            return false;
        case MAC_ENVI:
            if (record->event.pressed) {
                tap_code16(C(KC_SLSH));
            }
            return false;
        case MAC_SCRN:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_S);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}
