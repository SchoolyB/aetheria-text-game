// the player can find chest throughout the world. the chest need to have a chance to spawn randomly, then the items in it need to spawn randomly as well. see /Items/1_ItemGeneration.c
// chest can contain all kinds of items such as weapons, armor, gold, eventually when added potions and spell books/tomes
#include <stdio.h>
#include <stdlib.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"

typedef struct
{
  char Name[10];
  char Type[20];
  int isEmpty;
} LootChest;

void found_loot_chest()
{
  char input[10];
  printf("You've found a chest what would you like to do?\n");
  printf("1:Search The Chest\n");
  printf("2:Leave the chest\n");

  if (strcmp(input, "1") == 0 || strcmp(input, "search") == 0 || strcmp(input, "Search") == 0)
  {
    open_loot_chest();
    generate_chest_contents();
  }
  else if (strcmp(input, "2") == 0 || strcmp(input, "leave") == 0 || strcmp(input, "Leave") == 0)
  {
    printf("You decided to leave the chest alone.\n");
    // do more stuff
  }
  else
  {
    MAKE_VALID_DECISION;
    found_loot_chest();
  }
}

void generate_loot_chest_contents()
{
  generate_possible_armor();
}

void open_loot_chest()
{
  printf("Opening Chest....\n");
  PRINT_SLOWLY("Searching......", 40000);
  show_loot_chest_contents();
  // do more stuff
}

void close_loot_chest()
{
  printf("Closing Chest....\n");
}

void show_loot_chest_contents()
{
  printf("You found:\n");
  // do stuff
}
