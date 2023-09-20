#include <stdio.h>
#include "../../Utils/Global_Project_Variables.h"
#include "../../Enemies/Enemies.h"

int hero_health;

char enemy1_name[15];
int enemy1_health;
char enemy2_name[15];
int enemy2_health;

//===========================================================================================================//

int spawnCommonEnemy()
{
  // this initializes the random number generator
  srand(time(NULL)); // time() is used to get the current time as a seed, and NULL is used to indicate that we don't need to pass any parameters to the function

  struct Common_Enemy common_enemies[7] = {
      {"Common Thug", 80},
      {"CutThroat", 105},
      {"Thief", 100},
      {"Magi Fiend", 100}, // basically a mage
      {"Mercenary", 120},
      {"Veteran Mercenary", 120},
      {"Corrupt Guard", 150},
  };

  int random_number = rand() % 7; // rand() is used to generate random numbers, % 7 is used to get a number between 0 and 6
}
//===========================================================================================================//

int startFight()
{

  return 0;
}
