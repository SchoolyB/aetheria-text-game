#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utils/Globals.h"
#include "../Utils/Macros.h"
#include "../Utils/Prototypes.h"

#define MAX_SKILL_POINTS 4

int hero_health;
int hero_mana;
int hero_strength;
int hero_dexterity;
int hero_intelligence;
int hero_luck;
int hero_level;
char hero_ability1[20];
char hero_ability2[20];
char hero_ability3[20];
struct Hero_Ability
{
char name[15];
int max_possible_damage;
int min_possible_damage;
int mana_cost;
};

int skill_point_pool = 10; //this is the initial skill point pool
char skill[4][15] = {
  "Strength",
  "Dexterity",
  "Intelligence",
  "Luck"
};
//===========================================================================================================//
int setHeroStatsAndAbilities()
{
  if (strcmp(hero_class, "Warrior") == 0 ||
      strcmp(hero_class, "warrior") == 0 ||
      strcmp(hero_class, "WARRIOR") == 0)
  {
  // Hero Ability 1
  struct Hero_Ability FirstAbility;
  strcpy(FirstAbility.name, "Slash");
  FirstAbility.max_possible_damage = 15;
  FirstAbility.min_possible_damage = 7;
  FirstAbility.mana_cost = 0;
  // Give the global variable the value of the struct member
  strcpy(hero_ability1, FirstAbility.name);
  
  // Hero Ability 2
  struct Hero_Ability SecondAbility;
  strcpy(SecondAbility.name, "Cleave");
  SecondAbility.max_possible_damage = 16;
  SecondAbility.min_possible_damage = 8;
  SecondAbility.mana_cost = 0;
  // Give the global variable the value of the struct member
  strcpy(hero_ability2, SecondAbility.name);
  
  // Hero Ability 3
  struct Hero_Ability ThirdAbility;
  strcpy(ThirdAbility.name, "Thrash");
  ThirdAbility.max_possible_damage = 19;
  ThirdAbility.min_possible_damage = 10;
  ThirdAbility.mana_cost = 0;
  // Give the global variable the value of the struct member
  strcpy(hero_ability3, ThirdAbility.name);

  // Health & Mana
  hero_health = 120;
  hero_mana = 10;
  printf("As a %s you start with the following abilities:\n", hero_class);
  printf("%s\n%s\n%s\n", FirstAbility.name, SecondAbility.name, ThirdAbility.name);
  // TODO start working on combat math
  }
  else if (strcmp(hero_class, "Mage") == 0 ||
           strcmp(hero_class, "mage") == 0 ||
           strcmp(hero_class, "MAGE") == 0)
  {
    // Hero Ability 1
  struct Hero_Ability FirstAbility;
  strcpy(FirstAbility.name, "Fireball");
  FirstAbility.max_possible_damage = 10;
  FirstAbility.min_possible_damage = 5;
  FirstAbility.mana_cost = 5;
  strcpy(hero_ability1, FirstAbility.name);
  
  // Hero Ability 2
  struct Hero_Ability SecondAbility;
  strcpy(SecondAbility.name, "Frostbolt");
  SecondAbility.max_possible_damage = 15;
  SecondAbility.min_possible_damage = 10;
  SecondAbility.mana_cost = 9;
  strcpy(hero_ability2, SecondAbility.name);
  
  // Hero Ability 3
  struct Hero_Ability ThirdAbility;
  strcpy(ThirdAbility.name, "Arcane Blast");
  ThirdAbility.max_possible_damage = 21;
  ThirdAbility.min_possible_damage = 12;
  ThirdAbility.mana_cost = 12;
  strcpy(hero_ability3, ThirdAbility.name);
  // Health & Mana
    hero_health = 70;
    hero_mana = 120;
  }
  else if (strcmp(hero_class, "Rogue") == 0 ||
           strcmp(hero_class, "rogue") == 0 ||
           strcmp(hero_class, "ROGUE") == 0)
  {
    // Hero Ability 1
  struct Hero_Ability FirstAbility;
  strcpy(FirstAbility.name, "Back Stab");
  FirstAbility.max_possible_damage = 5;
  FirstAbility.min_possible_damage = 3;
  FirstAbility.mana_cost = 0;
  strcpy(hero_ability1, FirstAbility.name);
  // Hero Ability 2
  struct Hero_Ability SecondAbility;
  strcpy(SecondAbility.name, "Poison");
  SecondAbility.max_possible_damage = 9;
  SecondAbility.min_possible_damage = 5;
  SecondAbility.mana_cost = 0;
  strcpy(hero_ability2, SecondAbility.name);
  // Hero Ability 3
  struct Hero_Ability ThirdAbility;
  strcpy(ThirdAbility.name, "Assassinate");
  ThirdAbility.max_possible_damage = 16;
  ThirdAbility.min_possible_damage = 9;
  ThirdAbility.mana_cost = 0;
  strcpy(hero_ability3, ThirdAbility.name);

  // Health & Mana
    hero_health = 80;
    hero_mana = 80;
  }
  else if (strcmp(hero_class, "Cleric") == 0 ||
           strcmp(hero_class, "cleric") == 0 ||
           strcmp(hero_class, "CLERIC") == 0)
  {
    // Hero Ability 1
  struct Hero_Ability FirstAbility;
  strcpy(FirstAbility.name, "Holy Light");
  FirstAbility.max_possible_damage = 6;
  FirstAbility.min_possible_damage = 3;
  FirstAbility.mana_cost = 2;
  strcpy(hero_ability1, FirstAbility.name);
  
  // Hero Ability 2
  struct Hero_Ability SecondAbility;
  strcpy(SecondAbility.name, "Smite");
  SecondAbility.max_possible_damage = 15;
  SecondAbility.min_possible_damage = 10;
  SecondAbility.mana_cost = 0;
  strcpy(hero_ability2, SecondAbility.name);
  
  // Hero Ability 3
  struct Hero_Ability ThirdAbility;
  strcpy(ThirdAbility.name, "Divine Pillar");
  ThirdAbility.max_possible_damage = 19;
  ThirdAbility.min_possible_damage = 8;
  ThirdAbility.mana_cost = 15;
  strcpy(hero_ability3, ThirdAbility.name);

  // Health & Mana
    hero_health = 100;
    hero_mana = 100;
  }
  else if (strcmp(hero_class, "Bard") == 0 ||
           strcmp(hero_class, "bard") == 0 ||
           strcmp(hero_class, "BARD") == 0)
  {
    // Hero Ability 1
  struct Hero_Ability FirstAbility;
  strcpy(FirstAbility.name, "Ghastly Tune");
  FirstAbility.max_possible_damage = 9;
  FirstAbility.min_possible_damage = 4;
  FirstAbility.mana_cost = 2;
  strcpy(hero_ability1, FirstAbility.name);
  
  // Hero Ability 2
  struct Hero_Ability SecondAbility;
  strcpy(SecondAbility.name, "Murderous Lullaby");
  SecondAbility.max_possible_damage = 15;
  SecondAbility.min_possible_damage = 8;
  SecondAbility.mana_cost = 6;
  strcpy(hero_ability2, SecondAbility.name);
  
  // Hero Ability 3
  struct Hero_Ability ThirdAbility;
  strcpy(ThirdAbility.name, "Devilish Serenade");
  ThirdAbility.max_possible_damage = 21;
  ThirdAbility.min_possible_damage = 14;
  ThirdAbility.mana_cost = 9;
  strcpy(hero_ability3, ThirdAbility.name);

  // Health & Mana
    hero_health = 70;
    hero_mana = 70;
  }
  else
  {
    return 1;
  }
  return 0;
}

