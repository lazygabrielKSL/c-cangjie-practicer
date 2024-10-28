#include "../include/cj_keymapping.h"

static cj_keymapping cjk_row1[NKEYS_R1];
static cj_keymapping cjk_row2[NKEYS_R2];
static cj_keymapping cjk_row3[NKEYS_R3];
static cj_keymapping cjk_row4[NKEYS_R4];
static cj_keymapping cjk_row5[NKEYS_R5];
cj_keymapping* cjk_keymap[] = {cjk_row1, cjk_row2, cjk_row3, cjk_row4, cjk_row5};
const int cjk_row_nkeys[] = {NKEYS_R1, NKEYS_R2, NKEYS_R3, NKEYS_R4, NKEYS_R5};

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
    []手田水口廿卜山戈人心[]
    []日尸木火土竹十大中;'\[]
    []重難金女月弓一,./[]
*/
static const wchar_t* label_upper_row1[] = {L"~", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"0", L"-", L"=", L"Bckspce"};
static const wchar_t* label_upper_row2[] = {L"Tab", L"Q", L"W", L"E", L"R", L"T", L"Y", L"U", L"I", L"O", L"P", L"{", L"}", L"Enter"};
static const wchar_t* label_upper_row3[] = {L"Caps", L"A", L"S", L"D", L"F", L"G", L"H", L"J", L"K", L"L", L":", L"\"", L"|", L" "};
static const wchar_t* label_upper_row4[] = {L"Shift", L"Z", L"X", L"C", L"V", L"B", L"N", L"M", L"<", L">", L"?", L"Shift"};
static const wchar_t* label_upper_row5[] = {L"Ctrl", L"Super", L"Alt", L" ", L"Alt", L"Ctrl"};
static const wchar_t** label_upper[] = {label_upper_row1, label_upper_row2, label_upper_row3, label_upper_row4, label_upper_row5};

static const wchar_t label_lower_row1[] = {WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL};
static const wchar_t label_lower_row2[] = {WCHAR_NULL, L'手', L'田', L'水', L'口', L'廿', L'卜', L'山', L'戈', L'人', L'心', WCHAR_NULL, WCHAR_NULL, WCHAR_NULL};
static const wchar_t label_lower_row3[] = {WCHAR_NULL, L'日', L'尸', L'木', L'火', L'土', L'竹', L'十', L'大', L'中', WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL};
static const wchar_t label_lower_row4[] = {WCHAR_NULL, L'重', L'難', L'金', L'女', L'月', L'弓', L'一', WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL};
static const wchar_t label_lower_row5[] = {WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL, WCHAR_NULL};
static const wchar_t* label_lower[] = {label_lower_row1, label_lower_row2, label_lower_row3, label_lower_row4, label_lower_row5};

static const int key_width_row1[] = {CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH*2};
static const int key_width_row2[] = {WIDE_CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, WIDE_CHAR_KEY_WIDTH};
static const int key_width_row3[] = {CHAR_KEY_WIDTH*2, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH};
static const int key_width_row4[] = {SHIFT_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, CHAR_KEY_WIDTH, SHIFT_KEY_WIDTH};
static const int key_width_row5[] = {WIDE_CHAR_KEY_WIDTH, WIDE_CHAR_KEY_WIDTH, WIDE_CHAR_KEY_WIDTH, SPACE_KEY_WIDTH, WIDE_CHAR_KEY_WIDTH, WIDE_CHAR_KEY_WIDTH};
static const int* key_width[] = {key_width_row1, key_width_row2, key_width_row3, key_width_row4, key_width_row5};

void initialize_keymap()
{
    for (int i=0; i<NROLS; i++)
    {
        for (int j=0; j<cjk_row_nkeys[i]; j++)
        {
            wcscpy(cjk_keymap[i][j].label_upper, label_upper[i][j]);
            cjk_keymap[i][j].label_lower = label_lower[i][j];
            cjk_keymap[i][j].key_width = key_width[i][j];
            cjk_keymap[i][j].frame_color = FC_WHITE;
        }
    }
}

int change_key_frame_color(cj_keymapping key, int color)
{
    switch (color)
    {
    case FC_WHITE:
        break;
    case FC_GREEN:
        break;
    case FC_RED:
        break;   
    default:
        return -1;
    }
    key.frame_color = color;
    return color;
}