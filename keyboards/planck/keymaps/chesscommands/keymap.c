/*
 * 私が私だけのために設定したキーマップである。
 *
 * このプログラムは、"GNU General Public License"契約になっている。
 * 	http://www.gnu.org/licenses/
 * Jack Humbertが作ったデフォルトキーマップを基準に改変している(そのため、理解していないプログラム箇所が多い)。
 */

#include QMK_KEYBOARD_H
#include "muse.h"


#define CONFIG_MY_H
//#define HANZEN_jap0Reng4win M(0)	// WindowsOSでの日本語英語切り替えマクロ　Alt+チルダ`
//#define HANZEN_jap0Reng4mac M(1)	// MacOSでの日本語英語切り替えマクロ　commands+space


extern keymap_config_t keymap_config;

enum planck_layers {
	_BASEPlate = 0,
	_MACBASE,
	_LINUXBASE,
	_ANDROIDBASE,
	_IPADBASE,
	_BASETEMPLayer,	/* ベースレイヤーとの区切りを付けるための空行のような存在	*/

	_MOVEPlate,
	_MEDIAPlate,	// Windows用
	_MEDIAMacPlate,
	_MOUSEPlate,
	_HHKBPlate,

	_TEMPPlate1,
	_TEMPPlate2,
	_TEMPPlate3,
	_TEMPPlate4,
	_TEMPPlate5,

	_PLOVER,	// 音楽レイヤー
	_ADJUSTPlate,	// 他のレイヤーに切り替える。
	_ENDPlate_
};


enum planck_keycodes {
	ZEROReturn = SAFE_RANGE, // can always be here

	// 以下、レイヤー変更
	WINDOWSLAYER,
	MACLAYER,
	LINUXLAYER,
	ANDROIDLAYER,
	IPADLAYER,



	// 以下、独自のキーコード
	CTRLENTER,
	LGUIENTER,

	// 以下、マクロ
	HANZEN_jap0Reng4win,	// 日本語入力のオン／オフ（英語配列）
	HANZEN_jap0Reng4mac,	// 日本語入力のオン／オフ（英語配列）


	END_SAFE_RANGE
};




// CTRLENTER・LGUIENTER用
static uint16_t my_hash_timer;
#define MY_TAPPING_TERM 65






























































const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* WindowsBase Qwerty
 * ,------------------------------------------------------------------------------------.
 * |GUIEsc|   Q  |   W  |   E  |   R  |  T   ||  Y   |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------++-------------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |  G   ||  H   |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------++------|------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |  B   ||  N   |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | Space| Bkspc|半全角| Del  |LAlt|Ctrl/Ent|| Space| Shift|   `  |   \  |   -  |  =   |
 * `------------------------------------------------------------------------------------'
 */
[_BASEPlate] = LAYOUT_planck_grid(
	LGUI_T(KC_ESCAPE),	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,		KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRACKET,	
	KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,		KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	
	KC_LSHIFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,		KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RBRACKET,	
	KC_SPC,	LT(_MEDIAPlate, KC_BSPACE),	HANZEN_jap0Reng4win,	LT(_MOUSEPlate, KC_DELETE),	KC_LALT,	CTL_T(KC_ENTER),		LT(_MOVEPlate, KC_SPC),	KC_RSHIFT,	KC_GRAVE,	KC_BSLS,	KC_MINS,	KC_EQL	
),


/* _MACBASE Qwerty
 * ,------------------------------------------------------------------------------------.
 * |Escape|   Q  |   W  |   E  |   R  |  T   ||  Y   |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------++-------------+------+------+------+------|
 * |Ctl/Tab|  A  |   S  |   D  |   F  |  G   ||  H   |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------++------|------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |  B   ||  N   |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | Space| Bkspc|半全角|Del/Mos|LAlt|GUI/Ent|| Space|RShift|   `  |   \  |   -  |  =   |
 * `------------------------------------------------------------------------------------'
 */
[_MACBASE] = LAYOUT_planck_grid(
	KC_ESCAPE,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,		KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRACKET,	
	CTL_T(KC_TAB),	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,		KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	
	KC_LSHIFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,		KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RBRACKET,	
	KC_SPC,	LT(_MEDIAMacPlate, KC_BSPACE),	HANZEN_jap0Reng4mac,	LT(_MOUSEPlate, KC_DELETE),	KC_LALT,	LGUI_T(KC_ENTER),		LT(_MOVEPlate, KC_SPC),	KC_RSHIFT,	KC_GRAVE,	KC_BSLS,	KC_MINS,	KC_EQL	
),


