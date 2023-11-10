#include <stdio.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"
Enemy enemy;
Hero hero;

// TODO Need to create func that increases the amount of xp dropped on death depending on the level of the hero
void generate_enemy()
{
  strcpy(enemy.Name, "Goblin");
  strcpy(enemy.Description, "A small, green creature.");
  strcpy(enemy.Type, "Common");
  enemy.Health = 100;
  enemy.ExperienceDroppedOnDeath = 20;
}