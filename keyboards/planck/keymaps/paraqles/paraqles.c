#include "keymap_common.h"
#include "keymap_extras/keymap_german.h"

enum layer {
  _QW = 0,
  _QW_UP,
  _QW_DN,
  _NEO,
  _NEO_UP,
  _NEO_DN,
  _NP,
  _NPSC,
  _NPBC,
  _FN
};

enum makros {
  _BL_MAKRO = 0,
  _NP_SAVE,
  _NP_UNDO,
  _NP_REDO
};

int keymap_backlight_state = -1;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = { /* Qwerty */
    {KC_ESC,    KC_Q,      KC_W,        KC_E,        KC_R,         KC_T,     KC_Y,     KC_U,         KC_I,     KC_O,        KC_P,     KC_BSPC       },
    {KC_TAB,    KC_A,      KC_S,        KC_D,        KC_F,         KC_G,     KC_H,     KC_J,         KC_K,     KC_L,        KC_SCLN,  KC_QUOT       },
    {KC_LSFT,   KC_Z,      KC_X,        KC_C,        KC_V,         KC_B,     KC_N,     KC_M,         KC_COMM,  KC_DOT,      KC_SLSH,  SFT_T(KC_ENT) },
    {KC_LCTL,   FUNC(_FN), KC_LALT,     KC_LGUI,     FUNC(_QW_DN), KC_SPC,   KC_SPC,   FUNC(_QW_UP), KC_LEFT,  KC_DOWN,     KC_UP,    KC_RGHT       }
  },
  [_QW_UP] = { /* Qwerty Raise */
    {KC_GRV,    KC_1,      KC_2,        KC_3,        KC_4,         KC_5,     KC_6,     KC_7,         KC_8,     KC_9,        KC_0,     KC_DELETE     },
    {KC_TRNS,   KC_F1,     KC_F2,       KC_F3,       KC_F4,        KC_F5,    KC_F6,    KC_TRNS,      KC_UNDS,  KC_LCBR,     KC_RCBR,  KC_PIPE       },
    {KC_TRNS,   KC_F7,     KC_F8,       KC_F9,       KC_F10,       KC_F11,   KC_F12,   KC_TRNS,      KC_TRNS,  KC_TRNS,     KC_EQL,   KC_TRNS       },
    {KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,  FUNC(_QW_UP), KC_HOME,  KC_PGDN,     KC_PGUP,  KC_END        }
  },
  [_QW_DN] = { /* Qwerty Lower */
    {KC_TILD,   KC_EXLM,   KC_AT,       KC_HASH,     KC_DLR,       KC_PERC,  KC_CIRC,  KC_AMPR,      KC_ASTR,  KC_LPRN,     KC_RPRN,  KC_DELETE     },
    {KC_TRNS,   KC_F1,     KC_F2,       KC_F3,       KC_F4,        KC_F5,    KC_F6,    KC_TRNS,      KC_MINS,  KC_LBRC,     KC_RBRC,  KC_BSLS       },
    {KC_TRNS,   KC_F7,     KC_F8,       KC_F9,       KC_F10,       KC_F11,   KC_F12,   KC_TRNS,      KC_TRNS,  KC_TRNS,     KC_PLUS,  KC_TRNS       },
    {KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,     FUNC(_QW_DN), KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_HOME,  KC_PGDN,     KC_PGUP,  KC_END        }
  },

  [_NEO] = { /* NEO 2 */
    {KC_ESC,    DE_X,       DE_V,       DE_L,       DE_C,          DE_W,       DE_K,       DE_H,          DE_G,    DE_F,    DE_Q,    KC_BSPC       },
    {KC_TAB,    DE_U,       DE_I,       DE_A,       DE_E,          DE_O,       DE_S,       DE_N,          DE_R,    DE_T,    DE_D,    DE_Y          },
    {KC_LSFT,   DE_UE,      DE_OE,      DE_AE,      DE_P,          DE_Z,       DE_B,       DE_M,          DE_COMM, DE_DOT,  DE_J,    SFT_T(KC_ENT) },
    {KC_LCTL,   FUNC(_FN),  KC_LALT,    KC_LGUI,    FUNC(_NEO_DN), KC_SPC,     KC_SPC,     FUNC(_NEO_UP), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT       }
  },
  [_NEO_UP] = { /* NEO 2 Raise */
    {KC_TRNS,   KC_1,       KC_2,       KC_3,       KC_4,          KC_5,       KC_6,       KC_7,          KC_8,    KC_9,    KC_0,    KC_BSPC       },
    {KC_TRNS,   KC_F1,      KC_F2,      KC_F3,      KC_F4,         KC_F5,      KC_F6,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS       },
    {KC_TRNS,   KC_F7,      KC_F8,      KC_F9,      KC_F10,        KC_F11,     KC_F12,     KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS       },
    {KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TRNS,    FUNC(_NEO_UP), KC_HOME, KC_PGDN, KC_PGUP, KC_END        }
  },
  [_NEO_DN] = { /* NEO 2 Lower */
    {KC_TRNS,   DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,       DE_EXLM,    DE_LESS,    DE_MORE,       DE_EQL,  DE_AMPR, DE_SS,   KC_DELETE     },
    {DE_BSLS,   DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,       DE_QST,     DE_LPRN,    DE_RPRN,       DE_MINS, DE_COLN, DE_AT,   KC_TRNS       },
    {DE_HASH,   DE_DLR,     DE_TILD,    DE_PIPE,    DE_GRV,        DE_PLUS,    DE_PERC,    DE_DQOT,       DE_QUOT, DE_SCLN, KC_TRNS, KC_TRNS       },
    {KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    FUNC(_NEO_DN), KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_HOME, KC_PGDN, KC_PGUP, KC_END        }
  },

  [_NP] = { /* Numpad and Moves */
    {KC_ESC,  KC_PGUP,   KC_UP,   KC_HOME, KC_F1,       LCTL(KC_Z), KC_P7,   KC_P8,       KC_P9,      KC_PSLS,   KC_SCLN,    KC_BSPC       },
    {KC_TAB,  KC_LEFT,   KC_DOWN, KC_RGHT, KC_F2,       LCTL(KC_Y), KC_P4,   KC_P5,       KC_P6,      KC_PAST,   KC_COLN,    KC_EQL        },
    {KC_LSFT, KC_PGDN,   KC_TRNS, KC_END,  KC_F3,       LCTL(KC_S), KC_P1,   KC_P2,       KC_P3,      KC_PMNS,   KC_DOT,     KC_PENT       },
    {KC_LCTL, FUNC(_FN), KC_LALT, KC_LGUI, FUNC(_NPBC), KC_SPC,     KC_SPC,  FUNC(_NPSC), KC_P0,      KC_PPLS,   KC_COMM,    KC_PEQL       }
  },
  [_NPSC] = { /* Numpad small chars */
    {KC_TRNS, KC_Q,      KC_W,    KC_E,    KC_R,        KC_T,       KC_Y,    KC_U,        KC_I,       KC_O,      KC_P,       KC_DELETE     },
    {KC_TRNS, KC_A,      KC_S,    KC_D,    KC_F,        KC_G,       KC_H,    KC_J,        KC_K,       KC_L,      KC_SCLN,    KC_QUOT       },
    {KC_TRNS, KC_Z,      KC_X,    KC_C,    KC_V,        KC_B,       KC_N,    KC_M,        KC_COMM,    KC_DOT,    KC_SLSH,    SFT_T(KC_ENT) },
    {KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS, FUNC(_NPSC), KC_LEFT,    KC_DOWN,   KC_UP,      KC_RGHT       }
  },
  [_NPBC] = { /* Numpad capital chars */
    {KC_TRNS, S(KC_Q),   S(KC_W), S(KC_E), S(KC_R),     S(KC_T),    S(KC_Y), S(KC_U),     S(KC_I),    S(KC_O),   S(KC_P),    KC_DELETE     },
    {KC_TRNS, S(KC_A),   S(KC_S), S(KC_D), S(KC_F),     S(KC_G),    S(KC_H), S(KC_J),     S(KC_K),    S(KC_L),   S(KC_SCLN), S(KC_QUOT)    },
    {KC_TRNS, S(KC_Z),   S(KC_X), S(KC_C), S(KC_V),     S(KC_B),    S(KC_N), S(KC_M),     S(KC_COMM), S(KC_DOT), S(KC_SLSH), SFT_T(KC_ENT) },
    {KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, FUNC(_NPBC), KC_TRNS,    KC_TRNS, KC_TRNS,     KC_LEFT,    KC_DOWN,   KC_UP,      KC_RGHT       }
  },

  [_FN] = { /* Media Layer */
    {KC_VOLU, KC_MNXT,   KC_MPRV,  KC_TRNS, M(_BL_MAKRO), LCTL(KC_Z), KC_P7,   KC_P8, KC_P9,   KC_PSLS, KC_NLCK, KC_BSPC  },
    {KC_MUTE, KC_MSTP,   KC_MPLY,  KC_TRNS, BL_INC,       LCTL(KC_Y), KC_P4,   KC_P5, KC_P6,   KC_PAST, KC_TRNS, KC_POWER },
    {KC_VOLD, DF(_QW),   DF(_NEO), DF(_NP), BL_DEC,       LCTL(KC_S), KC_P1,   KC_P2, KC_P3,   KC_PMNS, KC_PENT, KC_TRNS  },
    {KC_TRNS, FUNC(_FN), KC_WBAK,  KC_WFWD, KC_TRNS,      KC_TRNS,    KC_TRNS, KC_PEQL, KC_P0, KC_PDOT, KC_PPLS, RESET    },
  },

};


const uint16_t PROGMEM fn_actions[] = {
    [_QW_UP]  = ACTION_LAYER_MOMENTARY(_QW_UP),   // QWERTY to RAISE
    [_QW_DN]  = ACTION_LAYER_MOMENTARY(_QW_DN),   // QWERTY to LOWER

    [_NEO_UP] = ACTION_LAYER_MOMENTARY(_NEO_UP),  // NEO to RAISE
    [_NEO_DN] = ACTION_LAYER_MOMENTARY(_NEO_DN),  // NEO to LOWER

    [_NPSC] = ACTION_LAYER_MOMENTARY(_NPSC),      // NEO to RAISE
    [_NPBC] = ACTION_LAYER_MOMENTARY(_NPBC),      // NEO to LOWER

    [_FN] = ACTION_LAYER_MOMENTARY(_FN),          // NEO to LOWER
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case _BL_MAKRO:
        if(record->event.pressed) {

          if(keymap_backlight_state > 0) {
            keymap_backlight_state = 0;
            return MACRODOWN(BL_OFF, END);

          } else {
            keymap_backlight_state = 1;
            return MACRODOWN(BL_ON, END);
          }
        }
        break;
    }
    return MACRO_NONE;
};
