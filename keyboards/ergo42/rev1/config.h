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








//	�d�͏���̂��߂ɒǉ����Ă��邪,�ǂ̒l���K�؂Ȃ̂��킩��Ȃ�20181026
#define USB_MAX_POWER_CONSUMPTION 100







//	�^�b�s���O���Ԃ��߂�����Ԃł̉�����L���ɂ��邽�߂̑[�u20180825
//		https://beta.docs.qmk.fm/features/feature_advanced_keycodes
//#define RETRO_TAPPING
#define PERMISSIVE_HOLD

//	#define PREVENT_STUCK_MODIFIERS










//				�g�������悭�킩��Ȃ�.�L���ɂȂ��Ă���Ȃ�.
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





/* 2�񂷂΂₭������2��ڃz�[���h�ŒP�����ɐݒ肵���L�[�̘A�����͂��\ */
//	https://docs.qmk.fm/#/feature_advanced_keycodes?id=tapping-force-hold
//	https://qiita.com/chesscommands/items/cf740e2e8b2b6879c798
//#define TAPPING_FORCE_HOLD
//	KC_SFTENT�p�ɐݒ肵��20190518
//		�Ӑ}���������ɂȂ��Ă���Ȃ���������,������.









/*	AutoShift��L���ɂ����ꍇ��,�ȉ���L���ɂ��Ē�������.	*/
#define NO_AUTO_SHIFT_SPECIAL
//#define NO_AUTO_SHIFT_NUMERIC	�������̂ݖ����ɂ���錾.
//#define NO_AUTO_SHIFT_ALPHA	���A���t�@�x�b�g�̂ݖ����ɂ���錾.





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



#define TAPPING_TERM_PER_KEY	// �L�[���ƂɃ^�b�s���O���Ԃ�ݒ肷��B	�����̂͂��Ȃ̂����A�ݒ肪���f����Ȃ�20190610
//	https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md


/* define tapping term */
//#define TAPPING_TERM 80
//#define TAPPING_TERM 100	// �����̒l�����傤�ǂ����̂�������Ȃ�20181102
#define TAPPING_TERM 90
//#define TAPPING_TERM 180	���������x������,�g�����ɂȂ�Ȃ�20181102
//#define TAPPING_TERM 75
//#define TAPPING_TERM 200	����΂ɂ��蓾�Ȃ��������x20190518
//#define TAPPING_TERM 50	���w�̓���������ȏ㑁���ł��Ȃ����߁A���d�Ȓl�������B�܂��Ă�,����ȏ㏬�����l�͎��ʂ��ƂɂȂ�20190518
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
