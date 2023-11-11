#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"
Enemy enemy;

// have a chance to appear more often
char CommonEnemyList[10][30][30] = {
    // name, desc, type,
    {"Thief", "desc", "Non-Magical Human"},
    {"Cutthroat", "desc", "Non-Magical Human"},
    {"Highwayman", "desc", "Non-Magical Human"},
    {"Slaver", "desc", "Non-Magical Human"},
    {"Wizard's Apprentice", "desc", "Magical Human"},
    {"Cultist", "desc", "Magical Human"},
    {"Rabid Dog", "desc", "Non-Magical Beast"},
    {"Wolf", "desc", "Non-Magical Beast"},
    {"Bear", "desc", "Non-Magical Beast"},
    {"Wild Boar", "desc", "Non-Magical Beast"}};
// This function will generate a random enemy and the enemy's abilities
void generate_enemy()
{
  srand(time(NULL));
  // todo need to add a way to generate enemy based on player level

  // This var will be used to determine which abilities the enemy will have
  int setEnemyAbilities;

  int randomEnemy;
  int enemyGenerated = 0; // 0 false 1 true
  for (int i = 0; i < 9; i++)
  {
    // srand(time(NULL));
    randomEnemy = rand() % 9;
    setEnemyAbilities = rand() % 4;
  }
  char *enemyName = CommonEnemyList[randomEnemy][0];
  char *enemyDesc = CommonEnemyList[randomEnemy][1];
  char *enemyType = CommonEnemyList[randomEnemy][2];

  int randomEnemyResult; // This is the return value from the switch case below.
  printf("Enemy generated:");
  /*This switch case takes in the
    random number and evaluates its value,
    depending on the value we generated
    the corresponding enemy*/
  switch (randomEnemy)
  {
  case 0:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 0;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 1:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 1;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 2:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 2;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 3:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 3;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 4:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 4;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 5:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 5;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 6:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 6;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 7:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 7;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 8:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 8;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  case 9:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 9;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    // need time a sec before calling next func() without this program crash
    usleep(550000);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    return randomEnemyResult;
    break;
  }
}

//==================================================================================//
// this function will generate a random ability for the enemy. need to call the func 4 times to generate 4 abilities
void generate_random_hero_ability(char *AbilityName, char *AbilityDesc, char *AbilityType)
{
  static int srand_flag = 0;

  if (!srand_flag)
  {
    srand(time(NULL));
    srand_flag = 1;
  }
  // if the enemy is a non magical human then it will have a different set of abilities
  if (strcmp(enemy.Type, "Non-Magical Human") == 0)
  {
    char EnemyAbilities[15][30][30] = {
        // ability name, ability desc, ability type
        {"Backstab", "ability desc", "Physical"},
        {"Slash", "ability desc", "Physical"},
        {"Charge", "ability desc", "Physical"},
        {"Stab", "ability desc", "Physical"},
        {"Thunderous Strike", "ability desc", "Physical"},
        {"Hammer Slam", "ability desc", "Physical"},
        {"Whirlwind Strike", "ability desc", "Physical"},
        {"Cleave", "ability desc", "Physical"},
        {"Crushing Blow", "ability desc", "Physical"},
        {"Sweeping Kick", "ability desc", "Physical"},
        // Add more abilities as needed
    };

    int previousRandomAbility = -1; // Initialize to a value not in the range [0, 4]
    for (int j = 0; j < 10; j++)
    {
      int randomAbility;
      do
      {
        randomAbility = rand() % 10;
      } while (randomAbility == previousRandomAbility);

      previousRandomAbility = randomAbility;
      char *enemyAbilityName = EnemyAbilities[randomAbility][0];
      char *enemyAbilityDesc = EnemyAbilities[randomAbility][1];
      char *enemyAbilityType = EnemyAbilities[randomAbility][2];

      switch (randomAbility)
      {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
        strcpy(AbilityName, enemyAbilityName);
        strcpy(AbilityDesc, enemyAbilityDesc);
        strcpy(AbilityType, enemyAbilityType);
        printf("Generated Ability: %s\n", AbilityName);
        return;
      }
    }
  }

  // if the enemy is a magical human then it will have a different set of abilities
  else if (strcmp(enemy.Type, "Magical Human") == 0)
  {
    char EnemyAbilities[15][30][30] = {
        // ability name, ability desc, ability type
        {"Fireball", "ability desc", "Fire"},
        {"Icebolt", "ability desc", "Frost"},
        {"Lightning Bolt", "ability desc", "Lighting"},
        {"Slash", "ability desc", "Physical"},
        {"Dark Blast", "ability desc", "Dark"},
        {"Poison Sting", "ability desc", "Poison"},
        {"Earthquake", "ability desc", "Earth"},
        {"Aqua Splash", "ability desc", "Water"},
        {"Wind Cutter", "ability desc", "Wind"},
        {"Thunderstorm", "ability desc", "Lightning"},
        // Add more abilities as needed
    };

    int previousRandomAbility = -1; // Initialize to a value not in the range [0, 4]
    for (int j = 0; j < 10; j++)
    {
      int randomAbility;
      do
      {
        randomAbility = rand() % 10;
      } while (randomAbility == previousRandomAbility);

      previousRandomAbility = randomAbility;
      char *enemyAbilityName = EnemyAbilities[randomAbility][0];
      char *enemyAbilityDesc = EnemyAbilities[randomAbility][1];
      char *enemyAbilityType = EnemyAbilities[randomAbility][2];

      switch (randomAbility)
      {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
        strcpy(AbilityName, enemyAbilityName);
        strcpy(AbilityDesc, enemyAbilityDesc);
        strcpy(AbilityType, enemyAbilityType);
        printf("Generated Ability: %s\n", AbilityName);
        return;
      }
    }
  }
  // if the enemy is a non magical beast then it will have a different set of abilities
  else if (strcmp(enemy.Type, "Non-Magical Beast") == 0)
  {
    char EnemyAbilities[15][30][30] = {
        // ability name, ability desc, ability type
        {"Bite", "ability desc", "Physical"},
        {"Slash", "ability desc", "Physical"},
        {"Charge", "ability desc", "Physical"},
        {"Lacerate", "ability desc", "Physical"},
        {"Pounce", "ability desc", "Physical"},
        {"Venomous Strike", "ability desc", "Physical"},
        {"Thunderous Roar", "ability desc", "Physical"},
        {"Swift Claw", "ability desc", "Physical"},
        {"Tail Swipe", "ability desc", "Physical"},
        {"Frostbite", "ability desc", "Physical"},
        // Add more abilities as needed
    };

    int previousRandomAbility = -1; // Initialize to a value not in the range [0, 4]
    for (int j = 0; j < 10; j++)
    {
      int randomAbility;
      do
      {
        randomAbility = rand() % 10;
      } while (randomAbility == previousRandomAbility);

      previousRandomAbility = randomAbility;
      char *enemyAbilityName = EnemyAbilities[randomAbility][0];
      char *enemyAbilityDesc = EnemyAbilities[randomAbility][1];
      char *enemyAbilityType = EnemyAbilities[randomAbility][2];

      switch (randomAbility)
      {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
        strcpy(AbilityName, enemyAbilityName);
        strcpy(AbilityDesc, enemyAbilityDesc);
        strcpy(AbilityType, enemyAbilityType);
        printf("Generated Ability: %s\n", AbilityName);
        return;
      }
    }
  }
}