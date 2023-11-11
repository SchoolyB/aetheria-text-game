#include <stdio.h>
#include <time.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"

Enemy enemy;

int initiate_combat()
{
  char input[10];
  int whoseTurnIsIt = roll_whose_turn_it_is();
  printf("Entering combat!\n");

  while (enemy.Health > 0)
  {
    // system("clear");
    MAKE_BOLD_N_UNDERLINED("IN COMBAT\n");
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

    if (roll_whose_turn_it_is() == 1)
    {
      puts("It's your turn!");
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
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability1.Name, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability1.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage);
          system("clear");
        }
        else if (strcmp(input, hero.Ability2.Name) == 0 || atoi(input) == 2)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability1.Name, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability2.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
          system("clear");
        }
        else if (strcmp(input, hero.Ability3.Name) == 0 || atoi(input) == 3)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability1.Name, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability3.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
          system("clear");
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
    }
    else if (roll_whose_turn_it_is() == 0)
    {
      puts("It's the enemy's turn!");
      sleep(2);
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
// this function calculates the mana spent by the hero. Called after each time an ability is used by the hero
void calculate_mana_spent(int *heroMana, int heroAbilityManaCost)
{
  int remainingMana = *heroMana - heroAbilityManaCost;
  int manaCost = heroAbilityManaCost;
  *heroMana = remainingMana;
}

//===================================================================================
// this function calculates the damage don eot the hero. Called after each time an ability is used by the enemy
// For cleanliness sake, I could just create one function to handle both enemy and hero dmg done to each other but I feel that could cause confusion later on
// TODO this also needs to take into consideration the enemies level
void calculate_dmg_done_to_hero(int *heroHealth, int enemyAbilityDmg)
{
  int heroRemainingHealth = *heroHealth - enemyAbilityDmg;
  int dmgDoneToHero = enemyAbilityDmg;
  *heroHealth = heroRemainingHealth;
}
//===================================================================================
// this returns a value of 1 or 0. determines whose turn it is to make a move
int roll_whose_turn_it_is()
{
  srand(time(NULL));
  int chance;

  chance = rand() % 100;
  if (chance < 50)
  {
    return 1; // hero's turn
  }
  else
  {
    return 0; // enemy's turn
  }
}
//===================================================================================
void enemy_makes_move()
{
  srand(time(NULL));
  int choice;

  choice = rand() % 3;
  if (choice == 1)
  {
    // enemy uses move 1
  }
  else if (choice == 2)
  {
    // enemy uses move 2
  }
  else
  {
    // enemy uses move 3
  }
}