
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>
#include <stdlib.h>


#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
};

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LWR,
    KC_RAIS,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  [   |  ]   |   \  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
     KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, KC_MPLY,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_EQL,
                      KC_LCTL, KC_LALT, KC_LGUI,  KC_LWR,  KC_SPC,  KC_ENT, KC_RAIS, KC_LBRC, KC_RBRC, KC_BSLS
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |      | MWU  |      |      | F11  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |-------.    ,-------| MWL  | MWD  | MWR  |      | F12  |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |      |      |  MB3 |  MB2 |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  [   |  ]   |   \  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_EQL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX,  KC_F11,   KC_DEL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,                   XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R,  KC_F12,  XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                      KC_LCTL, KC_LALT, KC_LGUI,  KC_LWR,  KC_SPC,  KC_ENT, KC_RAIS, XXXXXXX, XXXXXXX, XXXXXXX
),
/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | CapW | CapP |                    | PagU | PWrd |  Up  | NWrd |  F11 | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TO| hue^ |sat ^ | bri ^| CpyW | CpyP |-------.    ,-------| PagD | Left | Down | Right|  F12 | DLine|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn| CAPS |  Ins |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  [   |  ]   |   \  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_EQL,
    _______, XXXXXXX, RGB_TOG, RGB_MOD, KC_CAPW, KC_CAPP,                   KC_PGUP, KC_PRVWD,  KC_UP,KC_NXTWD,  KC_F11,  KC_DEL,
    _______, RGB_HUI, RGB_SAI, RGB_VAI, KC_CPYW, KC_CPYP,                   KC_PGDN,  KC_LEFT,KC_DOWN, KC_RGHT,  KC_F12, XXXXXXX,
    _______, RGB_HUD, RGB_SAD, RGB_VAD, KC_CAPS,  KC_INS, _______, _______, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, XXXXXXX,
                      KC_LCTL, KC_LALT, KC_LGUI,  KC_LWR,  KC_SPC,  KC_ENT, KC_RAIS, KC_LBRC, KC_RBRC, KC_BSLS
),
};


#ifdef RGB_MATRIX_ENABLE

void set_keycode_rgb(uint8_t index, HSV hsv) {
    hsv.v = hsv.v == 0 ? 0 : rgb_matrix_config.hsv.v;
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b );
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
      uint8_t layer = get_highest_layer(layer_state);

      for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
          for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
              uint8_t index = g_led_config.matrix_co[row][col];

              uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});

              if (index >= led_min && index < led_max && index != NO_LED) {
                if (keycode == XXXXXXX) {
                  rgb_matrix_set_color(index, RGB_BLACK);
                } else if (keycode != _______) {
                  if (layer!=_QWERTY) {
                    if (keycode == KC_UP || keycode == KC_DOWN || keycode == KC_LEFT || keycode == KC_RIGHT || keycode == KC_WH_U || keycode == KC_WH_D || keycode == KC_WH_L || keycode == KC_WH_R) {
                      set_keycode_rgb(index, (HSV){HSV_AZURE}); continue;
                    }
                    if (keycode == KC_PRVWD || keycode == KC_NXTWD) {
                      set_keycode_rgb(index, (HSV){HSV_CYAN}); continue;
                    }
                    if (keycode == KC_F1 || keycode == KC_LSTRT || keycode == KC_LEND || keycode == RGB_MOD) {
                      set_keycode_rgb(index, (HSV){HSV_BLUE}); continue;
                    }
                    if (keycode == KC_DEL || keycode == KC_BSPC || keycode == KC_ENT || keycode == KC_TAB) {
                      set_keycode_rgb(index, (HSV){HSV_ORANGE}); continue;
                    }
                    if (keycode == KC_Z) {
                      set_keycode_rgb(index, (HSV){255, 0, 255}); continue;
                    }
                    if (keycode == KC_PGUP || keycode == KC_PGDN || keycode == RGB_HUI || keycode == RGB_HUD || keycode == RGB_SAI || keycode == RGB_SAD || keycode == RGB_VAI || keycode == RGB_VAD) {
                      set_keycode_rgb(index, (HSV){HSV_MAGENTA}); continue;
                    }
                    if (keycode == C(KC_X) || keycode == C(KC_C) || keycode == C(KC_V) ||  keycode == KC_LBRC || keycode == KC_RBRC) {
                      set_keycode_rgb(index, (HSV){HSV_YELLOW}); continue;
                    }
                    if (keycode == KC_F11 || keycode == KC_LCBR || keycode == KC_BTN2) {
                      set_keycode_rgb(index, (HSV){HSV_ORANGE}); continue;
                    }
                    if (keycode == KC_F5 || keycode == KC_F8) {
                      set_keycode_rgb(index, (HSV){HSV_GREEN}); continue;
                    }
                    if (keycode == KC_CAPW || keycode == KC_CAPP) {
                      set_keycode_rgb(index, (HSV){HSV_ORANGE}); continue;
                    }
                    if (keycode == KC_CPYW || keycode == KC_CPYP) {
                      set_keycode_rgb(index, (HSV){HSV_GREEN}); continue;
                    }
                    if (keycode == KC_F10 || keycode == KC_BTN3) {
                      set_keycode_rgb(index, (HSV){21, 230, 255}); continue;
                    }
                  }
                }
                if (keycode == KC_ESC || keycode == C(KC_BSPC) || keycode == KC_F12) {
                    set_keycode_rgb(index, (HSV){HSV_RED}); continue;
                }
                if (keycode == KC_LWR) {
                    set_keycode_rgb(index, (HSV){HSV_CYAN}); continue;
                }
                if (keycode == KC_RAIS) {
                    set_keycode_rgb(index, (HSV){HSV_CORAL}); continue;
                }
              }
           }
      }
    return false;
  }



#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LWR:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case KC_RAIS:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
         case KC_PRVWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_LEFT);
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_RIGHT);
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_LEFT);
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_RIGHT);
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
			case _RAISE:
                    if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			case _LOWER:
					if (clockwise) {
						tap_code(KC_PGDN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_U);
					} else {
						tap_code(KC_WH_D);
					}
				break;
		}
    }
    return true;
}

#endif
