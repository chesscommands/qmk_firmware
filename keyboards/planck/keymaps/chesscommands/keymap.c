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
	_MAC_CtrlLayer,
	_LINUXBASE,
	_ANDROIDBASE,
	_IPADBASE,
	_TENKEYBASE,
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
	_EXPANSIONLayer,	// 拡張レイヤ
	_MISTYPEDLayer,	// 打ち間違い阻止
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
	TENKEYLAYER,



	// 以下、独自のキーコード
	CTRLENTER,
	LGUIENTER,

	// 以下、マクロ
	HANZEN_jap0Reng4win,	// 日本語入力のオン／オフ（英語配列）
	HANZEN_jap0Reng4mac,	// 日本語入力のオン／オフ（英語配列）
	HANZEN_jap0Reng4android,	// 日本語入力のオン／オフ（英語配列）

	SCREENSHOTPART_GET4mac,	// 画面の選択した部分のスクリーンショット(MacOS専用)shift + command +4



	END_SAFE_RANGE
};




// CTRLENTER・LGUIENTER用
static uint16_t my_hash_timer;
//#define MY_TAPPING_TERM 65
#define MY_TAPPING_TERM 180	// ←CTRLENTERを使うため用の値20191219






























































const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* WindowsBase Qwerty
 * ,------------------------------------------------------------------------------------.
 * |GUI/Tab|  Q  |   W  |   E  |   R  |  T   ||  Y   |   U  |   I  |   O  |   P  |   -  |
 * |------+------+------+------+------+------++-------------+------+------+------+------|
 * |Ctl/Ent|  A  |   S  |   D  |   F  |  G   ||  H   |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------++------|------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |  B   ||  N   |   M  |   ,  |   .  |   /  | ]/Sft|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |APP|_MEDIA/BSpace|半全角|Alt/del|/Esc|Ctl/Spc||Space| ¥ |   =  |   `  |   [  | Enter|
 * `------------------------------------------------------------------------------------'
 */
[_BASEPlate] = LAYOUT_planck_grid(
	LGUI_T(KC_TAB),	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,		KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_MINS,	
	CTL_T(KC_ENTER),	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,		KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOTE,	
	KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,		KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	RSFT_T(KC_RBRACKET),	
	KC_APPLICATION,	LT(_MEDIAPlate, KC_BSPACE),	HANZEN_jap0Reng4win,	ALT_T(KC_DELETE),	LT(_MOUSEPlate, KC_ESCAPE),	CTL_T(KC_SPACE),		LT(_MOVEPlate, KC_SPC),	KC_BSLS,	KC_EQL,	KC_GRAVE,	KC_LBRACKET,	KC_ENTER	
),
// []を最下段の右下(右から三つ目・二つ目)に配置した場合、ちょっと使いにくい。しかし、右から四つ目の場所にある＝は使いやすい配置なので、動かしたくない20201111
// []をファンクションレイアに移動した。そして、F23・F24を削除した。復活予定はない。


/* _MACBASE Qwerty
 * ,------------------------------------------------------------------------------------.
 * |GUI/Tab|  Q  |   W  |   E  |   R  |  T   ||  Y   |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------++-------------+------+------+------+------|
 * |Ctl/Ent|  A  |   S  |   D  |   F  |  G   ||  H   |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------++------|------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |  B   ||  N   |   M  |   ,  |   .  |   /  | ]/Sft|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |APP|MEDIA/BSpc|半全角|Alt/del|/Esc|GUI/Ctrl||Space|  ¥  |   =  |   `  |   [  | Enter|
 * `------------------------------------------------------------------------------------'
 */
[_MACBASE] = LAYOUT_planck_grid(
	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	LT(_MEDIAPlate, KC_BSPACE),	HANZEN_jap0Reng4mac,	ALT_T(KC_DELETE),	LT(_MOUSEPlate, KC_ESCAPE),	LGUI_T(KC_SPC),		LT(_MOVEPlate, KC_SPC),	_______,	_______,	_______,	_______,	_______	

),
//	※mcr：スクリーンショット用マクロキー

