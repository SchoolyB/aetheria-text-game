#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"

char input[100];
char confirmation[100];
Hero hero;

// ===========================================================================================================//
void get_first_name()
{
  print_step("Hero Creation", 1, 8);
  // clear_and_print_step("Hero Creation", 1, 8);
  printf("Enter your first name:");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (strlen(input) > 15)
  {
    printf("Your name is too long. Please enter a name that is less than 15 characters.\n");
    sleep(2);
    system("clear");
    get_first_name();
  }
  else if (strlen(input) < 2)
  {
    printf("Your name is too short. Please enter a name that is atleast 2 characters.\n");
    sleep(2);
    system("clear");
    get_first_name();
  }
  else
  {
    strcpy(hero.FirstName, input);
    printf("Your first name is \x1b[1;4m%s\x1b[0m is that correct? (y/n)\n", hero.FirstName);
    FGETS(confirmation);
    REMOVE_NEWLINE_CHAR(confirmation);
    if (INPUT_IS_YES(confirmation))
    {
      printf("You have chosen \x1b[1;4m%s\x1b[0m as your first name. This can be changed later.\n", hero.FirstName);
      system("clear");
      ask_for_dynasty_name();
    }
    else if (INPUT_IS_NO(confirmation))
    {
      system("clear");
      get_first_name();
    }
    else
    {
      clear_and_print_step("First Name", 1, 8);
      MAKE_VALID_DECISION;
      get_first_name();
    }
  }
}
// ===========================================================================================================//
void ask_for_dynasty_name()
{
  clear_and_print_step("Dynasty Name", 2, 8);
  printf("Do you have a dynasty name? (y/n)\n");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (INPUT_IS_YES(input))
  {
    get_dynasty_name();
  }
  else if (INPUT_IS_NO(input))
  {
    usleep(40000);
    MAKE_YELLOW("You have chosen not to have a dynasty name.\n");
    usleep(40000);
    MAKE_YELLOW("Are you sure you want to continue with this decision? (y/n)\n");
    FGETS(confirmation);
    REMOVE_NEWLINE_CHAR(confirmation);
    if (INPUT_IS_YES(confirmation))
    {
      printf("Ah, It seems you don't come from a great dynasty. Very well. \n");
      ask_for_gender();
    }
    else if (INPUT_IS_NO(confirmation))
    {
      ask_for_dynasty_name();
    }
    else
    {
      clear_and_print_step("Dynasty Name", 2, 8);
      MAKE_VALID_DECISION;
      ask_for_dynasty_name();
    }
  }
  else

  {
    MAKE_VALID_DECISION;
    ask_for_dynasty_name();
  }
}
// ===========================================================================================================//
void get_dynasty_name()
{
  clear_and_print_step("Dynasty Name", 2, 8);
  printf("What is the name of the dynasty you come from?\n");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (strlen(input) > 15)
  {
    printf("Your dynasty name is too long. Please enter a name that is less than 15 characters.\n");
    sleep(2);
    system("clear");
    get_dynasty_name();
  }
  else if (strlen(input) < 2)
  {
    printf("Your dynasty name is too short. Please enter a name that is atleast 2 characters.\n");
    sleep(2);
    system("clear");
    get_dynasty_name();
  }
  else
  {

    strcpy(hero.LastName, input);
    printf("Ah so you are a member of the \x1b[1;4m%s\x1b[0m dynasty.\n", hero.LastName);
    usleep(40000);
    printf("Is that correct? (y/n)\n");
    confirm_dynasty_name();
  }
}
// ===========================================================================================================//
void confirm_dynasty_name()
{
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (INPUT_IS_YES(input))
  {
    ask_for_gender();
  }
  else if (INPUT_IS_NO(input))
  {
    printf("Interesting....)\n");
    usleep(60000);
    get_dynasty_name();
  }
  else
  {
    MAKE_VALID_DECISION;
    get_dynasty_name();
  }
}
// ===========================================================================================================//
void ask_for_gender()
{
  clear_and_print_step("Gender", 3, 8);
  printf("Do you have a gender? (y/n)\n");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (INPUT_IS_YES(input))
  {
    get_gender();
  }
  else if (INPUT_IS_NO(input))
  {
    confirm_no_gender();
  }
  else
  {
    MAKE_VALID_DECISION;
    ask_for_gender();
  }
}
// ===========================================================================================================//
void confirm_no_gender()
{
  MAKE_YELLOW("Are you sure that you do not have a gender? (y/n)\n");
  FGETS(confirmation);
  REMOVE_NEWLINE_CHAR(confirmation);
  if (INPUT_IS_YES(confirmation))
  {
    get_homeland();
  }
  else if (INPUT_IS_NO(confirmation))
  {
    ask_for_gender();
  }
  else
  {
    clear_and_print_step("Gender", 3, 8);
    MAKE_VALID_DECISION;
    confirm_no_gender();
  }
}
// ===========================================================================================================//
#define IS_GENDER(input, lower_c, cap_c, lower_informal, cap_informal, lower_formal, cap_formal) ( \
    strcmp(input, cap_formal) == 0 ||                                                              \
    strcmp(input, lower_formal) == 0 ||                                                            \
    strcmp(input, cap_informal) == 0 ||                                                            \
    strcmp(input, lower_informal) == 0 ||                                                          \
    strcmp(input, cap_c) == 0 ||                                                                   \
    strcmp(input, lower_c) == 0)

