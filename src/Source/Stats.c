#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utils/Utils.h"

Hero hero;

//=================================================================================================//
#define IS_OF_CLASS(classname, string) (strcmp(classname, string) == 0)

int set_stats_and_abilities_and_inventory()
{
  if (IS_OF_CLASS(hero.Class, "Warrior"))
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

    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
    printf("You currently have a %s equipped. The %s adds %d, because of this the damage for %s in now:%d, the damage for %s is now %d, and the damage for %s is now %d \n", Inventory.Weapon.Name, Inventory.Weapon.Name, Inventory.Weapon.AddedDamage, hero.Ability1.Name, hero.Ability1.Damage, hero.Ability2.Name, hero.Ability2.Damage, hero.Ability3.Name, hero.Ability3.Damage);
  }
  else if (IS_OF_CLASS(hero.Class, "Mage"))
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
        "Punch",
        "Punch your enemy.",
        "Physical", // Type
        10,         // Damage
        0           // ManaCost
    };
    // Setting Abilities
    hero.Ability1 = Fireball;
    hero.Ability2 = Frostbolt;
    hero.Ability3 = ArcaneBlast;
  }
  else if (IS_OF_CLASS(hero.Class, "Rogue"))
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
  else if (IS_OF_CLASS(hero.Class, "Cleric"))
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
        "Physical", // Type
        30,         // Damage
        15          // ManaCost
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
  else if (IS_OF_CLASS(hero.Class, "Bard"))
  {

    // Setting Starting health and mana
    hero.Health = 40;
    hero.Mana = 60;

    // Declaring Abilities
    struct Ability1 CacophonousBlast = {
        "Cacophonous Blast",
        "Unleash a cacophonous blast of sound that shatters your enemies.",
        "Arcane", // Type
        100,      // Damage
        60        // ManaCost
    };

    struct Ability2 MelodicFury = {
        "Melodic Fury",
        "Go into a frenzy, striking your foes with a series of rapid, damaging notes.",
        "Arcane", // Type
        20,       // Damage per hit
        50        // ManaCost
    };

    struct Ability3 ResonantSurge = {
        "Resonant Surge",
        "Channel the power of resonance to unleash a devastating surge of energy.",
        "Arcane", // Type
        120,      // Single target damage
        70        // ManaCost
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
//=================================================================================================//
void set_attributes()
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
  printf("You can type either '\x1b[31m1\x1b[0m,\x1b[34m2\x1b[0m,\x1b[35m3\x1b[0m,\x1b[32m4\x1b[0m'\'\x1b[31mstr\x1b[0m,\x1b[34mint\x1b[0m,\x1b[35mdex\x1b[0m,\x1b[32mlck\x1b[0m', or the full word of each attribute that you would like to allocate points to.\n");
  sleep(2);
  printf("Which attribute would you like to allocate points to?\n");

  do
  {
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (IS_ATTRIBUTE("1", "str", "strength", "Strength", input))
    {
      printf("How many points would you like to allocate to \x1b[31mStrength\x1b[0m?");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to \x1b[31mStrength\x1b[0m.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to \x1b[31mStrength\x1b[0m.\n");
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
      printf("How many points would you like to allocate to \x1b[34mIntelligence\x1b[0m?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to \x1b[34mIntelligence\x1b[0m.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to \x1b[34mIntelligence\x1b[0m.\n");
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
      printf("How many points would you like to allocate to \x1b[35mDexterity\x1b[0m?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to \x1b[35mDexterity\x1b[0m.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to \x1b[35mDexterity\x1b[0m.\n");
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
      printf("How many points would you like to allocate to \x1b[32mLuck\x1b[0m?\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (atoi(input) > hero.AttributePointsPool)
      {
        printf("You do not have enough points to allocate %d points to \x1b[32mLuck\x1b[0m.\n", atoi(input));
        MAKE_STAT_COLOR_AND_PRINT_REMAINING;
      }
      else if (atoi(input) > MAX_POINTS)
      {
        printf("You cannot allocate more than 4 points to \x1b[32mLuck\x1b[0m.\n");
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

// This is in the event that the user wants to allocate points to strength
// This is in the event that the user wants to allocate points to intelligence
#define CALCULATE_NEW_HERO_MANA(new_mana, base_mana, int_points) new_mana = base_mana += int_points * 5;

#define CALCULATE_GLOBAL_MANA_COST(new_mana_cost, base_mana_cost, int_points) new_mana_cost = base_mana_cost += int_points * 2;

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
  else
  {
    perror("Invalid ability type\n");
    return;
  }

  calculate_new_hero_health(&hero.Health);
  calculate_new_hero_mana(&hero.Mana);

  /*
  TODO MAKE A TABLE SHOWING HOW EACH ATTRIBUTE AFFECTS EACH STAT
  TODO possibly find a better way to do this instead of calling the function 3 times
  */

  calculate_new_mana_cost(hero.IntelligenceAttribute.CurrentPoints, &hero.Ability1.ManaCost, hero.Ability1.Name);
  calculate_new_mana_cost(hero.IntelligenceAttribute.CurrentPoints, &hero.Ability2.ManaCost, hero.Ability2.Name);
  calculate_new_mana_cost(hero.IntelligenceAttribute.CurrentPoints, &hero.Ability3.ManaCost, hero.Ability3.Name);
  // END OF ATTRIBUTE POINT ALLOCATION CONFIRMATION LOGIC
}
