#include <stdio.h>
#include <stdlib.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"
void drop_item()
{
  char input[10];
  printf("Would you like to drop an item?\n");
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (strcmp(input, "yes") == 0)
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
  else if (strcmp(input, "no") == 0)
  {
    printf("You have chosen not to drop an item.\n");
  }
  else
  {
    printf("Invalid input.\n");
  }
}
void pick_up_item(char itemName[20], char itemDesc[50], char itemType[15], int itemWeight, int itemAddedDamage, int itemValue)
{
  char input[10];
  if (Inventory.Slot1.isOpen == 1)
  {
    printf("You DO have an open slot.\n");
    printf("Would you like to pick up the item?\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);
    if (strcmp(input, "yes") == 0)
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
    else if (strcmp(input, "no") == 0)
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

void equip_head_item()
{
}