void get_gender()
{
  printf("Please tell me your gender. (m/f or enter your own)\n");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (IS_GENDER(input, "m", "M", "man", "Man", "male", "male"))
  {
    strcpy(hero.Gender, "Male");
    printf("So your gender is \x1b[1;4m%s\x1b[0m is that correct? (y/n) \n", hero.Gender);
    confirm_gender();
  }
  else if (IS_GENDER(input, "f", "F", "woman", "Woman", "female", "Female"))
  {
    strcpy(hero.Gender, "Female");
    printf("So your gender is \x1b[1;4m%s\x1b[0m is that correct? (y/n) \n", hero.Gender);
    confirm_gender();
  }
  else
  {
    strcpy(hero.Gender, input);
    printf("So your gender is \x1b[1;4m%s\x1b[0m is that correct? (y/n) \n", hero.Gender);
    confirm_gender();
  }
}
// ===========================================================================================================//
void confirm_gender()
{
  FGETS(confirmation);
  REMOVE_NEWLINE_CHAR(confirmation);
  if (INPUT_IS_YES(confirmation))
  {
    get_homeland();
  }
  else if (INPUT_IS_NO(confirmation))
  {
    get_gender();
  }
  else
  {
    clear_and_print_step("Gender", 3, 8);
    MAKE_VALID_DECISION;
    confirm_gender();
  }
}
// ===========================================================================================================//
#define IS_NATION(input, number, lower, pascal, caps) ( \
    strcmp(input, number) == 0 ||                       \
    strcmp(input, lower) == 0 ||                        \
    strcmp(input, pascal) == 0 ||                       \
    strcmp(input, caps) == 0)

