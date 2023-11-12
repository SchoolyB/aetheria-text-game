#include <stdio.h>
#include <time.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"

Enemy enemy;

int initiate_combat()
{
  srand(time(NULL));
  int heroMadeMove = 0;
  int enemyMadeMove = 0;
  printf("Entering combat!\n");
  int CombatOnGoing = 1;
  do
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
    printf("%s" YELLOW "Name:%-50s" RESET "\n", "|", enemy.Name);
    printf("%s" YELLOW "Type:%-50s" RESET "\n", "|", enemy.Type);
    printf("%s" YELLOW "Health:%-50d" RESET "\n", "|", enemy.Health);
    printf("%s" YELLOW "Ability1:%-50s" RESET "\n", "|", enemy.EnemyAbility1.Name);
    printf("%s" YELLOW "Ability2:%-50s" RESET "\n", "|", enemy.EnemyAbility2.Name);
    printf("%s" YELLOW "Ability1Dmg:%-50d" RESET "\n", "|", enemy.EnemyAbility1.Damage);
    printf("%s" YELLOW "Ability2Dmg:%-50d" RESET "\n", "|", enemy.EnemyAbility2.Damage);

    printf("%s 1:%s Dmg:%d Mana Cost:%d\n", "|", hero.Ability1.Name, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage, hero.Ability1.ManaCost);
    printf("%s 2:%s Dmg:%d Mana Cost:%d\n", "|", hero.Ability2.Name, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage, hero.Ability2.ManaCost);
    printf("%s 3:%s Dmg:%d Mana Cost:%d\n", "|", hero.Ability3.Name, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage, hero.Ability3.ManaCost);

    printf("%s \n", "|");
    puts("==================================================================================");

    int heroMadeMove = 0;
    int enemyMadeMove = 0;

    int chance = rand() % 100;
    if (chance < 50)
    {
      puts("It's your turn!");
      char input[10];

      int heroMadeMove = 0;
      puts("What would you like to do?");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);

      if (strcmp(input, "attack") == 0 || strcmp(input, "fight") == 0 || strcmp(input, "charge") == 0)
      {
        puts("Which ability will you use? Enter the name or number.");
        FGETS(input);
        REMOVE_NEWLINE_CHAR(input);

        if (strcmp(input, hero.Ability1.Name) == 0 || atoi(input) == 1 && hero.Mana >= hero.Ability1.ManaCost)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability1.Name, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability1.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability1.Damage + Inventory.EquippedWeapon.AddedDamage);
          heroMadeMove = 1;
          system("clear");
        }
        else if (strcmp(input, hero.Ability1.Name) == 0 || atoi(input) == 1 && hero.Mana < hero.Ability1.ManaCost)
        {
          printf("You don't have enough mana to use %s!\n", hero.Ability1.Name);
        }
        //===================================================================================================

        if (strcmp(input, hero.Ability2.Name) == 0 || atoi(input) == 2 && hero.Mana >= hero.Ability2.ManaCost)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability2.Name, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability2.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
          heroMadeMove = 1;
          system("clear");
        }
        else if (strcmp(input, hero.Ability2.Name) == 0 || atoi(input) == 2 && hero.Mana < hero.Ability2.ManaCost)
        {
          printf("You don't have enough mana to use %s!\n", hero.Ability2.Name);
        }
        //===================================================================================================

        if (strcmp(input, hero.Ability3.Name) == 0 || atoi(input) == 3 && hero.Mana >= hero.Ability3.ManaCost)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability3.Name, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability3.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
          heroMadeMove = 1;
          system("clear");
        }
        else if (strcmp(input, hero.Ability3.Name) == 0 || atoi(input) == 3 && hero.Mana < hero.Ability3.ManaCost)
        {
          printf("You don't have enough mana to use %s!\n", hero.Ability3.Name);
        }
      }
      else if (strcmp(input, "run") == 0 || strcmp(input, "run away") == 0 || strcmp(input, "escape") == 0 || strcmp(input, "leave") == 0)
      {
        int chance;

        chance = rand() % 100;
        if (chance < 40)
        {
          puts("You've successfully ran away.");
          CombatOnGoing = 0;
        }
        else
        {
          puts("You've failed to run away!");
          heroMadeMove = 1;
        }
      }
      heroMadeMove = 1;
    }
    else if (chance >= 50)
    {
      // handling the enemy's turn
      puts("It's the enemy's turn!");
      sleep(2);
      enemy_makes_move();
      enemyMadeMove = 1;
    }
    else
    {
      puts("Something went wrong!");
      return 1;
    }

    // START OF ENEMY AND HERO DEATH HANDLING
    if (enemy.Health <= 0)
    {
      update_current_xp(hero.CurrentXP, enemy.ExperienceDroppedOnDeath);
      printf("You've defeated %s and have gained %d xp your xp is now at %d! your max xp at level:%d is %d\n", enemy.Name, enemy.ExperienceDroppedOnDeath, hero.CurrentXP, hero.Level, hero.MaxXP);
      calculate_xp_to_next_level(hero.CurrentXP, hero.MaxXP);

      if (hero.CurrentXP >= hero.MaxXP)
      {
        level_up(&hero.Level);
      }
    }
  } while (hero.Health > 0 && enemy.Health > 0 && CombatOnGoing == 1);
}

//===================================================================================
// this function calculates the enemies new health. Called after each time an ability is used by the hero
void calculate_dmg_done_to_enemy(int *currentEnemyHealth, int heroAbilityDmg)
{
  int enemyRemainingHealth = *currentEnemyHealth - heroAbilityDmg;
  *currentEnemyHealth = enemyRemainingHealth;
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
void calculate_dmg_done_to_hero(int *heroHealth, int *enemyAbilityDmg, const char *abilityName)
{
  int heroRemainingHealth = *heroHealth - *enemyAbilityDmg;
  *heroHealth = heroRemainingHealth;
  printf("The enemy used %s dealing %d damage to you!\n", abilityName, *enemyAbilityDmg);

  if (*heroHealth <= 0)
  {

    MAKE_BOLD_N_COLOR(31, "You've died!\n");
    // Add further actions if needed when the hero dies
  }
}

//===================================================================================
void enemy_makes_move()
{
  int choice = rand() % 2;
  if (choice == 0)
  {
    calculate_dmg_done_to_hero(&hero.Health, &enemy.EnemyAbility1.Damage, enemy.EnemyAbility1.Name);
  }
  else
  {
    calculate_dmg_done_to_hero(&hero.Health, &enemy.EnemyAbility2.Damage, enemy.EnemyAbility2.Name);
  }
}
//===================================================================================
int check_hero_remaining_mana(char *heroAbilityManaCost, char *heroAbilityName)
{
  if (hero.Mana < *heroAbilityManaCost)
  {
    printf("You do not have enough mana to use %s!\n", *heroAbilityName);
    return 0;
  }

  else if (hero.Mana >= *heroAbilityManaCost)
  {
    return 1;
  }
}