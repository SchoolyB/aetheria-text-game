#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../Utils/Functions/Escape.h"
#include "../Utils/Prototypes.h"
#include "../Utils/Macros.h"

#define GO_SEE_COMMOTION printf("You should make your way to the main deck to see what all the commotion is about.\n");
#define WHAT_DO_YOU_DO printf("What do you do?\n");
#define INVALID_INPUT printf("Invalid input.\n");

char options[3][100];
char input[100];

//=============================================================================================//
void ch0_wake_up() {
    char options[3][100] = {
        "1: Go to main deck",
        "2: Try to go back to sleep",
        "3: Go look at the mirror on the wall"
    };
    for(int i = 0 ; i < 3; i++) {
        printf("%s\n", options[i]);
    }

    FGETS(input);
    REMOVE_NEWLINE_CHARACTER(input);

// THE CORRECT WAY TO GO TO PROGRESS TO THE NEXT PART OF THE STORY
    if(STR_CMP(input, "1")){
       READ_FULL_TXT_FILE("./Prompts/ch0_1.txt"); 
       ch0_go_to_door();
    }
    // DOESNT PROGRESS TO THE NEXT PART OF THE STORY
    else if(STR_CMP(input, "2")){
      printf("You try to go back to sleep. The moment you begin to doze off you are awoken by the sound of the crew yelling 'land ho!'.\n");
	  GO_SEE_COMMOTION;
      char input[100];
        WHAT_DO_YOU_DO;
        printf("1: Go to main deck\n");
        printf("2: Go look at the mirror on the wall\n");
        REMOVE_NEWLINE_CHARACTER(input);
        FGETS(input);
        if(STR_CMP(input, "1")){
            READ_FULL_TXT_FILE("./Prompts/ch0_1.txt");
            ch0_go_to_door();
        }
        else if(STR_CMP(input, "2")){
            printf("You go look at the mirror");
			printf("You walk over to the wall and take a look in the small mirror. ALthough the mirror may be small you can still visibly see how ugly you are.\n");
			printf("A face only a mother could love indeed...As you continue to find more and more flaws with your ugly face you hear someone knocking on the door.\n");
			GO_SEE_COMMOTION;
            READ_FULL_TXT_FILE("./Prompts/ch0_1.txt");
            ch0_go_to_door();
            }
        else {
            INVALID_INPUT;
            ch0_wake_up();
        }
      }
    //   DOESNT PROGRESS TO THE NEXT PART OF THE STORY
    else if(STR_CMP(input, "3")){
        char input[100];
         printf("You walk over to the wall and take a look in the small mirror. ALthough the mirror may be small you can still visibly see how ugly you are.\n");
			printf("A face only a mother could love indeed...As you continue to find more and more flaws with your ugly face you hear someone knocking on the door.\n");
        WHAT_DO_YOU_DO;
        printf("1: Go to main deck\n");
        printf("2: Try to go back to sleep\n");
        FGETS(input);
        REMOVE_NEWLINE_CHARACTER(input);
        if(STR_CMP(input, "1")){
            READ_FULL_TXT_FILE("./Prompts/ch0_1.txt");
            ch0_go_to_door();
        }
        else if(STR_CMP(input, "2")){
            printf("Try to go to sleep");
            printf("You try to fgo to sleep...The moment that you begin to doze off you shoot awake to the sounds of the crew yelling 'land ho!'.'\n");
            GO_SEE_COMMOTION;
            ch0_go_to_door();
            }
        else {
            INVALID_INPUT;
            ch0_wake_up();
        }
    }
    else {
        INVALID_INPUT;
        ch0_wake_up();
    }
}

