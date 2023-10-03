#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../Utils/Functions/Escape.h"
#include "../Utils/Prototypes.h"
#include "../Utils/Macros.h"

char options[3][100];
char input[100];

int ch0_Prompt_0() {
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

    if(STR_CMP(input, "1")){
       READ_FULL_TXT_FILE("Stories/ch0_1.txt"); 
         
       ch0_Prompt0_Opt1();
    }
    else if(STR_CMP(input, "2")){
        READ_FULL_TXT_FILE("Stories/ch0_2.txt");
    }
    else if(STR_CMP(input, "3")){
        READ_FULL_TXT_FILE("Stories/ch0_3.txt");
    }
    else {
        printf("Invalid input\n");
        ch0_Prompt_0();
    }
   
    
    return 0;
}

int ch0_Prompt0_Opt1(){
    char input[100];
    char options[3][100] = {
        "1: Open the door",
        "2: Tell them to go away",
        "3: Say nothing"};
        for(int i = 0 ; i < 3; i++) {
            printf("%s\n", options[i]);
        }
        fgets(input, sizeof(input), stdin);
        REMOVE_NEWLINE_CHARACTER(input);
    
        if(STR_CMP(input, "1")){
            READ_FULL_TXT_FILE("Stories/ch0_01.txt");
        }
        else if(STR_CMP(input, "2")){
            // READ_FULL_TXT_FILE("Stories/ch0_02.txt");
        }
        else if(STR_CMP(input, "3")){
            // READ_FULL_TXT_FILE("Stories/ch0_03.txt");
        }
        else {
            printf("Invalid input\n");
            ch0_Prompt0_Opt1();
        }
}


// Keep this function at the bottom of the file
//======================================================================================================//
void start_ch0() {
  READ_FULL_TXT_FILE("Stories/introduction.txt");
    ch0_Prompt_0();
}
