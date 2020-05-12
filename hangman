#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "ascii.c"

int lines_num(FILE *file);

int printIndex(char *str, char *s);

int main(void)
{
    char *modes[3] = { "animals.txt", "englit.txt", "hardwords.txt" };

    printf("%s\n", text);

    printf("Welcome to hangman. Choose your category: \n");
    printf("Animals\nLiterature\nDifficult\n");

    char category[20];
    int chances = 6;
    scanf("%s", category);

    FILE *inptr;

    if (strncmp(category, "Ani", 7) == 0) {
        inptr = fopen("animals.txt", "r");
    } else if (strncmp(category, "Lit", 18) == 0) {
        inptr = fopen("englit.txt", "r");
    } else if (strncmp(category, "Diff", 15) == 0) {
        inptr = fopen("hardwords.txt", "r");
    } else {
        fprintf(stderr, "Error. Please choose one of the categories listed.");
        return 1;
    }

    int number_of_lines = lines_num(inptr);

    if (inptr == NULL)
    {
        fprintf(stderr, "There was an error.\n");
        return 2;
    }

    char temp_word[80];
    char word[50];

    srand(time(0));
    int rand_num = rand() % number_of_lines;

    fseek(inptr, 0, SEEK_SET);

    for (int i = 0; i <= number_of_lines + 1; i++)
    {
        fseek(inptr, 0, SEEK_CUR);

        if (i == rand_num)
        {
            strcpy(word, temp_word);
            break;
        }

        fgets(temp_word, 70, inptr);

    }

    printf("%s", pics[chances]);
    chances--;

    char guess_word[70] = "";

    for (int j = 0, n = strlen(word); j < n; j++)
    {
        if (isalpha(word[j]))
        {
            strcat(guess_word, "_");
        }
        else
        {
            strcat(guess_word, " ");
        }
    }

    printf("%s\n", guess_word);

    char input[2];
    while (strcmp(word, guess_word) != 0)
    {
        printf("Enter a letter to guess: (case-insensitive)\n");
        scanf("%s", input);

        char * pch;

        pch = strcasestr(word, input);

        while (pch != NULL)
        {
            pch = strcasestr(pch+1,input);
        }

        for (int i = 0; i < strlen(word); i++)
        {
            if (tolower(word[i]) == input[0])
            {
                if (guess_word[i] == input[0])
                {
                    printf("Already guessed.\n");
                }
                guess_word[i] = word[i];
                printf("%s\n", guess_word);
            } else if (chances >= 1 && strcasestr(word, input) == NULL) {
                chances--;
                printf("%s", pics[chances]);
                printf("Incorrect. You have %i chances left.\n", chances + 1);
                break;
            } else if (chances <= 1) {
                printf("You are out of chances. Try again.\n");
                return 0;
            }
        }
    }

    return 0;
}

int lines_num(FILE *file) {
    int ch;
    int number_of_lines = 0;

    while (EOF != (ch=getc(file)))
    {
        if ('\n' == ch)
        {
            ++number_of_lines;
        }
    }

    return number_of_lines;
}
