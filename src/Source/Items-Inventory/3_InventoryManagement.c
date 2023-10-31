#include <stdio.h>
#include <stdlib.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"

//============================================================================================================//
char possibleInventoryOptions[10][20] = {
    "1.Equip",
    "2.Unequip",
    "3.Drop",
    "4.Use",     // only if consumable
    "5.Examine", // this will be a description of the item/weapon/armor
    "6.Exit"};
// todo add new option called 'move' that allows you to move an item from one slot to another
void inventory_options()
{
  printf("What would you like to do?\n");
  PRINT_LIST_ITEMS(6, possibleInventoryOptions);

  char input[10];
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (STR_CMP_TWO(input, "1", "equip"))
  {
    // equip_item();
    puts("You chose the equip option.");
  }
  else if (STR_CMP_TWO(input, "2", "unequip"))
  {
    unequip_item();
    puts("You chose the unequip option.");
  }
  else if (STR_CMP_TWO(input, "3", "drop"))
  {
    drop_item();
    puts("You chose the drop option.");
  }
  else if (STR_CMP_TWO(input, "4", "use"))
  {
    // use_item();
    puts("You chose the use option.");
  }
  else if (STR_CMP_TWO(input, "5", "examine"))
  {
    // examine_item();
    puts("You chose the examine option.");
  }
  else if (STR_CMP_TWO(input, "6", "exit"))
  {
    puts("Exiting Inventory.\n");
  }
  else
  {
    MAKE_VALID_DECISION;
    inventory_options();
  }
}
//============================================================================================================//
void unequip_item()
{
  printf("Which of these would you like to unequip? you can enter the number,the exact name of the item, or you can enter 'weapon', 'head', 'chests', or 'legs'.\n");
  printf("(1)Equipped Weapon:%s\n", Inventory.EquippedWeapon.Name);
  printf("(2)Equipped Head Armor:%s\n", Inventory.EquippedHead.Name);
  printf("(3)Equipped Chest Armor:%s\n", Inventory.EquippedChest.Name);
  printf("(4)Equipped Leg Armor:%s\n", Inventory.EquippedLegs.Name);

  char input[10];
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (STR_CMP(input, Inventory.EquippedWeapon.Name) || atoi(input) == 1 || STR_CMP(input, "weapon"))
  {
    unequip_logic(&input, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value);
    choose_open_slot_to_move_to(&input);
  }
  else if (STR_CMP(input, Inventory.EquippedHead.Name) || atoi(input) == 2 || STR_CMP(input, "head"))
  {
    unequip_logic(&input, Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.AddedDamage, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Value);
  }
  else if (STR_CMP(input, Inventory.EquippedChest.Name) || atoi(input) == 3 || STR_CMP(input, "chest"))
  {
    unequip_logic(&input, Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.AddedDamage, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Value);
  }
  else if (STR_CMP(input, Inventory.EquippedLegs.Name) || atoi(input) == 4 || STR_CMP(input, "legs"))
  {
    unequip_logic(&input, Inventory.EquippedLegs.Name, Inventory.EquippedLegs.Description, Inventory.EquippedLegs.Type, Inventory.EquippedLegs.Weight, Inventory.EquippedLegs.AddedDamage, Inventory.EquippedLegs.AddedHealth, Inventory.EquippedLegs.Value);
  }
  else
  {
    MAKE_VALID_DECISION;
    unequip_item();
  }
}

