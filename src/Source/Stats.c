#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utils/Utils.h"

Hero hero;

//=================================================================================================//
#define IS_CLASS(classname, string) (strcmp(classname, string) == 0)

void set_stats_and_abilities()
{
  if (IS_CLASS(hero.Class, "Warrior"))
  {

    // Setting Starting health and mana
    hero.Health = 75;
    hero.Mana = 20;

    // Declaring Abilities
    struct Ability1 Slash = {
        "Slash",
        "Slash an enemy with your weapon.",
        "Physical", // Type
        20,         // Damage
        0           // ManaCost
    };

    struct Ability2 Charge = {
        "Charge",
        "Charge at an enemy with your weapon.",
        "Physical", // Type
        25,         // Damage
        0           // ManaCost
    };

    struct Ability3 Whirlwind = {
        "Whirlwind",
        "Spin around with your weapon, hitting all enemies around you.",
        "Physical", // Type
        45,         // Damage
        10          // ManaCost
    };
    // Setting Abilities
    hero.Ability1 = Slash;
    hero.Ability2 = Charge;
    hero.Ability3 = Whirlwind;
  }
  else if (IS_CLASS(hero.Class, "Mage"))
  {
    // Setting Starting health and mana
    hero.Health = 40;
    hero.Mana = 70;

    // Declaring Abilities
    struct Ability1 Fireball = {
        "Fireball",
        "Shoot a fireball at an enemy.",
        "Fire", // Type
        30,     // Damage
        15      // ManaCost
    };

    struct Ability2 Frostbolt = {
        "Frostbolt",
        "Shoot a frostbolt at an enemy.",
        "Frost", // Type
        30,      // Damage
        15       // ManaCost
    };

    struct Ability3 ArcaneBlast = {
        "Arcane Blast",
        "Shoot a blast of arcane energy at an enemy.",
        "Arcane", // Type
        30,       // Damage
        15        // ManaCost
    };
    // Setting Abilities
    hero.Ability1 = Fireball;
    hero.Ability2 = Frostbolt;
    hero.Ability3 = ArcaneBlast;
  }
  else if (IS_CLASS(hero.Class, "Rogue"))
  {
    // Setting Starting health and mana
    hero.Health = 30;
    hero.Mana = 40;

    // Declaring Abilities
    struct Ability1 Backstab = {
        "Backstab",
        "Stab an enemy in the back.",
        "Physical", // Type
        30,         // Damage
        15          // ManaCost
    };

    struct Ability2 Shadowstep = {
        "Shadow Step",
        "Cloak yourself with invisibility then sneak up on an enemy.",
        "Dark", // Type
        30,     // Damage
        15      // ManaCost
    };
    struct Ability3 Shadowstrike = {
        "Shadow Strike",
        "Strike an enemy with dark energy.",
        "Dark", // Type
        30,     // Damage
        15      // ManaCost
    };
    // Setting Abilities
    hero.Ability1 = Backstab;
    hero.Ability2 = Shadowstep;
    hero.Ability3 = Shadowstrike;
  }
  else if (IS_CLASS(hero.Class, "Cleric"))
  {

    // Setting Starting health and mana
    hero.Health = 60;
    hero.Mana = 50;

    // Declaring Abilities
    struct Ability1 Smite = {
        "Smite",
        "Smite an enemy with holy energy.",
        "Light", // Type
        30,      // Damage
        15       // ManaCost
    };

    struct Ability2 Heal = {
        "Heal",
        "Heal yourself.",
        "Light", // Type
        30,      // Damage
        15       // ManaCost
    };

    struct Ability3 HolyBolt = {
        "Holy Bolt",
        "Shoot a bolt of holy energy at an enemy.",
        "Light", // Type
        30,      // Damage
        15       // ManaCost
    };
    // Setting Abilities
    hero.Ability1 = Smite;
    hero.Ability2 = Heal;
    hero.Ability3 = HolyBolt;
  }
  else if (IS_CLASS(hero.Class, "Bard"))
  {
    // Setting Starting health and mana
    hero.Health = 40;
    hero.Mana = 60;

    // Declaring Abilities
    struct Ability1 CacophonousBlast = {
        "Cacophonous Blast",
        "Unleash a cacophonous blast of sound that shatters your enemies.",
        "Single Target Burst Damage", // Type
        100,                          // Damage
        60                            // ManaCost
    };

    struct Ability2 MelodicFury = {
        "Melodic Fury",
        "Go into a frenzy, striking your foes with a series of rapid, damaging notes.",
        "Combo Attack", // Type
        20,             // Damage per hit
        50              // ManaCost
    };

    struct Ability3 ResonantSurge = {
        "Resonant Surge",
        "Channel the power of resonance to unleash a devastating surge of energy.",
        "Burst Damage", // Type
        120,            // Single target damage
        70              // ManaCost
    };
    // Setting Abilities
    hero.Ability1 = CacophonousBlast;
    hero.Ability2 = MelodicFury;
    hero.Ability3 = ResonantSurge;
  }

  else
  {
    perror("Invalid class name you should'nt have made it this far, that means you broke something..\n");
    return 1;
  }
}

