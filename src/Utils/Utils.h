#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#ifndef UTILS_H
#define UTILS_H

/*
This file is separated into several sections. The sections are labeled and ordered as follows:
1. Macros
2. Functions
3. Prototypes
4. Structs
5. Global Variables
*/

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF MACROS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
/*
The Macros section holds all macros used in the program. Macros are sorted in the following categories:
1. Common Macros - Commonly used in most files
2. Skill Point Macros - Macros used in the skill point system
3. Command line Macros - Macros used in the command line system
4. File/Logging Macros - Macros used in the file/logging system
*/

/*START OF COMMON MACROS*/

// Simple print macro used whenever the user doesn't make a valid decision
#define MAKE_VALID_DECISION printf("Please make a valid decision.\n")
//--------------------------------------------------------------------------------//

// Evaluates if the users input string is the word 'yes' or letter y
#define INPUT_IS_YES(param) (strcmp(param, "y") == 0 || strcmp(param, "Y") == 0 || \
                             strcmp(param, "yes") == 0 || strcmp(param, "Yes") == 0)
//--------------------------------------------------------------------------------//

// Evaluates if the users input string is the word 'no' or letter n
#define INPUT_IS_NO(param) (strcmp(param, "n") == 0 || strcmp(param, "N") == 0 || \
                            strcmp(param, "no") == 0 || strcmp(param, "No") == 0)
//--------------------------------------------------------------------------------//

// Removes the newline character from the end of the users input string. This is needed for all fgets() calls
#define REMOVE_NEWLINE_CHAR(param)         \
  do                                       \
  {                                        \
    size_t len = strlen(param);            \
    if (len > 0 && param[len - 1] == '\n') \
    {                                      \
      param[len - 1] = '\0';               \
    }                                      \
  } while (0)
//--------------------------------------------------------------------------------//

// Cleaner way to call the fgets() function
#define FGETS(param) (fgets(param, sizeof(param), stdin))
//--------------------------------------------------------------------------------//

// Cleaner way to evaluate the users input string
#define STR_CMP(input, string) (strcmp(input, string) == 0)
//--------------------------------------------------------------------------------//

// CHANGE TEXT IN TERMINAL
//  The 'color' param should be a number between 31 and 36
//  The 'str' param should be the string you want to modify
#define MAKE_RED(str) printf("\x1b[31m%s\x1b[0m", str)
#define MAKE_BLUE(str) printf("\x1b[34m%s\x1b[0m", str)
#define MAKE_GREEN(str) printf("\x1b[32m%s\x1b[0m", str)
#define MAKE_PURPLE(str) printf("\x1b[35m%s\x1b[0m", str)
#define MAKE_YELLOW(str) printf("\x1b[33m%s\x1b[0m", str)
#define MAKE_CYAN(str) printf("\x1b[36m%s\x1b[0m", str)

#define MAKE_BOLD(str) printf("\x1b[1m%s\x1b[0m", str)
#define MAKE_UNDERLINED(str) printf("\x1b[4m%s\x1b[0m", str)
#define MAKE_BLINK(str) printf("\x1b[5m%s\x1b[0m", str)
#define MAKE_REVERSED(str) printf("\x1b[7m%s\x1b[0m", str)

#define MAKE_BOLD_N_UNDERLINED(str) printf("\x1b[1;4m%s\x1b[0m", str)
#define MAKE_BOLD_N_BLINK(str) printf("\x1b[1;5m%s\x1b[0m", str)
#define MAKE_BOLD_N_REVERSED(str) printf("\x1b[1;7m%s\x1b[0m", str)

#define MAKE_BOLD_N_COLOR(str, color) printf("\x1b[1;%dm%s\x1b[0m", color, str)
#define MAKE_UNDERLINED_N_COLOR(str, color) printf("\x1b[4;%dm%s\x1b[0m", color, str)
#define MAKE_BLINK_N_COLOR(str, color) printf("\x1b[5;%dm%s\x1b[0m", color, str)
#define MAKE_REVERSED_N_COLOR(str, color) printf("\x1b[7;%dm%s\x1b[0m", color, str)
//--------------------------------------------------------------------------------//
// Prints a string slowly to the terminal
#define PRINT_SLOWLY(str, delayMicroseconds) \
  do                                         \
  {                                          \
    for (int i = 0; i < strlen(str); i++)    \
    {                                        \
      putchar(str[i]);                       \
      fflush(stdout);                        \
      usleep(delayMicroseconds);             \
    }                                        \
    putchar('\n');                           \
  } while (0)
