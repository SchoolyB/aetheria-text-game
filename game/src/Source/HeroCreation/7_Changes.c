#include <stdio.h>
#include <string.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"

//=============================================================================================
// Takes care of all the logic for changing a specific hero creation item such as name, class, gender, etc.
void change_specific_creation_item()
{
  system("clear");
  printf("What would you like to change?\n Enter the number of the item you would like to change.\n");
  printf("Enter the number 8 to confirm your hero\n");
  printf("(1)First Name:");
  MAKE_BOLD_N_UNDERLINED(hero.FirstName);
  printf("\n");
  printf("(2)Last Name:");
  MAKE_BOLD_N_UNDERLINED(hero.LastName);
  printf("\n");
  printf("(3)Gender:");
  MAKE_BOLD_N_UNDERLINED(hero.Gender);
  printf("\n");
  printf("(4)Homeland:");
  MAKE_BOLD_N_UNDERLINED(hero.Homeland);
  printf("\n");
  printf("(5)Profession:");
  MAKE_BOLD_N_UNDERLINED(hero.Profession);
  printf("\n");
  printf("(6)Class:");
  MAKE_BOLD_N_UNDERLINED(hero.Class);
  printf("\n");
  printf("(7)Stat Allocation:" RED "str:%d " BLUE "int:%d " PURPLE "dex%d " GREEN "lck:%d " RESET "\n", hero.StrengthAttribute.CurrentPoints, hero.IntelligenceAttribute.CurrentPoints, hero.DexterityAttribute.CurrentPoints, hero.LuckAttribute.CurrentPoints);
  printf("(8)Confirm Hero\n");

  char input[10];

  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (STR_CMP(input, "1"))
  {
    printf("Currently you first name is %s\n", hero.FirstName);
    printf("What would you like to change your first name to?\n");
    char new[10];
    FGETS(new);
    REMOVE_NEWLINE_CHAR(new);
    printf("Very well you will no longer have the first name of %s\n", hero.FirstName);
    strcpy(hero.FirstName, new);
    printf("Your first name is now %s\n", hero.FirstName);
    change_specific_creation_item();
  }
  else if (STR_CMP(input, "2"))
  {
    if (hero.LastName[0] == '\0')
    {
      printf("You currently do not have a dynasty name.\n");
      printf("Would you like to set a dynasty name?\n");
      char want_dynasty_name[10];
      FGETS(want_dynasty_name);
      REMOVE_NEWLINE_CHAR(want_dynasty_name);
      if (INPUT_IS_YES(want_dynasty_name))
      {
        printf("Very well you will now have a dynasty name.\n");
        printf("What would you like your dynasty name to be?\n");
        char new[10];
        FGETS(new);
        REMOVE_NEWLINE_CHAR(new);
        strcpy(hero.LastName, new);
        printf("Your dynasty name is now %s\n", new);
        change_specific_creation_item();
      }
      else if (INPUT_IS_NO(want_dynasty_name))
      {
        printf("Very well you will not have a dynasty name.\n");
        change_specific_creation_item();
      }
      else
      {
        MAKE_VALID_DECISION;
        change_specific_creation_item();
      }
    }
    else
    {
      printf("Currently you dynasty name is %s\n", hero.LastName);
      printf("What would you like to change your dynasty name to?\n");
      char new[10];
      FGETS(new);
      REMOVE_NEWLINE_CHAR(new);
      strcpy(hero.LastName, new);
      printf("Your dynasty name is now %s\n", new);
      change_specific_creation_item();
    }
  }
  else if (STR_CMP(input, "3"))
  {
    if (hero.Gender[0] == '\0')
    {
      printf("You do not have a gender would you like to set one?\n");
      printf("Would you like to set a gender");
      char want_gender[10];
      FGETS(want_gender);
      REMOVE_NEWLINE_CHAR(want_gender);
      if (INPUT_IS_YES(want_gender))
      {
        printf("Very well, what is your gender is.\n");
        char new[10];
        FGETS(new);
        REMOVE_NEWLINE_CHAR(new);
        if (IS_GENDER(new, "m", "M", "man", "Man", "male", "Male"))
        {
          strcpy(hero.Gender, "Male");
          printf("Your gender is now %s\n", hero.Gender);
          change_specific_creation_item();
        }
        else if (IS_GENDER(new, "f", "F", "woman", "Woman", "female", "Female"))
        {
          strcpy(hero.Gender, "Female");
          printf("Your gender is now %s\n", hero.Gender);
          change_specific_creation_item();
        }
        else
        {
          strcpy(hero.Gender, new);
          printf("Very well your gender is now %s\n", hero.Gender);
          change_specific_creation_item();
        }
      }
      else if (INPUT_IS_NO(want_gender))
      {
        printf("Very well you will not have a gender\n");
        change_specific_creation_item();
      }
      else
      {
        MAKE_VALID_DECISION;
        change_specific_creation_item();
      }
    }
    else
    {
      printf("Currently your gender is %s\n", hero.Gender);
      printf("What would you like set your gender to?\n");
      char new[10];
      FGETS(new);
      REMOVE_NEWLINE_CHAR(new);
      if (IS_GENDER(new, "m", "M", "man", "Man", "male", "male"))
      {
        strcpy(hero.Gender, "Male");
        printf("Your gender is now %s\n", hero.Gender);
        change_specific_creation_item();
      }
      else if (IS_GENDER(new, "f", "F", "woman", "Woman", "female", "Female"))
      {
        strcpy(hero.Gender, "Female");
        printf("Your gender is now %s\n", hero.Gender);
        change_specific_creation_item();
      }
      else
      {
        strcpy(hero.Gender, new);
        printf("Very well your gender is now %s\n", hero.Gender);
        change_specific_creation_item();
      }
    }
  }
  else if (STR_CMP(input, "4"))
  {
    printf("I thought you were from the lands %s but it seems I was mistaken.\n", hero.Homeland);
    printf("Where are you from?\n");
    printf("Enter the number of the nation that you hail from.\n");
    char possibleHomelands[5][15] =
        {
            "1: Empyrea",
            "2: Wesward",
            "3: Magdalar",
            "4: Ashvadan",
            "5: Nadafia"};

    PRINT_LIST_ITEMS(5, possibleHomelands);
    char new[10];
    FGETS(new);
    REMOVE_NEWLINE_CHAR(new);
    if (STR_CMP(new, "1"))
    {
      strcpy(hero.Homeland, "Empyrea");
      printf("Very well, you now hail from the lands of %s.\n", hero.Homeland);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "2"))
    {
      strcpy(hero.Homeland, "Wesward");
      printf("Very well, you now hail from the lands of %s.\n", hero.Homeland);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "3"))
    {
      strcpy(hero.Homeland, "Magdalar");
      printf("Very well, you now hail from the lands of %s.\n", hero.Homeland);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "4"))
    {
      strcpy(hero.Homeland, "Ashvadan");
      printf("Very well, you now hail from the lands of %s.\n", hero.Homeland);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "5"))
    {
      strcpy(hero.Homeland, "Nadafia");
      printf("Very well, you now hail from the lands of %s.\n", hero.Homeland);
      change_specific_creation_item();
    }
    else
    {
      MAKE_VALID_DECISION;
      change_specific_creation_item;
    }
  }
  else if (STR_CMP(input, "5"))
  {
    printf("Your current profession is %s.\n", hero.Profession);
    printf("What is your new profession?\n");
    printf("Enter the number of the profession\n");
    char possibleProfessions[6][15] = {
        "1: Merchant",
        "2: Hunter",
        "3: Soldier",
        "4: thief",
        "5: Scholar",
        "6: None"};

    PRINT_LIST_ITEMS(6, possibleProfessions);
    char new[10];
    FGETS(new);
    REMOVE_NEWLINE_CHAR(new);

    if (STR_CMP(new, "1"))
    {
      strcpy(hero.Profession, "Merchant");
      printf("Very well, your new profession is %s.\n", hero.Profession);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "2"))
    {
      strcpy(hero.Profession, "Hunter");
      printf("Very well, your new profession is %s.\n", hero.Profession);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "3"))
    {
      strcpy(hero.Profession, "Soldier");
      printf("Very well, your new profession is %s.\n", hero.Profession);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "4"))
    {
      strcpy(hero.Profession, "Thief");
      printf("Very well, your new profession is %s.\n", hero.Profession);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "5"))
    {
      strcpy(hero.Profession, "Scholar");
      printf("Very well, your new profession is %s.\n", hero.Profession);
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "6"))
    {
      strcpy(hero.Profession, "None");
      printf("Very well, your new profession is %s.\n", hero.Profession);
      change_specific_creation_item();
    }
    else
    {
      MAKE_VALID_DECISION;
      change_specific_creation_item();
    }
  }
  else if (STR_CMP(input, "6"))
  {
    char possibleClasses[5][15] = {
        "1: Warrior",
        "2: Mage",
        "3: Rogue",
        "4: Cleric",
        "5: Bard"};
    char new[10];

    printf("Your current class is %s.\n", hero.Class);
    printf("What is your new class?\n");

    PRINT_LIST_ITEMS(5, possibleClasses);
    FGETS(new);
    REMOVE_NEWLINE_CHAR(new);

    if (STR_CMP(new, "1"))
    {
      strcpy(hero.Class, "Warrior");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_abilities();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "2"))
    {
      strcpy(hero.Class, "Mage");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_abilities();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "3"))
    {
      strcpy(hero.Class, "Rogue");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_abilities();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "4"))
    {
      strcpy(hero.Class, "Cleric");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_abilities();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "5"))
    {
      strcpy(hero.Class, "Bard");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_abilities();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "6"))
    {
      strcpy(hero.Class, "Archer");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_abilities();
      change_specific_creation_item();
    }
    else
    {
      MAKE_VALID_DECISION;
      change_specific_creation_item();
    }
  }
  else if (STR_CMP(input, "7"))
  {
    printf("Lets go over your attributes.\n");
    do
    {
      set_attributes();
    } while (hero.AttributePointsPool > 0);
    change_specific_creation_item();
  }
  else if (STR_CMP(input, "8"))
  {
    confirm_hero_creation_and_stats();
  }
  else
  {
    MAKE_VALID_DECISION;
    change_specific_creation_item();
  }

  if (hero.Homeland[0] == '\0')
  {
    printf("It seems you have not given a value to the following required category\n");
    printf("Home of Origin\n");
    printf("Please enter something in this category before you continue.\n");
    change_specific_creation_item();
  }

  if (hero.Class[0] == '\0')
  {

    printf("It seems you have not given a value to the following required category\n");
    printf("Class\n");
    printf("Please enter something this each category before you continue.\n");
    change_specific_creation_item();
  }

  if (hero.AttributePointsPool > 0)
  {
    PRINT_REMAINING_ATTRIBUTE_POINTS(hero.AttributePointsPool);
    printf("Please allocate all remaining attribute points before you continue.");
    change_specific_creation_item();
  }
  if (hero.AttributePointsPool > 0)
  {
    PRINT_REMAINING_ATTRIBUTE_POINTS(hero.AttributePointsPool);
    printf("Please allocate all remaining attribute points before you continue.");
    change_specific_creation_item();
  }
}