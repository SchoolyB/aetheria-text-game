#include <stdio.h>
#include <time.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"

Enemy enemy;

int initiate_combat()
{
  char input[10];
  printf("Entering combat!\n");

  while (enemy.Health > 0)
  {
    printf("Now fighting: %s\n", enemy.Name);
    printf("Enemy health: %d\n", enemy.Health);

    // Creating combat ui
    puts("==================================================================================");
    printf("%s %s %-50s %-50s\n", "|", hero.FirstName, hero.LastName, enemy.Name);

    printf("%s" GREEN "Health: %-50d", "|", hero.Health);
    printf(GREEN "Health:%-50d" RESET "\n", enemy.Health);

    printf("%s" BLUE "Mana: %-50d" RESET "\n", "|", hero.Mana);

    printf("%s \n", "|");
    printf("%s \n", "|");
    printf("%s \n", "|");
    printf("%s \n", "|");
    printf("%s \n", "|");
    printf("%s \n", "|");
    printf("%s \n", "|");
    printf("%s \n", "|");

    printf("%s 1:%s Dmg:%d Mana Cost:%d\n", "|", hero.Ability1.Name, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage, hero.Ability1.ManaCost);
    printf("%s 2:%s Dmg:%d Mana Cost:%d\n", "|", hero.Ability2.Name, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage, hero.Ability2.ManaCost);
    printf("%s 3:%s Dmg:%d Mana Cost:%d\n", "|", hero.Ability3.Name, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage, hero.Ability3.ManaCost);

    printf("%s \n", "|");
    puts("==================================================================================");

    puts("What would you like to do?");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (strcmp(input, "attack") == 0 || strcmp(input, "fight") == 0 || strcmp(input, "charge") == 0)
    {
      puts("Which ability will you use? Enter the name or number.");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (strcmp(input, hero.Ability1.Name) == 0 || atoi(input) == 1)
      {
        printf("%s used %s\n", hero.FirstName, hero.Ability1.Name);
        calculate_mana_spent(&hero.Mana, hero.Ability1.ManaCost);
        calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage);
      }
      else if (strcmp(input, hero.Ability2.Name) == 0 || atoi(input) == 2)
      {
        printf("%s used %s\n", hero.FirstName, hero.Ability1.Name);
        calculate_mana_spent(&hero.Mana, hero.Ability2.ManaCost);
        calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
      }
      else if (strcmp(input, hero.Ability3.Name) == 0 || atoi(input) == 3)
      {
        printf("%s used %s\n", hero.FirstName, hero.Ability1.Name);
        calculate_mana_spent(&hero.Mana, hero.Ability3.ManaCost);
        calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
      }
      else
      {
        MAKE_VALID_DECISION;
        return;
      }
    }
    else if (strcmp(input, "run") == 0 || strcmp(input, "run away") == 0 || strcmp(input, "escape") == 0 || strcmp(input, "leave") == 0)
    {
      srand(time(NULL));
      int chance;

      chance = rand() % 100;
      if (chance < 40)
      {
        puts("You've successfully ran away.");
        return 0;
      }
      else
      {
        puts("You've failed to run away!");
      }
    }
    // handle exp functions
    if (enemy.Health <= 0)
    {
      update_current_xp(hero.CurrentXP, enemy.ExperienceDroppedOnDeath);
      printf("You've defeated %s and have gained %d xp your xp is now at %d! your max xp at level:%d is %d\n", enemy.Name, enemy.ExperienceDroppedOnDeath, hero.CurrentXP, hero.Level, hero.MaxXP);
      calculate_xp_to_next_level(hero.CurrentXP, hero.MaxXP);

      if (hero.CurrentXP >= hero.MaxXP)
      {
        level_up(&hero.Level);
        return 0;
      }
    }
  }
}

//===================================================================================
// this function calculates the enemies new health. Called after each time an ability is used by the hero
void calculate_dmg_done_to_enemy(int *enemyHealth, int heroAbilityDmg)
{
  int enemyRemainingHealth = *enemyHealth - heroAbilityDmg;
  int dmgDoneToEnemy = heroAbilityDmg;
  *enemyHealth = enemyRemainingHealth;
}
//===================================================================================
void calculate_mana_spent(int *heroMana, int heroAbilityManaCost)
{
  int remainingMana = *heroMana - heroAbilityManaCost;
  int manaCost = heroAbilityManaCost;
  *heroMana = remainingMana;
}