#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_dvorak.h"  // alias keycode for software dvorak, DV_*

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 1
#define _LOWER 2
#define _RAISE 3
#define _UNIX_FN 4
#define _VIM_FN 5
#define _MOUSE_FN 6
#define _NUM 7
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  LOWER,
  RAISE,
  UNIX_FN,
  VIM_FN,
  MOUSE_FN,
  NUM,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define VOL_DW KC__VOLDOWN
#define VOL_UP KC__VOLUP
#define VFN_F LT(_VIM_FN,KC_F)
#define MFN_V LT(_MOUSE_FN,KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |`andC |   A  |   S  |   D  | VFN_F|   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  | MFN_V|   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | GUI  | LOWER|  (   | NUM  |SpaceF|SpaceF| NUM  |  )   | RAISE| Ctrl | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB       , KC_Q   , KC_W , KC_E   , KC_R , KC_T  , KC_Y   , KC_U, KC_I   , KC_O  , KC_P   , KC_LBRC  , \
  CTL_T(KC_GRV), KC_A   , KC_S , KC_D   , VFN_F, KC_G  , KC_H   , KC_J, KC_K   , KC_L  , KC_SCLN, KC_QUOT  , \
  KC_LSFT      , KC_Z   , KC_X , KC_C   , MFN_V, KC_B  , KC_N   , KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT  , \
  KC_LALT      , KC_LGUI, LOWER, KC_LPRN, NUM  , KC_SPC, UNIX_FN, NUM , KC_RPRN, RAISE , KC_RCTL, KC_RALT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | **** |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | **** |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | **** |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | **** |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_RBRC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* UNIX_FN
 * ,-----------------------------------------------------------------------------------.
 * | {    |      |      |      | C-P  |      |      | C-G  | C-C  |      | C-L  |  }   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | [    | HOME |      | END  | C-U  |      |  Del | Bksp | C-T  | C-N  | ESC  |  ]   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | (    |      |      |      |      |      |      | ENT  | C-W  | C-V  | C-Z  |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UNIX_FN] = KEYMAP( \
  DV_LCBR, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(DV_P), XXXXXXX, XXXXXXX, LCTL(DV_G), LCTL(DV_C), XXXXXXX,    LCTL(DV_L), DV_RCBR, \
  DV_LBRC, KC_HOME, XXXXXXX, KC_END,  LCTL(DV_U), XXXXXXX, KC_DEL,  KC_BSPC,    LCTL(DV_T), LCTL(DV_N), KC_ESC,     DV_RBRC, \
  KC_LPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_ENT,     LCTL(DV_W), LCTL(DV_V), LCTL(DV_Z), KC_RPRN, \
  _______, _______, _______, _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______  \
),

/* VIM_FN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Ctrl |Shift | **** |      | LEFT | DOWN | UP   |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM_FN] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_LCTL, KC_LSFT, KC_TRNS, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* NUM
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** |  +   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = KEYMAP( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  DV_BSLS, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    DV_PIPE, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, DV_EQL, \
  _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, DV_PLUS \
),

/* MOUSE_FN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | WH_L | WH_D | WH_U | WH_R |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | MS_L | MS_D | MS_U | MS_R |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |fast_a| mid_a| **** |      |      | BTN1 | BTN2 | BTN3 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** | **** |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE_FN] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_ACL2, KC_ACL1, KC_TRNS, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* Adjust (Lower + Raise)
 *, -----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |vol_dw|vol_up|      |      |      |      |      |Qwerty|      |Dvorak|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
KC_CAPS, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  , \
_______, VOL_DW , VOL_UP , _______, _______, _______, _______, QWERTY , _______, DVORAK , _______, _______  , \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  , \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// read docs/custom_quantum_functions.md
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case UNIX_FN:
      if (record->event.pressed) {
        layer_on(_UNIX_FN);
      } else {
        layer_off(_UNIX_FN);
      }
      return false;
      break;
    case VIM_FN:
      if (record->event.pressed) {
        layer_on(_VIM_FN);
      } else {
        layer_off(_VIM_FN);
      }
      return false;
      break;
    case MOUSE_FN:
      if (record->event.pressed) {
        layer_on(_MOUSE_FN);
      } else {
        layer_off(_MOUSE_FN);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      } else {
        layer_off(_NUM);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
