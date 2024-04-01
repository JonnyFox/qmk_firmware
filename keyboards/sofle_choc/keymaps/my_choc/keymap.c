
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
    _ADJUST,
};

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LWR,
    KC_RAIS,
    KC_ADJUST,
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
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
     KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, KC_MPLY,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                      KC_LCTL, KC_LALT, KC_LGUI,  KC_LWR,  KC_SPC,  KC_ENT, KC_RAIS, KC_RGUI, KC_RALT, KC_RCTL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   [  |   ]  |-------|    |-------|   {  |   }  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______,  KC_LWR, _______, _______, KC_RAIS, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    | PagU | PWrd |  Up  | NWrd | DLine| Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | CapW | CapP | CpyW | CpyP | Caps |-------.    ,-------| PagD | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |  \   | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
     KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_EQL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, KC_PRVWD,  KC_UP,KC_NXTWD, XXXXXXX,  KC_DEL,
    _______, KC_CAPW, KC_CAPP, KC_CPYW, KC_CPYP, KC_CAPS,                   KC_PGDN,  KC_LEFT,KC_DOWN, KC_RGHT, XXXXXXX,C(KC_BSPC),
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_INS, _______, XXXXXXX, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, KC_BSLS, _______,
                      _______, _______, _______,  KC_LWR, _______, _______, KC_RAIS, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOO|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TO| hue^ |sat ^ | bri ^|      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   QK_BOOT, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   RGB_TOG, RGB_HUI,  RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
   RGB_MOD, RGB_HUD,  RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______,  KC_LWR, _______, _______, KC_RAIS, _______, _______, _______
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
                    if (keycode == KC_UP || keycode == KC_DOWN || keycode == KC_LEFT || keycode == KC_RIGHT) {
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
                    if (keycode == KC_F5 || keycode == KC_F11 || keycode == KC_LCBR || keycode == KC_RCBR) {
                      set_keycode_rgb(index, (HSV){HSV_ORANGE}); continue;
                    }
                    if (keycode == KC_F8) {
                      set_keycode_rgb(index, (HSV){HSV_GREEN}); continue;
                    }
                    if (keycode == KC_CAPW || keycode == KC_CAPP) {
                      set_keycode_rgb(index, (HSV){HSV_ORANGE}); continue;
                    }
                    if (keycode == KC_CPYW || keycode == KC_CPYP) {
                      set_keycode_rgb(index, (HSV){HSV_GREEN}); continue;
                    }
                    if (keycode == KC_F10) {
                      set_keycode_rgb(index, (HSV){21, 230, 255}); continue;
                    }
                  }
                }
                if (keycode == KC_ESC || keycode == C(KC_BSPC)) {
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


// void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer) {
//     const ledmap *l = &(ledmap[layer]);

//     uint8_t val = rgb_matrix_get_val();

//     for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
//         HSV hsv = {
//             .h = (*l)[i][0],
//             .s = (*l)[i][1],
//             .v = val,
//         };

//         if (hsv.h || hsv.s) {
//             RGB rgb = hsv_to_rgb(hsv);
//             RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
//         }
//     }
// }

// void set_current_layer_rgb(void) {
//     set_rgblight_by_layer(get_highest_layer(layer_state | default_layer_state));
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     set_rgblight_by_layer(biton32(state));
//     return state;
// }


#endif


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("J.Fox"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("Sofle v2"), false);
    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    oled_write_P(PSTR("\n\n"), false);
    oled_write_P(PSTR("Layer\n"), false);
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
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
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAIS:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
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
				case _QWERTY:
					if (clockwise) {
						tap_code(KC_PGUP);
					} else {
						tap_code(KC_PGDN);
					}
				break;
			case _RAISE:
			case _LOWER:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif
