#include <stdio.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"
#include "2_CombatSystem.c"
#include "3_EnemyGeneration.c"

Hero hero;

// this function will be called when the hero kills an enemy
void update_current_xp(int currentXP, int xpFromEnemy)
{
  currentXP += xpFromEnemy;
  hero.CurrentXP = currentXP;
}
// this function will be called when the hero levels up
void calculate_max_xp_at_level(int level)
{
  int maxXP = level * 50;
  hero.MaxXP = maxXP;
  printf("Max XP at level %d: %d\n", level, hero.MaxXP);
}

// this function will be called when the hero kills an enemy
void calculate_xp_to_next_level(int currentXP, int maxXP)
{
  int xpToNextLevel = maxXP - currentXP;
  hero.XPToNextLevel = xpToNextLevel;
  printf("XP to next level: %d\n", hero.XPToNextLevel);
}

// this function will be called when the heros current xp is greater than or equal to the max xp
void level_up(int *level)
{
  *level += 1;
  printf("Hero is now level: %d\n", *level);
}

void run_funcs(maxXP)
{
  calculate_max_xp_at_level(hero.Level);
  // calculate_xp_to_next_level(100, hero.MaxXP);
  generate_enemy();
  initiate_combat();
}