#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4








/*  これ何だっけ？20190729
#ifndef CONFIG_MY_H
#define CONFIG_MY_H

#include "config_common.h"
*/








//#define GRAVE_ESC_GUI_OVERRIDE  // GUIキーとの組み合わせで、Escキーのまま使う。
//#define GRAVE_ESC_SHIFT_OVERRIDE
//#define GRAVE_ESC_CTRL_OVERRIDE
//#define GRAVE_ESC_ALT_OVERRIDE





#define TAPPING_TERM_PER_KEY	// キーごとにタッピング時間を設定する。
//	https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md

#define TAPPING_TERM 90	//　←この値が一番最適だった20190925
//#define TAPPING_TERM 180
//  なぜに90にしなければならなかったのか・・・完全に理由を忘れてしまった。
//  vimエディタを使って思い出した。
//  押下速度が速い場合、反応しないからだ20190925



//	レイヤー変更から戻ったとき、Shiftキーやmodifierキーが押されっぱなしを解放する措置20190729
//#define PREVENT_STUCK_MODIFIERS
	// https://github.com/qmk/qmk_firmware/blob/f39e1b5dfe7552f01dbc6eab95c268f41a9d98e2/readme.md#prevent-stuck-modifiers


//	タッピング時間を過ぎた状態での押下を有効にするための措置20180825
//		https://beta.docs.qmk.fm/features/feature_advanced_keycodes
//#define RETRO_TAPPING	// TAPPING_TERMを経過しても、他のキーを押していなければTapとして扱われるようになる。
#define PERMISSIVE_HOLD	// TAPPING_TERM経過前に他のキーを押すと、Holdとして扱われるようになる。


/* Set 0 if debouncing isn't needed */
//#define DEBOUNCE    10
//	設定値(ミリ秒)押された場合に限り、有効な打鍵とされる(Ergodxでの標準設定5)。



//	電力消費のために追加しているが,どの値が適切なのかわからない20181026
#define USB_MAX_POWER_CONSUMPTION 100




//	20181015
#define MOUSEKEY_DELAY				0
#define MOUSEKEY_INTERVAL			0
#define MOUSEKEY_MAX_SPEED			7
#define MOUSEKEY_TIME_TO_MAX		80
#define MOUSEKEY_WHEEL_MAX_SPEED	8
#define MOUSEKEY_WHEEL_TIME_TO_MAX	80



//  指定した時間以内のタッピング回数でレイヤーが変更される。
//#define TAPPING_TOGGLE 2

//  OSM(MOD_LCTL)キー用の設定？
#define ONESHOT_TIMEOUT 8000


/* 2回すばやく押して2回目ホールドで単押しに設定したキーの連続入力が可能 */
//	https://docs.qmk.fm/#/feature_advanced_keycodes?id=tapping-force-hold
//	https://qiita.com/chesscommands/items/cf740e2e8b2b6879c798
#define TAPPING_FORCE_HOLD
//	KC_SFTENT用に設定した20190518
//		意図した動きになってくれなかったため,無効化20190729
//      要は、上記の説明が逆なのか？


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/*	AutoShiftを有効にした場合に,以下を有効にして調整する.	*/
#define NO_AUTO_SHIFT_SPECIAL
//#define NO_AUTO_SHIFT_NUMERIC	←数字のみ無効にする宣言.
//#define NO_AUTO_SHIFT_ALPHA	←アルファベットのみ無効にする宣言.













/*
#endif
*/