/* _LINUXBASE Qwerty
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_LINUXBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* AndroidBASE Qwerty
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_ANDROIDBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* iPadBASE Qwerty
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_IPADBASE] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),


/* _BASETEMPLayer Qwerty
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_BASETEMPLayer] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),











































/* Move Layer
 * ,------------------------------------------------------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   ||  6   |  7   |  8   |  9   |  0   |  {   |
 * |------+------+------+------+------+------++-------------+------+------+------+------|
 * |LShift|  =   | MsUp | Lclk | Rclk | PgUp ||  ←  |  ↓  |  ↑  |  →  |   :  |  "   |
 * |------+------+------+------+------+------++------|------+------+------+------+------|
 * |LShift|  +   |MsLeft|MsDown|MsRght| PgDn || Home | End  |   <  |   >  |   ?  |  }   |	←Home・Endキーの場所をうまい具合によそに移動させられるならば,記号をここに配置したい.
 * |      |  !   |  @   |  #   |  $   |  %   || 継承 |  ^   |  &   |  *   |  (   |  )   |	←使い回したい。
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 *|ASトグル|ScrLok|     |      |      | LCtrl||      |  =   |  ~  |   |  |  _   |  +   |
 * `------------------------------------------------------------------------------------'
 */
[_MOVEPlate] = LAYOUT_planck_grid(
	_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_LEFT_CURLY_BRACE,	
	KC_LSHIFT,	KC_EQL,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_BTN1,	KC_PGUP,	KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT, KC_COLON, KC_DOUBLE_QUOTE,	
	_______,	KC_PLUS,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_PGDOWN,	KC_HOME,	KC_END,	KC_LEFT_ANGLE_BRACKET,	KC_RIGHT_ANGLE_BRACKET,	KC_QUESTION,	KC_RIGHT_CURLY_BRACE,	
	KC_ASTG,	KC_LOCKING_SCROLL,	_______,	_______,	_______,	_______,	KC_NO,	KC_EQL, KC_TILDE, KC_PIPE, KC_UNDERSCORE, KC_PLUS	
),

//	KC_ASTG：AutoShift自動押下のトグルキー
//		rules.mk	AUTO_SHIFT_ENABLE = yes



/* Media and mouse keys (Windows用)
 * ,------------------------------------------------------------------------------------.
 * |LShift|  1   | Home | End  |  4   |  5   ||  ←  |  ↓  |  ↑  |  →  |PrScrn| F12  |
 * |------|------+------+------+------+------++------+------+------+------+------+------|
 * |LShift|  F1  |CtlSft|CtlSft|  F4  |  F5  ||Shft←|Shft↓|Shft↑|Shft→|  F10 | F11  |
 * |------|------+------+------+------+------++------+------+------+------+------+------|
 * |WhelUp| LCtrl| Home | End  |Escape|PrScrn||Ctrl←|Ctrl↓|Ctrl↑|Ctrl→|   ?  |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |WlDown|      |      |      |LShift|      ||RShift| RSft |  +   |  |   |   _  |      |
 * `------------------------------------------------------------------------------------'
 */
  [_MEDIAPlate] = LAYOUT_planck_grid(
	KC_LSHIFT,	KC_1,	KC_HOME,	KC_END,	KC_4,	KC_5, 		KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT,	KC_PSCREEN,	KC_F12,	
	KC_LSHIFT,	KC_F1,	LSFT(KC_LWIN | KC_HOME),	LSFT(KC_LWIN | KC_END),	KC_F4,	KC_F5,		LSFT(KC_LALT | KC_LEFT),	LSFT(KC_LALT | KC_DOWN), LSFT(KC_LALT | KC_UP),   LSFT(KC_LALT | KC_RGHT),	KC_F10,	KC_F11,	
	KC_MS_WH_UP,	KC_LCTRL,	KC_HOME,	KC_END,	KC_ESCAPE,	LALT(KC_PSCREEN),		LCTL(KC_LEFT),	LCTL(KC_DOWN), LCTL(KC_UP),   LCTL(KC_RGHT),	KC_QUESTION,	KC_NO,	
	KC_MS_WH_DOWN,	KC_ENTER,	_______,	_______,	KC_LSHIFT,	_______,		KC_RSHIFT,	_______,	KC_PLUS, KC_PIPE, KC_UNDERSCORE,	_______	
  ),