/*
 * ,-------
 * |      |
 * |------+
 * |Gui/Tab	←上から2段目
 * |------+
 * |      |
 * |------+
 * | Swap |      |      |      |     |Ctrl/Esc||     |      |      |      |      |      |	←最後の4段目
 * `-------
 */
[_MAC_CtrlLayer] = LAYOUT_planck_grid(
	_______,	_______,	_______,	_______,	_______,	_______, 		_______,	_______,	_______,	_______,	_______,	_______,	
	LGUI_T(KC_ENTER),	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	
	TO(_MACBASE),	_______,	_______,	_______,	_______,	CTL_T(KC_SPACE),		_______,	_______,	_______,	_______,	_______,	_______	
),
//	"CTL_T(KC_TAB)"は、話にならないぐらいTabキーが動かない20190721

// Alt/Ent"ALT_T (KC_ENTER)"：配置の場所も問題だが、むしろ配置に問題があり、かなり使いにくい20190804


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


/* AndroidBASE Qwerty(Baseレイヤーからの継承)
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |半全角|      |     |Ctl/Ent||      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_ANDROIDBASE] = LAYOUT_planck_grid(
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	
	_______,	_______,	HANZEN_jap0Reng4android,	_______,	_______,	CTL_T(KC_ENTER),	_______,	_______,	_______,	_______,	_______,	_______	
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


/* テンキーBASE Qwerty
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |  /   |  7   |  8   |  9   |  -   |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |  *   |  4   |  5   |  6   |  +   |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||NumLock| Tab |  1   |  2   |  3   | Enter|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |  0   |  ,   |  .   | Enter|
 * `------------------------------------------------------------------------------------'
 */
