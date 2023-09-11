#include <stdio.h>
#include <unistd.h> // for usleep
#include <string.h> // for strlen
#include <time.h> // for time
#include <stdbool.h>

int escape(){
    bool escaped;
    char input[10];
    char* options[] = {"Run", "Fight"}; // Replace "Second Option" with your actual second option
    
    printf("What will you do?\n");
    for (int i = 0; i < 2; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }

    fgets(input, sizeof(input), stdin);

    // Remove the trailing newline character from the input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (strcmp(input, "1") == 0 ||
        strcmp(input, "Run") == 0 ||
        strcmp(input, "run") == 0) {
        srand(time(NULL)); // Initialize random seed
        int chance = rand() % 2; //50% chance
        if (chance == 1) {
            printf("You escaped!\n");
            escaped = true;
        }
        else {
            printf("You failed to escape!\n");
            escaped = false;
        }
    }
}