//--------------------------------------------------------------------------------//

// Read from a text file and print it to the terminal
#define READ_FULL_TXT_FILE(fileName)                    \
  do                                                    \
  {                                                     \
    FILE *file = fopen(fileName, "r");                  \
    if (file == NULL)                                   \
    {                                                   \
      perror("Error opening the file");                 \
      return 1;                                         \
    }                                                   \
    char buffer[100];                                   \
    while (fgets(buffer, sizeof(buffer), file) != NULL) \
    {                                                   \
      for (int i = 0; buffer[i] != '\0'; i++)           \
      {                                                 \
        putchar(buffer[i]);                             \
        fflush(stdout);                                 \
        usleep(40000);                                  \
      }                                                 \
    }                                                   \
    printf("\n");                                       \
    fclose(file);                                       \
  } while (0)
//--------------------------------------------------------------------------------//
// List items from an array
#define PRINT_LIST_ITEMS(num, arr) \
  do                               \
  {                                \
    for (int i = 0; i < num; i++)  \
    {                              \
      printf("%s\n", arr[i]);      \
    }                              \
  } while (0)
//--------------------------------------------------------------------------------//

/*
END OF COMMON MACROS
|
|
|
|
|
|
|
|
|
|
START OF SKILL POINT MACROS
*/
#define CHOOSE_STRENGTH(param) (strcmp(param, "1") == 0 || strcmp(param, "strength") == 0 || \
                                strcmp(param, "str") == 0)
#define CHOOSE_INTELLIGENCE(param) (strcmp(param, "2") == 0 || strcmp(param, "intelligence") == 0 || \
                                    strcmp(param, "int") == 0)
#define CHOOSE_DEXTERITY(param) (strcmp(param, "3") == 0 || strcmp(param, "dexterity") == 0 || \
                                 strcmp(param, "dex") == 0)
#define CHOOSE_LUCK(param) (strcmp(param, "4") == 0 || strcmp(param, "luck") == 0 || \
                            strcmp(param, "lck") == 0)

#define ALLOCATE_TO_SKILL(skill, amount, skill_point_pool, param)                                     \
  do                                                                                                  \
  {                                                                                                   \
    printf("How many points would you like to allocate to ");                                         \
    if (strcmp(skill, "Strength") == 0)                                                               \
    {                                                                                                 \
      MAKE_RED(skill);                                                                                \
    }                                                                                                 \
    else if (strcmp(skill, "Intelligence") == 0)                                                      \
    {                                                                                                 \
      MAKE_BLUE(skill);                                                                               \
    }                                                                                                 \
    else if (strcmp(skill, "Dexterity") == 0)                                                         \
    {                                                                                                 \
      MAKE_PURPLE(skill);                                                                             \
    }                                                                                                 \
    else if (strcmp(skill, "Luck") == 0)                                                              \
    {                                                                                                 \
      MAKE_GREEN(skill);                                                                              \
    }                                                                                                 \
    else                                                                                              \
    {                                                                                                 \
      printf("%s", skill); /* Print other skills in default color */                                  \
    }                                                                                                 \
    printf("?\n");                                                                                    \
    scanf("%d", &amount);                                                                             \
    if (amount > skill_point_pool)                                                                    \
    {                                                                                                 \
      printf("You do not have enough points to allocate that many to %s. Please try again\n", skill); \
    }                                                                                                 \
    else if (amount < 0)                                                                              \
    {                                                                                                 \
      printf("Invalid input. Please enter a valid number of points.\n");                              \
    }                                                                                                 \
    else if (amount > 4)                                                                              \
    {                                                                                                 \
      printf("You can only allocate 4 points to a skill area at this time. Please try again\n");      \
    }                                                                                                 \
    else if (amount >= 1 && amount <= 4)                                                              \
    {                                                                                                 \
      param = param + amount;                                                                         \
      skill_point_pool = skill_point_pool - amount;                                                   \
      break; /* Exit the loop on successful allocation */                                             \
    }                                                                                                 \
    else                                                                                              \
    {                                                                                                 \
      printf("Invalid input. Please enter a valid number of points.\n");                              \
    }                                                                                                 \
  } while (1); /* Continue the loop until a valid allocation is made */