[_TENKEYBASE] = LAYOUT_planck_grid(
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
 * |      |  !   |  @   |  #   |  $   |  %   ||  ^   |  &   |  *   |  (   |  )   |  _   |
 * |------+------+------+------+------+------++-------------+------+------+------+------|
 * |      | Home | End  | Esc  |  -   | Tab  ||  ←  |  ↓  |  ↑  |  →  |  :   |  "   |
 * |------+------+------+------+------+------++------|------+------+------+------+------|
 * |LShift|  1   |  2   |  3   |  4   |  5   ||  6   |  7   |  8   |  9   |  0   | }/Sft|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |Delete|      |      |      |      |      ||      |  |   |  +   |  ~   |  {   |backSpace|
 * `------------------------------------------------------------------------------------'
 */
[_MOVEPlate] = LAYOUT_planck_grid(
	_______,	KC_EXCLAIM,	KC_AT,	KC_HASH,	KC_DOLLAR,	KC_PERCENT,		KC_CIRCUMFLEX,	KC_AMPERSAND,	KC_ASTERISK,	KC_LEFT_PAREN,	KC_RIGHT_PAREN,	KC_UNDERSCORE,	
	_______,	KC_HOME,	KC_END,	KC_ESCAPE,	KC_MINS,	KC_TAB,		KC_LEFT,	KC_DOWN, KC_UP,   KC_RGHT, KC_COLON, RSFT(KC_QUOTE),	
	KC_LSFT,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,		KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	RSFT_T(KC_RIGHT_CURLY_BRACE),	
	_______,	_______,	_______,	_______,	_______,	_______,		_______,	KC_PIPE,	KC_PLUS,	KC_TILDE,	RSFT(KC_LBRACKET),	KC_BSPACE	
),

//	KC_ASTG：AutoShift自動押下のトグルキー
//		rules.mk	AUTO_SHIFT_ENABLE = yes



/* Mouse key
 * ,------------------------------------------------------------------------------------.
 * |      |※PrSc|PrScrn| Lclk | Rclk |Delete||Middle| Rclk | Lclk |   {  |   }  |      |	←Altキーは独立させておかなければ、WinOSでプリントスクリーン取得に困ることになる。
 * |------|------+------+------+------+------++------+------+------+------+------+------|
 * |      | ※mcr|LShift| Home |PageUp| Tab  ||MsLeft|MsDown| MsUp |MsRght|Insert|Delete|
 * |------|------+------+------+------+------++------+------+------+------+------+------|
 * |      | Swap |Delete| End  |PgDown|BSpace|| Wleft|WlDown|WhelUp|WRight| RAlt | }/Sft|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * | RESET|      | Enter|      |      |      ||      |  |   |   +  |   ~  |   {  |backSpace|	←通常の場所にAltキーが無ければ不便だと気づいた20200128
 * `------------------------------------------------------------------------------------'
 */
  [_MEDIAPlate] = LAYOUT_planck_grid(
	_______,	LALT(KC_PSCREEN),	KC_PSCREEN,	KC_MS_BTN2,	KC_MS_BTN1,	KC_DELETE, 		KC_MS_BTN3,	KC_MS_BTN1,	KC_MS_BTN2,	KC_LEFT_CURLY_BRACE,	KC_RIGHT_CURLY_BRACE,	_______,	
	_______,	SCREENSHOTPART_GET4mac,	KC_LSFT,	KC_HOME,	KC_PGUP,	KC_TAB,		KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_INSERT, KC_DELETE,	
	_______,	TO(_MAC_CtrlLayer),	KC_DELETE,	KC_END,	KC_PGDOWN,	KC_BSPACE,		KC_MS_WH_LEFT,	KC_MS_WH_DOWN, KC_MS_WH_UP,   KC_MS_WH_RIGHT,	KC_RALT,	RSFT_T(KC_RIGHT_CURLY_BRACE),	
	RESET,	_______,	KC_ENTER,	_______,	_______,	_______,		_______,	KC_PIPE,	KC_PLUS,	KC_TILDE,	KC_LEFT_CURLY_BRACE,	KC_BSPACE	
  ),

/* Function Layer
 * ,------------------------------------------------------------------------------------.
 * | GUI  | F11  | F12  | F13  | F14  | F15  || F16  | F17  | F18  |   [  |   ]  |   _  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      | Home | End  |PageUp|PgDown| F19  || F20  | F21  | F22  | F23  | F24  |   "  |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |  F7  |  F8  |  F9  | F10  | }/Sft|
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |  del |      | Enter|Escape|予約済| Space||予約済|   |  |   +  |   ~  |   {  |Insert|
 * `------------------------------------------------------------------------------------'
 */	
  [_MOUSEPlate] = LAYOUT_planck_grid( 
	KC_LGUI,	KC_F11,	KC_F12,	KC_F13,	KC_F14,	KC_F15,		KC_F16,	KC_F17,	KC_F18,	KC_LBRACKET,	KC_RBRACKET,	KC_UNDERSCORE,	
	_______,	KC_HOME,	KC_END,	KC_PGUP,	KC_PGDOWN,	KC_F19,		KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24,	KC_DOUBLE_QUOTE,	
	_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,		KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	RSFT_T(KC_RIGHT_CURLY_BRACE),	
	KC_DELETE,	_______,	KC_ENTER,	KC_ESCAPE,	_______,	KC_SPC,		_______,	KC_PIPE,	KC_PLUS,	KC_TILDE,	KC_LEFT_CURLY_BRACE,	KC_INSERT	
  ),
/*
https://smatu.net/2018/12/22/mac-function-key-f1-f12-default-setting/
	F1…ディスプレイ照度を下げる
	F2…ディスプレイ照度を上げる
	F3…ミンションコントロール（トラックパッドを3本指で上にスワイプと同じ機能）
	F4…Launchpad（ランチパッド：アプリをすべて表示する）
	F5…キーボードのバックライトを暗くする
	F6…キーボードのバックライトを明るくする
	F7…動画を一つ前へ
	F8…動画を再生/停止
	F9…動画を一つ後ろへ
	F10…ミュート/ミュート解除
	F11…音量を下げる
	F12…音量を上げる
※Mac上のファンクションキー機能

https://support.apple.com/ja-jp/HT204436
	キーボードに「fn」キーがない場合は、「control」キーを押しながらファンクションキーを押してみてください。
*/

/* LayerChange and Media Layer
 * ,------------------------------------------------------------------------------------.
 * |      |     |Win-Base|    |RGBトグル|テンキー||    |    | iOS |音楽mode|Plover|     |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |Audion|Andrid|Debug |Dvorak|Au_Clk|      ||      |      |色相増| Linux|色相減|      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |Audoff|      |     |Colemak|      |      ||RollOver| Mac|彩度上|      |彩度下|  ]   |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |0レイヤ| 予約|      |      |      |      || 予約 |      |明値増|      |明値減| F12  |
 * `------------------------------------------------------------------------------------'
 */
[_ADJUSTPlate] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	WINDOWSLAYER,	RGB_MOD,	RGB_TOG,   TENKEYLAYER,	XXXXXXX,	XXXXXXX,	IPADLAYER,	MU_MOD,	_PLOVER,	XXXXXXX,	
	AU_ON,	TG(_ANDROIDBASE),	DEBUG,	XXXXXXX,	CK_TOGG,	XXXXXXX,	XXXXXXX,	XXXXXXX,	RGB_HUI,	LINUXLAYER,	RGB_HUD,	XXXXXXX,	
	AU_OFF,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	MAGIC_TOGGLE_NKRO,	MACLAYER,	RGB_SAI,	XXXXXXX,	RGB_SAD,	KC_RBRACKET,	
	ZEROReturn,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	RGB_VAI,	XXXXXXX,	RGB_VAD,	KC_F12	
),
// AU_ON：Audioを有効化する。
//		WindowsやMacへのレイヤー切り替え時に音を鳴らすようにする。
//		AU_OFFは、その逆で、無音にする。