/* Media and mouse keys (Mac用)
 * ,------------------------------------------------------------------------------------.
 * |LShift|  1   | Home | End  |  4   |  5   ||  ←  |  ↓  |  ↑  |  →  |PrScrn| F12  |
 * |------|------+------+------+------+------++------+------+------+------+------+------|
 * |LShift|  F1  |CtlSft|CtlSft|  F4  |  F5  ||Shft←|Shft↓|Shft↑|Shft→|  F10 | F11  |
 * |------|------+------+------+------+------++------+------+------+------+------+------|
 * |WhelUp| LCtrl|CtlHme|CtlEnd|Escape|PrScrn||LGUI←|LGUI↓|LGUI↑|LGUI→|   ?  |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |WlDown|      |      |      |LShift|      ||RShift| RSft |  +   |  |   |   _  |      |
 * `------------------------------------------------------------------------------------'
 */
  [_MEDIAMacPlate] = LAYOUT_planck_grid(
	KC_LSHIFT,	KC_1,	KC_HOME,	KC_END,	KC_4,	KC_5, 		KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT,	KC_PSCREEN,	KC_F12,	
	KC_LSHIFT,	KC_F1,	LSFT(KC_LCMD | KC_HOME),	LSFT(KC_LCMD | KC_END),	KC_F4,	KC_F5,		LSFT(KC_LALT | KC_LEFT),	LSFT(KC_LALT | KC_DOWN), LSFT(KC_LALT | KC_UP),   LSFT(KC_LALT | KC_RGHT),	KC_F10,	KC_F11,	
	KC_MS_WH_UP,	KC_LCTRL,	KC_HOME,	KC_END,	KC_ESCAPE,	LALT(KC_PSCREEN),		LGUI(KC_LEFT),	LGUI(KC_DOWN), LGUI(KC_UP),   LGUI(KC_RGHT),	KC_QUESTION,	KC_NO,	
	KC_MS_WH_DOWN,	KC_ENTER,	_______,	_______,	KC_LSHIFT,	_______,		KC_RSHIFT,	_______,	KC_PLUS, KC_PIPE, KC_UNDERSCORE,	_______	
  ),



/* MOUSE and Function Layer
 * ,------------------------------------------------------------------------------------.
 * | F12  | F13  | F14  |  F15 |  F16 |  F17 || F24  | F18  | F19  | F20  |  F21 |  F22 |	←使い回したい。
 * | F12  |  !   |  @   |  #   |  $   |  %   ||  ^   |  &   |  *   |  (   |  )   |  F13 |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |LShift|WinMenu| Lclk| Rclk |Middle||MsLeft|MsDown| MsUp |MsRght|WhelUp| Stop |	←Mouse運用は、容量が足りず、有効化できない。
 * |      |LShift|WinMenu|Enter| Rclk |Middle||MsLeft|MsDown| MsUp |MsRght|WhelUp| Stop |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | LGui |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | RESET|      |Enter|予約済み|     |      ||      |RShift|      |WHleft|WlDown|WHRigt|
 * `------------------------------------------------------------------------------------'
 */
  [_MOUSEPlate] = LAYOUT_planck_grid(
//	KC_F12,	KC_F13,	KC_F14,	KC_F15,	KC_F16,	KC_F17,				KC_F24,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	
	KC_F12,	KC_EXCLAIM,	KC_AT,	KC_HASH,	KC_DOLLAR,	KC_PERCENT,			KC_CIRCUMFLEX,	KC_AMPERSAND,	KC_ASTERISK,	KC_LEFT_PAREN,	KC_RIGHT_PAREN,	KC_F13,	
//	_______,	KC_LSHIFT,	KC_APPLICATION,	KC_MS_BTN2,	KC_MS_BTN1,	KC_MS_BTN3,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_MS_WH_UP,	KC_MEDIA_STOP,	
	_______,	KC_LSHIFT,	KC_APPLICATION,	KC_ENTER,	KC_MS_BTN1,	KC_MS_BTN3,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_MS_WH_UP,	KC_MEDIA_STOP,	
	KC_LGUI,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,			KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	
	RESET,	XXXXXXX,	KC_ENTER,	_______,	_______,	_______,	XXXXXXX,	_______,	XXXXXXX,	KC_MS_WH_LEFT,	KC_MS_WH_DOWN,	KC_MS_WH_RIGHT	
  ),


/* LayerChange Layer
 * ,------------------------------------------------------------------------------------.
 * |      |     |Win-Base|     |Audion|Audoff||音楽mode|    | iOS  |      |Plover|      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |Andrid|      |Dvorak|Au_Clk|      ||      |      |      | Linux|      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |     |Colemak|      |      ||      | Mac  |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      | F12  |
 * `------------------------------------------------------------------------------------'
 */
