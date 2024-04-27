/* Copyright 2023 Brian Low
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
#pragma once

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot

// #	define SPLIT_USB_DETECT
// #	define ENCODER_DIRECTION_FLIP
#	define SPLIT_LAYER_STATE_ENABLE
#	define SPLIT_USB_TIMEOUT
#	define SPLIT_TRANSPORT_MIRROR             // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR

#ifdef POINTING_DEVICE_ENABLE
    #define MASTER_RIGHT
    #define SPLIT_POINTING_ENABLE
    #define POINTING_DEVICE_RIGHT
    #define POINTING_DEVICE_ROTATION_90
    #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
    #define CIRQUE_PINNACLE_DIAMETER_MM 40
    #define CIRQUE_PINNACLE_TAP_ENABLE 1
    #define CIRQUE_PINNACLE_CURVED_OVERLAY 1
    #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE 1
    #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#endif

// #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE


#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_LED_COUNT

	//#	define RGBLIGHT_EFFECT_BREATHING
	//# define RGBLIGHT_EFFECT_RAINBOW_MOOD
	//#	define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#	define RGBLIGHT_EFFECT_SNAKE
	//#	define RGBLIGHT_EFFECT_KNIGHT
	//#	define RGBLIGHT_EFFECT_CHRISTMAS
	//#	define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#	define RGBLIGHT_EFFECT_RGB_TEST
	//#	define RGBLIGHT_EFFECT_ALTERNATING
	//#	define RGBLIGHT_EFFECT_TWINKLE

    #	define RGBLIGHT_LED_COUNT 58
	//#	define RGBLED_SPLIT
	// #	define RGBLED_SPLIT { 35, 35 } // haven't figured out how to use this yet

	//#	define RGBLIGHT_LED_COUNT 30
    #	define RGBLIGHT_LIMIT_VAL 120
    #	define RGBLIGHT_HUE_STEP 10
    #	define RGBLIGHT_SAT_STEP 17
    #	define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
    #   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    #   define RGBLED_NUM 29    // Number of LEDs
    #   define RGBLED_NUM 29
    #   define DRIVER_LED_TOTAL RGBLED_NUM
    #   define RGB_DISABLE_WHEN_USB_SUSPENDED true
    // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
    #   define RGB_MATRIX_SLEEP // turn off effects when suspended
    // #   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

    #	define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

    #   define RGB_MATRIX_HUE_STEP 8
    #   define RGB_MATRIX_SAT_STEP 8
    #   define RGB_MATRIX_VAL_STEP 8
    #   define RGB_MATRIX_SPD_STEP 10

    /* Disable the animations you don't want/need.  You will need to disable a good number of these    *
    * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
    #   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
    #   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #   undef ENABLE_RGB_MATRIX_BREATHING
    #   undef ENABLE_RGB_MATRIX_CYCLE_ALL
    #   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #   undef ENABLE_RGB_MATRIX_DUAL_BEACON
    #   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #   undef ENABLE_RGB_MATRIX_RAINDROPS
    #   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #   undef ENABLE_RGB_MATRIX_SPLASH
    #   undef ENABLE_RGB_MATRIX_MULTISPLASH
    #   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
    #   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
