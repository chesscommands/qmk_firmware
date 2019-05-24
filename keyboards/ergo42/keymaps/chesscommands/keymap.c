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
	CTRLENTER,
	ALTSPACE,

  END_SAFE_RANGE
};





// CTRLENTER用
static uint16_t my_hash_timer;
#define MY_TAPPING_TERM 60	// CTRLENTERにはいいかもしれないが,やはり,一癖も二癖もある.この値では使いこなせない.











enum TapDanceDeclarations{
	LPRN_LBRC_LCBR,
	RPRN_RBRC_RCBR,
	ESC_SHIFT_LGUI,
	_LCTRL_LALT,
	LENTER_LCTRL,
	LCTRL_TWOLEYERMEDIA,

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



static tap left_Ctrl_Alt_tap_state = {
	// タップでAlt+`(日本語英語切り替えwinのみ)・押し続けることでLCtrl・ダブルタップ後の押し続けでAltキーとする.
	.is_press_action = true,
	.state = 0
	//	だめ20181024
	//		使い物にならない.しっかり押さなければ認識されない.タップ時間を短くすればいいように思うが,そうした場合Altキーに切り替えるのがしんどい.失敗
};


static tap left_Enter_tap_CtrlPress_state = {
	// タップでEnterキー・押し続けることでLCtrlキーとする.
	.is_press_action = true,
	.state = 0
};



static tap CtrlPress_2PressLeyer_state = {
	// 押し続けでLCtrlキー・2回タップ後の押し続けでレイヤー変更キーとする.
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



void LCTRLALT_finished (qk_tap_dance_state_t *state, void *user_data) {
	left_Ctrl_Alt_tap_state.state = cur_dance(state);
	switch (left_Ctrl_Alt_tap_state.state) {
//		case SINGLE_TAP: register_code(HANZENjap_eng); break;
		case SINGLE_TAP: register_code(KC_LCTRL); break;	// ← この組み合わせであれば使い物になりそうだ。
		case SINGLE_HOLD: register_code(KC_LCTRL); break;
		case DOUBLE_HOLD: register_code(KC_LALT); break;	// ← ほかのキーとの組み合わせができない.
	}
}
void LCTRLALT_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (left_Ctrl_Alt_tap_state.state) {
//		case SINGLE_TAP: unregister_code(HANZENjap_eng); break;
		case SINGLE_TAP: unregister_code(KC_LCTRL); break;
		case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
		case DOUBLE_HOLD: unregister_code(KC_LALT); break;
	}
	left_Ctrl_Alt_tap_state.state = 0;
}






void LENTERCTR_finished (qk_tap_dance_state_t *state, void *user_data) {
	left_Enter_tap_CtrlPress_state.state = cur_dance(state);
	switch (left_Enter_tap_CtrlPress_state.state) {
		case SINGLE_TAP: register_code(KC_ENTER); break;
		case SINGLE_HOLD: register_code(KC_LCTRL); break;
		case DOUBLE_HOLD: register_code(KC_ENTER); break;
	}
}
void LENTERCTR_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (left_Enter_tap_CtrlPress_state.state) {
		case SINGLE_TAP: unregister_code(KC_ENTER); break;
		case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
		case DOUBLE_HOLD: default: unregister_code(KC_ENTER); break;
	}
	left_Enter_tap_CtrlPress_state.state = 0;
}





//	以下、コンパイルエラーが発生し、思惑通りにいかなかった20181124
void CTRLPRESSLEYERMEDIA_finished (qk_tap_dance_state_t *state, void *user_data) {
	CtrlPress_2PressLeyer_state.state = cur_dance(state);
	switch (CtrlPress_2PressLeyer_state.state) {
		case SINGLE_TAP: register_code(KC_LCTRL); break;
		case SINGLE_HOLD: register_code(KC_LCTRL); break;
//		case DOUBLE_HOLD: register_code(MO(MEDIAPlate)); break;
	}
}
void CTRLPRESSLEYERMEDIA_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (CtrlPress_2PressLeyer_state.state) {
		case SINGLE_TAP: unregister_code(KC_LCTRL); break;
		case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
//		case DOUBLE_HOLD: default: unregister_code(MO(MEDIAPlate)); break;
	}
	CtrlPress_2PressLeyer_state.state = 0;
}









