/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"



#define HANZENjap_eng M(0)



extern keymap_config_t keymap_config;

enum planck_layers {
	BASEPlate = 0,
	MACBASE,
	LINUXBASE,
	ANDROIDBASE,
	IPADBASE,
	BASETEMPLayer,	/* ベースレイヤーとの区切りを付けるための空行のような存在	*/

	MOVESPlate,
	MEDIAPlate,
	MOUSEPlate,
	HHKBPlate,

	TEMPPlate1,
	TEMPPlate2,
	TEMPPlate3,
	TEMPPlate4,
	TEMPPlate5,

	ENDPlate
};

enum planck_keycodes {
	ZEROReturn = SAFE_RANGE, // can always be here

	END_SAFE_RANGE
};
































































const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |GUIEnt|   Q  |   W  |   E  |   R  |  T   |  Y   |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |  G   |  H   |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |  B   |  N   |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |半全角| Space| Bkspc|Delete| LAlt |LCtrl | Space| Shift|   =  |   `  |   -  |  \   |
 * `-----------------------------------------------------------------------------------'
 */
[BASEPlate] = LAYOUT_planck_grid(
	LGUI_T(KC_ENTER),	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRACKET,	
	KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	
	KC_LSHIFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RBRACKET,	
	HANZENjap_eng,	LT(MEDIAPlate, KC_SPC),	KC_BSPACE,	KC_DELETE,	LALT_T(KC_ESCAPE),	KC_LCTRL,	LT(MOVESPlate, KC_SPC),	KC_RSHIFT,	KC_EQL,	KC_GRAVE,	KC_MINS,	KC_BSLS	
),


/* MACBASE Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[MACBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* LINUXBASE Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LINUXBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* AndroidBASE Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ANDROIDBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* iPadBASE Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[IPADBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* BASETEMPLayer Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[BASETEMPLayer] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),








































/* Move Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  {   |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * |LShift|  =   | MsUp | Lclk | Rclk | PgUp |  ←  |  ↓  |  ↑  |  →  |   :  |  "   |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |LShift|  +   |MsLeft|MsDown|MsRght| PgDn | Home | End  |   <  |   >  |   ?  |  }   |	←Home・Endキーの場所をうまい具合によそに移動させられるならば,記号をここに配置したい.
 * |      |  !   |  @   |  #   |  $   |  %   | 継承 |  ^   |  &   |  *   |  (   |  )   |	←使い回したい。
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *|ASトグル|ScrLok|     |      |      | LCtrl|      |  =   |  +   |  ~   |  _   |  |   |
 * `-----------------------------------------------------------------------------------'
 */
[MOVESPlate] = LAYOUT_planck_grid(
	_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_LEFT_CURLY_BRACE,	
	KC_LSHIFT,	KC_EQL,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_BTN1,	KC_PGUP,	KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT, KC_COLON, KC_DOUBLE_QUOTE,	
	_______,	KC_PLUS,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_PGDOWN,	KC_HOME,	KC_END,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_RIGHT_CURLY_BRACE,	
	KC_ASTG,	KC_LOCKING_SCROLL,	_______,	_______,	_______,	_______,	KC_NO,	KC_EQL, KC_PLUS, KC_TILDE, KC_UNDERSCORE, KC_PIPE	
),

//	KC_ASTG：AutoShift自動押下のトグルキー
//		rules.mk	AUTO_SHIFT_ENABLE = yes



/* Media and mouse keys
 * ,-----------------------------------------------------------------------------------.
 * |LShift|  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |PrScrn| F12  |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |WhelUp| LCtrl| Home | End  |Escape|PrScrn|  |   |  _   |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |WlDown|      |      |      |LShift|      |RShift| RSft |  +   |  |   |   _  |      |
 * `-----------------------------------------------------------------------------------'
 */
  [MEDIAPlate] = LAYOUT_planck_grid(
	KC_LSHIFT,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5, 	KC_6,	KC_7,	KC_8,	KC_9,	KC_PSCREEN,	KC_F12,	
	KC_LSHIFT,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	
	KC_MS_WH_UP,	KC_LCTRL,	KC_HOME,	KC_END,	KC_ESCAPE,	LALT(KC_PSCREEN),	KC_PIPE,	KC_UNDERSCORE,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_NO,	
	KC_MS_WH_DOWN,	KC_ENTER,	_______,	_______,	KC_LSHIFT,	_______,	KC_RSHIFT,	_______,	KC_PLUS, KC_PIPE, KC_UNDERSCORE,	_______	
  ),

//	Alt＋F4：ウィンドウを閉じる （ブラクラならAlt＋F4数回を押すか押しっ放し）	←コレができない。AutoHotKeyで代替


/* MOUSE Layer
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |LShift|      | Lclk | Rclk |Middle|MsLeft|MsDown| MsUp |MsRght|WhelUp| Stop |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F13  | F14  |  F15 |  F16 |  F17 | F24  | F18  | F19  | F20  |  F21 |  F22 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |     |予約済み|     |      |      |      |      | Wleft|WlDown|WRight|
 * `-----------------------------------------------------------------------------------'
 */
  [MOUSEPlate] = LAYOUT_planck_grid(
	KC_F12,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	
	_______,	KC_LSHIFT,	XXXXXXX,	KC_MS_BTN2,	KC_MS_BTN1,	KC_MS_BTN3,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_MS_WH_UP,	KC_MEDIA_STOP,	
	_______,	KC_F13,	KC_F14,	KC_F15,	KC_F16,	KC_F17,	KC_F24,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	
	RESET,	XXXXXXX,	XXXXXXX,	_______,	_______,	_______,	XXXXXXX,	_______,	XXXXXXX,	KC_MS_WH_LEFT,	KC_MS_WH_DOWN,	KC_MS_WH_RIGHT	
  )



	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),
*/
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
*/

};




const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch(id) {
	case 0:
		if (record->event.pressed) { // 日本語入力のオン／オフ（英語配列）
			return MACRO( D(LALT), T(GRAVE), U(LALT), END);
		}
		break;


	}
	return MACRO_NONE;
};




#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
//	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	return update_tri_layer_state(state, MOVESPlate, MEDIAPlate, MOUSEPlate);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case ZEROReturn:
		// レイヤーのデフォルトをゼロに戻す20180908
		if (record->event.pressed) {
			// キー押下時に動く
			eeconfig_update_default_layer( 0 );
			default_layer_set( 0 );
		}
		else {
			// キー押上時に動く
		}
		return false;
		break;
	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
/*
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
*/
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
/*    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
*/
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
/*    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
*/
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
/*    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
*/  }
      return true;
}
