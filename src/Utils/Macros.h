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

//this macro will add whatever number the suer enters for a skill,,,amount is user input, param is the skill, num is either 1,2,3,4. All skills cap @ 4
#define ALLOCATION(amount, skill, param, num) \
    if (amount == num) { \
        param = param + num; \
        printf("%d Points put into %s \n", param, skill); \
    }

//this macro supports the one above
#define ALLOCATION_LIMIT_CHECK(amount, param, skill_pool, str, int, dex, lck) \
    if (amount > 4) { \
        printf("You can only allocate 4 points to a skill area at this time. Please try again\n"); \
        skill_pool = 10; \
        str = 0; \
        int = 0; \
        dex = 0; \
        lck = 0; \
        initialSKillPointAllocation(); \
    }
// simple the code for the skill point allocation
#define PRINT_REMAINING_POINTS(param) printf("You have %d points left to allocate\n", param)
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


// this macro is used to open and write to the log file 
#define CREATE_LOG_FILE(variable, filename) \
  FILE *variable = fopen(filename, "a"); \
  if (variable == NULL) \
  { \
    perror("Error opening the log file"); \
    exit(1); \
  }


#endif