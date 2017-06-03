/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"

#define BASE 0
#define HHKB 1
#define SPACE_FN 2
#define LEFT_FN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | `     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | Backs |Esc|
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | \     |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

  [BASE] = KEYMAP(  //  default layer
  KC_GRV  , KC_1    , KC_2   , KC_3    , KC_4     , KC_5 , KC_6 , KC_7 , KC_8    , KC_9   , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , KC_ESC , \
  KC_TAB  , KC_Q    , KC_W   , KC_E    , KC_R     , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS , \
  KC_LCTL , KC_A    , KC_S   , KC_D    , KC_FN3   , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_SCLN , KC_QUOT , KC_ENT  , \
  KC_LSFT , KC_Z    , KC_X   , KC_C    , KC_V     , KC_B , KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT , KC_FN1  , \
  KC_LALT , KC_LGUI , KC_FN2 , KC_RGUI , KC_RALT) ,



    /* Layer1 HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */
  [HHKB] = KEYMAP(
  KC_PWR,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL, \
  KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_UP,    KC_TRNS,  KC_BSPC,          \
  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT,  KC_PENT,                    \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PPLS,  KC_PMNS,  KC_END,   KC_PGDN,  KC_DOWN,  KC_TRNS,  KC_TRNS,                    \
                     KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS),


    /* Layer 2 SpaceFN:
     * ,-----------------------------------------------------------------------------------------.
     * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     |     |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |  '  |  ,  |  .  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |  /  |  =  |   \    |
     * |-----------------------------------------------------------------------------------------|
     * | Control  |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |  -  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |  ;  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  |  Shift  | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           |LAlt |  LGui  |              SpaceFN              |  RGui  |RAlt |
     *
     * ,-----------------------------------------------------------------------------------------.
     * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     |     |
     * |-----------------------------------------------------------------------------------------|
     * |        |     |     | *** |     |     |     |     | *** |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------|
     * | Control  | HOME|     | END | *** |     | Del | BS  |     |     | ESC |     |            |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |     |     |     |     |     |     | ENT |     |     |     |  Shift  | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           | **** |  ****  |              ****              |  ****  |**** |

     */
  [SPACE_FN] = KEYMAP(
  KC_NO   , KC_F1   , KC_F2   , KC_F3   , KC_F4      , KC_F5 , KC_F6  , KC_F7   , KC_F8      , KC_F9      , KC_F10 , KC_F11  , KC_F12 , KC_NO , KC_NO , \
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , LCTL(KC_R) , KC_NO , KC_NO  , KC_NO   , KC_TRNS    , KC_NO      , KC_NO  , KC_NO   , KC_NO  , KC_NO , \
  KC_LCTL , KC_HOME , KC_NO   , KC_END  , LCTL(KC_F) , KC_NO , KC_DEL , KC_BSPC , LCTL(KC_K) , LCTL(KC_L) , KC_ESC , KC_NO   , KC_NO  , \
  KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_NO      , KC_NO , KC_NO  , KC_ENT  , KC_NO      , KC_NO      , KC_NO  , KC_RSFT , KC_NO  , \
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS)   ,


    /* Layer 3 LeftFN
     * ,-----------------------------------------------------------------------------------------.
     * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     |     |
     * |-----------------------------------------------------------------------------------------|
     * |        |     |     |     |     |     | LEF | DOW | UP  | RGHT|     |     |     |        |
     * |-----------------------------------------------------------------------------------------|
     * | Control  | HOME|     | END |     |     | Del | BS  |     |     | ESC |     |            |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |     |     |     |     |     |     | ENT |     |     |     |  Shift  | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           | **** |  ****  |              ****              |  ****  |**** |
         */
  [LEFT_FN] = KEYMAP(
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO    , KC_NO , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO , KC_NO , \
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO    , KC_NO , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO , \
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_TRNS  , KC_NO , KC_LEFT , KC_DOWN , KC_UP , KC_RGHT , KC_NO , KC_NO   , KC_NO , \
  KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_NO    , KC_NO , KC_NO   , KC_ENT  , KC_NO , KC_NO   , KC_NO , KC_RSFT , KC_NO , \
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS) ,

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(HHKB),  // KC_FN1
    [2] = ACTION_LAYER_TAP_KEY(SPACE_FN, KC_SPACE),  // KC_FN2
    [3] = ACTION_LAYER_TAP_KEY(LEFT_FN, KC_F),  // KC_FN3
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
