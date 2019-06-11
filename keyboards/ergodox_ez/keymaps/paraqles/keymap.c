#include QMK_KEYBOARD_H
#include "process_auto_shift.h"
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "rgblight.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_C_BLUE,
  RGB_C_GREEN,
  RGB_C_PURPLE
};

#define WSP_UP        LALT(LCTL(KC_UP))
#define WSP_DOWN      LALT(LCTL(KC_DOWN))
#define WSP_LEFT      LALT(LCTL(KC_LEFT))
#define WSP_RIGHT     LALT(LCTL(KC_RIGHT))

#define WSP_MW_UP     LALT(LCTL(LSFT(KC_UP)))
#define WSP_MW_DOWN   LALT(LCTL(LSFT(KC_DOWN)))
#define WSP_MW_LEFT   LALT(LCTL(LSFT(KC_LEFT)))
#define WSP_MW_RIGHT  LALT(LCTL(LSFT(KC_RIGHT)))

#define _QWERTY 0
#define RGBLIGHT_LAYER_COLOR_QWERTY  0x1D, 0xE2, 0xDC

#define _SHIFTOL 1
#define RGBLIGHT_LAYER_COLOR_SHIFTOL  0x1D, 0x85, 0xE2
#define _SHIFTOR 2
#define RGBLIGHT_LAYER_COLOR_SHIFTOR  0xAD, 0x85, 0xE2

#define _MOUSE  3
#define RGBLIGHT_LAYER_COLOR_MOUSE   0x85, 0xE2, 0x1D

#define _MOVEL  4
#define RGBLIGHT_LAYER_COLOR_MOVEL   0xE2, 0xDC, 0x1D
#define _MOVER  5
#define RGBLIGHT_LAYER_COLOR_MOVER   0xE2, 0xDC, 0x1D

