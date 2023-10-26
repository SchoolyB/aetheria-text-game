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
    // set_attributes();
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

    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Driftwood staff", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
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

    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Rusty Dagger", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
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

    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Rusty Mace", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
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
    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Driftwood Lute", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
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
    printf("it is recommended that you apply some points to \x1b[31mStrength\x1b[0m\n");
    printf("Doing so means you can deliver more powerful physical blows to enemies and endure more damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Mage"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to \x1b[34mIntelligence\x1b[0m\n");
    printf("Doing so means you can deliver more powerful magical blows to enemies and endure more magical damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Rogue"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to \x1b[35mDexterity\x1b[0m\n");
    printf("Doing so means you can deliver more powerful physical blows to enemies and endure more damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Cleric"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to \x1b[34mIntelligence\x1b[0m\n");
    printf("Doing so means you can deliver more powerful magical blows to enemies and endure more magical damage in battle.\n");
  }
  else if (STR_CMP(hero.Class, "Bard"))
  {
    printf("If you are playing as a \x1b[1;4m%s\x1b[0m ", hero.Class);
    printf("it is recommended that you apply some points to \x1b[34mIntelligence\x1b[0m\n");
    printf("Doing so means you can deliver more powerful magical blows to enemies and endure more magical damage in battle.\n");
  }
  else
  {
    perror("Invalid class name you should'nt have made it this far, that means you broke something..\n");
    return 1;
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
  printf("You can type the associated numbers such as'\x1b[31m1\x1b[0m,\x1b[34m2\x1b[0m,\x1b[35m3\x1b[0m,\x1b[32m4\x1b[0m',\n abbreviations such as\'\x1b[31mstr\x1b[0m,\x1b[34mint\x1b[0m,\x1b[35mdex\x1b[0m,\x1b[32mlck\x1b[0m', or the full word of each attribute of your choice.\n");
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
    return 1;
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
//=================================================================================================//

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
    printf("You can type 'redo' or '1' to start at the creation process again. You can also type 'change' or '2' to change something in particular.\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

#define STR_CMP_TWO(input, string1, string2) (strcmp(input, string1) == 0 || strcmp(input, string2) == 0)

    if (STR_CMP_TWO(input, "1", "redo"))
    {
      printf("Very well then, lets start from the beginning.\n");
      get_first_name();
    }
    else if (STR_CMP_TWO(input, "2", "change"))
    {
      change_specific_creation_item();
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
  printf("(7)Stat Allocation: \x1b[31mstr:%d\x1b[0m  \x1b[34mint:%d\x1b[0m \x1b[35mdex%d\x1b[0m \x1b[32mlck:%d\x1b[0m\n", hero.StrengthAttribute.CurrentPoints, hero.IntelligenceAttribute.CurrentPoints, hero.DexterityAttribute.CurrentPoints, hero.LuckAttribute.CurrentPoints);
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
        printf("Very well, tell what your gender is.\n");
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
      set_stats_and_abilities_and_inventory();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "2"))
    {
      strcpy(hero.Class, "Mage");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_stats_and_abilities_and_inventory();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "3"))
    {
      strcpy(hero.Class, "Rogue");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_stats_and_abilities_and_inventory();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "4"))
    {
      strcpy(hero.Class, "Cleric");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_stats_and_abilities_and_inventory();
      change_specific_creation_item();
    }
    else if (STR_CMP(new, "5"))
    {
      strcpy(hero.Class, "Bard");
      printf("Very well, your new class is %s.\n", hero.Class);
      set_stats_and_abilities_and_inventory();
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