#include <stdio.h>
#include <unistd.h> // for usleep
#include <string.h> // for strlen
#include <time.h> // for time
#include "../../../utils/Escape.c"
#include "../Prototypes/Chapter1.h"



int startChapter() {

    getEscapeDecision();
    return 0;
}

int getEscapeDecision(){
    char input[10];
    printf("What will you do?\n");
    fgets(input, sizeof(input), stdin);
    if (strcmp(input, "1") == 0 ||
        strcmp(input, "Run") == 0 ||
        strcmp(input, "run") == 0) {
            // printf("You chose to run!\n");
            // TODO figure out why this isnt working
            printf("TEST");
            // escape();
        }
        else if(strcmp(input, "2") == 0 ||
        strcmp(input, "Fight") == 0 ||
        strcmp(input, "fight") == 0) {
            printf("You chose to fight!\n");
            // Do something here;
        }
    return 0;
} 

