#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#ifndef UTILS_H
#define UTILS_H
// TODO clean this file

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
//--------------------------------------------------------------------------------//

// Cleaner way to evaluate the users input string for two possible values
#define STR_CMP_TWO(input, string1, string2) (strcmp(input, string1) == 0 || strcmp(input, string2) == 0)
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

#define ALLOCATE_TO_SKILL(skill, amount, pool, param)                                                 \
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
    if (amount > pool)                                                                                \
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
      pool = pool - amount;                                                                           \
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
#define IS_INVENTORY_COMMAND(param) (strcmp(param, "/inventory") == 0 || strcmp(param, "/inv") == 0)
#define IS_GOD_MODE_COMMAND(param) (strcmp(param, "/godmode") == 0 || strcmp(param, "/god") == 0)
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
//---------------------------------------------------------------lck:%d-+END OF MACROS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

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

// /*END OF NOTEPAD/LOGGING FUNCTIONS

// ===========================================================================================================//
void clear_and_print_step(const char *string, int step, int maxsteps)
{
  system("clear");
  printf("----- %s ----- %d/%d\n", string, step, maxsteps);
}

void print_step(const char *string, int step, int maxsteps)
{
  printf("----- %s ----- %d/%d\n", string, step, maxsteps);
}
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF PROTOTYPES+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
/*This section holds all function prototypes used in the program.*/

// COMMAND LINE PROTOTYPES//
#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H
void start_game();
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

void calculate_new_hero_dmg_str();
void calculate_new_hero_dmg_int();
void calculate_new_hero_health();
void calculate_new_hero_mana();
void calculate_new_mana_cost();
void calculate_dmg_with_equipped_weapon();
void calculate_remaining_carrying_capacity();
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
  char FirstName[15];
  char LastName[15];
  char Gender[10];
  char Homeland[10];
  char Profession[10];
  char Class[10];

  // Health and Mana
  int Health;
  int Mana;
  // Attributes
  char AttributeNames[4][20];
  int AttributePointsPool;
  struct Attribute
  {
    char Name[20];
    int CurrentPoints;
    int MaxPoints;
  } StrengthAttribute, IntelligenceAttribute, DexterityAttribute, LuckAttribute;
  // Hero Level & XP pool
  int Level;
  int CurrentXP;
  int XPToNextLevel;
  int MaxXP;
  // Attack and Defense
  int Atk;
  int Def;
  // Abilities

  struct Ability1
  {
    char Name[20];
    char Description[100];
    char Type[15];
    int Damage;
    int ManaCost;
  } Ability1;

  struct Ability2
  {
    char Name[20];
    char Description[100];
    char Type[15];
    int Damage;
    int ManaCost;
  } Ability2;

  struct Ability3
  {
    char Name[20];
    char Description[100];
    char Type[15];
    int Damage;
    int ManaCost;
  } Ability3;

} Hero;
extern Hero hero;

// this struct will be applicable to all things in the game that the user can pick up from weapons, armor, and items, to potions, books, etc
typedef struct
{
  char Name[20];
  char Description[100];
  char Type[20]; // weapon, armors, item, potion, book, etc
  int AddedDamage;
  int AddedHealth;
  int Weight;
  int Value;
  char Art[1000];
  char Rarity[10]; // common, uncommon, rare, epic, legendary // wood, iron, steel, etc
  // char Style[10];  // for weapons..i.e sword,axe,mace,staff,wand,etc
} Item;

typedef struct
{
  Item Item;
  int Quantity;
  int isOpen; // 0 = false, 1 = true
} InventorySlot;
struct Inventory
{
  Item EquippedWeapon;
  Item EquippedHead;
  Item EquippedChest;
  Item EquippedLegs;
  InventorySlot Slot1;
  InventorySlot Slot2;
  InventorySlot Slot3;
  int CarryingCapacity;
  int MaxCarryingCapacity;
  int CurrentGold;
} Inventory;

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF STRUCTS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF INVENTORY RELATED FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF INVENTORY RELATED FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF MATH FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

// This function calculates the amount of dmg the heros abilities do based on how many points are allocated to the strength attribute

