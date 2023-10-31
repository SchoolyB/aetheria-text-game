#include <stdio.h>
#include <stdlib.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"

//============================================================================================================//
char possibleInventoryOptions[10][20] = {
    "1.Equip",
    "2.Drop",
    "3.Use",     // only if consumable
    "4.Examine", // this will be a description of the item/weapon/armor
    "5.Exit"};
// todo add new option called 'move' that allows you to move an item from one slot to another
void inventory_options()
{
  printf("What would you like to do?\n");
  PRINT_LIST_ITEMS(5, possibleInventoryOptions);

  char input[10];
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (STR_CMP_TWO(input, "1", "equip"))
  {
    // equip_item();
    puts("You chose the equip option.");
  }
  else if (STR_CMP_TWO(input, "2", "drop"))
  {
    // drop_item();
    puts("You chose the drop option.");
  }
  else if (STR_CMP_TWO(input, "3", "use"))
  {
    // use_item();
    puts("You chose the use option.");
  }
  else if (STR_CMP_TWO(input, "4", "examine"))
  {
    // examine_item();
    puts("You chose the examine option.");
  }
  else if (STR_CMP_TWO(input, "5", "exit"))
  {
    printf("Exiting Inventory.\n");
  }
  else
  {
    MAKE_VALID_DECISION;
    inventory_options();
  }
}
//============================================================================================================//
// this function is used to drop an item if the slot is not empty
void drop_item()
{
  char input[10];
  printf("Would you like to drop an item?\n");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (INPUT_IS_YES(input))
  {
    printf("You have chosen to drop an item.\n");
    printf("Which slot would you like to drop?\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);
    if (strcmp(input, "1") == 0)
    {
      printf("You have chosen to drop slot 1.\n");
      if (Inventory.Slot1.isOpen == 0)
      {
        printf("You have dropped '%s'.\n", Inventory.Slot1.Weapon.Name);
        Inventory.Slot1.isOpen = 1;
        strcpy(Inventory.Slot1.Weapon.Name, "Empty");
        strcpy(Inventory.Slot1.Weapon.Description, "Empty");
        strcpy(Inventory.Slot1.Weapon.Type, "Empty");
        Inventory.Slot1.Weapon.Weight = 0;
        Inventory.Slot1.Weapon.AddedDamage = 0;
        Inventory.Slot1.Weapon.Value = 0;
      }
      else if (Inventory.Slot1.isOpen == 1)
      {
        printf("Slot 1 is already empty.\n");
      }
      else
      {
        printf("Check failed.\n");
      }
    }
    else
    {
      printf("Check failed.\n");
    }
  }
  else if (INPUT_IS_NO(input))
  {
    printf("You have chosen not to drop an item.\n");
  }
  else
  {
    printf("Invalid input.\n");
  }
}
//============================================================================================================//
// this function is used to pick up an item and place it in an open slot
void pick_up_item(char itemName[20], char itemDesc[50], char itemType[15], int itemWeight, int itemAddedDamage, int itemValue)
{
  char input[10];
  if (Inventory.Slot1.isOpen == 1)
  {
    printf("You DO have an open slot.\n");
    printf("Would you like to pick up the item?\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);
    if (INPUT_IS_YES(input))
    {
      printf("You have picked up '%s'.\n", itemName);
      Inventory.Slot1.isOpen = 0;
      strcpy(Inventory.Slot1.Weapon.Name, itemName);
      strcpy(Inventory.Slot1.Weapon.Description, itemDesc);
      strcpy(Inventory.Slot1.Weapon.Type, itemType);
      Inventory.Slot1.Weapon.Weight = itemWeight;
      Inventory.Slot1.Weapon.AddedDamage = itemAddedDamage;
      Inventory.Slot1.Weapon.Value = itemValue;
    }
    else if (INPUT_IS_NO(input))
    {
      printf("You have chosen not to pick up the item.\n");
    }
    else
    {
      printf("Invalid input.\n");
    }
  }
  else if (Inventory.Slot1.isOpen == 0)
  {
    printf("You DO NOT have an open slot.\n");
  }
  else
  {
    printf("Check failed.\n");
  }
}
//============================================================================================================//

// this function allows the player to equip an item from their inventory to this character
// void equip_item()
// {
//   printf("Would you like to equip an item?\n");
// }