[_ADJUSTPlate] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	WINDOWSLAYER,	XXXXXXX,	AU_ON,   AU_OFF,	MU_MOD,	XXXXXXX,	IPADLAYER,	XXXXXXX,	_PLOVER,	XXXXXXX,	
	XXXXXXX,	ANDROIDLAYER,	XXXXXXX,	XXXXXXX,	CK_TOGG,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	LINUXLAYER,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	MACLAYER,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_F12	
)
// MU_MOD	Cycle through the music modes
//	CHROMATIC_MODE - Chromatic scale, row changes the octave
//	GUITAR_MODE - Chromatic scale, but the row changes the string (+5 st)
//	VIOLIN_MODE - Chromatic scale, but the row changes the string (+7 st)
//	MAJOR_MODE  - Major scale

// CK_TOGG	play sound if enabled キー押下のたびに音を出す。







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
	return false;
};




#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
	return update_tri_layer_state(state, _MOVEPlate, _MOUSEPlate, _ADJUSTPlate);
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

	case HANZEN_jap0Reng4win:
		// 日本語入力のオン／オフ（英語配列）
		if (record->event.pressed) {
			// Alt+`
			SEND_STRING( SS_RALT("`") );	// X_GRAVE
		}
		return false;
		break;

	case HANZEN_jap0Reng4mac:
		// 日本語入力のオン／オフ（英語配列）
		if (record->event.pressed) {
			// commands+Space
			SEND_STRING( SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI) );
		}
		return false;
		break;

	case CTRLENTER:	// Windows用
// https://www.reddit.com/r/olkb/comments/a5ujx6/can_i_make_qmks_modtap_behave_like_easyavrs_tap/
		if(record->event.pressed) {
			my_hash_timer = timer_read();
			register_code(KC_LCTL);	// キーを押し続けることで、Ctrlキーになる。
		} else {
			unregister_code(KC_LCTL);	// Ctrlキーが解放される。
			if (timer_elapsed(my_hash_timer) < MY_TAPPING_TERM) {
				SEND_STRING(SS_TAP(X_ENTER));	// タップによる操作で、Enterキーが働く。
			}
		}
		return false;	// 処理終了。
		break;
	case LGUIENTER:	// Mac用
		if(record->event.pressed) {
			my_hash_timer = timer_read();
			register_code(KC_LGUI);
		} else {
			unregister_code(KC_LGUI);
			if (timer_elapsed(my_hash_timer) < MY_TAPPING_TERM) {
				SEND_STRING(SS_TAP(X_ENTER));
			}
		}
		return false;
		break;
/**/


/*	以下、WindowsレイヤーとMacレイヤーなどの切り替え設定を行う20190607
	case MOVEPlateLayer:	// 通常の矢印などの移動レイヤー
		if (record->event.pressed) {
			layer_on(_MOVEPlate);
			update_tri_layer(_MOVEPlate, _MOUSEPlate, _ADJUSTPlate);
		}
		else {
			layer_off(_MOVEPlate);
			update_tri_layer(_MOVEPlate, _MOUSEPlate, _ADJUSTPlate);
		}
		return false;
		break;
	case MOUSEPlateLayer:	// HJKLキーでマウスカーソルを動かす。もしくは、日本語配列の記号を使うレイヤー
		if (record->event.pressed) {
			layer_on(_MOUSEPlate);
			update_tri_layer(_MOVEPlate, _MOUSEPlate, _ADJUSTPlate);
		}
		else {
			layer_off(_MOUSEPlate);
			update_tri_layer(_MOVEPlate, _MOUSEPlate, _ADJUSTPlate);
		}
		return false;
		break;
*/

	case WINDOWSLAYER:	// WindowsOS用に使うレイヤーを基準にする。
		if (record->event.pressed) {
			set_single_persistent_default_layer(_BASEPlate);
		}
		return false;
		break;
	case MACLAYER:	// MacOS用に使うレイヤーを基準にする。
		if (record->event.pressed) {
			set_single_persistent_default_layer(_MACBASE);
		}
		return false;
		break;
/*	ここまで20190607 */





















/*
	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
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

uint16_t get_tapping_term(uint16_t keycode) {
	switch (keycode) {
		case ALT_T(KC_ENTER):
		case CTL_T(KC_ENTER):	// Windows用
		case LGUI_T(KC_ENTER):	// Mac用
			return 68;
//		case LT(_MOUSEPlate, KC_DELETE):	// test
//			return 90;
		default:
			return TAPPING_TERM;
	}
}



