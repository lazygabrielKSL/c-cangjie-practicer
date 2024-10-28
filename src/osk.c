#include "../include/osk.h"
#include <locale.h>

/* static function prototypes */
/*
    print_horizontal_frame_line:
        Prints a horizontal line covering a row of keys like this: ---
        Length of - is decided by key_width + HLINE_OFFSET (def in header).
        *Unimplemented feature:*
        *The color of - is decided by the frame color of the corresponding key.*
*/
static void print_horizontal_frame_line(int row_index);

/*
    print_row:
        Prints the specified row of key.
        Horizontal lines are not included.
        *Color support has not been implemented yet*
*/
static void print_row(const int row_index);

void print_osk()
{
    for (int i=0; i<NROLS; i++)
    {
        print_horizontal_frame_line(i);
        print_row(i);
    }
    print_horizontal_frame_line(NROLS);
}

static void print_horizontal_frame_line(int row_index)
{
    row_index = (row_index >= NROLS) ? NROLS-1 : row_index;
    for (int i=0; i<cjk_row_nkeys[row_index]; i++)
    {
        for (int j=0; j<cjk_keymap[row_index][i].key_width + HLINE_OFFSET; j++)
        {
            wprintf(L"-");
        }
    }
    wprintf(L"-\n");
}

static void print_row(const int row_index)
{
    cj_keymapping* key = NULL;
    // print upper
    for (int i=0; i<cjk_row_nkeys[row_index]; i++)
    {
        key = &cjk_keymap[row_index][i];
        wprintf(L"|%ls", key->label_upper);
        for (int j=0; j<key->key_width-wcslen(key->label_upper); j++)
        {
            wprintf(L" ");
        }
    }
    wprintf(L"|\n");
    //print lower
    for (int i=0; i<cjk_row_nkeys[row_index]; i++)
    {
        key = &cjk_keymap[row_index][i];
        wprintf(L"|");
        for (int j=0; j<key->key_width-(key->label_lower?2:0); j++)
        {
            wprintf(L" ");
        }
        wprintf(L"%lc", key->label_lower);
    }
    wprintf(L"|\n");
}

#define DEBUG_OSK
#ifdef DEBUG_OSK
int main ()
{
    setlocale(LC_ALL, "zh_TW.UTF-8");
    initialize_keymap();
    print_osk();
    return 0;
}
#endif