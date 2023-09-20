#include <stdio.h>
#include <unistd.h> // for usleep
#include <string.h> // for strlen
#include <time.h>   // for time
#include <stdbool.h>
#include "Escape.h"

bool escaped;

int escape()
{
    char input[10];
    char *options[] = {"Run", "Fight"};

    int chance = rand() % 2;
    printf("What will you do?\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%d. %s\n", i + 1, options[i]);
    }
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[--len] = '\0';
    }

    if (strcmp(input, "1") == 0 ||
        strcmp(input, "run") == 0 ||
        strcmp(input, "Run") == 0)
    {
        printf("You tried to run away.\n");
        if (chance == 0)
        {
            printf("You got away safely.\n");
            escaped = true;
            // Do something here
            return 0;
        }
        else
        {
            printf("You failed to get away.\n");
            escaped = false;
            // Do something here
            return 1;
        }
    }
    else if (strcmp(input, "2") == 0 ||
             strcmp(input, "fight") == 0 ||
             strcmp(input, "Fight") == 0)
    {
        printf("You decided to fight.\n");
        escaped = false;
    }
}
