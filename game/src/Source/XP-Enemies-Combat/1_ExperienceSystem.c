#include <stdio.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"
#include "2_CombatSystem.c"
#include "3_EnemyGeneration.c"

Hero hero;

// Called when the hero kills an enemy
void update_current_xp(int currentXP, int xpFromEnemy)
{
  currentXP += xpFromEnemy;
  hero.CurrentXP = currentXP;
}
//================================================================================================
// Called when the hero levels up
// this function calculates the max xp at the heros current level
void calculate_max_xp_at_level(int level)
{
  int maxXP = level * 50;
  hero.MaxXP = maxXP;
  printf("Max XP at level %d: %d\n", level, hero.MaxXP);
}
//================================================================================================
// Called when the hero kills an enemy
// this function calculates the xp needed to achieve the to next level
void calculate_xp_to_next_level(int currentXP, int maxXP)
{
  int xpToNextLevel = maxXP - currentXP;
  hero.XPToNextLevel = xpToNextLevel;
  printf("XP to next level: %d\n", hero.XPToNextLevel);
}
//================================================================================================
// Called when the heros current xp is greater than or equal to the max xp
// this function levels up the hero
void level_up(int *level)
{
  *level += 1;
  printf("Hero is now level: %d\n", *level);
}

//================================================================================================
// TODO delete when done with debugging Called when the hero kills an enemy
void run_funcs(maxXP)
{
  generate_enemy();
  // calculate_max_xp_at_level(hero.Level);
  // generate_enemy();
  // initiate_combat();
}