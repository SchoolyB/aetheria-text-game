#include <stdio.h>
#include <stdlib.h>
#include "./Utils/Utils.h"
#include "Source/Items-Inventory/Items-Inventory.h"
#include "Source/Items-Inventory/2_InventoryManagement.c"

void hero_steps_on_item()
{
  printf("You have stepped on an something.\n");
  printf("You should pick it up.\n");
  // pick_up_item("Sword", "A sword", "Weapon", 10, 10, 10);
}
