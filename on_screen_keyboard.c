#include "on_screen_keyboard.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHAR_KEY_WIDTH 4 // Default key width
#define WIDE_CHAR_KEY_WIDTH 6 // Tab, CapsLock
#define SHIFT_KEY_WIDTH 11
#define SPACE_KEY_WIDTH 38
#define KEYS_IN_ROW 14
#define HLINE_LEN 75 // used in printing horizontal lines
#define ALIGN_LEFT 0
#define ALIGN_RIGHT 1

/*
    Some notes: keyboard key numbers:
        row 1 = 1*14 (`1234567890-=)(Backspace)
        row 2 = 1.2*1 (tab) + 1*12 (QWERTYUIOP)([]) + 1.8*1 (upper part of enter) 
        row 3 = 1.5*1 (caps lock) + 1*12 (ASDFGHJKL)(;'\) + 1.5*1 (upper part of enter) 
        row 4 = 2*1 (Shift) + 1*10 (ZXCVBNM)(,./) + 3*1 (Shift)
        row 5 = 1*3 (Ctrl)(Super)(Alt) + 9*1 (Space) + 1.5*2 (Alt)(Ctrl)
*/

void print_osk()
{
    // TODO: detect console width
    //int console_width; // TODO: Implement this
    
    if (1) // TODO: if console width >= osk width
    {
        // print osk
        // row 1
        print_horizontal_frame_line();
        print_keys("~1234567890-=", CHAR_KEY_WIDTH, ALIGN_LEFT); 
        print_multichar_key("Backspce", CHAR_KEY_WIDTH*2, ALIGN_LEFT);
        print_end_of_key_row();
        print_blank_keys(KEYS_IN_ROW-1, CHAR_KEY_WIDTH);
        print_blank_keys(1, CHAR_KEY_WIDTH*2); // Backspace
        print_end_of_key_row();

        // row 2
        print_horizontal_frame_line();
        print_multichar_key("Tab", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_keys("QWERTYUIOP{}", CHAR_KEY_WIDTH, ALIGN_LEFT); 
        print_multichar_key("Enter", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_end_of_key_row();
        print_blank_keys(1, WIDE_CHAR_KEY_WIDTH); // Tab
        print_blank_keys(KEYS_IN_ROW-2, CHAR_KEY_WIDTH);
        print_blank_keys(1, WIDE_CHAR_KEY_WIDTH); //Enter
        print_end_of_key_row();

        // row 3
        print_horizontal_frame_line();
        print_multichar_key("Caps", CHAR_KEY_WIDTH*2, ALIGN_LEFT);
        print_keys("ASDFGHJKL:\"|", CHAR_KEY_WIDTH, ALIGN_LEFT); 
        print_blank_keys(1, CHAR_KEY_WIDTH); // The lower part of Enter
        print_end_of_key_row();
        print_blank_keys(1, CHAR_KEY_WIDTH*2); // CapsLock
        print_blank_keys(KEYS_IN_ROW-1, CHAR_KEY_WIDTH);
        print_end_of_key_row();

        // row 4
        print_horizontal_frame_line();
        print_multichar_key("Shift", SHIFT_KEY_WIDTH, ALIGN_LEFT);
        print_keys("ZXCVBNM<>?", CHAR_KEY_WIDTH, ALIGN_LEFT); 
        print_multichar_key("Shift", SHIFT_KEY_WIDTH, ALIGN_LEFT);
        print_end_of_key_row();
        print_blank_keys(1, SHIFT_KEY_WIDTH); // LShift
        print_blank_keys(KEYS_IN_ROW-(SHIFT_KEY_WIDTH/CHAR_KEY_WIDTH*2), CHAR_KEY_WIDTH);
        print_blank_keys(1, SHIFT_KEY_WIDTH); // RShift
        print_end_of_key_row();

        // row 5
        print_horizontal_frame_line();
        print_multichar_key("Ctrl", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_multichar_key("Supr", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_multichar_key("Alt", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_blank_keys(1, SPACE_KEY_WIDTH);
        print_multichar_key("Alt", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_multichar_key("Ctrl", WIDE_CHAR_KEY_WIDTH, ALIGN_LEFT);
        print_end_of_key_row();
        print_blank_keys(3, WIDE_CHAR_KEY_WIDTH); // LCtrl, Super, LAlt
        print_blank_keys(1, SPACE_KEY_WIDTH); // Space
        print_blank_keys(2, WIDE_CHAR_KEY_WIDTH); //RAlt, RCtrl
        print_end_of_key_row();

        // end
        print_horizontal_frame_line();
    }
}

static inline void print_horizontal_frame_line()
{
    for (int i=0; i<HLINE_LEN; i++)
    {
        printf("-");
    }
    printf("\n");
}

static inline void print_keys(const char* key_array, int width, int align)
{
    int karray_len = strlen(key_array);

    if (align == ALIGN_RIGHT)
    {
        for (int i=0; i<karray_len; i++)
        {
            printf("|");
            for (int j=0; j<width-1; j++)
            {
                printf(" ");
            }
            printf("%c", key_array[i]);
        }
    }

    else // default: left-aligned
    {
        for (int i=0; i<karray_len; i++)
        {
            printf("|");
            printf("%c", key_array[i]);
            for (int j=0; j<width-1; j++)
            {
                printf(" ");
            }
        }
    }
}

static inline void print_multichar_key(const char* label_str, int width, int align)
{
    #ifdef DEBUG
    if (strlen(label_str) < width)
    {
        print_blank_keys(1, width);
    }
    #endif

    if (align == ALIGN_RIGHT)
    {
        printf("|");
        for (int i=width-strlen(label_str); i>0; i--)
        {
            printf(" ");
        }
        printf("%s", label_str);
    }
    else
    {
        printf("|%s", label_str);
        for (int i=width-strlen(label_str); i>0; i--)
        {
            printf(" ");
        }
    }
}

static inline void print_blank_keys(int length, int width)
{
    for (int i=0; i<length; i++)
    {
        printf("|");
        for (int j=0; j<width; j++)
        {
            printf(" ");
        }
    }
}

static inline void print_end_of_key_row()
{
    printf("|\n");
}

int main()
{
    print_osk();
    return 0;
}