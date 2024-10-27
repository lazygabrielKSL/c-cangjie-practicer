#include "on_screen_keyboard.h"
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#define CHAR_KEY_WIDTH 4 // Default key width
#define WIDE_CHAR_KEY_WIDTH 6 // Tab, CapsLock
#define SHIFT_KEY_WIDTH 11
#define SPACE_KEY_WIDTH 38
#define KEYS_IN_ROW 14
#define HLINE_LEN 75 // used in printing horizontal lines
#define ALIGN_LEFT 0
#define ALIGN_RIGHT 1

/* static function prototypes */
/*
    print_horizontal_frame_line:
        
*/
static inline void print_horizontal_frame_line();

/*
    print_key_row:
        Print the specified part of the keyboard layout without line break,
        read from an array of char (e.g. string).

        width should > 0.
        ALIGN_LEFT, ALIGN_RIGHT should be defined as macro.

        ex. 
            char row[] = "ASDFG";
            print_keys(row, 1, ALIGN_LEFT);  // output: |A|S|D|F|G
            print_keys(row, 1, ALIGN_RIGHT); // output: |A|S|D|F|G
            print_keys(row, 2, ALIGN_LEFT);  // output: |A |S |D |F |G 
            print_keys(row, 3, ALIGN_RIGHT); // output: |  A|  S|  D|  F|  G

*/
static inline void print_keys(const wchar_t* key_array, int width, int align);

/*
    print_multchar_key:
        Print a key whose label is not merely a character.
        e.g. Backspace, tab, Enter...
        Does not support print multiple keys.
        Does not support right align. (Seems like there is no need to do this.)
*/
static inline void print_multichar_key(const wchar_t* label_str, int width);

/*
    print_blank_keys:
        same as print_key_row but without characters inside.
        ex.
            print_blank_keys(5, 2); //output: |  |  |  |  |  
*/
static inline void print_blank_keys(int length, int width);

/*
    print_end_of_key_row:
        prints "|\n"
*/
static inline void print_end_of_key_row();

/* layout notes */
/*
Upper layout:
    ~1234567890-=[Backspace]
    [Tab]QWERTYUIOP{}[Enter]
    [Caps]ASDFGHJKL:"|[Enter]
    [Shift]ZXCVBNM<>?[Shift]
    [Ctrl][Super][Alt][Space][Alt][Ctrl]
*/
/*
Lower (cangjie) layout:
    Row 1 N/A
    [][]
    [];'\[]
    [],./[]
*/
void print_osk()
{
    // row 1
    print_horizontal_frame_line();
    print_keys(L"~1234567890-=", CHAR_KEY_WIDTH, ALIGN_LEFT); 
    print_multichar_key(L"Backspce", CHAR_KEY_WIDTH*2);
    print_end_of_key_row();
    print_blank_keys(KEYS_IN_ROW-1, CHAR_KEY_WIDTH);
    print_blank_keys(1, CHAR_KEY_WIDTH*2); // Backspace
    print_end_of_key_row();

    // row 2
    print_horizontal_frame_line();
    print_multichar_key(L"Tab", WIDE_CHAR_KEY_WIDTH);
    print_keys(L"QWERTYUIOP{}", CHAR_KEY_WIDTH, ALIGN_LEFT); 
    print_multichar_key(L"Enter", WIDE_CHAR_KEY_WIDTH);
    print_end_of_key_row();
    print_blank_keys(1, WIDE_CHAR_KEY_WIDTH); // Tab
    print_keys(L"手田水口廿卜山戈人心", CHAR_KEY_WIDTH, ALIGN_RIGHT);
    print_blank_keys(2, CHAR_KEY_WIDTH); //{}
    print_blank_keys(1, WIDE_CHAR_KEY_WIDTH); //Enter
    print_end_of_key_row();

    // row 3
    print_horizontal_frame_line();
    print_multichar_key(L"Caps", CHAR_KEY_WIDTH*2);
    print_keys(L"ASDFGHJKL:\"|", CHAR_KEY_WIDTH, ALIGN_LEFT); 
    print_blank_keys(1, CHAR_KEY_WIDTH); // The lower part of Enter
    print_end_of_key_row();
    print_blank_keys(1, CHAR_KEY_WIDTH*2); // CapsLock
    print_keys(L"日尸木火土竹十大中", CHAR_KEY_WIDTH, ALIGN_RIGHT);
    print_blank_keys(4, CHAR_KEY_WIDTH); // :"| and lower part of Enter
    print_end_of_key_row();

    // row 4
    print_horizontal_frame_line();
    print_multichar_key(L"Shift", SHIFT_KEY_WIDTH);
    print_keys(L"ZXCVBNM<>?", CHAR_KEY_WIDTH, ALIGN_LEFT); 
    print_multichar_key(L"Shift", SHIFT_KEY_WIDTH);
    print_end_of_key_row();
    print_blank_keys(1, SHIFT_KEY_WIDTH); // LShift
    print_keys(L"重難金女月弓一", CHAR_KEY_WIDTH, ALIGN_RIGHT);
    print_blank_keys(3, CHAR_KEY_WIDTH); // <>?
    print_blank_keys(1, SHIFT_KEY_WIDTH); // RShift
    print_end_of_key_row();

    // row 5
    print_horizontal_frame_line();
    print_multichar_key(L"Ctrl", WIDE_CHAR_KEY_WIDTH);
    print_multichar_key(L"Super", WIDE_CHAR_KEY_WIDTH);
    print_multichar_key(L"Alt", WIDE_CHAR_KEY_WIDTH);
    print_blank_keys(1, SPACE_KEY_WIDTH);
    print_multichar_key(L"Alt", WIDE_CHAR_KEY_WIDTH);
    print_multichar_key(L"Ctrl", WIDE_CHAR_KEY_WIDTH);
    print_end_of_key_row();
    print_blank_keys(3, WIDE_CHAR_KEY_WIDTH); // LCtrl, Super, LAlt
    print_blank_keys(1, SPACE_KEY_WIDTH); // Space
    print_blank_keys(2, WIDE_CHAR_KEY_WIDTH); //RAlt, RCtrl
    print_end_of_key_row();

    // end
    print_horizontal_frame_line();
}

static inline void print_horizontal_frame_line()
{
    for (int i=0; i<HLINE_LEN; i++)
    {
        wprintf(L"-");
    }
    wprintf(L"\n");
}

static inline void print_keys(const wchar_t* key_array, int width, int align)
{
    int karray_len = wcslen(key_array);

    if (align == ALIGN_RIGHT)
    {
        for (int i=0; i<karray_len; i++)
        {
            wprintf(L"|");
            for (int j=0; j<width-2; j++) // Chinese char is 2 spaces wide
            {
                wprintf(L" ");
            }
            wprintf(L"%lc", key_array[i]);
        }
    }

    else // default: left-aligned
    {
        for (int i=0; i<karray_len; i++)
        {
            wprintf(L"|");
            wprintf(L"%lc", key_array[i]);
            for (int j=0; j<width-1; j++)
            {
                wprintf(L" ");
            }
        }
    }
}

static inline void print_multichar_key(const wchar_t* label_str, int width)
{
    wprintf(L"|%ls", label_str);
    for (int i=width-wcslen(label_str); i>0; i--)
    {
        wprintf(L" ");
    }
}

static inline void print_blank_keys(int length, int width)
{
    for (int i=0; i<length; i++)
    {
        wprintf(L"|");
        for (int j=0; j<width; j++)
        {
            wprintf(L" ");
        }
    }
}

static inline void print_end_of_key_row()
{
    wprintf(L"|\n");
}