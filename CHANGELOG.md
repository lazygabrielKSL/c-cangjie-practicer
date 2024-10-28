# 20241028

## 20241028-1

- Moved `.c` files into `src`, and `.h` files into `include`.

- Prepared `osk` for frame color support. (Thoroughly revamped printing logic.)

    - Upper and lower labels are handled by the same function.

    - H-lines printing is now key-status-aware.

- Made keymapping a independent source file. (It was a part of `osk` before.) 

## 20241028-2

- `generate_lesson`

    - Generates an array of string. Chinese chars have not been supported yet.
    
    - Supports lesson printing: `ex. rrrr-rr-rrrrr`.

    - Needs to free memory allocation via `free_lesson()` for each lesson after use.

# 20241027

- Implemented on screen keyboard (`osk`) with full layout.

- Pseudo code in `main.c`