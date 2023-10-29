// build a function that randomly generates an armor pickup(could be head, chest, or legs)
// build a function that randomly generates a weapon pickup. (could be sword, axe, mace, staff, bow, etc)
// build a function that says the hero has found an item. inside this function call all the others
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"
// Define structures for Armor types
// Arrays for possible armor names and added health values
char possibleHeadArmorNames[3][20] = {"Leather Helmet", "Iron Helmet", "Steel Helmet"};
char possibleChestArmorNames[3][20] = {"Leather Chestplate", "Iron Chestplate", "Steel Chestplate"};
char possibleLegArmorNames[3][20] = {"Leather Leggings", "Iron Leggings", "Steel Leggings"};

char possibleHeadArmorDescriptions[3][100] = {"HeadDescription1", "HeadDescription2", "HeadDescription3"};
char possibleChestArmorDescriptions[3][100] = {"ChestDescription1", "ChestDescription2", "ChestDescription3"};
char possibleLegArmorDescriptions[3][100] = {"LegDescription1", "LegDescription2", "LegDescription3"};

char possibleArmorTypes[3][10] = {"Light", "Medium", "Heavy"};

char possibleHeadArmorAddedHealth[3] = {10, 20, 30};
char possibleChestArmorAddedHealth[3] = {20, 30, 40};
char possibleLegArmorAddedHealth[3] = {10, 20, 30};
int possibleArmorWeight[100];
int possibleArmorValue[1000];

// Function to generate random armor pickup
void generate_possible_armor(HeadArmor *HeadArmor, ChestArmor *ChestArmor, LegArmor *LegArmor)
{
  // Seed the random number generator
  srand(time(NULL));

  // Generate random indices for armor selection
  int randomHead = rand() % 3;
  int randomChest = rand() % 3;
  int randomLeg = rand() % 3;

  // Copy the selected armor properties to the structures
  strcpy(HeadArmor->Name, possibleHeadArmorNames[randomHead]);
  HeadArmor->AddedHealth = possibleHeadArmorAddedHealth[randomHead];

  strcpy(ChestArmor->Name, possibleChestArmorNames[randomChest]);
  ChestArmor->AddedHealth = possibleChestArmorAddedHealth[randomChest];

  strcpy(LegArmor->Name, possibleLegArmorNames[randomLeg]);
  LegArmor->AddedHealth = possibleLegArmorAddedHealth[randomLeg];
}
