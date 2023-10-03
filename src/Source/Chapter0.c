#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../Utils/Functions/Escape.h"
#include "../Utils/Prototypes.h"
#include "../Utils/Macros.h"

#define GO_SEE_COMMOTION printf("You should make your way to the main deck to see what all the commotion is about.\n");

char options[3][100];
char input[100];

int ch0_wake_up() {
    char options[3][100] = {
        "1: Go to main deck",
        "2: Try to go back to sleep",
        "3: Go look at the mirror on the wall"
    };
    for(int i = 0 ; i < 3; i++) {
        printf("%s\n", options[i]);
    }

    fgets(input, sizeof(input), stdin);
    REMOVE_NEWLINE_CHARACTER(input);

// THE CORRECT WAY TO GO TO PROGRESS TO THE NEXT PART OF THE STORY
    if(STR_CMP(input, "1")){
       READ_FULL_TXT_FILE("Stories/ch0_1.txt"); 
       ch0_go_to_main_deck();
    }
    // DOESNT PROGRESS TO THE NEXT PART OF THE STORY
    else if(STR_CMP(input, "2")){
      printf("You try to go back to sleep. The moment you begin to doze off you are awoken by the sound of the crew yeling 'land ho!'.\n");
	  GO_SEE_COMMOTION;
      char input[100];
        printf("What do you do?\n");
        printf("1: Go to main deck\n");
        printf("2: Go look at the mirror on the wall\n");
        REMOVE_NEWLINE_CHARACTER(input);
        fgets(input, sizeof(input), stdin);
        if(STR_CMP(input, "1")){
            READ_FULL_TXT_FILE("Stories/ch0_1.txt");
            ch0_go_to_main_deck();
        }
        else if(STR_CMP(input, "2")){
            printf("You go look at the mirror");
			printf("You walk over to the wall and take a look in the small mirror. ALthough the mirror may be small you can still visibly see how ugly you are.\n");
			printf("A face only a mother could love indeed...As you continue to find more and more flaws with your ugly face you hear someone knocking on the door.\n");
			GO_SEE_COMMOTION;
            READ_FULL_TXT_FILE("Stories/ch0_1.txt");
            ch0_go_to_main_deck();
            }
        else {
            printf("Invalid input\n");
            ch0_wake_up();
        }
      }
    //   DOESNT PROGRESS TO THE NEXT PART OF THE STORY
    else if(STR_CMP(input, "3")){
        char input[100];
         printf("You go look at the mirror");
        printf("Better go up to the main deck to see what all the commotion is about\n");
        printf("What do you do?\n");
        fgets(input, sizeof(input), stdin);
        REMOVE_NEWLINE_CHARACTER(input);
        if(STR_CMP(input, "1")){
            READ_FULL_TXT_FILE("Stories/ch0_1.txt");
            ch0_go_to_main_deck();
        }
        else if(STR_CMP(input, "2")){
            printf("Try to go to sleep");
            printf("You try to fgo to sleep...The moment that you begin to doze off you shoot awake to the sounds of the crew yelling 'land ho!'.'\n");
            GO_SEE_COMMOTION();
            READ_FULL_TXT_FILE("Stories/ch0_1.txt");
            ch0_go_to_main_deck();
            }
        else {
            printf("Invalid input\n");
            ch0_wake_up();
        }
    }
    else {
        printf("Invalid input\n");
        ch0_wake_up();
    }
    return 0;
}

//=====================================================================================================//
void  ch0_go_to_main_deck(){
    char input[100];
    READ_FULL_TXT_FILE("Stories/ch0_1txt");
    printf("What do you do?");
    //TODO KEEP WORKING ON THIS
	
}

// Keep this function at the bottom of the file
//======================================================================================================//
void start_ch0() {
  READ_FULL_TXT_FILE("Stories/introduction.txt");
    ch0_wake_up();
}