void get_homeland()
{
  clear_and_print_step("Home of Origin", 4, 8);
  char possibleHomelands[5][15] =
      {
          "1: Empyrea",
          "2: Wesward",
          "3: Magdalar",
          "4: Ashvadan",
          "5: Nadafia"};

  printf("Which of these lands do you hail from?\n");
  PRINT_LIST_ITEMS(5, possibleHomelands);
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (IS_NATION(input, "1", "empyrea", "Empyrea", "EMPYREA"))
  {
    strcpy(hero.Homeland, "Empyrea");
    // READ_FULL_TXT_FILE("./Lore/Countries/Empyrea.txt");
    printf("Are the lands of \x1b[1;4m%s\x1b[0m where you hail from?(y/n)\n", hero.Homeland);
    confirm_homeland();
  }
  else if (IS_NATION(input, "2", "wesward", "Wesward", "WESWARD"))
  {
    strcpy(hero.Homeland, "Wesward");
    // READ_FULL_TXT_FILE("./Lore/Countries/Wesward.txt");
    printf("Are the lands of \x1b[1;4m%s\x1b[0m where you hail from? (y/n)\n", hero.Homeland);
    confirm_homeland();
  }
  else if (IS_NATION(input, "3", "ashvadan", "Ashvadan", "ASHVADAN"))
  {
    strcpy(hero.Homeland, "Ashvadan");
    // READ_FULL_TXT_FILE("./Lore/Countries/Ashvadan.txt");
    printf("Are the lands of \x1b[1;4m%s\x1b[0m where you hail from?(y/n)\n", hero.Homeland);
    confirm_homeland();
  }
  else if (IS_NATION(input, "4", "magdalar", "Magdlar", "MAGDALAR"))
  {
    strcpy(hero.Homeland, "Magdalar");
    // READ_FULL_TXT_FILE("./Lore/Countries/Magdalar.txt");
    printf("Are the lands of \x1b[1;4m%s\x1b[0m where you hail from? (y/n)\n", hero.Homeland);
    confirm_homeland();
  }
  else if (IS_NATION(input, "5", "nadafia", "Nadafia", "NADAFIA"))
  {
    strcpy(hero.Homeland, "Nadafia");
    // READ_FULL_TXT_FILE("./Lore/Countries/Nadafia.txt");
    printf("Are the lands of \x1b[1;4m%s\x1b[0m where you hail from? (y/n)\n", hero.Homeland);
    confirm_homeland();
  }
  else
  {

    MAKE_VALID_DECISION;
    get_homeland();
  }
}
// ===========================================================================================================//
void confirm_homeland()
{
  FGETS(confirmation);
  REMOVE_NEWLINE_CHAR(confirmation);
  if (INPUT_IS_YES(confirmation))
  {
    get_profession();
  }
  else if (INPUT_IS_NO(confirmation))
  {
    get_homeland();
  }
  else
  {
    clear_and_print_step("Home of Origin", 4, 8);
    MAKE_VALID_DECISION;
    printf("You hail from the lands of \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Homeland);
    confirm_homeland();
  }
}
// ===========================================================================================================//
#define IS_PROFESSION(input, number, lower, pascal, caps) ( \
    strcmp(input, number) == 0 ||                           \
    strcmp(input, lower) == 0 ||                            \
    strcmp(input, pascal) == 0 ||                           \
    strcmp(input, caps) == 0)

