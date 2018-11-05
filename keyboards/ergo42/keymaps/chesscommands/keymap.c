#include QMK_KEYBOARD_H



#include "debug.h"
#include "action_layer.h"
#include "version.h"

//#include "quantum.h"
//#include "action.h"
//#include "process_keycode/process_tap_dance.h"










#define HANZENjap_eng M(0)








//	�E�L�[�ɉ����ݒ肵�Ȃ��ꍇ
//	KC_NO�@�ˁ@XXXXXXX
//	�E�O�̃��C���[�L�[�������p���ꍇ
//	KC_TRANSPARENT�@�ˁ@KC_TRNS��������_______


enum layerNumber {
	BASEPlate = 0,
	BASETEMPLayer,	/* �x�[�X���C���[�Ƃ̋�؂��t���邽�߂̋�s�̂悤�ȑ���	*/

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
	_LCTRL_LALT,

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
	//	�J�����ʗp
	.is_press_action = true,
	.state = 0
};

static tap rprn_tap_state = {
	// �����ʗp
	.is_press_action = true,
	.state = 0
};




static tap escShiftLGui_tap_state = {
	// �^�b�v��Esc�E���������邱�Ƃŉ��������邱�Ƃ�Shift�E�_�u���^�b�v��̉���������GUI�L�[�Ƃ���.
	.is_press_action = true,
	.state = 0
};



static tap left_Ctrl_Alt_tap_state = {
	// �^�b�v��Alt+`(���{��p��؂�ւ�win�̂�)�E���������邱�Ƃ�LCtrl�E�_�u���^�b�v��̉���������Alt�L�[�Ƃ���.
	.is_press_action = true,
	.state = 0
	//	����20181024
	//		�g�����ɂȂ�Ȃ�.�������艟���Ȃ���ΔF������Ȃ�.�^�b�v���Ԃ�Z������΂����悤�Ɏv����,���������ꍇAlt�L�[�ɐ؂�ւ���̂�����ǂ�.���s
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
		case SINGLE_TAP: register_code(KC_LCTRL); break;	// �� ���̑g�ݍ��킹�ł���Ύg�����ɂȂ肻�����B
		case SINGLE_HOLD: register_code(KC_LCTRL); break;
		case DOUBLE_HOLD: register_code(KC_LALT); break;	// �� �ق��̃L�[�Ƃ̑g�ݍ��킹���ł��Ȃ�.
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



//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[LPRN_LBRC_LCBR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LPRN_finished, LPRN_reset),
	[RPRN_RBRC_RCBR]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, RPRN_finished, RPRN_reset),
	[ESC_SHIFT_LGUI]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ESL_finished, ESL_reset),
	[_LCTRL_LALT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LCTRLALT_finished, LCTRLALT_reset)

};




















