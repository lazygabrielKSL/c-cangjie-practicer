#include "../include/on_screen_keyboard.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "zh_TW.UTF-8");
    print_osk();

    // while(1):

        // settings = load_settings(path);
            // config file should have:
            // int radicals_per_generation;
            // double target_typing_speed;
        // fclose(settings);

        // profile = load_profile(path);
            // profile should have:
            // int radicals_unlocked;
            // double radicals_per_minute[];
        // fclose(profile);

        // mode = select_options();
        // switch(mode):
            // case == GAME:
                // while (1):
                    // radicals = generate_random_radicals(radicals_per_generation, radicals_unlocked, radicals_per_minute);
                    // print_generated_radicals(radicals);
                    
                    // for (radical in radicals):
                        // timer_start();
                        // get_input();
                        // while (!input_correct):
                            // if (input == HOTKEY_EXIT):
                                // break;
                            // if (input == HOTKEY_VIEW_PROFILE):
                                // save_profile();
                                // print_typing_profile();
                            // indicate_wrong_input();
                            // get_input();
                        // timer_stop();
                        // update_rpm(radicals_per_minute[radical], timer);
                    
                    // if (radicals_unlocked <= 26):
                        // if (radicals_per_minute[radicals_unclocked+1] > target_typing_speed):
                            // radicals_unlocked ++;
                    
                    // clear_lines_except_osk_from_terminal();

                // save_profile();
                // break;
            
            // case SETTINGS:
                // edit_settings(path);
                // break;
            
            // case QUIT:
                // return 0;

    return 0;
}