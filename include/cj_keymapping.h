#ifndef CJ_KEYMAPPING_H
#define CJ_KEYMAPPING_H

#include <wchar.h>

/*
    Width of each key on the keyboard.
    Use for printing on screen keyboard.
*/
#define CHAR_KEY_WIDTH 4 // Default key width
#define WIDE_CHAR_KEY_WIDTH 6 // Tab, CapsLock
#define SHIFT_KEY_WIDTH 11
#define SPACE_KEY_WIDTH 38

/*
    How many rows and how many keys on each row.
*/
#define NROLS 5
#define NKEYS_R1 14 // ~1234567890-=[Bckspce]
#define NKEYS_R2 14 // [Tab]QWERTYUIOP{}[UEnter]
#define NKEYS_R3 14 // [Caps]ASDFGHJKL:"|[LEnter]
#define NKEYS_R4 12 // [Shift]ZXCVBNM<>?[Shift]
#define NKEYS_R5 6 // [Ctrl][Super][Alt][Space][Alt][Ctrl]

/*
    Use for explicitly assign a wstring to null.
*/
#define WCHAR_NULL (wchar_t)0

/*
    The color of the key's frame.
*/
#define FC_WHITE 0
#define FC_GREEN 1
#define FC_RED 2

typedef struct
{
    wchar_t label_upper[16]; // I guess that 16 is more than enough
    wchar_t label_lower;
    int key_width;
    int frame_color;
} cj_keymapping;
/*
    !!!THE INTERFACE OF CJ_KEYMAPPING!!!

    initialize_keymap(); // MUST CALL THIS BEFORE DOING ANYTHING!!!

    struct      cjk_keymap[N][M]                // referencing a specific key on row N, index (left to right) M.
    wchar_t*    cjk_keymap[N][M].label_upper    // The upper label of key(N,M), which is a wide char string. ex. "Q", "Backspace"...
    wchar_t     cjk_keymap[N][M].label_lower    // The lower label of key(N,M), which is the cangjie radical mapped to the key.
    int         cjk_keymap[N][M].key_width      // The width of key(N,M). Use for printing on screen keyboard.
    int         cjk_keymap[N][M].frame_color    // The color of the key's frame. value: FC_WHITE(default), FC_GREEN, FC_RED
*/
extern cj_keymapping* cjk_keymap[NROLS];

/*
    initialize_keymap:
        MUST CALL THIS BEFORE DOING ANYTHING!!!
*/
void initialize_keymap();

/*
    change_key_frame_color:
        Changes the frame color of the specified key.
        If changed successfully, color is returned.
        If color is other value than FC_WHITE, FC_GREEN, FC_RED, 
        the frame color will not be changed and -1 will be returned.
*/
int change_key_frame_color(cj_keymapping key, int color);

/*
    cjk_row_nkeys[N]:
    return the number of keys on row N.
*/
extern const int cjk_row_nkeys[NROLS];

#endif