#define _CONFIG 6
#define RGBLIGHT_LAYER_COLOR_CONFIG  0x7A, 0x1D, 0xE2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ergodox(
    // Left Side
    KC_ESC,                 KC_1,        KC_2,       KC_3,      KC_4,        KC_5,        KC_CAPS,
    KC_TAB,                 KC_Q,        KC_W,       KC_E,      KC_R,        KC_T,        KC_RALT,
    LCMD_T(KC_DEL),         KC_A,        KC_S,       KC_D,      KC_F,        KC_G,
    LT(_CONFIG, KC_TILD),   KC_Z,        KC_X,       KC_C,      KC_V,        KC_B,        LT(_SHIFTOR, KC_EQL),

    KC_LCTL,                TT(_MOVEL),  KC_LEFT,    KC_RIGHT,  KC_LSHIFT,

                            KC_LALT,     KC_HOME,
                                         KC_END,
    KC_SPACE,               KC_BSPACE,   KC_LSHIFT,

    // Right Side
    KC_CAPS,                KC_6,        KC_7,       KC_8,      KC_9,        KC_0,        KC_MINUS,
    OSM(MOD_RALT),          KC_Y,        KC_U,       KC_I,      KC_O,        KC_P,        LT(_MOUSE, KC_BSLASH),
                            KC_H,        KC_J,       KC_K,      KC_L,        KC_SCLN,     RCMD_T(KC_QUOTE),
    LT(_SHIFTOL, KC_ESC),   KC_N,        KC_M,       KC_COMMA,  KC_DOT,      KC_SLASH,    KC_NO,

                                         KC_RSHIFT,  KC_UP,     KC_DOWN,     TT(_MOVER),  KC_RCTL,

    KC_PGUP,                KC_LALT,
    KC_PGDOWN,
    KC_RSHIFT,              KC_TAB,      KC_ENTER
  ),

  [_SHIFTOL] = LAYOUT_ergodox(
    // Left Side
    KC_F13,     KC_F1,     KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F12,
    KC_TRNS,    KC_EXLM,   KC_AT,     KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_BSLASH,
    KC_TRNS,    KC_GRAVE,  KC_PERC,   KC_LPRN,  KC_RPRN,  KC_HASH,
    KC_TRNS,    KC_DLR,    KC_CIRC,   KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,

    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_LABK,  KC_RABK,

                KC_TRNS,   KC_TRNS,
                           KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,

    // Right Side
    KC_F14,     KC_F6,     KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_F11,
    KC_BSPACE,  KC_P7,     KC_P8,    KC_P9,     KC_PPLS,  KC_PMNS,  KC_TRNS,
                KC_P4,     KC_P5,    KC_P6,     KC_PAST,  KC_PSLS,  KC_TRNS,
    KC_PENT,    KC_P1,     KC_P2,    KC_P3,     KC_PDOT,  KC_DLR,   KC_TRNS,

                           KC_P0,    KC_TRNS,   KC_PCMM,  KC_TRNS,  KC_TRNS,

    KC_TRNS,    KC_NLCK,
    KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS
  ),

  [_SHIFTOR] = LAYOUT_ergodox(
    // Left Side
    KC_F13,     KC_F1,    KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F12,
    KC_TRNS,    KC_PMNS,  KC_PPLS,   KC_P7,    KC_P8,    KC_P9,    KC_BSPACE,
    KC_TRNS,    KC_PSLS,  KC_PAST,   KC_P4,    KC_P5,    KC_P6,
    KC_TRNS,    KC_DLR,   KC_PDOT,   KC_P1,    KC_P2,    KC_P3,    KC_PENT,

    KC_TRNS,    KC_TRNS,  KC_PCMM,   KC_TRNS,  KC_P0,

                KC_NLCK,  KC_TRNS,
                          KC_TRNS,
    KC_TRNS,    KC_TRNS,  KC_TRNS,

    // Right Side
    KC_F14,     KC_F6,    KC_F7,    KC_F8,     KC_F9,    KC_F10,    KC_F11,
    KC_BSLASH,  KC_PIPE,  KC_LCBR,  KC_RCBR,   KC_AT,    KC_EXLM,   KC_TRNS,
                KC_HASH,  KC_LPRN,  KC_RPRN,   KC_PERC,  KC_GRAVE,  KC_TRNS,
    KC_TRNS,    KC_TILD,  KC_LBRC,  KC_RBRC,   KC_CIRC,  KC_DLR,    KC_TRNS,

                          KC_LABK,  KC_RABK,   KC_TRNS,  KC_TRNS,   KC_TRNS,

    KC_TRNS,    KC_TRNS,
    KC_TRNS,
    KC_TRNS,    KC_TRNS,  KC_TRNS
  ),

  [_MOVEL] = LAYOUT_ergodox(
    // Left Side
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      WSP_MW_UP,    KC_TRNS,       KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  WSP_MW_LEFT,  WSP_MW_DOWN,  WSP_MW_RIGHT,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,  KC_TRNS,

    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,

              KC_TRNS,  KC_TRNS,
                        KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,

    // Right Side
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,        KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      WSP_UP,      KC_TRNS,        KC_TRNS,  KC_TRNS,
              KC_MSTP,  WSP_LEFT,     WSP_DOWN,    WSP_RIGHT,      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,        KC_TRNS,  KC_TRNS,

                        KC_TRNS,      KC_TRNS,     KC_TRNS,        KC_TRNS,  KC_TRNS,

    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [_MOVER] = LAYOUT_ergodox(
    // Left Side
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      WSP_UP,       KC_TRNS,       KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  WSP_LEFT,     WSP_DOWN,     WSP_RIGHT,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,  KC_TRNS,

    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,

              KC_TRNS,  KC_TRNS,
                        KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,

    // Right Side
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      WSP_MW_UP,    KC_TRNS,        KC_TRNS,  KC_TRNS,
              KC_MSTP,  WSP_MW_LEFT,  WSP_MW_DOWN,  WSP_MW_RIGHT,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,

                        KC_TRNS,      KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [_MOUSE] = LAYOUT_ergodox(
    // Left Side
    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS,         KC_TRNS,
    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_MS_UP,    KC_TRNS,        KC_TRNS,         KC_TRNS,
    KC_TRNS,      KC_MS_WH_LEFT,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,    KC_MS_WH_RIGHT,
    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS,         KC_TRNS,

    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_MS_WH_UP, KC_MS_WH_DOWN,

                  KC_TRNS,        KC_TRNS,
                                  KC_TRNS,
    KC_MS_BTN1,   KC_MS_BTN2,     KC_TRNS,

    // Right Side
    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_LGUI,         KC_TRNS,
    KC_TRNS,      KC_TRNS,        KC_VOLD,     KC_MUTE,     KC_VOLU,        KC_LALT,         KC_TRNS,
                  KC_MSTP,        KC_MPRV,     KC_MPLY,     KC_MNXT,        KC_TRNS,         KC_TRNS,
    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS,         KC_TRNS,

                                  KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS,         KC_TRNS,

    KC_TRNS,      KC_TRNS,
    KC_TRNS,
    KC_WWW_HOME,  KC_WWW_BACK,    KC_WWW_FORWARD
  ),

  [_CONFIG] = LAYOUT_ergodox(
    // Left Side
    KC_TRNS,      KC_ASRP,   KC_ASUP,   KC_ASDN,  KC_ASON,  KC_ASOFF,  KC_TRNS,
    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,

    DF(_QWERTY),  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,

                  KC_TRNS,   KC_TRNS,
                             KC_TRNS,
    KC_TRNS,      KC_TRNS,   KC_TRNS,


    // Right Side
    RGB_TOG,      RGB_MOD,   RGB_M_P,   RGB_M_B,  RGB_M_R,  RGB_M_SW,  KC_TRNS,
    KC_TRNS,      RGB_RMOD,  RGB_M_SN,  RGB_M_K,  RGB_M_X,  RGB_M_G,   RGB_M_T,
                  RGB_HUI,   RGB_SAI,   RGB_VAI,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    RGB_TOG,      RGB_HUD,   RGB_SAD,   RGB_VAD,  KC_TRNS,  KC_TRNS,   KC_TRNS,

                             KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,

    RGB_C_BLUE,   KC_TRNS,
    RGB_C_GREEN,
    RGB_C_PURPLE,      KC_TRNS,   KC_TRNS
  ),

};

// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

// How long (in milliseconds) to wait between animation steps for each of the "Cycling rainbow" animations
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {120, 60, 30};

// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};

// How long (in milliseconds) to wait between animation steps for each of the "Snake" animations
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {100, 50, 20};

// How long (in milliseconds) to wait between animation steps for each of the "Knight" animations
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};