#define PRINT_REMAINING_POINTS(param) printf("You have %d points left to allocate.\n", param)
//--------------------------------------------------------------------------------//
/*
END OF SKILL POINT MACROS
|
|
|
|
|
|
|
|
|
|
START OF COMMAND LINE MACROS
*/
// The 'param' param should be the users input string
#define IS_RESTART_COMMAND(param) (strcmp(param, "/restart") == 0)
#define IS_EXIT_COMMAND(param) (strcmp(param, "/exit") == 0 || strcmp(param, "/quit") == 0)
#define IS_COMMANDS_COMMAND(param) (strcmp(param, "/commands") == 0)
#define IS_GAME_COMMAND(param) (strcmp(param, "/game") == 0)
#define IS_INFO_COMMAND(param) (strcmp(param, "/info") == 0)
#define IS_CLEAR_COMMAND(param) (strcmp(param, "/clear") == 0)
#define IS_WRITE_NOTE_COMMAND(param) (strcmp(param, "/nw") == 0 || strcmp(param, "/write") == 0)
#define IS_READ_NOTES_COMMAND(param) (strcmp(param, "/nr") == 0 || strcmp(param, "/read") == 0)
#define IS_CLEAR_NOTES_COMMAND(param) (strcmp(param, "/nc") == 0)
#define IS_LORE_COMMAND(param) (strcmp(param, "/lore") == 0)
//--------------------------------------------------------------------------------//
/*END OF COMMAND LINE MACROS
|
|
|
|
|
|
|
|
|
|
START OF FILE/LOGGING MACROS
*/
#define CREATE_LOG_FILE(variable, filename) \
  FILE *variable = fopen(filename, "a");    \
  if (variable == NULL)                     \
  {                                         \
    perror("Error opening the log file");   \
    exit(1);                                \
  }

#define LOG_MESSAGE(logFile, message)                            \
  do                                                             \
  {                                                              \
    time_t currentTime;                                          \
    time(&currentTime);                                          \
    fprintf(logFile, "[%s] %s\n", ctime(&currentTime), message); \
    fflush(logFile);                                             \
  } while (0)
//--------------------------------------------------------------------------------//
/*END OF FILE/LOGGING COMMANDS*/
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF MACROS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
// TODO may not need this function if the 'LOG_MESSAGE' macro works
void logMessage(FILE *logFile, const char *message)
{
  time_t currentTime;
  time(&currentTime);
  fprintf(logFile, "[%s] %s\n", ctime(&currentTime), message);
  fflush(logFile);
}

#define MAX_NOTE_LENGTH 300
// Create a note in the notepad also creates notepad if it doesn't exist
int createNote()
{

  CREATE_LOG_FILE(notePad, "notepad.txt");
  CREATE_LOG_FILE(logFile, "logs/runtime.log");
  char note[MAX_NOTE_LENGTH];
  printf("Enter a note: ");
  if (fgets(note, sizeof(note), stdin) == NULL)
  {
    // Handle note error
    perror("fgets");
    exit(1);
  }
  REMOVE_NEWLINE_CHAR(note);
  time_t entryTimeAndDate;
  time(&entryTimeAndDate);
  fprintf(notePad, "---------Start of Entry---------\n");
  fprintf(notePad, "%s %s\n", ctime(&entryTimeAndDate), note);
  fprintf(notePad, "----------End of Entry----------\n");
  fflush(notePad);
  usleep(500000);
  printf("\x1b[32mNote Added Successfully!\x1b[0m\n");
  logMessage(logFile, "Note Added Successfully!");
  fclose(logFile);
  return 0;
}
// Read all notes from the notepad
int readNotes()
{
  FILE *notePad = fopen("notepad.txt", "r");
  if (notePad == NULL)
  {
    perror("Error opening the log file");
    exit(1);
  }
  char note[MAX_NOTE_LENGTH];
  while (fgets(note, sizeof(note), notePad) != NULL)
  {
    printf("%s", note);
  }
  fclose(notePad);
  return 0;
}

// Clears all notes from the notepad
int clearNotes()
{
  FILE *notePad = fopen("notepad.txt", "w");
  if (notePad == NULL)
  {
    perror("Error opening the log file");
    exit(1);
  }
  fclose(notePad);
  printf("\x1b[32mNotes Cleared Successfully!\x1b[0m\n");
  return 0;
}

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF PROTOTYPES+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
/*This section holds all function prototypes used in the program.*/

// COMMAND LINE PROTOTYPES//
#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H
int COMMAND_LINE();
#endif

// UTIL FUNCTIONS PROTOTYPES//
#ifndef UTIL_FUNCS_H
#define UTIL_FUNCS_H
void logMessage(FILE *logFile, const char *message);
void appendToLog();
int createNote();
int readNotes();
int clearNotes();
#endif