//===========================================================================================================//
int initialSKillPointAllocation(){
  printf("You have been given %d points to allocate to your skills\n", skill_point_pool);
  char skillAreaChoice[10]; // i.e strength, dex, etc
  int amount; //the amount to allocate to skill 
  printf("You can allocate points to the following areas\n");
  printf("\x1b[31m1:(str)Strength\n\x1b[0m");
  printf("\x1b[34m2:(int)Intelligence\n\x1b[0m");
  printf("\x1b[35m3:(dex)Dexterity\n\x1b[0m");
  printf("\x1b[32m4:(lck)Luck\n\x1b[0m");
  PRINT_REMAINING_POINTS(skill_point_pool);
// TODO build logic to subtract whatever number user enters for points from total point pool. then when total pool == 0 move to next phase of program.
while(skill_point_pool > 0){ //the expression might need to be diff idk
  printf("Which area would you like to apply points\n");
  fgets(skillAreaChoice, sizeof(skillAreaChoice), stdin);
  REMOVE_NEWLINE_CHARACTER(skillAreaChoice);
  if(CHOOSE_STRENGTH(skillAreaChoice)){
    printf("How many points would you like to allocate into \x1b[31mStrength\x1b[0m? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_strength, 1);
    ALLOCATION(amount, skill, hero_strength, 2);
    ALLOCATION(amount, skill, hero_strength, 3);
    ALLOCATION(amount, skill, hero_strength, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_strength, skill_point_pool, hero_strength, hero_intelligence, hero_dexterity, hero_luck);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else if(CHOOSE_INTELLIGENCE(skillAreaChoice)){
    printf("How many points would you like to allocate into \x1b[34mIntelligence\x1b[0m? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_intelligence, 1);
    ALLOCATION(amount, skill, hero_intelligence, 2);
    ALLOCATION(amount, skill, hero_intelligence, 3);
    ALLOCATION(amount, skill, hero_intelligence, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_intelligence, skill_point_pool, hero_strength, hero_intelligence, hero_dexterity, hero_luck);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else if(CHOOSE_DEXTERITY(skillAreaChoice)){
    printf("How many points would you like to allocate into \x1b[35mDexterity\x1b[0m? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_dexterity, 1);
    ALLOCATION(amount, skill, hero_dexterity, 2);
    ALLOCATION(amount, skill, hero_dexterity, 3);
    ALLOCATION(amount, skill, hero_dexterity, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_dexterity, skill_point_pool, hero_strength, hero_intelligence, hero_dexterity, hero_luck);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else if(CHOOSE_LUCK(skillAreaChoice)){
    printf("How many points would you like to allocate into \x1b[32mLuck\x1b[0m? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_luck, 1);
    ALLOCATION(amount, skill, hero_luck, 2);
    ALLOCATION(amount, skill, hero_luck, 3);
    ALLOCATION(amount, skill, hero_luck, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_luck, skill_point_pool, hero_strength, hero_intelligence, hero_dexterity, hero_luck);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else{
    MAKE_VALID_DECISION;
    initialSKillPointAllocation();
  }
}
  return 0;
}
//===========================================================================================================//
int allocationConfirmation(){
  char allocationConfirmationInput[10];
  if(skill_point_pool == 0){
  // TODO REMOVE THIS STRING AND REPLACE WITH A FUNCTION CALL TO THE NEXT PART OF THE PROGRAM
// printf("YOU HIT THE MARK, MOVING ON TO NEXT PART OF PROGRAM\n");

  printf("Are you sure that you want to continue with these points in these areas?\n");
  printf("\x1b[31mStrength: %d\n\x1b[0m", hero_strength);
  printf("\x1b[34mIntelligence: %d\n\x1b[0m", hero_intelligence);
  printf("\x1b[35mDexterity: %d\n\x1b[0m", hero_dexterity);
  printf("\x1b[32mLuck: %d\n\x1b[0m", hero_luck);\

  fgets(allocationConfirmationInput, sizeof(allocationConfirmationInput), stdin);
  REMOVE_NEWLINE_CHARACTER(allocationConfirmationInput);
  if(IS_YES(allocationConfirmationInput)){
    printf("You have chosen to continue with these points\n");
    printf("Moving on to next part of program\n");
  }
  else if(IS_NO(allocationConfirmationInput)){
    printf("You have chosen to reallocate your points\n");
    skill_point_pool = 10;
    initialSKillPointAllocation();
    allocationConfirmation();
  }
  else{
    MAKE_VALID_DECISION;
    allocationConfirmation();
  }
 }
}
//===========================================================================================================//
int setHeroLvl()
{
  hero_level = 1;
  return 0;
}
//===========================================================================================================//
// KEEP THIS FUNCTION AT THE BOTTOM OF THE FILE
int setAllHeroStats()
{ 
  setHeroStatsAndAbilities();
  initialSKillPointAllocation();
  allocationConfirmation();
  setHeroLvl();
  return 0;
}