//============================================================================================================//
void choose_open_slot_to_move_to(char *input)
{
  printf("Which slot would you like to move %s to?\n", Inventory.EquippedWeapon.Name);
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (STR_CMP(input, "1") && Inventory.Slot1.isOpen == 1)
  {
    puts("You have chosen to move your weapon to Slot 1.");
    Inventory.Slot1.isOpen = 0;
    strcpy(Inventory.Slot1.Item.Name, Inventory.EquippedWeapon.Name);
    strcpy(Inventory.Slot1.Item.Description, Inventory.EquippedWeapon.Description);
    strcpy(Inventory.Slot1.Item.Type, Inventory.EquippedWeapon.Type);
    Inventory.Slot1.Item.Weight = Inventory.EquippedWeapon.Weight;
    Inventory.Slot1.Item.AddedDamage = Inventory.EquippedWeapon.AddedDamage;
    Inventory.Slot1.Item.Value = Inventory.EquippedWeapon.Value;
    puts("Slot 1 is now full.");
    printf("%s has been placed in Slot 1\n", Inventory.EquippedWeapon.Name);
    strcpy(Inventory.EquippedWeapon.Name, "Empty");
    strcpy(Inventory.EquippedWeapon.Description, "Empty");
    strcpy(Inventory.EquippedWeapon.Type, "Empty");
    Inventory.EquippedWeapon.Weight = 0;
    Inventory.EquippedWeapon.AddedDamage = 0;
    Inventory.EquippedWeapon.Value = 0;
  }
  else if (STR_CMP(input, "1") && Inventory.Slot1.isOpen == 0)
  {
    puts("Slot 1 is full.");
    puts("Please choose another slot.");
    choose_open_slot_to_move_to(&input);
  }
  else if (STR_CMP(input, "2") && Inventory.Slot2.isOpen == 1)
  {
    puts("You have chosen to move your weapon to Slot 2.");
    Inventory.Slot2.isOpen = 0;
    strcpy(Inventory.Slot2.Item.Name, Inventory.EquippedWeapon.Name);
    strcpy(Inventory.Slot2.Item.Description, Inventory.EquippedWeapon.Description);
    strcpy(Inventory.Slot2.Item.Type, Inventory.EquippedWeapon.Type);
    Inventory.Slot2.Item.Weight = Inventory.EquippedWeapon.Weight;
    Inventory.Slot2.Item.AddedDamage = Inventory.EquippedWeapon.AddedDamage;
    Inventory.Slot2.Item.Value = Inventory.EquippedWeapon.Value;
    puts("Slot 2 is now full.");
    printf("%s has been placed in Slot 2\n", Inventory.EquippedWeapon.Name);
    strcpy(Inventory.EquippedWeapon.Name, "Empty");
    strcpy(Inventory.EquippedWeapon.Description, "Empty");
    strcpy(Inventory.EquippedWeapon.Type, "Empty");
    Inventory.EquippedWeapon.Weight = 0;
    Inventory.EquippedWeapon.AddedDamage = 0;
    Inventory.EquippedWeapon.Value = 0;
  }
  else if (STR_CMP(input, "2") && Inventory.Slot2.isOpen == 0)
  {
    puts("Slot 2 is full.");
    puts("Please choose another slot.");
    choose_open_slot_to_move_to(&input);
  }
  else if (STR_CMP(input, "3") && Inventory.Slot3.isOpen == 1)
  {
    puts("You have chosen to move your weapon to Slot 3.");
    Inventory.Slot3.isOpen = 0;
    strcpy(Inventory.Slot3.Item.Name, Inventory.EquippedWeapon.Name);
    strcpy(Inventory.Slot3.Item.Description, Inventory.EquippedWeapon.Description);
    strcpy(Inventory.Slot3.Item.Type, Inventory.EquippedWeapon.Type);
    Inventory.Slot3.Item.Weight = Inventory.EquippedWeapon.Weight;
    Inventory.Slot3.Item.AddedDamage = Inventory.EquippedWeapon.AddedDamage;
    Inventory.Slot3.Item.Value = Inventory.EquippedWeapon.Value;
    puts("Slot 3 is now full.");
    printf("%s has been placed in Slot 3\n", Inventory.EquippedWeapon.Name);
    strcpy(Inventory.EquippedWeapon.Name, "Empty");
    strcpy(Inventory.EquippedWeapon.Description, "Empty");
    strcpy(Inventory.EquippedWeapon.Type, "Empty");
    Inventory.EquippedWeapon.Weight = 0;
    Inventory.EquippedWeapon.AddedDamage = 0;
    Inventory.EquippedWeapon.Value = 0;
  }
  else if (STR_CMP(input, "3") && Inventory.Slot3.isOpen == 0)
  {
    puts("Slot 3 is full.");
    puts("Please choose another slot.");
    choose_open_slot_to_move_to(&input);
  }

  else
  {
    puts("Check failed.");
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
        printf("You have dropped '%s'.\n", Inventory.Slot1.Item.Name);
        Inventory.Slot1.isOpen = 1;
        strcpy(Inventory.Slot1.Item.Name, "Empty");
        strcpy(Inventory.Slot1.Item.Description, "Empty");
        strcpy(Inventory.Slot1.Item.Type, "Empty");
        Inventory.Slot1.Item.Weight = 0;
        Inventory.Slot1.Item.AddedDamage = 0;
        Inventory.Slot1.Item.Value = 0;
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
      strcpy(Inventory.Slot1.Item.Name, itemName);
      strcpy(Inventory.Slot1.Item.Description, itemDesc);
      strcpy(Inventory.Slot1.Item.Type, itemType);
      Inventory.Slot1.Item.Weight = itemWeight;
      Inventory.Slot1.Item.AddedDamage = itemAddedDamage;
      Inventory.Slot1.Item.Value = itemValue;
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

void unequip_logic(char *input, char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue)
{
  printf("You have chosen to unequip %s.", equippedItemName);
  if (Inventory.Slot1.isOpen == 0 && Inventory.Slot2.isOpen == 0 && Inventory.Slot3.isOpen == 0)
  {
    puts("All slots are full.");
    puts("Please clear a slot before unequipping this item.");
  }
  else if (Inventory.Slot1.isOpen == 1 && Inventory.Slot2.isOpen == 0 && Inventory.Slot3.isOpen == 0)
  {
    puts("Slot 1 is open.");
    printf("Moving %s to Slot 1.\n", equippedItemName);
    Inventory.Slot1.isOpen = 0;
    strcpy(Inventory.Slot1.Item.Name, equippedItemName);
    strcpy(Inventory.Slot1.Item.Description, equippedItemDesc);
    strcpy(Inventory.Slot1.Item.Type, equippedItemType);
    Inventory.Slot1.Item.Weight = equippedItemWeight;
    Inventory.Slot1.Item.AddedDamage = equippedItemAddedDamage;
    Inventory.Slot1.Item.AddedHealth = Inventory.EquippedHead.AddedHealth;
    Inventory.Slot1.Item.Value = equippedItemValue;
    Inventory.Slot1.Item.AddedHealth = Inventory.EquippedHead.AddedHealth;
    printf("%s has been placed in Slot 1\n", equippedItemName);
    puts("Slot 1 is now full.");
    strcpy(equippedItemName, "Empty");
    strcpy(equippedItemDesc, "Empty");
    strcpy(equippedItemType, "Empty");
    equippedItemWeight = 0;
    equippedItemAddedHealth = 0;
    equippedItemAddedDamage = 0;
    equippedItemValue = 0;
  }
  else if (Inventory.Slot2.isOpen == 1 && Inventory.Slot1.isOpen == 0 && Inventory.Slot3.isOpen == 0)
  {
    puts("Slot 2 is open.");
    puts("Moving weapon to slot 2.");
    Inventory.Slot2.isOpen = 0;
    strcpy(Inventory.Slot2.Item.Name, equippedItemName);
    strcpy(Inventory.Slot2.Item.Description, equippedItemDesc);
    strcpy(Inventory.Slot2.Item.Type, equippedItemType);
    Inventory.Slot2.Item.Weight = equippedItemWeight;
    Inventory.Slot2.Item.AddedDamage = equippedItemAddedDamage;
    Inventory.Slot1.Item.AddedHealth = Inventory.EquippedHead.AddedHealth;
    Inventory.Slot2.Item.Value = equippedItemValue;
    puts("Slot 2 is now full.");
    printf("%s has been placed in Slot 2\n", equippedItemName);
    strcpy(equippedItemName, "Empty");
    strcpy(equippedItemDesc, "Empty");
    strcpy(equippedItemType, "Empty");
    equippedItemWeight = 0;
    equippedItemAddedHealth = 0;
    equippedItemAddedDamage = 0;
    equippedItemValue = 0;
  }
  else if (Inventory.Slot3.isOpen == 1 && Inventory.Slot1.isOpen == 0 && Inventory.Slot2.isOpen == 0)
  {
    puts("Slot 3 is open.");
    puts("Moving weapon to slot 3.");
    Inventory.Slot3.isOpen = 0;
    strcpy(Inventory.Slot3.Item.Name, equippedItemName);
    strcpy(Inventory.Slot3.Item.Description, equippedItemDesc);
    strcpy(Inventory.Slot3.Item.Type, equippedItemType);
    Inventory.Slot3.Item.Weight = equippedItemWeight;
    Inventory.Slot3.Item.AddedDamage = equippedItemAddedDamage;

    Inventory.Slot3.Item.Value = equippedItemValue;
    puts("Slot 3 is now full.");
    printf("%s has been placed in Slot 3\n", equippedItemName);
    strcpy(equippedItemName, "Empty");
    strcpy(equippedItemDesc, "Empty");
    strcpy(equippedItemType, "Empty");
    equippedItemWeight = 0;
    equippedItemAddedHealth = 0;
    equippedItemAddedDamage = 0;
    equippedItemValue = 0;
  }
  else if (Inventory.Slot1.isOpen == 1 && Inventory.Slot2.isOpen == 1 && Inventory.Slot3.isOpen == 1)
  {
    puts("All slots are open.");
    puts("Please choose a slot to move your weapon to.");
    puts("1.Slot 1");
    puts("2.Slot 2");
    puts("3.Slot 3");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);
    if (STR_CMP(input, "1"))
    {
      puts("You have chosen to move your weapon to Slot 1.");
      Inventory.Slot1.isOpen = 0;
      strcpy(Inventory.Slot1.Item.Name, equippedItemName);
      strcpy(Inventory.Slot1.Item.Description, equippedItemDesc);
      strcpy(Inventory.Slot1.Item.Type, equippedItemType);
      Inventory.Slot1.Item.Weight = equippedItemWeight;
      Inventory.Slot1.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = Inventory.EquippedHead.AddedHealth;
      Inventory.Slot1.Item.Value = equippedItemValue;
      puts("Slot 1 is now full.");
      printf("%s has been placed in Slot 1\n", equippedItemName);
      strcpy(equippedItemName, "Empty");
      strcpy(equippedItemDesc, "Empty");
      strcpy(equippedItemType, "Empty");
      equippedItemWeight = 0;
      equippedItemAddedHealth = 0;
      equippedItemAddedDamage = 0;
      equippedItemValue = 0;
    }
    else if (STR_CMP(input, "2"))
    {
      puts("You have chosen to move your weapon to Slot 2.");
      Inventory.Slot2.isOpen = 0;
      strcpy(Inventory.Slot2.Item.Name, equippedItemName);
      strcpy(Inventory.Slot2.Item.Description, equippedItemDesc);
      strcpy(Inventory.Slot2.Item.Type, equippedItemType);
      Inventory.Slot2.Item.Weight = equippedItemWeight;
      Inventory.Slot2.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = Inventory.EquippedHead.AddedHealth;

      Inventory.Slot2.Item.Value = equippedItemValue;
      puts("Slot 2 is now full.");
      printf("%s has been placed in Slot 2\n", equippedItemName);
      strcpy(equippedItemName, "Empty");
      strcpy(equippedItemDesc, "Empty");
      strcpy(equippedItemType, "Empty");
      equippedItemWeight = 0;
      equippedItemAddedHealth = 0;
      equippedItemAddedDamage = 0;
      equippedItemValue = 0;
    }
    else if (STR_CMP(input, "3"))
    {
      puts("You have chosen to move your weapon to Slot 3.");
      Inventory.Slot3.isOpen = 0;
      strcpy(Inventory.Slot3.Item.Name, equippedItemName);
      strcpy(Inventory.Slot3.Item.Description, equippedItemDesc);
      strcpy(Inventory.Slot3.Item.Type, equippedItemType);
      Inventory.Slot3.Item.Weight = equippedItemWeight;
      Inventory.Slot3.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = Inventory.EquippedHead.AddedHealth;

      equippedItemAddedHealth = 0;

      Inventory.Slot3.Item.Value = equippedItemValue;
      puts("Slot 3 is now full.");
      printf("%s has been placed in Slot 3\n", equippedItemName);
      strcpy(equippedItemName, "Empty");
      strcpy(equippedItemDesc, "Empty");
      strcpy(equippedItemType, "Empty");
      equippedItemWeight = 0;
      equippedItemAddedHealth = 0;
      equippedItemAddedDamage = 0;
      equippedItemValue = 0;
    }
    else
    {
      puts("Check failed.");
    }
  }

  else if (Inventory.Slot1.isOpen == 1 || Inventory.Slot2.isOpen == 1 || Inventory.Slot3.isOpen == 1)
  {
    printf("Here is the status of your inventory slots:\n");
    if (Inventory.Slot1.isOpen == 1)
    {
      puts("Slot 1: Open\n");
    }
    if (Inventory.Slot2.isOpen == 1)
    {
      puts("Slot 2: Open\n");
    }
    if (Inventory.Slot3.isOpen == 1)
    {
      puts("Slot 3: Open\n");
    }
    if (Inventory.Slot1.isOpen == 0)
    {
      printf("Slot 1: Full contains %s\n", Inventory.Slot1.Item.Name);
    }
    if (Inventory.Slot2.isOpen == 0)
    {
      printf("Slot 2: Full contains %s\n", Inventory.Slot2.Item.Name);
    }
    if (Inventory.Slot3.isOpen == 0)
    {
      printf("Slot 3: Full contains %s\n", Inventory.Slot3.Item.Name);
    }
    else
    {
      puts("Check failed.");
    }
  }
}