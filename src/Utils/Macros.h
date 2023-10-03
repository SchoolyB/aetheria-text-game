#ifndef MACROS_H
#define MACROS_H
#include <string.h>

// This macro is used to make sure the user enters a valid decision
#define MAKE_VALID_DECISION printf("Please make a valid decision\n")

// This macro is used to check if the user input is yes
#define IS_YES(param) (strcmp(param, "y") == 0 || strcmp(param, "Y") == 0 || \
                       strcmp(param, "yes") == 0 || strcmp(param, "Yes") == 0)

// This macro is used to check if the user input is no
#define IS_NO(param) (strcmp(param, "n") == 0 || strcmp(param, "N") == 0 || \
                      strcmp(param, "no") == 0 || strcmp(param, "No") == 0)

//! IMPORTANT ! This macro is used to remove the newline character from the input
#define REMOVE_NEWLINE_CHARACTER(param)    \
  do                                       \
  {                                        \
    size_t len = strlen(param);            \
    if (len > 0 && param[len - 1] == '\n') \
    {                                      \
      param[len - 1] = '\0';               \
    }                                      \
  } while (0)
// the next 4 macros are used to check if the user input is a valid choice for the skill point allocation
#define CHOOSE_STRENGTH(param)(strcmp(param, "1") == 0 || strcmp(param, "strength") == 0 ||\
strcmp(param, "str") == 0 )
#define CHOOSE_INTELLIGENCE(param)(strcmp(param, "2") == 0 || strcmp(param, "intelligence") == 0 || \
strcmp(param, "int") == 0 )
#define CHOOSE_DEXTERITY(param)(strcmp(param, "3") == 0 || strcmp(param, "dexterity") == 0 || \
strcmp(param, "dex") == 0 )
#define CHOOSE_LUCK(param)(strcmp(param, "4") == 0 || strcmp(param, "luck") == 0 || \
strcmp(param, "lck") == 0 )


#define ALLOCATE_TO_SKILL(skill, amount, skill_point_pool, param) \
    do { \
        printf("How many points would you like to allocate to "); \
        if (strcmp(skill, "Strength") == 0) { \
            printf("\x1b[31m%s\x1b[0m", skill); /* Make "Strength" red */ \
        } else if (strcmp(skill, "Intelligence") == 0) { \
            printf("\x1b[34m%s\x1b[0m", skill); /* Make "Intelligence" blue */ \
        } else if (strcmp(skill, "Dexterity") == 0) { \
            printf("\x1b[35m%s\x1b[0m", skill); /* Make "Dexterity" green */ \
        } else if (strcmp(skill, "Luck") == 0) { \
            printf("\x1b[32m%s\x1b[0m", skill); /* Make "Luck" purple */ \
        } else { \
            printf("%s", skill); /* Print other skills in default color */ \
        } \
        printf("?\n"); \
        scanf("%d", &amount); \
        if (amount > skill_point_pool) { \
            printf("You do not have enough points to allocate that many to %s. Please try again\n", skill); \
        } else if (amount < 0) { \
            printf("Invalid input. Please enter a valid number of points.\n"); \
        } else if (amount > 4) { \
            printf("You can only allocate 4 points to a skill area at this time. Please try again\n"); \
        } else if (amount >= 1 && amount <= 4) { \
            param = param + amount; \
            skill_point_pool = skill_point_pool - amount; \
            break; /* Exit the loop on successful allocation */ \
        } else { \
            printf("Invalid input. Please enter a valid number of points.\n"); \
        } \
    } while (1); /* Continue the loop until a valid allocation is made */


// simple the code for the skill point allocation
#define PRINT_REMAINING_POINTS(param) printf("You have %d points left to allocate.\n", param)
// this macro is used in the RootCommandLine.c & InGameCommandLine.c files to check if the user input is a valid command
#define MAX_INPUT_LENGTH 100

//=========================COMMAND LINE MACROS=========================//
#define IS_RESTART_COMMAND(param)(strcmp(param, "/restart")== 0)
#define IS_EXIT_COMMAND(param)(strcmp(param, "/exit") == 0 || strcmp(param, "/quit") == 0)
#define IS_ROOT_COMMANDS_COMMAND(param)(strcmp(param, "/commands") == 0)
#define IS_IN_GAME_COMMANDS_COMMAND(param)(strcmp(param, "/commands") == 0)
#define IS_GAME_COMMAND(param)(strcmp(param, "/game") == 0)
#define IS_INFO_COMMAND(param)(strcmp(param, "/info") == 0)
#define IS_CLEAR_COMMAND(param)(strcmp(param, "/clear") == 0)
#define IS_WRITE_NOTE_COMMAND(param)(strcmp(param, "/nw") == 0 || strcmp(param, "/write") == 0)
#define IS_READ_NOTES_COMMAND(param)(strcmp(param, "/nr") == 0 || strcmp(param, "/read") == 0)
#define IS_CLEAR_NOTES_COMMAND(param)(strcmp(param, "/nc") == 0)
//=========================COMMAND LINE MACROS=========================//



//=========================COMBAT MACROS=========================//

#define PLAYER_IS_DEAD(param)(param <= 0)
#define ENEMY_IS_DEAD(param)(param <= 0)

//=========================COMBAT MACROS=========================//

// this macro is used to open and write to the log file 
#define CREATE_LOG_FILE(variable, filename) \
  FILE *variable = fopen(filename, "a"); \
  if (variable == NULL) \
  { \
    perror("Error opening the log file"); \
    exit(1); \
  }




//=========================STORY MACROS=========================//

#define STR_CMP(input, string)(strcmp(input, string) == 0)



#define READ_FULL_TXT_FILE(fileName) \
    do { \
        FILE *file = fopen(fileName, "r"); \
        if (file == NULL) { \
            perror("Error opening the file"); \
            return 1; \
        } \
        char buffer[100]; \
        while (fgets(buffer, sizeof(buffer), file) != NULL) { \
            for (int i = 0; buffer[i] != '\0'; i++) { \
                putchar(buffer[i]); \
                fflush(stdout); \
                usleep(40000); \
            } \
        } \
        printf("\n"); \
        fclose(file); \
    } while(0)
    
#define PRINT_SLOWLY(str, delayMicroseconds) \
    do { \
        for (int i = 0; i < strlen(str); i++) { \
            putchar(str[i]); \
            fflush(stdout); \
            usleep(delayMicroseconds); \
        } \
    } while(0)

#endif