// MU_MOD	音楽モードを切り替える
//	CHROMATIC_MODE - 色彩スケール、行はオクターブを変更します
//	GUITAR_MODE - 色彩スケール、ただし行は文字列を変更します（+5 st）
//	VIOLIN_MODE - クロマチックスケール、ただし、行は文字列を変更します（+7 st）
//	MAJOR_MODE  - 大規模

// RGB
//	RGB_TOG	RGBライティングのオン/オフを切り替えます
//	RGB_MOD	モードを切り替え、Shiftキーを押したまま逆方向
//			Static (no animation) mode：静的（アニメーションなし）モード
//			Breathing animation mode：呼吸アニメーションモード
//			Rainbow animation mode：レインボーアニメーションモード
//			Swirl animation mode：旋回アニメーションモード
//			Snake animation mode：スネークアニメーションモード
//			"Knight Rider" animation mode：「ナイトライダー」アニメーションモード
//			Christmas animation mode：クリスマスアニメーションモード
//			Static gradient animation mode：静的グラデーションアニメーションモード
//			Red,Green,Blue test animation mode：赤、緑、青のテストアニメーションモード
//	RGB_HUI	色相を増やす
//	RGB_HUD	色相を下げる
//	RGB_SAI	彩度を上げる
//	RGB_SAD	彩度を下げる
//	RGB_VAI	値を増やす（明るさ）
//	RGB_VAD	値を下げる（明るさ）

// CK_TOGG	play sound if enabled キー押下のたびに音を出す。

// Nキーロールオーバー
//  MAGIC_TOGGLE_NKRO　トグル
//  rules.mkに、"NKRO_ENABLE = yes"を記載しなければ有効化できない。

// Andridレイヤー
//	Windowsレイヤーを継承しているため、他のレイヤーから変更することは相成らない(WinOS同様Ctrlキーを基準にコピペ作業をするため)。




