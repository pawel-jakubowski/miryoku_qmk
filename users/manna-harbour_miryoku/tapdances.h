#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    SPC_NAV,
    BSPC_NUM,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void spc_finished(qk_tap_dance_state_t *state, void *user_data);
void spc_reset(qk_tap_dance_state_t *state, void *user_data);
void bspc_finished(qk_tap_dance_state_t *state, void *user_data);
void bspc_reset(qk_tap_dance_state_t *state, void *user_data);

