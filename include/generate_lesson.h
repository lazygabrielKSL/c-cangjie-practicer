#ifndef GENERATE_LESSON_H
#define GENERATE_LESSON_H

/*
    generate_lesson:
    Returns a random char string containing alphabets.
    Behavior depends on the arguments.
    Must call free_lesson() after using generated lesson.
    Returns NULL if malloc fails.
*/
char** generate_lesson(const int words_per_gen, const int rads_unlocked);
// To-do: generate lessons depend on rpm
// To-do: generate radicals depend on occurrence

/*
    free_lesson:
    MUST BE CALLED AFTER generate_lesson IS USED!!!
    Returns 0 if success.
*/
int free_lesson(char** lesson, const int words_in_lesson);

/*
    print_lesson:
    like this: rrrrr-rr-rrrr
*/
void print_lesson(char** lesson, const int words_in_lesson);
// To-do: print in CH char.

#endif