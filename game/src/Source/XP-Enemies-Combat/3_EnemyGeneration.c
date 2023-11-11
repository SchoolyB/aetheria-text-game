#include <stdio.h>
#include <time.h>
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

char EnemyAbilities[10][30][30] = {
    // ability name, ability desc, ability type
    {"Backstab", "ability desc", "Physical"},
    {"Slash", "ability desc", "Physical"},
    {"Charge", "ability desc", "Physical"},
    {"Stab", "ability desc", "Physical"},
    {"Whip", "ability desc", "Physical"},
    {"Fireball", "ability desc", "Fire"},
    {"Icebolt", "ability desc", "Frost"},
    {"Lightning Bolt", "ability desc", "Lighting"},
    {"Bite", "ability desc", "Physical"},

};

// This function will generate a random enemy and the enemy's abilities
void generate_enemy()
{
  // todo need to add a way to generate enemy based on player level

  // This var will be used to determine which abilities the enemy will have
  int setEnemyAbilities;

  int randomEnemy;
  int enemyGenerated = 0; // 0 false 1 true
  for (int i = 0; i < 9; i++)
  {
    srand(time(NULL));
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
    return randomEnemyResult;
    break;
  case 1:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 1;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    return randomEnemyResult;
    break;
  case 2:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 2;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 3:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 3;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 4:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 4;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 5:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 5;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 6:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 6;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 7:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 7;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 8:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 8;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  case 9:
    strcpy(enemy.Name, enemyName);
    strcpy(enemy.Type, enemyType);
    printf("%s\n", enemy.Name);
    randomEnemyResult = 9;
    generate_random_hero_ability(enemy.EnemyAbility1.Name, enemy.EnemyAbility1.Description, enemy.EnemyAbility1.Type);
    generate_random_hero_ability(enemy.EnemyAbility2.Name, enemy.EnemyAbility2.Description, enemy.EnemyAbility2.Type);
    generate_random_hero_ability(enemy.EnemyAbility3.Name, enemy.EnemyAbility3.Description, enemy.EnemyAbility3.Type);
    generate_random_hero_ability(enemy.EnemyAbility4.Name, enemy.EnemyAbility4.Description, enemy.EnemyAbility4.Type);
    return randomEnemyResult;
    break;
  }
}

//==================================================================================//
// this function will generate a random ability for the enemy. need to call the func 4 times to generate 4 abilities
void generate_random_hero_ability(char *AbilityName, char *AbilityDesc, char *AbilityType)
{

  // if the enemy is a non magical human then it will have a different set of abilities
  if (strcmp(enemy.Type, "Non-Magical Human") == 0)
  {

    char EnemyAbilities[10][30][30] = {
        // ability name, ability desc, ability type
        {"Backstab", "ability desc", "Physical"},
        {"Slash", "ability desc", "Physical"},
        {"Charge", "ability desc", "Physical"},
        {"Stab", "ability desc", "Physical"},
        {"Bite", "ability desc", "Physical"},
    };
  }
  // if the enemy is a magical human then it will have a different set of abilities
  else if (strcmp(enemy.Type, "Magical Human") == 0)
  {
    char EnemyAbilities[10][30][30] = {
        // ability name, ability desc, ability type
        {"Fireball", "ability desc", "Fire"},
        {"Icebolt", "ability desc", "Frost"},
        {"Lightning Bolt", "ability desc", "Lighting"},
        {"Slash", "ability desc", "Physical"},
        {"Dark Blast", "ability desc", "Dark"},
    };
  }
  // if the enemy is a non magical beast then it will have a different set of abilities
  else if (strcmp(enemy.Type, "Non-Magical Beast") == 0)
  {
    char EnemyAbilities[10][30][30] = {
        // ability name, ability desc, ability type
        {"Bite", "ability desc", "Physical"},
        {"Slash", "ability desc", "Physical"},
        {"Charge", "ability desc", "Physical"},
        {"Lacerate", "ability desc", "Physical"},
        {"Pounce", "ability desc", "Physical"},
    };
  }

  int randomAbility;
  for (int j = 0; j < 5; j++)
  {
    srand(time(NULL));
    randomAbility = rand() % 5;
  }
  printf("Ability generated: %s\n", EnemyAbilities[randomAbility][0]);
  char *enemyAbilityName = EnemyAbilities[randomAbility][0];
  char *enemyAbilityDesc = EnemyAbilities[randomAbility][1];
  char *enemyAbilityType = EnemyAbilities[randomAbility][2];
  switch (randomAbility)
  {
  case 0:
    strcpy(AbilityName, enemyAbilityName);
    strcpy(AbilityDesc, enemyAbilityDesc);
    strcpy(AbilityType, enemyAbilityType);
    break;
  case 1:
    strcpy(AbilityName, enemyAbilityName);
    strcpy(AbilityDesc, enemyAbilityDesc);
    strcpy(AbilityType, enemyAbilityType);
    break;
  case 2:
    strcpy(AbilityName, enemyAbilityName);
    strcpy(AbilityDesc, enemyAbilityDesc);
    strcpy(AbilityType, enemyAbilityType);
    break;
  case 3:
    strcpy(AbilityName, enemyAbilityName);
    strcpy(AbilityDesc, enemyAbilityDesc);
    strcpy(AbilityType, enemyAbilityType);
    break;
  case 4:
    strcpy(AbilityName, enemyAbilityName);
    strcpy(AbilityDesc, enemyAbilityDesc);
    strcpy(AbilityType, enemyAbilityType);
    break;
  }
}
