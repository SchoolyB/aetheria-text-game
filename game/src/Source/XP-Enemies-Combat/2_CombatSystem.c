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
  refresh_combat_ui(0);
  do
  {

    int heroMadeMove = 0;
    int enemyMadeMove = 0;

    int chance = rand() % 100;
    if (chance < 50)
    {
      puts("It's your turn!");
      char input[10];

      int heroMadeMove = 0;
      puts("What would you like to do?(fight, item, run, skip, help)");
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
          refresh_combat_ui(2);
        }
        else if (strcmp(input, hero.Ability1.Name) == 0 || atoi(input) == 1 && hero.Mana < hero.Ability1.ManaCost)
        {
          printf("You don't have enough mana to use %s!\n", hero.Ability1.Name);
          refresh_combat_ui(2);
        }
        //===================================================================================================

        if (strcmp(input, hero.Ability2.Name) == 0 || atoi(input) == 2 && hero.Mana >= hero.Ability2.ManaCost)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability2.Name, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability2.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability2.Damage + Inventory.EquippedWeapon.AddedDamage);
          heroMadeMove = 1;
          refresh_combat_ui(1);
        }
        else if (strcmp(input, hero.Ability2.Name) == 0 || atoi(input) == 2 && hero.Mana < hero.Ability2.ManaCost)
        {
          printf("You don't have enough mana to use %s!\n", hero.Ability2.Name);
          refresh_combat_ui(1);
        }
        //===================================================================================================

        if (strcmp(input, hero.Ability3.Name) == 0 || atoi(input) == 3 && hero.Mana >= hero.Ability3.ManaCost)
        {
          printf("%s used %s dealing %d damage.\n", hero.FirstName, hero.Ability3.Name, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
          sleep(2);
          calculate_mana_spent(&hero.Mana, hero.Ability3.ManaCost);
          calculate_dmg_done_to_enemy(&enemy.Health, hero.Ability3.Damage + Inventory.EquippedWeapon.AddedDamage);
          heroMadeMove = 1;
          refresh_combat_ui(1);
        }
        else if (strcmp(input, hero.Ability3.Name) == 0 || atoi(input) == 3 && hero.Mana < hero.Ability3.ManaCost)
        {
          printf("You don't have enough mana to use %s!\n", hero.Ability3.Name);
          refresh_combat_ui(1);
        }
      }
      else if (strcmp(input, "run") == 0 || strcmp(input, "run away") == 0 || strcmp(input, "escape") == 0 || strcmp(input, "leave") == 0 || strcmp(input, "flee") == 0 || strcmp(input, "Run") == 0 || strcmp(input, "Run Away") == 0 || strcmp(input, "Escape") == 0 || strcmp(input, "Leave") == 0 || strcmp(input, "Flee") == 0)
      {
        int chance;

        chance = rand() % 100;
        if (chance < 40)
        {
          puts("You've successfully ran away.");
          CombatOnGoing = 0;

          MAKE_BOLD_N_UNDERLINED("EXIT COMBAT\n");
        }
        else
        {
          puts("You've failed to run away!");
          heroMadeMove = 1;
          refresh_combat_ui(2);
        }
      }
      else if (strcmp(input, "skip") == 0 || strcmp(input, "Skip") == 0)
      {
        puts("You've skipped your turn!");
        heroMadeMove = 1;
      }
      else if (strcmp(input, "item") == 0 || strcmp(input, "Item") == 0)
      {
        if (Inventory.Slot1.isOpen == 1 && Inventory.Slot2.isOpen == 1 && Inventory.Slot3.isOpen == 1)
        {
          puts("You have no usable items in your inventory");
          refresh_combat_ui(1);
        }
        else
        {
          puts("What item would you like to use?");
          // TODO keep working on this
        }
      }
      else if (strcmp(input, "help") == 0 || strcmp(input, "Help") == 0)
      {
        int goBack = 0;
        char input[10];
        do
        {
          show_combat_help_menu();
          FGETS(input);
          REMOVE_NEWLINE_CHAR(input);
          if (strcmp(input, "back") == 0)
          {
            goBack = 1;
            refresh_combat_ui(0);
          }
          else
          {
            puts("Invalid command! Type help to see the commands you can use.");
            system("clear");
            refresh_combat_ui(0);
          }
        } while (goBack == 0);
      }
      else
      {
        puts("Invalid command! Type help to see the commands you can use.");
      }
    }
    else if (chance >= 50)
    {
      // handling the enemy's turn
      puts("It's the enemy's turn!");
      sleep(2);
      enemy_makes_move();
      refresh_combat_ui(2);
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
      system("clear");
      MAKE_BOLD_N_UNDERLINED("EXITED COMBAT\n");
      printf("You've defeated %s!\n", enemy.Name);
      printf("You've gained %f XP!\n", enemy.ExperienceDroppedOnDeath);
      calculate_current_xp(&enemy.ExperienceDroppedOnDeath);
      calculate_xp_cap_at_current_level(hero.Level);

      if (hero.CurrentXP >= hero.MaxXP)
      {
        level_up(&hero.Level, &hero.CurrentXP);
        // calling this function again to recalculate the max xp at the heros new level
        calculate_xp_cap_at_current_level(hero.Level);
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
void calculate_dmg_done_to_hero(int *heroHealth, int *enemyAbilityDmg, const char *abilityName)
{
  int heroRemainingHealth = *heroHealth - *enemyAbilityDmg;
  *heroHealth = heroRemainingHealth;
  printf("The enemy used %s dealing %d damage to you!\n", abilityName, *enemyAbilityDmg);

  if (*heroHealth <= 0)
  {

    MAKE_BOLD_N_COLOR("You've died!\n", 31);
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
void refresh_combat_ui(int sleepTime)
{
  sleep(sleepTime);
  system("clear");
  MAKE_BOLD_N_UNDERLINED("IN COMBAT\n");
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
}

void show_combat_help_menu()
{
  printf("=============================================================================\n");
  printf("%-10s | %-30s \n", "Combat Commands", "Description");
  printf("----------------------------------------------------------------------------\n");
  printf("%-10s | %-30s \n", "Fight", "Use powerful abilities to destroy your enemy");
  printf("%-10s | %-30s \n", "Item", "Use an item from your inventory");
  printf("%-10s | %-30s \n", "Run", "Attempt to run away like a coward");
  printf(RED "%-10s | %-30s \n", "Skip", "Skip your turn be warned you may take damage from the enemy" RESET);
  printf("%-10s | %-30s \n", "Help", "Display helpful commands to use during");
  printf("=============================================================================\n");
  printf("Type 'back' to go back to the combat menu.\n");
}