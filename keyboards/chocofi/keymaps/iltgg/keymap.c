// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include "keymap_us.h"
#include QMK_KEYBOARD_H

enum layer_names {
    _SNTH,
    _QWERTY,
    _SHIFT,
    _EXTEND,
    _SYMBOL,
    _NUMBER,
    _NUMPAD,
    _FUNCTION,
    _MOUSE,
    _GAMING,
    _GAMING_EXTEND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer - SNTH
    [0] = LAYOUT_split_3x5_3(
        KC_X,    KC_P,    KC_D,    KC_M,    KC_Q,                               KC_QUOT, KC_Y,    KC_O,    KC_U,    KC_SCLN,
        KC_S,    KC_N,    KC_T,    KC_H,    KC_V,                               KC_G,    KC_C,    KC_A,    KC_E,    KC_I,
        KC_F,    KC_B,    KC_K,    KC_L,    KC_J,                               KC_Z,    KC_W,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MO(3),   KC_R, MO(4),               KC_BSPC, KC_SPC,  MO(2)
    ),
    // QWERTY Layer
    [1] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MO(3),   KC_NO, MO(4),              KC_BSPC, KC_SPC,  KC_LSFT
    ),
    // Shift Layer
    [2] = LAYOUT_split_3x5_3(
        S(KC_X),    S(KC_P),    S(KC_D),    S(KC_M),    S(KC_Q),                               S(KC_QUOT), S(KC_Y),    S(KC_O),    S(KC_U),    S(KC_SCLN),
        S(KC_S),    S(KC_N),    S(KC_T),    S(KC_H),    S(KC_V),                               S(KC_G),    S(KC_C),    S(KC_A),    S(KC_E),    S(KC_I),
        S(KC_F),    S(KC_B),    S(KC_K),    S(KC_L),    S(KC_J),                               S(KC_Z),    S(KC_W),    S(KC_COMM), S(KC_DOT),  S(KC_SLSH),
                                   KC_NO,   S(KC_R),    MO(5),                          KC_NO, KC_NO,      KC_NO
    ),
    // Extend Layer
    [3] = LAYOUT_split_3x5_3(
        MO(8),          MO(7),          KC_NO,          KC_NO,          KC_INS,                               KC_HOME,    KC_PGDN,    KC_PGUP, KC_END,    KC_CAPS,
        OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_RALT),                               KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_DEL,
        C(KC_Z),       C(KC_X),    C(KC_C),    C(KC_V),    KC_LGUI,                               KC_NO,    KC_NO,    KC_NO, KC_NO, KC_PSCR,
                                   KC_NO,   KC_NO, KC_NO,           KC_ESC,  KC_ENT,  KC_TAB
    ),
    // Symbol Layer
    [4] = LAYOUT_split_3x5_3(
        KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,                                  KC_EQL,KC_GRV,KC_DQUO,KC_QUOT,KC_MINUS,
        OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LCTL), KC_CIRC,   KC_ASTR,KC_LPRN,KC_LCBR,KC_LBRC,KC_UNDS,
        KC_NO,KC_NO,KC_BSLS,KC_PIPE,KC_AMPR,                                   KC_TILD,KC_RPRN,KC_RCBR,KC_RBRC,KC_PLUS,
        KC_NO,KC_NO,KC_NO, KC_NO,KC_NO,MO(5)
    ),
    // Number Layer
    [5] = LAYOUT_split_3x5_3(
        KC_NO,MO(6),KC_COMM,KC_DOT,KC_NUM, KC_EQL,KC_7,KC_8,KC_9,KC_MINUS,
        OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_RALT), KC_ASTR,KC_4,KC_5,KC_6,KC_PLUS,
        MO(5),KC_SPC,KC_TAB,KC_BSPC,KC_ENT, KC_0,KC_1,KC_2,KC_3,KC_SLSH,
        KC_NO,KC_NO,KC_NO, KC_NO,KC_NO,KC_NO
    ),
    // Number Layer - Numpad Keycodes
    [6] = LAYOUT_split_3x5_3(
        KC_NO,KC_NO,KC_PCMM,KC_PDOT,KC_NUM, KC_PEQL,KC_P7,KC_P8,KC_P9,KC_PMNS,
        OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_RALT), KC_PAST,KC_P4,KC_P5,KC_P6,KC_PPLS,
        KC_NO,KC_SPC,KC_TAB,KC_BSPC,KC_PENT, KC_P0,KC_P1,KC_P2,KC_P3,KC_PSLS,
        KC_NO,KC_NO,KC_NO, KC_NO,KC_NO,KC_NO
    ),
    // Function Layer
    [7] = LAYOUT_split_3x5_3(
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, KC_F1,KC_F2,KC_F3,KC_F4,KC_SCRL,
        OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LCTL), KC_NO,    KC_F5,KC_F6,KC_F7,KC_F8, TG(1),
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, KC_F9,KC_F10,KC_F11,KC_F12, DF(9),
        KC_NO,KC_NO,KC_NO, KC_NO,KC_NO,KC_NO
    ),
    // Mouse Layer
    [8] = LAYOUT_split_3x5_3(
        KC_NO ,KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,     KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LALT ,KC_LGUI, KC_LSFT, KC_LCTL, KC_NO,     KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_NO,
        KC_NO ,KC_NO, KC_NO, KC_NO, KC_NO,     KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_NO,
        KC_NO,KC_NO,KC_NO,          KC_MS_BTN2,KC_MS_BTN1,KC_MS_BTN3
    ),
    // Gaming Layer - Modified QWERTY
    // [9] = LAYOUT_split_3x5_3(
    //     ,,,,, ,,,,,
    //     ,,,,, ,,,,,
    //     ,,,,, ,,,,,
    //     ,,, ,,
    // ),
    // Gaming Layer Extend
    // [10] = LAYOUT_split_3x5_3(
    //     ,,,,, ,,,,,
    //     ,,,,, ,,,,,
    //     ,,,,, ,,,,,
    //     ,,, ,,
    // ),
};

#ifdef OLED_ENABLE
bool render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _SNTH:
            oled_write_P(PSTR("SNTH\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _SHIFT:
            oled_write_P(PSTR("SHIFT\n"), false);
            break;
        case _EXTEND:
            oled_write_P(PSTR("EXTEND\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYMBOL\n"), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("NUMBER\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FUNCTION\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("GAMING\n"), false);
            break;
        case _GAMING_EXTEND:
            oled_write_P(PSTR("GAMING++\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}

bool render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);

    return false;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        // oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
#endif
