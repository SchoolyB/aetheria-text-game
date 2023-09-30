#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utils/Globals.h"
#include "../Utils/Macros.h"
#include "../Utils/Prototypes.h"

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

int amount; //used for skill allocation
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
  }
  else if (strcmp(hero_class, "Mage") == 0 ||
           strcmp(hero_class, "mage") == 0 ||
           strcmp(hero_class, "MAGE") == 0)
  {
  // Hero Ability 1
  struct Hero_Ability FirstAbility;
  strcpy(FirstAbility.name, "Fireball");
  FirstAbility.max_possible_damage = 12;
  FirstAbility.min_possible_damage = 6;
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
int points_allocation(){
  printf("You have been given %d points to allocate to your skills\n", skill_point_pool);
  printf("You can type numbers 1,2,3 or 4, the abbreviations for each skill or the full word\n");
  printf("Which skill would you like to allocate points to?\n");
  printf("\x1b[31m(str)Strength: %d\n\x1b[0m", hero_strength);
  printf("\x1b[34m(int)Intelligence: %d\n\x1b[0m", hero_intelligence);
  printf("\x1b[35m(dex)Dexterity: %d\n\x1b[0m", hero_dexterity);
  printf("\x1b[32m(lck)Luck: %d\n\x1b[0m", hero_luck);
  do{
    char skillAreaChoice[10]; // i.e strength, dex, etc
   //the amount to allocate to skill 
  fgets(skillAreaChoice, sizeof(skillAreaChoice), stdin);
  REMOVE_NEWLINE_CHARACTER(skillAreaChoice);
  if(CHOOSE_STRENGTH(skillAreaChoice)){
     ALLOCATE_TO_SKILL("Strength", amount, skill_point_pool, hero_strength);
    PRINT_REMAINING_POINTS(skill_point_pool);
    printf("Which skill would you like to allocate points to?\n");
    printf("\x1b[31m(str)Strength: %d\n\x1b[0m", hero_strength);
    printf("\x1b[34m(int)Intelligence: %d\n\x1b[0m", hero_intelligence);
    printf("\x1b[35m(dex)Dexterity: %d\n\x1b[0m", hero_dexterity);
    printf("\x1b[32m(lck)Luck: %d\n\x1b[0m", hero_luck);
  }
  else if(CHOOSE_INTELLIGENCE(skillAreaChoice)){
    ALLOCATE_TO_SKILL("Intelligence", amount, skill_point_pool, hero_intelligence);
    PRINT_REMAINING_POINTS(skill_point_pool);
    printf("Which skill would you like to allocate points to?\n");
    printf("\x1b[31m(str)Strength: %d\n\x1b[0m", hero_strength);
    printf("\x1b[34m(int)Intelligence: %d\n\x1b[0m", hero_intelligence);
    printf("\x1b[35m(dex)Dexterity: %d\n\x1b[0m", hero_dexterity);
    printf("\x1b[32m(lck)Luck: %d\n\x1b[0m", hero_luck);
  }
  else if(CHOOSE_DEXTERITY(skillAreaChoice)){
    ALLOCATE_TO_SKILL("Dexterity", amount, skill_point_pool, hero_dexterity);
    PRINT_REMAINING_POINTS(skill_point_pool);
    printf("Which skill would you like to allocate points to?\n");
    printf("\x1b[31m(str)Strength: %d\n\x1b[0m", hero_strength);
    printf("\x1b[34m(int)Intelligence: %d\n\x1b[0m", hero_intelligence);
    printf("\x1b[35m(dex)Dexterity: %d\n\x1b[0m", hero_dexterity);
    printf("\x1b[32m(lck)Luck: %d\n\x1b[0m", hero_luck);
  }

  else if(CHOOSE_LUCK(skillAreaChoice)){
    ALLOCATE_TO_SKILL("Luck", amount, skill_point_pool, hero_luck);
    PRINT_REMAINING_POINTS(skill_point_pool);
    printf("Which skill would you like to allocate points to?\n");
    printf("\x1b[31m(str)Strength: %d\n\x1b[0m", hero_strength);
    printf("\x1b[34m(int)Intelligence: %d\n\x1b[0m", hero_intelligence);
    printf("\x1b[35m(dex)Dexterity: %d\n\x1b[0m", hero_dexterity);
    printf("\x1b[32m(lck)Luck: %d\n\x1b[0m", hero_luck);
  }
  capAllocation();
  }while (skill_point_pool > 0);
}
//===========================================================================================================//
int capAllocation(){
   if(hero_strength > 4 || hero_dexterity > 4 || hero_intelligence > 4 || hero_luck > 4){
    printf("You can only allocate 4 points to a skill area at this time...\n");
    printf("Resetting skill points...Please try again\n");
    refreshPoints();
    points_allocation();
  }
    else{
    return 0;
  }
}
//===========================================================================================================//
int refreshPoints(){
  skill_point_pool = 10;
  hero_strength = 0;
  hero_dexterity = 0;
  hero_intelligence = 0;
  hero_luck = 0;
}
//===========================================================================================================//
int confirmAllocation(){
  char allocationConfirmation[10];
  printf("Are you sure you want to allocate these points? (y/n)\n");
  while (getchar() != '\n'); // Clear input buffer. look up "Buffer Flushing"
  fgets(allocationConfirmation, sizeof(allocationConfirmation), stdin);
  REMOVE_NEWLINE_CHARACTER(allocationConfirmation);
  if(IS_YES(allocationConfirmation)){
    printf("Points allocated successfully!\n");
    return 0;
  }
  else if(IS_NO(allocationConfirmation)){
    printf("Resetting skill points...Please try again\n");
    refreshPoints();
    points_allocation();
  }
  else{
    MAKE_VALID_DECISION;
    confirmAllocation();
  }
}
//===========================================================================================================//
int setHeroLevel(){
  hero_level = 1;
  return 0;
}
//===========================================================================================================//
int setStatsPointsAbilities(){
  points_allocation();
  setHeroStatsAndAbilities();
  confirmAllocation();
  setHeroLevel();
  return 0;
}