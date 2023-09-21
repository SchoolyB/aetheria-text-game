#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Utils/Global_Project_Variables.h"
#include "../../Utils/Macros/Macros.h"

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
char skillAreas[4][15] = {
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
  char skillAreaChoice[10]; // i.e strength, dex, etc
  int amount; //the amount to allocate to skill
  char allocationConfirmation[10]; //confirmation 
  printf("Now its time to allocate some points to a particular skill area.\n You can allocate points to the following areas\n");
  for(int i = 0; i < 4; i++ ){
    printf("%s\n", skillAreas[i]);
  };
  printf("You have a total of %d points to spend\n", skill_point_pool);

if(skill_point_pool > 0){ //the expression might need to be diff idk
  printf("Which area would you like to apply points\n");
  fgets(skillAreaChoice, sizeof(skillAreaChoice), stdin);
  REMOVE_NEWLINE_CHARACTER(skillAreaChoice);
  if(CHOOSE_STRENGTH(skillAreaChoice)){
    printf("How many points would you like to allocate into strength? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, hero_strength, 1);
    ALLOCATION(amount, hero_strength, 2);
    ALLOCATION(amount, hero_strength, 3);
    ALLOCATION(amount, hero_strength, 4);
    ALLOCATION_LIMIT_CHECK(amount, hero_strength, initialSKillPointAllocation());
  }
  else if(CHOOSE_INTELLIGENCE(skillAreaChoice)){
    printf("How many points would you like to allocate into intelligence? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, hero_intelligence, 1);
    ALLOCATION(amount, hero_intelligence, 2);
    ALLOCATION(amount, hero_intelligence, 3);
    ALLOCATION(amount, hero_intelligence, 4);
    ALLOCATION_LIMIT_CHECK(amount, hero_intelligence,initialSKillPointAllocation());
  }
  else if(CHOOSE_DEXTERITY(skillAreaChoice)){
    printf("How many points would you like to allocate into dexterity? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, hero_dexterity, 1);
    ALLOCATION(amount, hero_dexterity, 2);
    ALLOCATION(amount, hero_dexterity, 3);
    ALLOCATION(amount, hero_dexterity, 4);
    ALLOCATION_LIMIT_CHECK(amount, hero_dexterity,initialSKillPointAllocation());
  }
  else if(CHOOSE_LUCK(skillAreaChoice)){
    printf("How many points would you like to allocate into luck? (1 through 4)\n");
    scanf("%d", &amount);
    ALLOCATION(amount, hero_luck, 1);
    ALLOCATION(amount, hero_luck, 2);
    ALLOCATION(amount, hero_luck, 3);
    ALLOCATION(amount, hero_luck, 4);
    ALLOCATION_LIMIT_CHECK(amount, hero_luck,initialSKillPointAllocation());
  }
  else{
    MAKE_VALID_DECISION;
    initialSKillPointAllocation();
  }
}
  return 0;
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
  setHeroLvl();
  return 0;
}