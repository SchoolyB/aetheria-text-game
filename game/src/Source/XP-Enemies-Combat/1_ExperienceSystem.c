#include <stdio.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"
#include "2_CombatSystem.c"
#include "3_EnemyGeneration.c"

Hero hero;

// First func called when the hero kills an enemy
// this function calculates the current xp that the hero has
void calculate_current_xp(float *XPGainedFromEnemy)
{
  float *currentXP;
  currentXP = &(hero.CurrentXP); // this is dereferencing the pointer.
  *currentXP = *currentXP + *XPGainedFromEnemy;
}

//================================================================================================
// Second func called when the hero kills an enemy
// this function calculates the max xp at the heros current level
void calculate_xp_cap_at_current_level(int level)
{
  float maxXP = level * 25;
  hero.MaxXP = maxXP;
}
//================================================================================================
// Called when the heros current xp is greater than or equal to the max xp
// this function levels up the hero
void level_up(int *level, int *heroCurrentXP)
{
  *level += 1;
  calculate_xp_cap_at_current_level(hero.Level);
  calculate_hero_health_after_level_up(&hero.Health, hero.Level);
  calculate_hero_mana_after_level_up(&hero.Mana, hero.Level);
  // Not sure if I want to reset the xp to 0 or keep it at the current xp
  *heroCurrentXP = 0;
  printf("Hero is now level: %d\n", *level);
}

//================================================================================================
// START ENEMY XP STUFF
// this function calculates the xp dropped by the enemy
// then calls the function to calculate the xp dropped with the modifier
void calculate_enemy_base_xp_dropped(int heroLevel)
{
  int XPDroppedOnDeath;
  float XPAsFloat;
  if (heroLevel <= 3)
  {
    XPDroppedOnDeath = 10;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 3 && heroLevel <= 6)
  {
    XPDroppedOnDeath = 20;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 6 && heroLevel <= 9)
  {
    XPDroppedOnDeath = 30;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 9 && heroLevel <= 12)
  {
    XPDroppedOnDeath = 40;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 12 && heroLevel <= 15)
  {
    XPDroppedOnDeath = 50;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 15 && heroLevel <= 18)
  {
    XPDroppedOnDeath = 60;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 18 && heroLevel <= 21)
  {
    XPDroppedOnDeath = 70;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
  else if (heroLevel > 21 && heroLevel <= 24)
  {
    XPDroppedOnDeath = 80;
    XPAsFloat = (float)XPDroppedOnDeath;
    calculate_enemy_xp_dropped_with_modifier(&XPAsFloat, heroLevel);
  }
}
//================================================================================================
// this function calculates the xp dropped by the enemy with the modifier
// this is called by the calculate_enemy_base_xp_dropped() function
void calculate_enemy_xp_dropped_with_modifier(float *XPDroppedOnDeath, int heroLevel)
{
  float xpDroppedOnDeath = *XPDroppedOnDeath;
  int heroLvl = heroLevel;
  float xpDroppedOnDeathModifier;
  if (heroLvl <= 3)
  {
    xpDroppedOnDeathModifier = 1.0;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 3 && heroLvl <= 6)
  {
    xpDroppedOnDeathModifier = 1.50;
    // if someone dropped 100 xp and the modifier is 2 then the new xp dropped would be 200
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 6 && heroLvl <= 9)
  {
    xpDroppedOnDeathModifier = 2.25;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 9 && heroLvl <= 12)
  {
    xpDroppedOnDeathModifier = 3.0;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 12 && heroLvl <= 15)
  {
    xpDroppedOnDeathModifier = 3.75;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 15 && heroLvl <= 18)
  {
    xpDroppedOnDeathModifier = 4.50;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 18 && heroLvl <= 21)
  {
    xpDroppedOnDeathModifier = 5.25;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
  else if (heroLvl > 21 && heroLvl <= 24)
  {
    xpDroppedOnDeathModifier = 6.0;
    enemy.ExperienceDroppedOnDeath = xpDroppedOnDeath * xpDroppedOnDeathModifier;
  }
}
//================================================================================================
// this function handles the heros  health increase. should be called when the hero levels up
void calculate_hero_health_after_level_up(int *heroHealth, int heroLvl)
{
  switch (heroLvl)
  {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
  case 15:
  case 16:
  case 17:
  case 18:
  case 19:
  case 20:
    hero.Health += 12;
    break;
  }
  hero.Health = *heroHealth;
}
//=================================================================================================
// this function handles the heros mana increase. should be called when the hero levels up
void calculate_hero_mana_after_level_up(int *heroMana, int heroLvl)
{
  switch (heroLvl)
  {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
  case 15:
  case 16:
  case 17:
  case 18:
  case 19:
  case 20:
    hero.Mana += 8;
    break;
  }
  hero.Mana = *heroMana;
}
//================================================================================================
void run_funcs(maxXP)
{
  generate_enemy();
  // initiate_combat();
  level_up(&hero.Level, &hero.CurrentXP);
}