//=====================================================================================================//
void  ch0_go_to_door(){
    char input[100];
    READ_FULL_TXT_FILE("./Prompts/ch0_1.txt");
    WHAT_DO_YOU_DO;
    printf("1: Ask him whats so funny.\n");
    printf("2: Acknoledege him and go to see the captain.\n");
    printf("3: Ignore him and try to make your way to the main deck.\n");
    FGETS(input);
    REMOVE_NEWLINE_CHARACTER(input);
    if(STR_CMP(input, "1")){
        char input[100];
        printf("You ask Lotsino what so funny...");
        printf("He stares at you intensely as if to itemidate you.");
        printf("'This is my first time seeing you this whole voyage.\n");
        printf("I heard talk about you but didnt realize you were so puney.'\n");
        sleep(1);
        printf("You take offense to the comment but realize there is little you can do about it");
        WHAT_DO_YOU_DO;
        
        FGETS(input);
        REMOVE_NEWLINE_CHARACTER(input);
        printf("1: Squeeze by Lotsino and make you way to the main deck.\n");
        printf("2: Squeeze by Lotsino and make your way to the captains quaters.\n");
        
        if(STR_CMP(input, "1" || "2")){
            ch0_leave_your_cabin();
            }
        else {
            INVALID_INPUT;
        }
    }
    //TODO KEEP WORKING ON THIS
	
}
//======================================================================================================//
void ch0_leave_your_cabin(){
    char input[100];
    printf("Which way do you go?\n");
    WHAT_DO_YOU_DO;
    printf("1: Go left");
    printf("2. Go Right");
    printf("3: Ask Lotsino which way you need to go.");
    FGETS(input);
    REMOVE_NEWLINE_CHARACTER(input);
    if(STR_CMP(input, "1")){
        ch0_go_left_in_front_of_lotsino();
    }
    else if(STR_CMP(input, "2")){
        printf("You turn to the right and look down the passageway and begin walking.\n");
        ch0_go_right_in_front_of_lotsino();
    }
    else if(STR_CMP(input, "3")){
        char input[100];
        ask_lotsino_for_directions();
        WHAT_DO_YOU_DO;
        printf("1: Go right\n");
        printf("2: Go left\n");
        printf("3: Ask Lotsino which way to go. \n");
        FGETS(input);
        REMOVE_NEWLINE_CHARACTER(input);
        if(STR_CMP(input, "1")){
            ch0_go_right_in_front_of_lotsino();
        }
        else if(STR_CMP(input, "2")){
            ch0_go_left_in_front_of_lotsino();
        }
        else if(STR_CMP(input, "3")){
            ask_lotsino_for_directions();
            ch0_leave_your_cabin();
        }
        else{
            INVALID_INPUT;
            ch0_leave_your_cabin();
        }
    }
    else {
        INVALID_INPUT;
        ch0_leave_your_cabin();
    }
}
//======================================================================================================//
void ch0_go_left_in_front_of_lotsino(){
    printf("You turn to the left and look down the passegway and begin walking.\n");
    printf("You as you take your first couple of steps you feel a heavy weight on your shoulder.\n");
    printf("You turn a round and see Lotsino's hand grabbing you\n");
    printf("Lotsino looks at you intensley and says...\n");
    printf("The captains quarters are not that way puney\n");
    printf("Lotsino then strongly turns you the other direction and gives you a slight push telling you to go\n");
}

//======================================================================================================//
void ch0_go_right_in_front_of_lotsino(){
 //do stuff   
}

//======================================================================================================//
void ask_lotsino_for_directions(){
    printf("You ask Lotsino which direction to go \n");
    printf("'To get to the captains quarters from you you need to take a right, then go up one level.\n");
    printf("The captains quaters are the only quaters on that level knock on the door you and he should allow you in.");
    printf("Dont go any levels higher until you speak witht the captain...'");
    printf("'GOT IT?!?!' Lotsino screams.");
    printf("Now go...");
}
// Keep this function at the bottom of the file
//======================================================================================================//
void start_ch0() {
    READ_FULL_TXT_FILE("./Prompts/introduction.txt");
    ch0_wake_up();
}
