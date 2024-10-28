# 20241028

- Moved `.c` files into `src`, and `.h` files into `include`.

- Prepared `osk` for frame color support. (Thoroughly revamped printing logic.)

    - Upper and lower labels are handled by the same function.

    - H-lines printing is now key-status-aware.

- Made keymapping a independent source file. (It was a part of `osk` before.) 

# 20241027

- Implemented on screen keyboard (`osk`) with full layout.

- Pseudo code in `main.c`