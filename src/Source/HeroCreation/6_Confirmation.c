#include <stdio.h>
#include <string.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"

void confirm_hero_creation_and_stats()
{
  clear_and_print_step("Confirmation", 8, 8);
  char confirmation[10];
  printf("Well then it seems like you are ready to begin your adventure!\n");
  printf("But before you go lets go over everything one more time.\n");

  printf("Take a look at this table...\n");

  printf("============================================================================\n");
  printf("%-15s | %-15s | %-15s | %-15s \n", "First Name", "Dynasty Name", "Gender", "Nation of Origin");
  printf("%-15s | %-15s | %-15s | %-15s \n", hero.FirstName, hero.LastName, hero.Gender, hero.Homeland);
  printf("----------------------------------------------------------------------------\n");
  printf("%-15s | %-15s \n", "Profession", "Class");
  // TODO create hero level
  printf("%-15s | %-15s \n", hero.Profession, hero.Class);
  printf("----------------------------------------------------------------------------\n");
  printf("%-15s | %-15s | %-15s | %-15s \n", "Strength Points", "Intelligence Points", "Dexterity Points", "Luck Points");
  printf("%-15d | %-15d | %-15d | %-15d \n", hero.StrengthAttribute.CurrentPoints, hero.IntelligenceAttribute.CurrentPoints, hero.DexterityAttribute.CurrentPoints, hero.LuckAttribute.CurrentPoints);
  printf("----------------------------------------------------------------------------\n");
  printf("%-15s | %-15s \n", "Health", "Mana");
  printf("%-15d | %-15d \n", hero.Health, hero.Mana);
  printf("----------------------------------------------------------------------------\n");
  printf("%-15s | %-15s | %-15s \n", "Ability 1", "Ability 2", "Ability 3");
  printf("%-15s | %-15s | %-15s \n", hero.Ability1.Name, hero.Ability2.Name, hero.Ability3.Name);
  printf("============================================================================\n");

  printf("Is everything correct? (y/n)\n");
  FGETS(confirmation);
  REMOVE_NEWLINE_CHAR(confirmation);

  if (INPUT_IS_YES(confirmation))
  {
    printf("Great! It seems you are ready to begin your adventure!\n I wish you the best of luck in your endeavors\n");
  }
  else if (INPUT_IS_NO(confirmation))
  {
    char input[10];
    printf("Hmmm interesting...\n Would you like to start at the beginning or would you like to change something in particular?\n");
    printf("You can type 'redo' or '1' to start at the creation process again. You can also type 'change' or '2' to change something in particular, Lastly you can type 'confirm' or '3' to confirm the information\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (STR_CMP_TWO(input, "1", "redo"))
    {
      printf("Very well then, lets start from the beginning.\n");
      get_first_name();
    }
    else if (STR_CMP_TWO(input, "2", "change"))
    {
      change_specific_creation_item();
    }
    else if (STR_CMP_TWO(input, "3", "confirm"))
    {
      confirm_hero_creation_and_stats();
    }
    else
    {
      printf("Invalid input, please try again.\n");
      confirm_hero_creation_and_stats();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    confirm_hero_creation_and_stats();
  }

  if (hero.FirstName[0] == '\0')
  {

    printf("It seems you have not given a value to the following required category\n");
    printf("First Name\n");
    printf("Please enter something this each category before you continue.\n");
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
}
//=================================================================================================//