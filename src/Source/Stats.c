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
char hero_class[10];

int skill_point_pool = 10; //this is the initial skill point pool
char skill[4][15] = {
  "Strength",
  "Dexterity",
  "Intelligence",
  "Luck"
};

int setHeroHealth()
{
  if (strcmp(hero_class, "Warrior") == 0 ||
      strcmp(hero_class, "warrior") == 0 ||
      strcmp(hero_class, "WARRIOR") == 0)
  {
    hero_health = 120;
  }
  else if (strcmp(hero_class, "Mage") == 0 ||
           strcmp(hero_class, "mage") == 0 ||
           strcmp(hero_class, "MAGE") == 0)
  {
    hero_health = 70;
  }
  else if (strcmp(hero_class, "Rogue") == 0 ||
           strcmp(hero_class, "rogue") == 0 ||
           strcmp(hero_class, "ROGUE") == 0)
  {
    hero_health = 80;
  }
  else if (strcmp(hero_class, "Cleric") == 0 ||
           strcmp(hero_class, "cleric") == 0 ||
           strcmp(hero_class, "CLERIC") == 0)
  {
    hero_health = 100;
  }
  else if (strcmp(hero_class, "Bard") == 0 ||
           strcmp(hero_class, "bard") == 0 ||
           strcmp(hero_class, "BARD") == 0)
  {
    hero_health = 70;
  }
  else
  {
    return 1;
  }
  return 0;
}

int setHeroMana()
{
  if (strcmp(hero_class, "Warrior") == 0 ||
      strcmp(hero_class, "warrior") == 0 ||
      strcmp(hero_class, "WARRIOR") == 0)
  {
    hero_mana = 20;
  }
  else if (strcmp(hero_class, "Mage") == 0 ||
           strcmp(hero_class, "mage") == 0 ||
           strcmp(hero_class, "MAGE") == 0)
  {
    hero_mana = 120;
  }
  else if (strcmp(hero_class, "Rogue") == 0 ||
           strcmp(hero_class, "rogue") == 0 ||
           strcmp(hero_class, "ROGUE") == 0)
  {
    hero_mana = 80;
  }
  else if (strcmp(hero_class, "Cleric") == 0 ||
           strcmp(hero_class, "cleric") == 0 ||
           strcmp(hero_class, "CLERIC") == 0)
  {
    hero_mana = 100;
  }
  else if (strcmp(hero_class, "Bard") == 0 ||
           strcmp(hero_class, "bard") == 0 ||
           strcmp(hero_class, "BARD") == 0)
  {
    hero_mana = 70;
  }
  else
  {
    return 1;
  }
  return 0;
}
//=======================================================
int initialSKillPointAllocation(){
  printf("You have %d points to allocate to your skills\n", skill_point_pool);
  char skillAreaChoice[10]; // i.e strength, dex, etc
  int amount; //the amount to allocate to skill 
  printf("You can allocate points to the following areas\n");
  printf("\x1b[31m1:Strength\n\x1b[0m");
  printf("\x1b[34m2:Intelligence\n\x1b[0m");
  printf("\x1b[35m3:Dexterity\n\x1b[0m");
  printf("\x1b[32m4:Luck\n\x1b[0m");
  PRINT_REMAINING_POINTS(skill_point_pool);
// TODO build logic to subtract whatever number user enters for points from total point pool. then when total pool == 0 move to next phase of program.
while(skill_point_pool > 0){ //the expression might need to be diff idk
  printf("Which area would you like to apply points\n");
  fgets(skillAreaChoice, sizeof(skillAreaChoice), stdin);
  REMOVE_NEWLINE_CHARACTER(skillAreaChoice);
  if(CHOOSE_STRENGTH(skillAreaChoice)){
    printf("How many points would you like to allocate into strength? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_strength, 1);
    ALLOCATION(amount, skill, hero_strength, 2);
    ALLOCATION(amount, skill, hero_strength, 3);
    ALLOCATION(amount, skill, hero_strength, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_strength);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else if(CHOOSE_INTELLIGENCE(skillAreaChoice)){
    printf("How many points would you like to allocate into intelligence? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_intelligence, 1);
    ALLOCATION(amount, skill, hero_intelligence, 2);
    ALLOCATION(amount, skill, hero_intelligence, 3);
    ALLOCATION(amount, skill, hero_intelligence, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_intelligence);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else if(CHOOSE_DEXTERITY(skillAreaChoice)){
    printf("How many points would you like to allocate into dexterity? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_dexterity, 1);
    ALLOCATION(amount, skill, hero_dexterity, 2);
    ALLOCATION(amount, skill, hero_dexterity, 3);
    ALLOCATION(amount, skill, hero_dexterity, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_dexterity);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else if(CHOOSE_LUCK(skillAreaChoice)){
    printf("How many points would you like to allocate into luck? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, skill, hero_luck, 1);
    ALLOCATION(amount, skill, hero_luck, 2);
    ALLOCATION(amount, skill, hero_luck, 3);
    ALLOCATION(amount, skill, hero_luck, 4);
    skill_point_pool  = skill_point_pool - amount;
    ALLOCATION_LIMIT_CHECK(amount, hero_luck);
    PRINT_REMAINING_POINTS(skill_point_pool);
  }
  else{
    MAKE_VALID_DECISION;
    initialSKillPointAllocation();
  }
}
  return 0;
}
 
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
int setHeroLvl()
{
  hero_level = 1;
  return 0;
}
int setAllHeroStats()
{
  setHeroHealth();
  setHeroMana();
  initialSKillPointAllocation();
  allocationConfirmation();
  setHeroLvl();
  return 0;
}