#include QMK_KEYBOARD_H



#include "debug.h"
#include "action_layer.h"
#include "version.h"

//#include "quantum.h"
//#include "action.h"
//#include "process_keycode/process_tap_dance.h"










#define HANZENjap_eng M(0)








//	・キーに何も設定しない場合
//	KC_NO　⇒　XXXXXXX
//	・前のレイヤーキーを引き継ぐ場合
//	KC_TRANSPARENT　⇒　KC_TRNSもしくは_______


enum layerNumber {
	BASEPlate = 0,
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


enum custom_keycodes {
  ZEROReturn = SAFE_RANGE, // can always be here

  END_SAFE_RANGE
};
















enum TapDanceDeclarations{
	LPRN_LBRC_LCBR,
	RPRN_RBRC_RCBR,
	ESC_SHIFT_LGUI,

	SOME_OTHER_DANCE
};

enum TapDanceQuadFunction {
	SINGLE_TAP = 1,
	SINGLE_HOLD = 2,
	DOUBLE_TAP = 3,
	DOUBLE_HOLD = 4,
	DOUBLE_SINGLE_TAP = 5, //send two single taps
	TRIPLE_TAP = 6,
	TRIPLE_HOLD = 7
};

typedef struct {
	bool is_press_action;
	int state;
} tap;

static tap lprn_tap_state = {
	//	開き括弧用
	.is_press_action = true,
	.state = 0
};

static tap rprn_tap_state = {
	// 閉じ括弧用
	.is_press_action = true,
	.state = 0
};




static tap escShiftLGui_tap_state = {
	// タップでEsc・押し続けることで押し続けることでShift・ダブルタップ後の押し続けでGUIキーとする.
	.is_press_action = true,
	.state = 0
};





int cur_dance (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed)  return SINGLE_TAP;
		else return SINGLE_HOLD;
	}
	else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	if (state->count == 3) {
		if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
		else return TRIPLE_HOLD;
	}
	else return 8; //magic number. At some point this method will expand to work for more presses
}

void LPRN_finished (qk_tap_dance_state_t *state, void *user_data) {
	lprn_tap_state.state = cur_dance(state);
	switch (lprn_tap_state.state) {
//    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_9); 
//                                             break;
		case SINGLE_TAP: register_code(KC_LBRACKET); break;
		case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_LBRACKET); 
												break;
	}
}

void LPRN_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (lprn_tap_state.state) {
//    case SINGLE_TAP: unregister_code(KC_9); unregister_code(KC_LSFT); 
//                                             break;
		case SINGLE_TAP: unregister_code(KC_LBRACKET); break;
		case DOUBLE_TAP: unregister_code(KC_LBRACKET); unregister_code(KC_LSFT); 
													break;
	}
	lprn_tap_state.state = 0;
}


void RPRN_finished (qk_tap_dance_state_t *state, void *user_data) {
	rprn_tap_state.state = cur_dance(state);
	switch (rprn_tap_state.state) {
//    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_0); 
//                                             break;
	case SINGLE_TAP: register_code(KC_RBRACKET); break;
	case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_RBRACKET); 
											break;
	}
}

void RPRN_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (rprn_tap_state.state) {
//    case SINGLE_TAP: unregister_code(KC_0); unregister_code(KC_LSFT); 
//                                             break;
		case SINGLE_TAP: unregister_code(KC_RBRACKET); break;
		case DOUBLE_TAP: unregister_code(KC_RBRACKET); unregister_code(KC_LSFT); 
													break;
	}
	rprn_tap_state.state = 0;
}


void ESL_finished (qk_tap_dance_state_t *state, void *user_data) {
	escShiftLGui_tap_state.state = cur_dance(state);
	switch (escShiftLGui_tap_state.state) {
		case SINGLE_TAP: register_code(KC_ESCAPE); break;
		case SINGLE_HOLD: register_code(KC_LSHIFT); break;
		case DOUBLE_HOLD: register_code(KC_LGUI); break;
	}
}

void ESL_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (escShiftLGui_tap_state.state) {
		case SINGLE_TAP: unregister_code(KC_ESCAPE); break;
		case SINGLE_HOLD: unregister_code(KC_LSHIFT); break;
		case DOUBLE_HOLD: unregister_code(KC_LGUI); break;
	}
	escShiftLGui_tap_state.state = 0;
}



//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[LPRN_LBRC_LCBR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LPRN_finished, LPRN_reset),
	[RPRN_RBRC_RCBR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, RPRN_finished, RPRN_reset),
	[ESC_SHIFT_LGUI]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ESL_finished, ESL_reset)

};




