/* _ExpansionLayer Qwerty
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
[_EXPANSIONLayer] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),





/* _MistypedLayer Qwerty
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------++------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_MISTYPEDLayer] = LAYOUT_planck_grid(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_LEFT_CURLY_BRACE,	KC_RIGHT_CURLY_BRACE,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX	
),




/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Win層 |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,	
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,	
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,	
    WINDOWSLAYER, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX	
)

	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
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
	return update_tri_layer_state(state, _MEDIAPlate, _MOUSEPlate, _ADJUSTPlate);
//	return update_tri_layer_state(state, _MEDIAPlate, _MOVEPlate, _ADJUSTPlate);
//	return update_tri_layer_state(state, _MOVEPlate, _MOUSEPlate, _ADJUSTPlate);
		// Altキーと矢印キーの組み合わせをするつもりが、押し間違えたため、マウスレイアと矢印レイアの組み合わせにする。
		// それでも押し間違えることがあれば、マウスレイアとファンクションレイアの組み合わせに変更する。
		// 20201026
	return update_tri_layer_state(state, _MOUSEPlate, _MOVEPlate, _EXPANSIONLayer);
	return update_tri_layer_state(state, _MEDIAPlate, _MOVEPlate, _MISTYPEDLayer);
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

	case HANZEN_jap0Reng4android:
		// 日本語入力のオン／オフ（英語配列）
		if (record->event.pressed) {
			// Shift+Space（IMEによって変わりそうな気がする）
			SEND_STRING( SS_DOWN(X_LSHIFT) SS_TAP(X_SPACE) SS_UP(X_LSHIFT) );
		}
		return false;
		break;

	case SCREENSHOTPART_GET4mac:
		// MacOS専用のスクリーンショット用マクロキー(選択部分)
		if (record->event.pressed) {
			// shift + command +4
			SEND_STRING( SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI) SS_DOWN(X_4) SS_UP(X_4) SS_UP(X_LGUI) SS_UP(X_LSHIFT) );
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
	case TG(_ANDROIDBASE):	//←音が出るだけになってしまい、レイヤー変更がなされなくなってしまった20190823
//	case _ANDROIDBASE:	←レイヤーが戻らなくなってしまった(正確に言えば、レイヤーを変更する以前に、キーコードの設定場所が音を出すだけになってしまった。何より不可解なのは、そのキーを押下するためのレイヤー変更をしていないのに、そのキーが押されてたことになってしまった)20190823
		PLAY_SONG(plover_song);	// ←この音は変更したい。
//err		TG(_ANDROIDBASE);
		return true;	// falseの場合に、音を出すだけになったが、trueの場合は、本来のキーコードが活かされるようだ。
		break;
/*	ここまで20190607 */



//	以下、サンプル
//		https://docs.qmk.fm/#/custom_quantum_functions?id=example-process_record_user-implementation
//	試したかったのは、音を出す場合の処理しか実装していないため、本来のEnterキーが無効化されているのでは無いかと言うこと。
//	実際は、音を出しつつEnterキーが動いたと言うこと。
//case KC_ENTER:
// Play a tone when enter is pressed
//if (record->event.pressed) {
//PLAY_SONG(plover_song);
//}
//return true; // Let QMK send the enter press/release events


