// HERO CREATION PROTOTYPES//
#ifndef HERO_CREATION_H
#define HERO_CREATION_H
void get_first_name();
void ask_for_dynasty_name();
void get_dynasty_name();
void confirm_dynasty_name();
void ask_for_gender();
void get_gender();
void confirm_no_gender();
void confirm_gender();
void get_homeland();
void confirm_homeland();
void get_profession();
void confirm_profession();
void get_class();
void confirm_class();
void log_hero_creation();
#endif

// SKILL POINT PROTOTYPES//
#ifndef SKILL_POINT_H
#define SKILL_POINT_H
int setHeroStatsAndAbilities();
int setAllHeroStats();
int setHeroLvl();
int initialSKillPointAllocation();
int capAllocation();
int refreshPoints();
#endif

// CHAPTER 0 PROTOTYPES//
#ifndef CHAPTER_0_H
#define CHAPTER_0_H
void start_ch0();
void ch0_wake_up();
void ch0_go_to_main_deck();
#endif
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF PROTOTYPES+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF STRUCTS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
/*This section holds all structs used in the program.*/

// HERO STRUCT
typedef struct
{
  // Creation Information
  char FirstName[10];
  char LastName[10];
  char Gender[10];
  char Homeland[10];
  char Profession[10];
  char Class[10];
  // Health and Mana
  int Health;
  int Mana;
  // Skills
  int Strength;
  int Intelligence;
  int Dexterity;
  int Luck;
  int Level;
  // Attack and Defense
  int Atk;
  int Def;
  // Abilities
  char Ability1[20];
  char Ability2[20];
  char Ability3[20];
} Hero;
extern Hero hero;
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF STRUCTS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF GLOBAL VARIABLE+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
extern char hero_first_name[10];
extern char hero_dynasty_name[10];
extern char hero_race[10];
extern char hero_gender[10];
extern char hero_homeland[10];
extern char hero_profession[15];
extern char hero_class[10];
// Hero Primary Stats Have a max value of 200....this might change
extern int hero_health;
extern int hero_mana;
// Hero Secondary Stats Have a max value of 50
extern int hero_strength;
extern int hero_intelligence;
extern int hero_dexterity;
extern int hero_luck;
extern int hero_level;
// Hero Attack and Defense
extern int hero_atk;
extern int hero_def;

// Hero abilities
extern char hero_ability1[20];
extern char hero_ability2[20];
extern char hero_ability3[20];

// Enemy Variables
extern char current_enemy_name[20];
extern int current_enemy_health;
extern char current_enemy_ability1[20];
extern char current_enemy_ability2[20];

// Origins, classes, and  TODO professions
extern char possibleHomelands[5][10];
extern char possibleClasses[5][10];
extern char possibleProfessions[6][15];

extern char WarriorArt[] =
    "..............................,:::::,::.\n"
    "............................,::,,,,,:;;.\n"
    "..........................,::,,,,,:;;;;.\n"
    ".........................,:,,,,,:;;;;;;.\n"
    ".......................,::,,,,:;;;;;+;;.\n"
    ".....................,::,,,,:;;;;;+;:,..\n"
    "...................,::,,,,:;;+;;;;:,....\n"
    "..................,:,,,,:;;+;;;;:.......\n"
    "................,::,,,:;;+;+;:,.........\n"
    ".......,,,....,::,,,:;;+;;;:,...........\n"
    "......,:,::,,::,,,:;;++;;:,.............\n"
    "......,::,,:;:,,:;;++;:,................\n"
    "........,;:,,::;;;;;:,..................\n"
    ".......:;;:::,,:;;:.....................\n"
    ".,,,,:;;:::::;:,,::,....................\n"
    ".;,,:;;:::::;;:::,,:,...................\n"
    ".,::,,::::;;:...,:::,...................\n"
    "...,::,,:;:.............................\n"
    ".....,::,,:.............................\n"
    ".......,,,,.............................\n";