void tester()
{

  // START OF ATTRIBUTE POINT ALLOCATION LOGIC
  hero.AttributePointsPool = 10;
  char input[10];
  char confirmation[10];

#define MAKE_STAT_COLOR(num, string, stat) printf("\x1b[%dm%s: %d\x1b[0m\n", num, string, stat);

#define PRINT_REMAINING_ATTRIBUTE_POINTS(num) printf("You have %d attribute points left to allocate. Which attribute would you like to allocate points to next?\n", num)

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

  MAKE_STAT_COLOR(31, "Strength(str)", hero.StrengthAttribute.CurrentPoints);
  MAKE_STAT_COLOR(34, "Intelligence(int)", hero.IntelligenceAttribute.CurrentPoints);
  MAKE_STAT_COLOR(35, "Dexterity(dex)", hero.DexterityAttribute.CurrentPoints);
  MAKE_STAT_COLOR(32, "Luck(lck)", hero.DexterityAttribute.CurrentPoints);

  struct Attribute
  {
    int CurrentPoints;
  } StrengthAttribute, IntelligenceAttribute, DexterityAttribute, LuckAttribute;

  printf("You have been given %d points to allocate to you attributes.\n", hero.AttributePointsPool);
  printf("You can type either '1,2,3,4', 'str','int','dex','lck', or the full word of each attribute name that you would like to allocate points to.\n");
  sleep(2);
  printf("Which attribute would you like to allocate points to?\n");

  do
  {
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (IS_ATTRIBUTE("1", "str", "strength", "Strength", input))
    {
      printf("How many points would you like to allocate to Strength?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to Strength.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to Strength.\n");
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else
      {
        printf("%d\n", MAX_POINTS);
        hero.StrengthAttribute.CurrentPoints += atoi(input);
        hero.AttributePointsPool -= atoi(input);
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
    }
    else if (IS_ATTRIBUTE("2", "int", "intelligence", "Intelligence", input))
    {
      printf("How many points would you like to allocate to Intelligence?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to Intelligence.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to Intelligence.\n");
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
      printf("How many points would you like to allocate to Dexterity?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to Dexterity.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to Dexterity.\n");
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
      printf("How many points would you like to allocate to Luck?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to Luck.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to Luck.\n");
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
  // TODO MAKE A TABLE SHOWING HOW EACH ATTRIBUTE AFFECTS EACH STAT

#define ALLOCATED_TO(number, string) printf("You have allocated %d to %s.\n", number, string);
#define CHANGE_TO_STATS(base, new, attribute) printf("The previous value of %s was %d The current value is: %d\n", attribute, base, new);
#define CALCULATE_NEW_DMG(new, base, points, number) new = base += points *number;

#define PRINT_NEW_STATS_AND_DMG() (                                                                             \
    printf("%-15s | %-15s | \n", "Health", "Mana");                                                             \
    printf("%-15s | %-15s | \n", hero.Health, hero.Mana);                                                       \
    printf("----------------------------------------------------------------------------\n");                   \
    printf("----------------------------------------------------------------------------\n");                   \
    printf("%-15s | %-15s | %-15s \n", hero.Ability1.Name, hero.Ability2.Name, hero.Ability3.Name);             \
    printf("%-15d | %-15d | %-15d \n", hero.Ability1.Damage, hero.Ability2.Damage, hero.Ability3.Damage);       \
    printf("----------------------------------------------------------------------------\n");                   \
    printf("%-15s | %-15s | %-15s \n", "Ability 1 Mana Cost", "Ability 2 Mana Cost", "Ability 3 Mana Cost");    \
    printf("%-15d | %-15d | %-15d \n", hero.Ability1.ManaCost, hero.Ability2.ManaCost, hero.Ability3.ManaCost); \
    printf("----------------------------------------------------------------------------\n"));

  // TODO need to find a way to clean these switch cases up. as it stands this is only for 1 ability in one class. would need to do 14 more like it...
  switch (hero.StrengthAttribute.CurrentPoints)
  {
  case 1:
    char with_1_attribute_point;
    ALLOCATED_TO(1, "Strength");
    CALCULATE_NEW_DMG(with_1_attribute_point, hero.Ability1.Damage, hero.StrengthAttribute.CurrentPoints, 2);
    printf("With your current attribute point allocation these are your new stats:\n");

    break;
  case 2:
    char with_2_attribute_points;
    ALLOCATED_TO(2, "Strength");
    CALCULATE_NEW_DMG(with_2_attribute_points, hero.Ability1.Damage, hero.StrengthAttribute.CurrentPoints, 2);
    printf("With your current attribute point allocation these are your new stats:\n");

    break;
  case 3:
    char with_3_attribute_points;
    ALLOCATED_TO(3, "Strength");
    CALCULATE_NEW_DMG(with_3_attribute_points, hero.Ability1.Damage, hero.StrengthAttribute.CurrentPoints, 2);
    printf("With your current attribute point allocation these are your new stats:\n");

    break;
  case 4:
    char with_4_attribute_points;
    ALLOCATED_TO(4, "Strength");
    CALCULATE_NEW_DMG(with_4_attribute_points, hero.Ability1.Damage, hero.StrengthAttribute.CurrentPoints, 2);
    printf("With your current attribute point allocation these are your new stats:\n");

  default:
    break;
  }

  // printf("Are you satisfied with your attribute point allocation?\n");
  // FGETS(confirmation);
  // REMOVE_NEWLINE_CHAR(confirmation);

  // if (strcmp(confirmation, "yes") == 0 || strcmp(confirmation, "Yes") == 0)
  // {
  //   printf("Great! Let's move on to the next step.\n");
  // }
  // else if (strcmp(confirmation, "no") == 0 || strcmp(confirmation, "No") == 0)
  // {
  //   printf("Okay, let's start over.\n");
  //   hero.AttributePointsPool = 10;
  //   hero.StrengthAttribute.CurrentPoints = 0;
  //   hero.IntelligenceAttribute.CurrentPoints = 0;
  //   hero.DexterityAttribute.CurrentPoints = 0;
  //   hero.LuckAttribute.CurrentPoints = 0;
  //   tester();
  // }
  // else
  // {
  //   printf("Invalid input, please try again.\n");
  // }

  // END OF ATTRIBUTE POINT ALLOCATION CONFIRMATION LOGIC
}