void calculate_new_hero_dmg_str(int *base_dmg, char *AbilityName)
{
  int new_dmg;
  switch (hero.StrengthAttribute.CurrentPoints)
  {
  case 1:
    new_dmg = *base_dmg += 1 * 2;
    break;
  case 2:
    new_dmg = *base_dmg += 2 * 2;
    break;
  case 3:
    new_dmg = *base_dmg += 3 * 2;
    break;
  case 4:
    new_dmg = *base_dmg += 4 * 2;
    break;
  default:
    break;
  }
  *base_dmg = new_dmg;
}
// This function calculates the amount of dmg the heros abilities do based on how many points are allocated to the intelligence attribute
void calculate_new_hero_dmg_int(int *base_dmg, char *AbilityName)
{
  int new_dmg;
  switch (hero.IntelligenceAttribute.CurrentPoints)
  {
  case 1:
    new_dmg = *base_dmg += 1 * 3;
    break;
  case 2:
    new_dmg = *base_dmg += 2 * 3;
    break;
  case 3:
    new_dmg = *base_dmg += 3 * 3;
    break;
  case 4:
    new_dmg = *base_dmg += 4 * 3;
    break;
  default:
    break;
  }
  *base_dmg = new_dmg;
}
//
void calculate_new_hero_dmg_dex(int *base_dmg, char *AbilityName)
{
  int new_dmg;
  switch (hero.DexterityAttribute.CurrentPoints)
  {
  case 1:
    new_dmg = *base_dmg += 1 * 2;
    break;
  case 2:
    new_dmg = *base_dmg += 2 * 2;
    break;
  case 3:
    new_dmg = *base_dmg += 3 * 2;
    break;
  case 4:
    new_dmg = *base_dmg += 4 * 2;
    break;
  default:
    break;
  }
  *base_dmg = new_dmg;
}
// This function calculates the amount how much health the hero has based on how many points are allocated to the strength attribute
void calculate_new_hero_health(int *base_health)
{
  int new_health;
  switch (hero.StrengthAttribute.CurrentPoints)
  {
  case 1:
    new_health = *base_health += 1 * 5;
    break;
  case 2:
    new_health = *base_health += 2 * 5;
    break;
  case 3:
    new_health = *base_health += 3 * 5;
    break;
  case 4:
    new_health = *base_health += 4 * 5;
    break;
  default:
    break;
  }
}
// this function calculates the amount of health the hero has based on the armor they have equipped
void calculate_new_health_from_armor(int *base_health, Item *equipped_head_armor, Item *equipped_chest_armor, Item *equipped_leg_armor)
{
  int new_health;
  new_health = *base_health += equipped_head_armor->AddedHealth + equipped_chest_armor->AddedHealth + equipped_leg_armor->AddedHealth;
  *base_health = new_health;
}
// This function calculates the amount how much mana the hero has based on how many points are allocated to the intelligence attribute
void calculate_new_hero_mana(int *base_mana)
{
  int new_mana;

  switch (hero.IntelligenceAttribute.CurrentPoints)
  {
  case 1:
    new_mana = *base_mana += 1 * 2;
    break;
  case 2:
    new_mana = *base_mana += 2 * 2;
    break;
  case 3:
    new_mana = *base_mana += 3 * 2;
    break;
  case 4:
    new_mana = *base_mana += 4 * 2;
  }
  *base_mana = new_mana;
}
// This function calculates the amount of mana the heros abilities cost based on how many points are allocated to the intelligence attribute
void calculate_new_mana_cost(int param, int *base_mana_cost, char *AbilityName)
{
  int new_mana_cost;

  switch (param)
  {
  case 1:
    new_mana_cost = *base_mana_cost - 1.0 / 2.0;
    break;
  case 2:
    new_mana_cost = *base_mana_cost - 2.0 / 2.0;
    break;
  case 3:
    new_mana_cost = *base_mana_cost - 3.0 / 2.0;
    break;
  case 4:
    new_mana_cost = *base_mana_cost - 4.0 / 2.0;
    break;
  default:
    printf("Invalid param value: %d\n", param);
    return;
  }

  if (new_mana_cost < 0)
  {
    new_mana_cost = 0;
  }

  *base_mana_cost = new_mana_cost;
}

void calculate_dmg_with_equipped_weapon(int *base_dmg, Item *item)
{
  int new_dmg;
  new_dmg = *base_dmg += item->AddedDamage;
  *base_dmg = new_dmg;
}

// this function is used to calculate the amount of carrying capacity the hero has left this func should be called whenever an item is added to the inventory or removed from the inventory
void calculate_remaining_carrying_capacity(int *base_carrying_capacity, int *max_carrying_capacity, Item *equipped_weapon, Item *equipped_head_armor, Item *equipped_chest_armor, Item *equipped_leg_armor)
{

  int new_carrying_capacity;

  *base_carrying_capacity = *max_carrying_capacity - equipped_weapon->Weight - equipped_head_armor->Weight - equipped_chest_armor->Weight - equipped_leg_armor->Weight;

  new_carrying_capacity = *base_carrying_capacity;
}
// function runs if player adds str points. this increases max carrying capacity
void calculate_new_max_carrying_capacity_from_str(int *base_max)
{
  int new_max;
  switch (hero.StrengthAttribute.CurrentPoints)
  {
  case 1:
    new_max = *base_max += 1 * 4;
  case 2:
    new_max = *base_max += 2 * 4;
  case 3:
    new_max = *base_max += 3 * 4;
  case 4:
    new_max = *base_max += 4 * 4;
  }
  *base_max = new_max;
}
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF MATH FUNCTIONS+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF GLOBAL VARIABLE+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

// Enemy Variables
extern char current_enemy_name[20];
extern int current_enemy_health;
extern char current_enemy_ability1[20];
extern char current_enemy_ability2[20];

// Origins, classes, and  TODO professions
extern char possibleHomelands[5][10];
extern char possibleClasses[6][10];
extern char possibleProfessions[6][15];

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF GLOBAL VARIABLE+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+START OF ART+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
char WarriorArt[] =
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