extern char MageArt[] =
    ".......,:::::,..........................\n"
    ".....,:;;;;;;;:,........................\n"
    "...,:;;;;;;;;;;;:,......................\n"
    ".,:;;;;;:,.,,;;;;;;,....................\n"
    ",;;;;;:,:;:,,,,;;;;;;,..................\n"
    ",;;;;;,.:**+++,.,;;;;;:.................\n"
    ".:;;;;;,,;****;..,;;;;;,................\n"
    "..,:;;;;:,::;;;,:;;;;;:.................\n"
    "....,:::,......:;;;;:...................\n"
    "...............,;;;;;:;;,...............\n"
    "................,:;;*%%%%;..............\n"
    "..................:%%%%%?;:;,...........\n"
    "..................,+%%?++?%%%+..........\n"
    "....................,,,?%%%%%+,.........\n"
    "......................,+%%?*;;;:,.......\n"
    "........................,:,:;;;;;:,.....\n"
    "............................,:;;;;;:,...\n"
    "..............................,:;;;;;:,.\n"
    "................................,:;;;;;,\n"
    "..................................,::::,\n";

extern char RogueArt[] =
    ",;:.....................................\n"
    ",**,....................................\n"
    ".:?*,...................................\n"
    "..+?*,..................................\n"
    "..,??*:.................................\n"
    "...;???;................................\n"
    "...,+???+,..............................\n"
    "....,+???*+;;::,........................\n"
    ".....,+*???????+,,,.....................\n"
    "......,+**????????*,,,:,................\n"
    ".......,;***????????????*;..............\n"
    ".........,;+***???????????+;:,..........\n"
    "...........,:;+++****;;??%%%%*;,........\n"
    "................,,,,,..:*???++??,.......\n"
    "..........................,:?%%?;.......\n"
    "............................+?+**;,.....\n"
    "............................,;?*+*+:,...\n"
    ".............................,:**+*??*:.\n"
    "...............................,:*%%%S?,\n"
    ".................................,:;++:.\n";

extern char ClericArt[] =
    "......,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....\n"
    "...,::;;;;;:;;;;;;;;;;;;;;;;;;;;;;;;;;;;,...\n"
    "...:+;;+++;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:...\n"
    "...:+;;+++;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...\n"
    "...:+;++++;;;;;;;;;;;;;::;;;;;;;;;;;;;;+;...\n"
    "...:++++++;;;;;;;;;;;;:,,+;;;;;;;;;;;;;+;...\n"
    "...:++++++;;;;;;;;;;;;:,:+;;;;;;;;;;;;;+;...\n"
    "...;*+++++;;;;;;:,,,,,,,,::::::;;;;;++++;...\n"
    "...;*+++*+;;;;;;;+++++;,,++++++*++++++++;...\n"
    "...;*++**+;;;;;;;+++++;,:*++++++++++++++;...\n"
    "...;*+****;;;;;;;;;;;+;,:+++++++++++++++;...\n"
    "...;******++++++++++++;,:*++++++++++++++;...\n"
    "...;?*****++++++++++++;,:*++++++++++++++;...\n"
    "...+?*****++++++++++++;,:*++++++++++++++;...\n"
    "...+?*****++++++++++++;:;*++++++++++++++;...\n"
    "...+?*****+++++++++++++*?*++++++++++++++;...\n"
    "...+?***?*+++++++++++++++++++++++++++++++...\n"
    "...+??**?*+++++++++++++++++++++++++++++++...\n"
    "...+%????*+++++++++++++++++++++++++++++*+...\n"
    "...*%????*+++++++++++++++++++++++++++++*+...\n"
    "...*%????*+++++++++++++++++++++++++++++*+...\n"
    "...*%?????******************************+...\n"
    "...*#S????******************************+...\n"
    "...+#S%?????????????????????????????????;...\n"
    "....,;+++++++++++++++++++++++++++++++++:,...\n";

extern char BardArt[] =
    "................................,,......\n"
    "..............................,,,;++:...\n"
    "..............................,;;**??;..\n"
    "............................,:++++++::,.\n"
    "..........................,:+++++;::,,..\n"
    "........................,:++++++:.......\n"
    "......................,:++++++:,........\n"
    "...........,,,::;;;;;+++++++:,..........\n"
    ".......,:;;++*****+**??**+:,............\n"
    "....,;++;;;;;++++++++****,..............\n"
    "...;+++;;++*?????**++++++,..............\n"
    "..+*+;++++*?????****++++;...............\n"
    ".;**++++++??*????***++++:...............\n"
    ".+*+++**++*?**??****++++,...............\n"
    ".+*++*??*+++******+++++:................\n"
    ".:*+++?****+++++++++++;.................\n"
    "..;*+++******++++++++;,.................\n"
    "...:+++++++++++++++;:...................\n"
    "....,,;;++++++++;;:,....................\n"
    "........,,::::,,........................\n";

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF GLOBAL VARIABLE+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

#endif