// These control which hues are selected for each of the "Static gradient" modes
const uint16_t RGBLED_GRADIENT_RANGES[] PROGMEM = {360, 240, 180, 120, 90};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

/*void set_default_layer_color(void) {*/
  /*uint8_t default_layer = biton32(default_layer_state);*/

  /*switch(default_layer) {*/
    /*case _QWERTY:*/
      /*#ifdef RGBLIGHT_ENABLE*/
        /*rgblight_enable();*/
        /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_QWERTY);*/
      /*#endif*/
      /*break;*/
    /*default:*/
      /*break;*/
  /*}*/
/*}*/

void matrix_init_user(void) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  /*bootmagic();*/

  /*set_default_layer_color();*/

  autoshift_disable();
};

/*void led_set_user(uint8_t usb_led) {*/
  /*if(usb_led & (1 << USB_LED_NUM_LOCK)) {*/
    /*ergodox_right_led_1_on();*/
  /*} else {*/
    /*ergodox_right_led_1_off();*/
  /*}*/

  /*if(usb_led & (1 << USB_LED_CAPS_LOCK)) {*/
    /*ergodox_right_led_2_on();*/
  /*} else {*/
    /*ergodox_right_led_2_off();*/
  /*}*/
/*}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    /*case KC_LEAD:                */
    /*  if(record->event.pressed) {*/
    /*    ergodox_right_led_3_on();*/
    /*  }                          */
    /*  break;                     */

  #ifdef RGBLIGHT_ENABLE
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

    case RGB_C_BLUE:
      if (record->event.pressed) {
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(240,255,255);
      }
      return false;
      break;

    case RGB_C_GREEN:
      if (record->event.pressed) {
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(120,255,128);
      }
      return false;
      break;

    case RGB_C_PURPLE:
      if (record->event.pressed) {
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(296,254,255);
      }
      return false;
      break;
  #endif
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if(layer == 0) {
      /*set_default_layer_color();*/
    } else {
      switch (layer) {
        case _SHIFTOL:
          ergodox_right_led_1_on();

          #ifdef RGBLIGHT_ENABLE
            /*rgblight_enable();*/
            /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_SHIFTOL);*/
          #endif
          break;
        case _SHIFTOR:
          ergodox_right_led_1_on();

          #ifdef RGBLIGHT_ENABLE
            /*rgblight_enable();*/
            /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_SHIFTOR);*/
          #endif
          break;

        case _MOUSE:
          ergodox_right_led_2_on();

          #ifdef RGBLIGHT_ENABLE
            /*rgblight_enable();*/
            /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_MOUSE);*/
          #endif
          break;

        case _MOVEL:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();

          #ifdef RGBLIGHT_ENABLE
            /*rgblight_enable();*/
            /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_MOVEL);*/
          #endif
          break;
        case _MOVER:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();

          #ifdef RGBLIGHT_ENABLE
            /*rgblight_enable();*/
            /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_MOVER);*/
          #endif
          break;

        case _CONFIG:
          ergodox_right_led_3_on();

          #ifdef RGBLIGHT_ENABLE
            /*rgblight_enable();*/
            /*rgblight_setrgb(RGBLIGHT_LAYER_COLOR_CONFIG);*/
          #endif
          break;
        default:
          break;
      }
    }
    return state;

};

