#ifndef ON_SCREEN_KEYBOARD_H
#define ON_SCREEN_KEYBOARD_H

/*
    print_osk:
        prints the cangjie keyboard layout on the console.
*/
void print_osk();

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
static inline void print_keys(const char* key_array, int width, int align);

/*
    print_multchar_key:
        Print a key whose label is not merely a character.
        e.g. Backspace, tab, Enter...
        Does not support print multiple keys.
*/
static inline void print_multichar_key(const char* label_str, int width, int align);

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

#endif