char MageArt[] =
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

char RogueArt[] =
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

char ClericArt[] =
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

char BardArt[] =
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

char ArcherArt[] =

    "                         .+**-                             \n"
    "                        .*****                             \n"
    "                        =***+.                             \n"
    "                       .*****-                             \n"
    "                       +*-:****=:.                         \n"
    "                      +*=   =*****+-.                      \n"
    "                     -**     :+*******-                    \n"
    "                    .**-       :+*******=.                 \n"
    "                   .**+          .+*******+.               \n"
    "                   +*+             .=*****#*-              \n"
    "                  :**.               .*#****#+             \n"
    "                  +*:                 .*#***##=            \n"
    "      .::::::::. +*=                   =##***#*            \n"
    "     =*************                    :##***##=           \n"
    "      .-++=.  .:=**--------------------=###**##*--+#*+-    \n"
    "       :+*+:...:=**====================+########==###*=    \n"
    "     :+**+====+***+                    .###**##+   :.      \n"
    "     :==========-**:                   -##**###.           \n"
    "                 :**                   *##**##+            \n"
    "                  -**.               .+##**##*.            \n"
    "                   +*+              -###**##=              \n"
    "                   :**=           -*##**###-               \n"
    "                    =**:        :*##**###-                 \n"
    "                     +*+      -*######*:                   \n"
    "                     .**-   -*####*=:.                     \n"
    "                       **:.*###*=.                         \n"
    "                       -##*##+:                            \n"
    "                        *###+                              \n"
    "                        :####+                             \n"
    "                        :+#*=                              \n";

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+END OF ART+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

//+1+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-DEBUGGING+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
void activate_god_mode()
{
  strcpy(hero.FirstName, "God");
  strcpy(hero.LastName, "Mode");
  strcpy(hero.Gender, "Unknown");
  strcpy(hero.Homeland, "Empyrea");
  strcpy(hero.Profession, "Hunter");
  strcpy(hero.Class, "Mage");
  hero.Level = 20;
  hero.MaxXP;
  hero.Health = 1000;
  hero.Mana = 1000;
  strcpy(hero.Ability1.Name, "God Mode Ability 1");
  strcpy(hero.Ability1.Description, "Ability 1 desc.");
  hero.Ability1.Damage = 1000;
  strcpy(hero.Ability2.Name, "God Mode Ability 2");
  strcpy(hero.Ability2.Description, "Ability 2 desc.");
  hero.Ability2.Damage = 1000;
  strcpy(hero.Ability3.Name, "God Mode Ability 3");
  strcpy(hero.Ability3.Description, "Ability 3 desc.");
  hero.Ability3.Damage = 1000;
  hero.StrengthAttribute.CurrentPoints = 10;
  hero.IntelligenceAttribute.CurrentPoints = 10;
  hero.DexterityAttribute.CurrentPoints = 10;
  hero.LuckAttribute.CurrentPoints = 10;
  hero.AttributePointsPool = 0;
  Inventory.MaxCarryingCapacity = 1000;
  Inventory.CurrentGold = 1000000;

  // Inventory.Slot1.Quantity = 0;
  strcpy(Inventory.EquippedWeapon.Name, "God Mode Weapon");
  strcpy(Inventory.EquippedWeapon.Description, "God Mode Weapon Desc.");
  strcpy(Inventory.EquippedWeapon.Type, "Weapon");
  strcpy(Inventory.EquippedHead.Name, "God Mode Head");
  strcpy(Inventory.EquippedHead.Description, "God Mode Head Desc.");
  strcpy(Inventory.EquippedHead.Type, "Head");
  strcpy(Inventory.EquippedChest.Name, "God Mode Chest");
  strcpy(Inventory.EquippedChest.Description, "God Mode Chest Desc.");
  strcpy(Inventory.EquippedChest.Type, "Chest");
  strcpy(Inventory.EquippedLegs.Name, "God Mode Legs");
  strcpy(Inventory.EquippedLegs.Description, "God Mode Legs Desc.");
  strcpy(Inventory.EquippedLegs.Type, "Legs");
  Inventory.EquippedWeapon.AddedDamage = 1000;
  Inventory.EquippedWeapon.AddedHealth = 5;
  Inventory.EquippedWeapon.Weight = 5;
  Inventory.EquippedWeapon.Value = 5;
  Inventory.EquippedHead.AddedDamage = 5;
  Inventory.EquippedHead.AddedHealth = 5;
  Inventory.EquippedHead.Weight = 5;
  Inventory.EquippedHead.Value = 5;
  Inventory.EquippedChest.AddedDamage = 5;
  Inventory.EquippedChest.AddedHealth = 5;
  Inventory.EquippedChest.Weight = 5;
  Inventory.EquippedChest.Value = 5;
  Inventory.EquippedLegs.AddedDamage = 5;
  Inventory.EquippedLegs.AddedHealth = 5;
  Inventory.EquippedLegs.Weight = 5;
  Inventory.EquippedLegs.Value = 5;
}
#endif
