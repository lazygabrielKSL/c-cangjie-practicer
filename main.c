#include "on_screen_keyboard.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "zh_TW.UTF-8");
    print_osk();
    return 0;
}