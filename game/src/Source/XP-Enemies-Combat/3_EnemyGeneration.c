#include <stdio.h>
#include <time.h>
#include "XP-Combat.h"
#include "../../Utils/Utils.h"
Enemy enemy;

// have a chance to appear more often
char CommonEnemyList[30][30][30] = {
    // name, desc, type,
    {"Thief", "desc", "Non-Magical Human"},
    {"Cutthroat", "desc", "Non-Magical Human"},
    {"Highwayman", "desc", "Non-Magical Human"},
    {"Slaver", "desc", "Non-Magical Human"},
    {"Wizard's Apprentice", "desc", "Magical Human"},
    {"Cultist", "desc", "Magical Human"},
    {"Rabid Dog", "desc", "Non-Magical Beast"},
    {"Wolf", "desc", "Non-Magical Beast"},
    {"Bear", "desc", "Non-Magical Beast"},
    {"Wild Boar", "desc", "Non-Magical Beast"}};

// have a chance to appear less often
// char UncommonEnemyList[8][20] = {
//     "Bandit",
//     "Assassin",
//     "Rogue Knight",
//     "Necromancer",
//     "Dark Shaman",
//     "Berserker",
//     "Dire Wolf",
//     "Giant Arachnid"};

// // have a chance to rarely appear
// char RareEnemyList[6][20] = {
//     "Necromancer",
//     "Dark Wizard",
//     "Fire Mage",
//     "Troll",
//     "Dark Alchemist",
//     "Inquisitor"};

void generate_enemy()
{
  srand(time(NULL));
  int randomEnemy;
  int enemyGenerated = 0; // 0 false 1 true
  for (int i = 0; i < 10; i++)
  {
    randomEnemy = rand() % 10;
    char Type = CommonEnemyList
  }
}
//==================================================================================//
void generate_enemy_abilities()
{
}