const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |ESCAPE| Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |  [{  |  ]   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Bkspc| Enter|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   '  |Escape|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | LGUI | LGUI |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |  ]}  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | ←   | Space|  \   | LSft(| LAlt | LCtrl|Escape|   |Space |)RSft |   -  |   =  |  `   | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASEPlate] = LAYOUT(
	KC_ESCAPE,	KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,			KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	TD(LPRN_LBRC_LCBR),	KC_RBRC,	
	KC_BSPACE,	LT(MOUSEPlate,	KC_ENTER),	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	KC_GESC,	
	QK_LGUI,	TD(ESC_SHIFT_LGUI),	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,			KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	TD(RPRN_RBRC_RCBR),	KC_RSFT,	
	KC_LEFT,	KC_SPC,	KC_BSLS,	KC_LALT,	KC_LSPO,	KC_LCTRL,	LT(MEDIAPlate, KC_ESCAPE),			LT(MOVESPlate, KC_SPC),	KC_RSPC,	KC_MINS,	KC_EQL,	KC_GRAVE,	KC_DOWN,	KC_RGHT	
  ),



  /* Temp Layer
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASETEMPLayer] = LAYOUT(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX
  ),



  /* Move Layer
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | RESET|      |      |      |      |      |      |   | PgUp | Tab  | Home | End  | SysRq|Bkspc |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |  ←  |  ↓  |  ↑  |  →  | -_   |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   | PgDn |  |   |  [{  |  ]}  |  \|  |RShift|      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      | Ins  |Pause |LShift| LAlt | LCtrl|Escape|  |予約済み|     |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOVESPlate] = LAYOUT(
	RESET,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,			KC_PGUP,	KC_TAB,	KC_HOME,	KC_END,	KC_PSCREEN,	KC_BSPACE,	KC_NO,	
	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,			KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT, KC_MINUS, KC_NO, KC_NO,	
	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,			KC_PGDOWN,	KC_PIPE,	KC_LBRACKET,	KC_RBRACKET,	KC_BSLASH,	KC_RSHIFT,	KC_NO,	
	KC_NO,	KC_INSERT,	KC_PAUSE,	_______,	_______,	KC_LCTRL,	KC_ESCAPE,			KC_NO,	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO	
  ),
 






  /* Media and mouse keys
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | 継承 | 継承 |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 | 継承 |
   * |------+------|------+------+------+------+------+   |------+------+------+------+------+------|------+
   * | 継承 | 継承 |  1   |  2   |  3   |  4   |  5   |   |  6   |  7   |  8   |  9   |  0   |  F12 | 継承 |
   * |------+------|------+------+------+------+------+   |------+------+------+------+------+------|------+
   * | 継承 | 継承 |  !   |  @   |  #   |  $   |  %   |   |  ^   |  &   |  *   |  (   |  )   |   ;  | 継承 |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  |半角/全角| Sft|      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MEDIAPlate] = LAYOUT(
	_______,	_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,			KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	_______,	
	_______,	_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,			KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_F12,	_______,	
	_______,	_______,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC, 		KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_SCLN,	_______,	
	_______,	_______,	_______,	_______,	_______,	_______,	_______,			HANZENjap_eng,	_______,	_______,	_______,	_______,	_______,	_______	
  ),



  /* MOUSE Layer
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | RESET|      | Home |      | End  | PgUp | Tab  |   | VolUp| Lclk |Middle| Rclk |      | Play |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |     |予約済み| Del |      |      | PgDn |      |   |MsLeft|MsDown| MsUp |MsRght|      | Stop |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   | VolDn| Prev | Next |      | Mute |RShift|      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      | LCtrl| Bkspc|   |      |      |      |      | Wleft|WRight|      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOUSEPlate] = LAYOUT(
	RESET,	XXXXXXX,	KC_HOME,	KC_NO,	KC_END,	KC_PGUP,	KC_TAB,			KC_AUDIO_VOL_UP,	KC_MS_BTN1,	KC_MS_BTN3,	KC_MS_BTN2,	KC_NO,	KC_MEDIA_PLAY_PAUSE,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	KC_DELETE,	KC_NO,	KC_NO,	KC_PGDOWN,	XXXXXXX,			KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_NO,	KC_MEDIA_STOP,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_BSPACE,			KC_AUDIO_VOL_DOWN,	KC_MEDIA_PREV_TRACK,	KC_MEDIA_NEXT_TRACK,	KC_NO,	KC_AUDIO_MUTE,	KC_RSHIFT,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_MS_WH_LEFT,	KC_MS_WH_RIGHT,	XXXXXXX
  )


























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


	}
	return true;
}



void matrix_init_user(void) {
	// レイヤーを0に戻す.
	//		https://github.com/qmk/qmk_firmware/blob/master/tmk_core/common/action_layer.c
//	eeconfig_update_default_layer(0);
//	default_layer_set(0);
};



// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};



// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {


	uint8_t layer = biton32(state);
	switch (layer) {
		case 0:
			break;
		default:
			break;
	}


	return state;
};






