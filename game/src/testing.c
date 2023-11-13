#include <stdio.h>
#include <stdlib.h>
#include "./Utils/Utils.h"
#include "./Source/XP-Enemies-Combat/XP-Combat.h"
#include "./Source/XP-Enemies-Combat/1_ExperienceSystem.c"
#include "./Source/Items-Inventory/Items-Inventory.h"
#include "./Source/Items-Inventory/1_ItemGeneration.c"

void testing_stuff()
{
  found_loot_chest();
  generate_enemy();
  initiate_combat();
}