/*
	// よくわからないが,コンパイルエラーになるため,よくわからないままコメントアウト20190408
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ‾(1<<6);
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
//		case KC_SFTENT:	// 20191222
//			return TAPPING_TERM * 3;
		case ALT_T(KC_TAB):	// 20190915
			return TAPPING_TERM * 3;
		case LT(_MOUSEPlate, KC_TAB):	// 追加20190911
			return TAPPING_TERM * 2.5;
//		case LSFT_T(KC_ESCAPE):	// 20190923	←Shiftキー単体での動作が使い物にならない(マウス優先作業の複数選択など)20191024
		case LSFT_T(KC_ENTER):	// 20190923
//		case CTL_T(KC_TAB):	// 20190923	←コメントアウト20200329
//		case LSFT_T(KC_TAB):	// 20190921	←Tabキーを使うときには抜群に素晴らしい時間設定になっているが、Shiftキー単体を使うときには反応が遅いため、使い物にならない時間設定になっている20190926
			return TAPPING_TERM * 2.3;	// 20190923
		case LT(_MOUSEPlate, KC_DELETE):	// 追加20191024
//		case LT(_MOUSEPlate, KC_BSPACE):	// 追加20191227	←これではちょっと遅い？20200131
//		case CTL_T(KC_TAB):	// Mac用20190815
		case LCTL(LSFT(KC_TAB)):
//		case LT(_MEDIAPlate, KC_TAB):	// 追加20190912
		case CTL_T(KC_ENTER):	// 20190910
		case CTL_T(KC_TAB):	// 20200329
		case LGUI_T(KC_TAB):
		case LGUI_T(KC_ENTER):	// 20200329
		case ALT_T(KC_BSPACE):	// 20190913
		case ALT_T(KC_DELETE):	// 20191227
		case ALT_T(KC_ESCAPE):	// 20201104
		case RSFT_T(KC_EQL):	// 20200329
		case RSFT_T(KC_QUOTE):	// 20201005
		case RSFT_T(KC_LBRACKET):	// (1.8だったが変更)20201017
		case RSFT_T(KC_RBRACKET):	// 20201112
		case RSFT_T(KC_GRAVE):	// 20201107
//		case RSFT_T(KC_LEFT_CURLY_BRACE):	←コンパイルエラーになる。
//		case RSFT_T(RSFT(KC_LBRACKET):	←コンパイルエラーになる。
//		case LT(_MOVEPlate, KC_SPC):	// ちょっとだけ時間延長20190925
		case LGUI_T(KC_SPACE):	// Spaceキーを日常使用にするための措置20190925
			return TAPPING_TERM * 2;
//		case LT(_MOUSEPlate, KC_TAB):	// 追加(TAPPING_TERMのみならばブラウザのタブ切り替えが正常になる。しかし、アプリ切り替えに何が出てくる。*2,*1.8,*1.5,*1.3の場合は評価が逆になる。)(1.3・1.5は最悪かな)20190910
//			return TAPPING_TERM * 1.5;
//		case LT(_MOUSEPlate, KC_BSPACE):	// 変更20200131
		case RSFT_T(KC_MINS):
		case LSFT_T(KC_TAB):	// 20190926	←1.3の場合は、Shiftキー単体で動かすには抜群によかったが、Tabキーが全く使えなかったため、妥協して1.5にした。1.8では、Tabキー操作に問題がある。そのため2にした。
			return TAPPING_TERM * 2.3;
		case LT(_MEDIAPlate, KC_ESCAPE):	// 追加20200213
		case LT(_MEDIAPlate, KC_BSPACE):	// 追加20200214
		case LT(_MOUSEPlate, KC_ESCAPE):	// 追加20200214
		case LT(_MOUSEPlate, KC_APPLICATION):	// 追加20200820
		case LT(_MOVEPlate, KC_SPC):	// スペース機能を活用したい20190728	←なぜ1.8にしたのか不明20190926
//		case LSFT_T(KC_ESCAPE):	// 変更(×2ではだめだった)20191025
			return TAPPING_TERM * 1.8;
		case LGUI_T(KC_ESCAPE):	// Windows用
		case CTL_T(KC_ESCAPE):	// Mac用
//		case LSFT_T(KC_ESCAPE):	// 変更(×1.8ではだめだった)1.5はギリギリ許容できる20191025
			return TAPPING_TERM * 1.5;
//		case LSFT_T(KC_ESCAPE):	// 変更20200205	←これぐらいが妥当なのだろう20200210
		case LT(_MOUSEPlate, KC_BSPACE):	// 変更20200207	←かなり挑戦的
			return TAPPING_TERM * 1.4;
//		case LSFT_T(KC_ESCAPE):	// 変更20200207	←かなり挑戦的(だめだった。Escの効きが悪くなる20200210)
			return TAPPING_TERM * 1.3;
//		case CTL_T(KC_ENTER):	// Windows用
//			return 73;	// Ctrlキー2回連続押しで、Atokの画面が起動する。
		case ALT_T(KC_ENTER):	// Mac用
//		case LGUI_T(KC_ENTER):	コメントアウト20200329
//			return 68;
//			return 73;
			return 110;
//		case LT(_MOUSEPlate, KC_DELETE):	// test
//			return 90;
//		case CTL_T(KC_ENTER):	// Mac用20190725
//			return TAPPING_TERM + 20;
//		case LSFT_T(KC_TAB):	// 20190926
//			return 1.3;
//		case ALT_T(KC_ENTER):
		default:
			return TAPPING_TERM;
	}
}