const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |  T   | Space|   |  Y   |   U  |   I  |   O  |   P  |  [   |   `  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Bkspc|   A  |   S  |   D  |   F  |  G   |  Tab |   |  H   |   J  |   K  |   L  |   ;  |   '  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Space|   Z  |   X  |   C  |   V  |  B   |Shift(|   |  N   |   M  |   ,  |   .  |   /  |  ]   |Escape|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LGUI |Escape| Enter|Escape| LCtrl| LAlt |   | Space|)Shift|   =  |   -  |   \  |RClick| LGUI |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASEPlate] = LAYOUT(
	KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_SPC,			KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRACKET,	KC_GRAVE,	
	KC_BSPACE,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_TAB,			KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	KC_ENTER,	
	KC_SPC,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_LSPO,			KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RBRACKET,	KC_GESC,	
 	QK_LGUI,	QK_LGUI,	KC_GESC,	LT(MOUSEPlate,	KC_ENTER),	LT(MEDIAPlate, KC_ESCAPE),	KC_LCTRL,	ALT_T(KC_ENTER),			LT(MOVESPlate, KC_SPC),	KC_RSPC,	KC_EQL,	KC_MINS,	KC_BSLS,	KC_MS_BTN2,	QK_RGUI	
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
   * | RESET|      | Pad7 | Pad8 | Pad8 |  *   |  /   |   | PgUp |  -_  | Home | End  | SysRq|  {   |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |LShift| Pad4 | Pad5 | Pad6 |  -   |CapLck|   |  ��  |  ��  |  ��  |  ��  |   :  |  "   |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |ScrLok| Pad1 | Pad2 | Pad3 |  +   |LShift|   |PgDown|  _   |   <  |   >  |   ?  |  }   |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      | Pad0 | LCtrl| LAlt |  |�\��ς�|     |  +   |  _   |  |   | Enter|      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOVESPlate] = LAYOUT(
	RESET,	XXXXXXX,	KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_KP_ASTERISK,	KC_KP_SLASH,			KC_PGUP,	KC_MINUS,	KC_HOME,	KC_END,	KC_PSCREEN,	KC_LEFT_CURLY_BRACE,	KC_NO,	
	KC_NO,	KC_LSHIFT,	KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_MINUS,	KC_CAPSLOCK,			KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT, KC_COLON, KC_DOUBLE_QUOTE, KC_NO,	
	KC_NO,	KC_LOCKING_SCROLL,	KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_PLUS,	_______,			KC_PGDOWN,	KC_UNDERSCORE,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_RIGHT_CURLY_BRACE,	KC_NO,	
	KC_NO,	_______,	_______,	_______,	KC_KP_0,	_______,	_______,			KC_NO,	_______, KC_PLUS, KC_UNDERSCORE, KC_PIPE, KC_ENTER, KC_NO	
  ),







  /* Media and mouse keys
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | �p�� |  !   |  @   |  #   |  $   |  %   | �p�� |   |  ^   |  &   |  *   |  (   |  )   |      | �p�� |
   * |------|------+------+------+------+------+------+   |------+------+------+------+------+------|------+
   * | �p�� |  1   |  2   |  3   |  4   |  5   | PgUp |   |  6   |  7   |  8   |  9   |  0   |      | �p�� |
   * |------|------+------+------+------+------+------+   |------+------+------+------+------+------|------+
   * | �p�� | Del  | Home | End  | LCtrl| Bkspc| PgDn |   |  |   |  _   |   <  |   >  |   ?  |      | �p�� |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |LShift|      |     |�\��ς�|     |      |  |���p/�S�p|RSft|      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MEDIAPlate] = LAYOUT(
//	_______,	KC_EXCLAIM,	KC_AT,	KC_HASH,	KC_DOLLAR,	KC_PERCENT,	_______,			KC_CIRCUMFLEX,	KC_AMPERSAND,	KC_ASTERISK,	KC_LEFT_PAREN,	KC_RIGHT_PAREN,	KC_NO,	_______,	
	_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F11,			KC_F12,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	_______,
	_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5, 	KC_PGUP,			KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_NO,	_______,	
//	_______,	KC_RSHIFT,	(KC_HOME | KC_LCTRL),	(KC_END | KC_LCTRL),	KC_DELETE,	KC_BSPACE,	KC_PGDOWN,			KC_PIPE,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_SCLN,	KC_NO,	_______,	
	_______,	KC_DELETE,	KC_HOME,	KC_END,	KC_LCTRL,	KC_BSPACE,	KC_PGDOWN,			KC_PIPE,	KC_UNDERSCORE,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_NO,	_______,	
	_______,	KC_LSHIFT,	_______,	_______,	_______,	_______,	_______,			HANZENjap_eng,	_______,	_______,	_______,	_______,	_______,	_______	
  ),


  /* MOUSE Layer
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | RESET|  F1  |  F2  |  F3  |  F4  |  F5  | F11  |   | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |LShift|      | Rclk | Lclk |Middle|      |   |MsLeft|MsDown| MsUp |MsRght|WhelUp| Stop |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      | F13  | F14  |  F15 |  F16 |  F17 | F23  |   | F24  | F18  | F19  | F20  |  F21 |  F22 |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |     |�\��ς�|     |      | RESET|   |      |      |      | Wleft|WlDown|WRight|      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOUSEPlate] = LAYOUT(
	RESET,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F11,			KC_F12,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	XXXXXXX,
	XXXXXXX,	KC_LSHIFT,	XXXXXXX,	KC_MS_BTN2,	KC_MS_BTN1,	KC_MS_BTN3,	XXXXXXX,			KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_MS_WH_UP,	KC_MEDIA_STOP,	XXXXXXX,
	XXXXXXX,	KC_F13,	KC_F14,	KC_F15,	KC_F16,	KC_F17,	KC_F23,			KC_F24,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,	_______,	_______,	RESET,			XXXXXXX,	_______,	XXXXXXX,	KC_MS_WH_LEFT,	KC_MS_WH_DOWN,	KC_MS_WH_RIGHT,	XXXXXXX
  )


























};


















































const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
		if (record->event.pressed) { // ���{����͂̃I���^�I�t�i�p��z��j
			return MACRO( D(LALT), T(GRAVE), U(LALT), END);
		}
		break;


  }
  return MACRO_NONE;
};






bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case ZEROReturn:
		// ���C���[�̃f�t�H���g���[���ɖ߂�20180908
		if (record->event.pressed) {
			// �L�[�������ɓ���
			eeconfig_update_default_layer( 0 );
			default_layer_set( 0 );
		}
		else {
			// �L�[���㎞�ɓ���
		}
		return false;
		break;


	}
	return true;
}



void matrix_init_user(void) {
	// ���C���[��0�ɖ߂�.
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






