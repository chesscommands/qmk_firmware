/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Biacco42

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REV1_CONFIG_H
#define REV1_CONFIG_H

#include "config_common.h"








//	電力消費のために追加しているが,どの値が適切なのかわからない20181026
#define USB_MAX_POWER_CONSUMPTION 100







//	タッピング時間を過ぎた状態での押下を有効にするための措置20180825
//		https://beta.docs.qmk.fm/features/feature_advanced_keycodes
//#define RETRO_TAPPING
#define PERMISSIVE_HOLD

//	#define PREVENT_STUCK_MODIFIERS










//				使い方がよくわからない.有効になってくれない.
//#define IGNORE_MOD_TAP_INTERRUPT
//		https://bouzuya.hatenablog.com/entry/2017/09/09/235959



//	20181015
#define MOUSEKEY_DELAY				0
#define MOUSEKEY_INTERVAL			0
#define MOUSEKEY_MAX_SPEED			7
#define MOUSEKEY_TIME_TO_MAX		80
#define MOUSEKEY_WHEEL_MAX_SPEED	8
#define MOUSEKEY_WHEEL_TIME_TO_MAX	80





//#define TAPPING_TOGGLE  2

#define ONESHOT_TIMEOUT 8000





/* 2回すばやく押して2回目ホールドで単押しに設定したキーの連続入力が可能 */
//	https://docs.qmk.fm/#/feature_advanced_keycodes?id=tapping-force-hold
//	https://qiita.com/chesscommands/items/cf740e2e8b2b6879c798
//#define TAPPING_FORCE_HOLD
//	KC_SFTENT用に設定した20190518
//		意図した動きになってくれなかったため,無効化.









/*	AutoShiftを有効にした場合に,以下を有効にして調整する.	*/
#define NO_AUTO_SHIFT_SPECIAL
//#define NO_AUTO_SHIFT_NUMERIC	←数字のみ無効にする宣言.
//#define NO_AUTO_SHIFT_ALPHA	←アルファベットのみ無効にする宣言.





//#define GRAVE_ESC_GUI_OVERRIDE
//#define GRAVE_ESC_SHIFT_OVERRIDE
//#define GRAVE_ESC_CTRL_OVERRIDE
//#define GRAVE_ESC_ALT_OVERRIDE

















/* USB Device descriptor parameter */
#define VENDOR_ID       0xBC42
#define PRODUCT_ID      0x0042
#define DEVICE_VER      0x0100
#define MANUFACTURER    Biacco42
#define PRODUCT         Ergo42
#define DESCRIPTION     The Answer to the Ultimate Question of Life, the Universe, and at least Keyboards

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
// #define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6 } //uncomment this line and comment line above if you need to reverse left-to-right key order

#define CATERINA_BOOTLOADER



#define TAPPING_TERM_PER_KEY	// キーごとにタッピング時間を設定する。	←そのはずなのだが、設定が反映されない20190610
//	https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md


/* define tapping term */
//#define TAPPING_TERM 80
//#define TAPPING_TERM 100	// ←この値がちょうどいいのかもしれない20181102
#define TAPPING_TERM 90
//#define TAPPING_TERM 180	←反応が遅いため,使い物にならない20181102
//#define TAPPING_TERM 75
//#define TAPPING_TERM 200	←絶対にあり得ない反応速度20190518
//#define TAPPING_TERM 50	←指の動きをこれ以上早くできないため、無謀な値だった。ましてや,これ以上小さい値は死ぬことになる20190518
//#define TAPPING_TERM 30
//#define TAPPING_TERM 60



/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#define RGBLED_NUM 12    // Number of LEDs

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