void get_profession()
{
  clear_and_print_step("Profession", 5, 8);
  char possibleProfessions[6][15] = {
      "1: Merchant",
      "2: Hunter",
      "3: Soldier",
      "4: thief",
      "5: Scholar",
      "6: None"};

  printf("What is your profession?\n");
  PRINT_LIST_ITEMS(5, possibleProfessions);
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (IS_PROFESSION(input, "1", "merchant", "Merchant", "MERCHANT"))
  {
    strcpy(hero.Profession, "Merchant");
    printf("Ah so you have a background as a \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Profession);
    confirm_profession();
  }
  else if (IS_PROFESSION(input, "2", "hunter", "Hunter", "HUNTER"))
  {
    strcpy(hero.Profession, "Hunter");
    printf("Ah so you have a background as a \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Profession);
    confirm_profession();
  }
  else if (IS_PROFESSION(input, "3", "soldier", "Soldier", "SOLDIER"))
  {
    strcpy(hero.Profession, "Soldier");
    printf("Ah so you have a background as a \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Profession);
    confirm_profession();
  }
  else if (IS_PROFESSION(input, "4", "thief", "Thief", "THIEF"))
  {
    strcpy(hero.Profession, "Thief");
    printf("Ah so you have a background as a \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Profession);
    confirm_profession();
  }
  else if (IS_PROFESSION(input, "5", "scholar", "Scholar", "SCHOLAR"))
  {
    strcpy(hero.Profession, "Scholar");
    printf("Ah so you have a background as a \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Profession);
    confirm_profession();
  }
  else if (IS_PROFESSION(input, "6", "none", "None", "NONE"))
  {
    strcpy(hero.Profession, "None");
    printf("Ah so you \x1b[1;4mdo not\x1b[0m have a profession is that correct? (y/n)\n");
    confirm_profession();
  }
  else
  {
    MAKE_VALID_DECISION;
    get_profession();
  }
}
// ===========================================================================================================//
void confirm_profession()
{
  FGETS(confirmation);
  REMOVE_NEWLINE_CHAR(confirmation);
  if (INPUT_IS_YES(confirmation))
  {
    get_class();
  }
  else if (INPUT_IS_NO(confirmation))
  {
    get_profession();
  }
  else
  {
    clear_and_print_step("Profession", 5, 8);
    MAKE_VALID_DECISION;

    if (hero.Profession == "None")
    {
      printf("You do not have a profession, is that correct? (y/n)\n");
      confirm_profession();
    }
    else
    {
      printf("You have a background as a \x1b[1;4m%s\x1b[0m , is that correct? (y/n)\n", hero.Profession);
      confirm_profession();
    }
  }
}
// ===========================================================================================================//
#define IS_CLASS(input, number, lower, pascal, caps) ( \
    strcmp(input, number) == 0 ||                      \
    strcmp(input, lower) == 0 ||                       \
    strcmp(input, pascal) == 0 ||                      \
    strcmp(input, caps) == 0)

#define PRINT_CLASS(adjective, class) printf("Ah so you are a \x1b[1;4m%s %s\x1b[0m is that correct?(y/n) \n", adjective, class);

void get_class()
{
  clear_and_print_step("Class", 6, 8);
  char possibleClasses[6][15] = {
      "1: Warrior",
      "2: Mage",
      "3: Rogue",
      "4: Cleric",
      "5: Bard",
      "6: Archer"};
  printf("What is your class?\n");
  PRINT_LIST_ITEMS(6, possibleClasses);
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (IS_CLASS(input, "1", "warrior", "Warrior", "WARRIOR"))
  {
    strcpy(hero.Class, "Warrior");
    printf(WarriorArt);
    PRINT_CLASS("Mighty", hero.Class);
    confirm_class();
  }
  else if (IS_CLASS(input, "2", "mage", "Mage", "MAGE"))
  {
    strcpy(hero.Class, "Mage");
    printf(MageArt);
    PRINT_CLASS("Mystical", hero.Class);
    confirm_class();
  }
  else if (IS_CLASS(input, "3", "rogue", "Rogue", "ROGUE"))
  {
    strcpy(hero.Class, "Rogue");
    printf(RogueArt);
    PRINT_CLASS("Sly", hero.Class);
    confirm_class();
  }
  else if (IS_CLASS(input, "4", "cleric", "Cleric", "CLERIC"))
  {
    strcpy(hero.Class, "Cleric");
    printf(ClericArt);
    PRINT_CLASS("Holy", hero.Class);
    confirm_class();
  }
  else if (IS_CLASS(input, "5", "bard", "Bard", "BARD"))
  {
    strcpy(hero.Class, "Bard");
    printf(BardArt);
    PRINT_CLASS("Talented", hero.Class);
    confirm_class();
  }
  else if (IS_CLASS(input, "6", "archer", "Archer", "ARCHER"))
  {
    strcpy(hero.Class, "Archer");
    printf(ArcherArt);
    PRINT_CLASS("Sharpshooting", hero.Class);
    confirm_class();
  }
  else
  {
    MAKE_VALID_DECISION;
    get_class();
  }
}
// ===========================================================================================================//
void confirm_class()
{
  FGETS(confirmation);
  REMOVE_NEWLINE_CHAR(confirmation);
  if (INPUT_IS_YES(confirmation))
  {
    printf("Very well.\n");
    set_hero_level(&hero);
    log_creation_data_to_file();
  }
  else if (INPUT_IS_NO(confirmation))
  {
    get_class();
  }
  else
  {
    clear_and_print_step("Class", 6, 8);
    MAKE_VALID_DECISION;
    printf("You are a \x1b[1;4m%s\x1b[0m is that correct?(y/n) \n", hero.Class);
    confirm_class();
  }
}
// ===========================================================================================================//
void show_creation_data(FILE *logFile, const char *category, const char *value)
{
  fprintf(logFile, "%s: %s\n", category, value);
  fflush(logFile);
}

// ===========================================================================================================//
void set_hero_level(Hero *hero)
{
  hero->Level = 1;
}

// ===========================================================================================================//
void log_creation_data_to_file()
{
  // !IMPORTANT the path of the log file is accessed from where the executable is located
  FILE *logFile = fopen("../game/src/logs/runtime.log", "a");
  if (logFile == NULL)
  {
    perror("Error opening file");
    exit(1);
  }
  fprintf(logFile, "Hero Information: \n");
  fprintf(logFile, "Hero Creation Date: %s \n", __DATE__);
  show_creation_data(logFile, "First Name", hero.FirstName);
  show_creation_data(logFile, "Dynasty Name", hero.LastName);
  show_creation_data(logFile, "Gender", hero.Gender);
  show_creation_data(logFile, "Home of Origin", hero.Homeland);
  show_creation_data(logFile, "Profession", hero.Profession);
  show_creation_data(logFile, "Class", hero.Class);
  show_creation_data(logFile, "+===========================+", NULL);
  fclose(logFile);
}