//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[LPRN_LBRC_LCBR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LPRN_finished, LPRN_reset),
	[RPRN_RBRC_RCBR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, RPRN_finished, RPRN_reset),
	[ESC_SHIFT_LGUI]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ESL_finished, ESL_reset),
	[_LCTRL_LALT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LCTRLALT_finished, LCTRLALT_reset),
	[LENTER_LCTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LENTERCTR_finished, LENTERCTR_reset),
	[LCTRL_TWOLEYERMEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLPRESSLEYERMEDIA_finished, CTRLPRESSLEYERMEDIA_reset)

};



















const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |GUIEsc|   Q  |   W  |   E  |   R  |  T   | APP  |   |  Y   |   U  |   I  |   O  |   P  |  [   |   `  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |  G   |LShift|   |  H   |   J  |   K  |   L  |   ;  |   '  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Space|   Z  |   X  |   C  |   V  |  B   | Tab  |   |  N   |   M  |   ,  |   .  |   /  |  ]   |Escape|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Delete| Bkspc|半全角| LAlt |Sft/Etr|LCtrl|LShift|   | Space| Shift|   =  |   `  |   -  |  \   | LGUI |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASEPlate] = LAYOUT(
	LGUI_T(KC_ESCAPE),	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_APPLICATION,			KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRACKET,	KC_GRAVE,	
	KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	LSFT_T(KC_ESCAPE),			KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	KC_SFTENT,	
	KC_SPC,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_TAB,			KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RBRACKET,	KC_GESC,	
//	KC_BSPACE,	LT(MEDIAPlate, KC_SPC),	HANZENjap_eng,	KC_DELETE,	LALT_T(KC_ENTER),	KC_LCTRL,	KC_SPC,			LT(MOVESPlate, KC_SPC),	KC_RSHIFT,	KC_EQL,	KC_GRAVE,	KC_MINS,	KC_BSLS,	QK_RGUI	
//	KC_BSPACE,	LT(MEDIAPlate, KC_SPC),	HANZENjap_eng,	KC_DELETE,	KC_LALT,	CTRLENTER,	KC_SPC,			LT(MOVESPlate, KC_SPC),	KC_RSHIFT,	KC_EQL,	KC_GRAVE,	KC_MINS,	KC_BSLS,	QK_RGUI	
//	KC_BSPACE,	LT(MEDIAPlate, KC_SPC),	HANZENjap_eng,	KC_DELETE,	ALTSPACE,	CTL_T(KC_ENTER),	KC_SPC,			LT(MOVESPlate, KC_SPC),	KC_RSHIFT,	KC_EQL,	KC_GRAVE,	KC_MINS,	KC_BSLS,	QK_RGUI	
//	KC_LALT,	LT(MEDIAPlate, KC_BSPACE),	HANZENjap_eng,	KC_DELETE,	KC_SFTENT,	KC_LCTRL,	KC_SPC,			LT(MOVESPlate, KC_SPC),	KC_RSHIFT,	KC_EQL,	KC_GRAVE,	KC_MINS,	KC_BSLS,	QK_RGUI
	KC_DELETE,	LT(MEDIAPlate, KC_BSPACE),	HANZENjap_eng,	KC_LALT,	SFT_T(KC_ENTER),	KC_LCTRL,	KC_SPC,			LT(MOVESPlate, KC_SPC),	KC_RSHIFT,	KC_EQL,	KC_GRAVE,	KC_MINS,	KC_BSLS,	QK_RGUI	
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
   * |      |  1   |  2   |  3   |  4   |  5   |      |   |  6   |  7   |  8   |  9   |  0   |  {   |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |LShift|  =   | MsUp | Lclk | Rclk | PgUp |      |   |  ←  |  ↓  |  ↑  |  →  |   :  |  "   |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |LShift|  +   |MsLeft|MsDown|MsRght| PgDn |      |   | Home | End  |   <  |   >  |   ?  |  }   | RESET|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   *|ASトグル|ScrLok|     |      |      | LCtrl|      |  |予約済み|  =  |  +   |  ~   |  _   |  |   |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOVESPlate] = LAYOUT(
	_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	_______,			KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_LEFT_CURLY_BRACE,	KC_NO,	
	KC_LSHIFT,	KC_EQL,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_BTN1,	KC_PGUP,	_______,			KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT, KC_COLON, KC_DOUBLE_QUOTE, KC_NO,	
	_______,	KC_PLUS,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_PGDOWN,	_______,			KC_HOME,	KC_END,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_RIGHT_CURLY_BRACE,	RESET,	
	KC_ASTG,	KC_LOCKING_SCROLL,	_______,	_______,	_______,	_______,	_______,			KC_NO,	KC_EQL, KC_PLUS, KC_TILDE, KC_UNDERSCORE, KC_PIPE, KC_NO	
  ),

//	KC_ASTG：AutoShift自動押下のトグルキー
//		rules.mk	AUTO_SHIFT_ENABLE = yes




  /* Media and mouse keys
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |LShift|  1   |  2   |  3   |  4   |  5   | 継承 |   |  6   |  7   |  8   |  9   |PrScrn| F12  | 継承 |
   * |------|------+------+------+------+------+------+   |------+------+------+------+------+------|------+
   * |LShift|  F1  |  F2  |  F3  |  F4  |  F5  | 継承 |   |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | 継承 |
   * |------|------+------+------+------+------+------+   |------+------+------+------+------+------|------+
   * |WhelUp| Enter| Home | End  |Escape|PrScrn| 継承 |   |  |   |  _   |   <  |   >  |   ?  |      | 継承 |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |WlDown| LCtrl|      |      |LShift|      |      |   |RShift| RSft |  +   |  |   |   _  |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MEDIAPlate] = LAYOUT(
	KC_LSHIFT,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5, 	_______,			KC_6,	KC_7,	KC_8,	KC_9,	KC_PSCREEN,	KC_F12,	_______,	
	KC_LSHIFT,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	RESET,			KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	XXXXXXX,
	KC_MS_WH_UP,	KC_ENTER,	KC_HOME,	KC_END,	KC_ESCAPE,	LALT(KC_PSCREEN),	_______,			KC_PIPE,	KC_UNDERSCORE,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_NO,	_______,	
	KC_MS_WH_DOWN,	KC_LCTRL,	_______,	_______,	KC_LSHIFT,	_______,	_______,			KC_RSHIFT,	_______,	KC_PLUS, KC_PIPE, KC_UNDERSCORE,	_______,	_______	
  ),

//	Alt＋F4：ウィンドウを閉じる （ブラクラならAlt＋F4数回を押すか押しっ放し）	←コレができない。AutoHotKeyで代替




  /* MOUSE Layer
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  | RESET|   |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |LShift|      | Lclk | Rclk |Middle|      |   |MsLeft|MsDown| MsUp |MsRght|WhelUp| Stop |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      | F13  | F14  |  F15 |  F16 |  F17 | F23  |   | F24  | F18  | F19  | F20  |  F21 |  F22 |      |
   * |  !   |  @   |  #   |  $   |  %   | 継承 | 継承 |   |  ^   |  &   |  *   |  (   |  )   |      | 継承 |	←使い回したい。
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | RESET|      |     |予約済み|     |      | RESET|   |      |      |      | Wleft|WlDown|WRight|      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOUSEPlate] = LAYOUT(
	KC_F12,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	RESET,			KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	XXXXXXX,
	_______,	KC_LSHIFT,	XXXXXXX,	KC_MS_BTN2,	KC_MS_BTN1,	KC_MS_BTN3,	XXXXXXX,			KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_MS_WH_UP,	KC_MEDIA_STOP,	XXXXXXX,
	_______,	KC_F13,	KC_F14,	KC_F15,	KC_F16,	KC_F17,	KC_F23,			KC_F24,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	XXXXXXX,
	RESET,	XXXXXXX,	XXXXXXX,	_______,	_______,	_______,	RESET,			XXXXXXX,	_______,	XXXXXXX,	KC_MS_WH_LEFT,	KC_MS_WH_DOWN,	KC_MS_WH_RIGHT,	XXXXXXX
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


	case CTRLENTER:
// https://www.reddit.com/r/olkb/comments/a5ujx6/can_i_make_qmks_modtap_behave_like_easyavrs_tap/
		if(record->event.pressed) {
			my_hash_timer = timer_read();
			register_code(KC_LCTL); // Change the key to be held here
		} else {
			unregister_code(KC_LCTL); // Change the key that was held here, too!
			if (timer_elapsed(my_hash_timer) < MY_TAPPING_TERM) {
				SEND_STRING(SS_TAP(X_ENTER)); // Change the character(s) to be sent on tap here
			}
		}
		return false; // We didn't handle other keypresses
		break;


	case ALTSPACE:
		if(record->event.pressed) {
			my_hash_timer = timer_read();
			register_code(KC_LALT);
		} else {
			unregister_code(KC_LALT);
			if (timer_elapsed(my_hash_timer) < MY_TAPPING_TERM) {
//				register_code(KC_ESCAPE);
//				unregister_code(KC_ESCAPE);
				SEND_STRING(SS_TAP(X_ESCAPE));
				SEND_STRING(SS_TAP(X_SPACE));
			}
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






