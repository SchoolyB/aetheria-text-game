#include <stdio.h>
#include <stdlib.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"
// #include "../XP-Enemies-Combat/1_ExperienceSystem.c"

Hero hero;
#define IS_OF_CLASS(classname, string) (strcmp(classname, string) == 0)

void set_baseline_stats()
{
  set_hero_level(&hero);                         // sets the hero to level 1 at the end of the creation process
  calculate_xp_cap_at_current_level(hero.Level); // sets the max xp for the hero at the end of the creation process
  Inventory.MaxCarryingCapacity = 50;            // testing out all classes having the same carrying capacity

  if (IS_OF_CLASS(hero.Class, "Warrior"))
  {
    hero.Health = 75;
    hero.Mana = 20;
  }
  else if (IS_OF_CLASS(hero.Class, "Mage"))
  {
    hero.Health = 40;
    hero.Mana = 70;
  }
  else if (IS_OF_CLASS(hero.Class, "Rogue"))
  {
    hero.Health = 30;
    hero.Mana = 40;
  }
  else if (IS_OF_CLASS(hero.Class, "Cleric"))
  {
    hero.Health = 60;
    hero.Mana = 50;
  }
  else if (IS_OF_CLASS(hero.Class, "Bard"))
  {
    hero.Health = 40;
    hero.Mana = 60;
  }
  else if (IS_OF_CLASS(hero.Class, "Archer"))
  {
    hero.Health = 55;
    hero.Mana = 20;
  }
  else
  {
    perror("Invalid class name you should'nt have made it this far\n");
    log_error("Invalid class", "set_baseline_stats", "exit");
  }
}
// ===========================================================================================================//
void set_hero_level(Hero *hero)
{
  hero->Level = 1;
}