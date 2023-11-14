#include <stdio.h>
#include <stdlib.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"

//=================================================================================================//
int set_attributes()
{
  clear_and_print_step("Attribute Points", 7, 8);
  // START OF ATTRIBUTE POINT ALLOCATION LOGIC
  hero.AttributePointsPool = 10;
  char input[10];
  char confirmation[10];

#define MAKE_STAT_COLOR(num, string, stat) printf("\x1b[%dm%s: %d\x1b[0m\n", num, string, stat);

#define PRINT_REMAINING_ATTRIBUTE_POINTS(num) printf("You have %d attribute points left to allocate. Which attribute would you like to allocate points to next?\n", num)
  if (STR_CMP(hero.Class, "Warrior"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to" RED "Strength" RESET "\n");
    printf("Doing so means you can deliver more powerful physical blows to enemies and endure more damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Mage"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to" BLUE "Intelligence" RESET "\n");
    printf("Doing so means you can deliver more powerful magical blows to enemies and endure more magical damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Rogue"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to" PURPLE "Dexterity" RESET "\n");
    printf("Doing so means you can deliver more powerful physical blows to enemies and endure more damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Cleric"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to" BLUE "Intelligence" RESET "\n");
    printf("Doing so means you can deliver more powerful magical blows to enemies and endure more magical damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Bard"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to" BLUE "Intelligence" RESET "\n");
    printf("Doing so means you can deliver more powerful magical blows to enemies and endure more magical damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Archer"))
  {
    printf("If you are playing as an \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("It is recommended that you apply some points to" PURPLE "Dexterity" RESET "\n");
    printf("Doing so means you can to land precise and fatal shots on your targets in battle\n");
  }
  else
  {
    perror("Invalid class name you should'nt have made it this far\n");
    log_error("Invalid class", "set_attributes", "exit");
  }

#define MAKE_STAT_COLOR_AND_PRINT_REMAINING                                           \
  PRINT_REMAINING_ATTRIBUTE_POINTS(hero.AttributePointsPool);                         \
  MAKE_STAT_COLOR(31, "Strength(str)", hero.StrengthAttribute.CurrentPoints);         \
  MAKE_STAT_COLOR(34, "Intelligence(int)", hero.IntelligenceAttribute.CurrentPoints); \
  MAKE_STAT_COLOR(35, "Dexterity(dex)", hero.DexterityAttribute.CurrentPoints);       \
  MAKE_STAT_COLOR(32, "Luck(lck)", hero.LuckAttribute.CurrentPoints);

#define IS_ATTRIBUTE(num, short, full_low, full_cap, input) (strcmp(input, num) == 0 ||      \
                                                             strcmp(input, short) == 0 ||    \
                                                             strcmp(input, full_low) == 0 || \
                                                             strcmp(input, full_cap) == 0)
#define MAX_POINTS 4

  MAKE_STAT_COLOR(31, "1:Strength(str)", hero.StrengthAttribute.CurrentPoints);
  MAKE_STAT_COLOR(34, "2:Intelligence(int)", hero.IntelligenceAttribute.CurrentPoints);
  MAKE_STAT_COLOR(35, "3:Dexterity(dex)", hero.DexterityAttribute.CurrentPoints);
  MAKE_STAT_COLOR(32, "4:Luck(lck)", hero.DexterityAttribute.CurrentPoints);

  struct Attribute
  {
    int CurrentPoints;
  } StrengthAttribute, IntelligenceAttribute, DexterityAttribute, LuckAttribute;

  printf("You have been given %d points to allocate to you attributes.\n", hero.AttributePointsPool);
  printf("There are three ways to choose which attribute to apply points to. They are:\n");
  printf("1.Typing the number associated with the attribute." RED "1, " BLUE "2, " PURPLE "3, " GREEN "4" RESET "\n");
  printf("2.Typing the abbreviation of the attribute." RED "str, " BLUE "int, " PURPLE "dex, " GREEN "lck" RESET "\n");
  printf("3.Typing the full word of the attribute.\n");
  sleep(2);
  printf("Which attribute would you like to allocate points to?\n");

  do
  {
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (IS_ATTRIBUTE("1", "str", "strength", "Strength", input))
    {
      system("clear");
      printf("How many points would you like to allocate to " RED "Strength" RESET "\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);
      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to " RED "Strength" RESET "\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to " RED "Strength" RESET "\n");
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else
      {
        hero.StrengthAttribute.CurrentPoints += atoi(input);
        hero.AttributePointsPool -= atoi(input);
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
    }
    else if (IS_ATTRIBUTE("2", "int", "intelligence", "Intelligence", input))
    {
      system("clear");
      printf("How many points would you like to allocate to " BLUE "Intelligence" RESET "\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to " BLUE "Intelligence" RESET "\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to " BLUE "Intelligence" RESET "\n");
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else
      {
        hero.IntelligenceAttribute.CurrentPoints += atoi(input);
        hero.AttributePointsPool -= atoi(input);
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
    }
    else if (IS_ATTRIBUTE("3", "dex", "dexterity", "Dexterity", input))
    {
      system("clear");
      printf("How many points would you like to allocate to" PURPLE "Dexterity" RESET "\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to" PURPLE "Dexterity" RESET "\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to" PURPLE "Dexterity" RESET "\n");
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else
      {
        hero.DexterityAttribute.CurrentPoints += atoi(input);
        hero.AttributePointsPool -= atoi(input);
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
    }
    else if (IS_ATTRIBUTE("4", "lck", "luck", "Luck", input))
    {
      system("clear");
      printf("How many points would you like to allocate to " GREEN "Luck" RESET "\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to " GREEN "Luck" RESET "\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to to " GREEN "Luck" RESET "\n");
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else
      {
        hero.LuckAttribute.CurrentPoints += atoi(input);
        hero.AttributePointsPool -= atoi(input);
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
    }
    else
    {
      printf("Invalid input, please try again.\n");
      MAKE_STAT_COLOR_AND_PRINT_REMAINING;
    }

  } while (hero.AttributePointsPool > 0);

  // END OF ATTRIBUTE POINT ALLOCATION LOGIC

  // START OF ATTRIBUTE POINT ALLOCATION CONFIRMATION LOGIC

  MAKE_STAT_COLOR(31, "Strength(str)", hero.StrengthAttribute.CurrentPoints);
  MAKE_STAT_COLOR(34, "Intelligence(int)", hero.IntelligenceAttribute.CurrentPoints);
  MAKE_STAT_COLOR(35, "Dexterity(dex)", hero.DexterityAttribute.CurrentPoints);
  MAKE_STAT_COLOR(32, "Luck(lck)", hero.LuckAttribute.CurrentPoints);

  // Handles physical damage
  if (strcmp(hero.Ability1.Type, "Physical") == 0 ||
      strcmp(hero.Ability2.Type, "Physical") == 0 ||
      strcmp(hero.Ability3.Type, "Physical") == 0)
  {
    calculate_new_hero_dmg_str(&hero.Ability1.Damage, hero.Ability1.Name);
    calculate_new_hero_dmg_str(&hero.Ability2.Damage, hero.Ability2.Name);
    calculate_new_hero_dmg_str(&hero.Ability3.Damage, hero.Ability3.Name);
  }
  // Handles different types of magic damage
  else if (strcmp(hero.Ability1.Type, "Fire") == 0 ||
           strcmp(hero.Ability2.Type, "Fire") == 0 ||
           strcmp(hero.Ability3.Type, "Fire") == 0 ||
           strcmp(hero.Ability1.Type, "Frost") == 0 ||
           strcmp(hero.Ability2.Type, "Frost") == 0 ||
           strcmp(hero.Ability3.Type, "Frost") == 0 ||
           strcmp(hero.Ability1.Type, "Arcane") == 0 ||
           strcmp(hero.Ability2.Type, "Arcane") == 0 ||
           strcmp(hero.Ability3.Type, "Arcane") == 0 ||
           strcmp(hero.Ability1.Type, "Dark") == 0 ||
           strcmp(hero.Ability2.Type, "Dark") == 0 ||
           strcmp(hero.Ability3.Type, "Dark") == 0 ||
           strcmp(hero.Ability1.Type, "Light") == 0 ||
           strcmp(hero.Ability2.Type, "Light") == 0 ||
           strcmp(hero.Ability3.Type, "Light") == 0)
  {
    calculate_new_hero_dmg_int(&hero.Ability1.Damage, hero.Ability1.Name);
    calculate_new_hero_dmg_int(&hero.Ability2.Damage, hero.Ability2.Name);
    calculate_new_hero_dmg_int(&hero.Ability3.Damage, hero.Ability3.Name);
  }
  else if (strcmp(hero.Ability1.Type, "Ranged") == 0 ||
           strcmp(hero.Ability1.Type, "Ranged") == 0 ||
           strcmp(hero.Ability1.Type, "Ranged") == 0)
  {
    calculate_new_hero_dmg_dex(&hero.Ability1.Damage, hero.Ability1.Name);
    calculate_new_hero_dmg_dex(&hero.Ability2.Damage, hero.Ability2.Name);
    calculate_new_hero_dmg_dex(&hero.Ability3.Damage, hero.Ability3.Name);
  }
  else
  {
    perror("Invalid ability type\n");
    logMessage("Invalid ability type", "set_attributes()");
  }
  // TODO need to find a bette rplace for these...this is stupid and ugly
  calculate_new_hero_health(&hero.Health);
  calculate_new_hero_mana(&hero.Mana);
  calculate_new_max_carrying_capacity_from_str(&Inventory.MaxCarryingCapacity);

  /*
  TODO MAKE A TABLE SHOWING HOW EACH ATTRIBUTE AFFECTS EACH STAT
  TODO possibly find a better way to do this instead of calling the function 3 times
  */

  calculate_new_mana_cost(hero.IntelligenceAttribute.CurrentPoints, &hero.Ability1.ManaCost, hero.Ability1.Name);
  calculate_new_mana_cost(hero.IntelligenceAttribute.CurrentPoints, &hero.Ability2.ManaCost, hero.Ability2.Name);
  calculate_new_mana_cost(hero.IntelligenceAttribute.CurrentPoints, &hero.Ability3.ManaCost, hero.Ability3.Name);
}
//=================================================================================================//
