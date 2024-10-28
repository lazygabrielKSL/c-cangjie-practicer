#include "../include/generate_lesson.h"
#include <time.h> // for srand(time(NULL));
#include <stdlib.h> // for srand(), rand(), malloc()
#include <stdio.h> // for printf()

/*
日月金木水火土
竹戈十大中一弓
人心手口
尸廿山女田卜
難重
*/

const char* unlockable = "mbhoinrtfylujdksegvcpawqxz"; // ordered by frequency

char** generate_lesson(const int words_per_gen, const int rads_unlocked)
{
    srand(time(NULL));
    char** lesson = malloc(sizeof(char*) * words_per_gen);
    if (lesson == NULL)
    {
        return NULL;
    }

    for (int w=0; w<words_per_gen; w++)
    {
        int rads_in_this_word = rand()%5 + 1; // Should not be uniform dist.!!! Impl. this later.
        char* this_word = malloc(sizeof(char) * (rads_in_this_word+1));
        if (this_word == NULL)
        {
            return NULL;
        }
        for (int r=0; r<rads_in_this_word; r++)
        {
            this_word[r] = unlockable[rand()%rads_unlocked]; // Should not be uniform dist.!!! Impl. this later.
        }
        this_word[rads_in_this_word] = '\0';
        lesson[w] = this_word;
    }
    return lesson;
}

int free_lesson(char** lesson, const int words_in_lesson)
{
    for (int w=0; w<words_in_lesson; w++)
    {
        free(lesson[w]);
    }
    free(lesson);
    return 0;
}

void print_lesson(char** lesson, const int words_in_lesson)
{
    for (int i=0; i<words_in_lesson-1; i++)
    {
        printf("%s-", lesson[i]);
    }
    printf("%s\n", lesson[words_in_lesson-1]);
}

#define DEBUG_GEN
#ifdef DEBUG_GEN
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "zh_TW.UTF-8");
    char** lesson = generate_lesson(3, 5);
    print_lesson(lesson, 3);
    free_lesson(lesson, 3);
    return 0;
}
#endif