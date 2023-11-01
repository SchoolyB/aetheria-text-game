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
    equip_item();
  }
  else if (STR_CMP_TWO(input, "2", "unequip"))
  {
    selected_to_unequip();
  }
  else if (STR_CMP_TWO(input, "3", "drop"))
  {
    drop_item();
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
// this function takes in and handles the logic for EQUIPPING an item. See logic in void equip_logic()

//============================================================================================================//
//= == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == = //

void selected_to_unequip()
{

  system("clear");
  selected_inventory_option("Unequip");
  if (Inventory.EquippedWeapon.Name[0] == '\0' && Inventory.EquippedHead.Name[0] == '\0' && Inventory.EquippedChest.Name[0] == '\0' && Inventory.EquippedLegs.Name[0] == '\0')
  {
    puts("You have nothing equipped.");
    return;
  }
  else
  {
    printf("Which of these would you like to unequip?\n");
    printf("(1)Equipped Weapon:%s\n", Inventory.EquippedWeapon.Name);
    printf("(2)Equipped Head Armor:%s\n", Inventory.EquippedHead.Name);
    printf("(3)Equipped Chest Armor:%s\n", Inventory.EquippedChest.Name);
    printf("(4)Equipped Leg Armor:%s\n", Inventory.EquippedLegs.Name);
  }
  char input[10];
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);
  if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && STR_CMP(input, "1"))
  {
    puts("You dont have a weapon equipped please try again");
    sleep(2);
    selected_to_unequip();
  }
  else if (strcmp(Inventory.EquippedHead.Name, "None") == 0 && STR_CMP(input, "2"))
  {
    puts("You dont have  head armor equipped please try again");
    sleep(2);
    selected_to_unequip();
  }
  else if (strcmp(Inventory.EquippedChest.Name, "None") == 0 && STR_CMP(input, "3"))
  {
    puts("You dont have chest armor equipped please try again");
    sleep(2);
    selected_to_unequip();
  }
  else if (strcmp(Inventory.EquippedLegs.Name, "None") == 0 && STR_CMP(input, "4"))
  {
    puts("You dont have leg armor equipped please try again");
    sleep(2);
    selected_to_unequip();
  }

  if (STR_CMP(input, "1") || STR_CMP(input, Inventory.EquippedWeapon.Name) || STR_CMP(input, "weapon") && Inventory.EquippedWeapon.Name[0] != '\0')
  {

    printf("You have chosen to unequip %s.\n", Inventory.EquippedWeapon.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedWeapon.Name);
    show_slots(Inventory.Slot1.Item.Name, Inventory.Slot2.Item.Name, Inventory.Slot3.Item.Name);

    char newInput[10];
    FGETS(newInput);
    REMOVE_NEWLINE_CHAR(newInput);
    if (STR_CMP(newInput, "1") || STR_CMP(newInput, Inventory.Slot1.Item.Name) || STR_CMP(newInput, "slot1") && Inventory.Slot1.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
    }
    else if (STR_CMP(newInput, "2") || STR_CMP(newInput, Inventory.Slot2.Item.Name) || STR_CMP(newInput, "slot2") && Inventory.Slot2.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
    }
    else if (STR_CMP(newInput, "3") || STR_CMP(newInput, Inventory.Slot3.Item.Name) || STR_CMP(newInput, "slot3") && Inventory.Slot3.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
    }
    else
    {
      puts("Check 1 failed.");
    }
  }

  else if (STR_CMP(input, "2") || STR_CMP(input, Inventory.EquippedHead.Name) || STR_CMP(input, "head") && Inventory.EquippedHead.Name[0] != '\0')
  {
    printf("You have chosen to unequip %s.\n", Inventory.EquippedHead.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedHead.Name);
    show_slots(Inventory.Slot1.Item.Name, Inventory.Slot2.Item.Name, Inventory.Slot3.Item.Name);

    char newInput[10];
    FGETS(newInput);
    REMOVE_NEWLINE_CHAR(newInput);
    if (STR_CMP(newInput, "1") || STR_CMP(newInput, Inventory.Slot1.Item.Name) || STR_CMP(newInput, "slot1") && Inventory.Slot1.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.AddedDamage, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Value, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
    }
    else if (STR_CMP(newInput, "2") || STR_CMP(newInput, Inventory.Slot2.Item.Name) || STR_CMP(newInput, "slot2") && Inventory.Slot2.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.AddedDamage, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Value, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
    }
    else if (STR_CMP(newInput, "3") || STR_CMP(newInput, Inventory.Slot3.Item.Name) || STR_CMP(newInput, "slot3") && Inventory.Slot3.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.AddedDamage, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Value, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
    }
    else
    {
      puts("Check 2 failed.");
    }
  }

  else if (STR_CMP(input, "3") || STR_CMP(input, Inventory.EquippedChest.Name) || STR_CMP(input, "chest") && Inventory.EquippedChest.Name[0] != '\0')
  {
    printf("You have chosen to unequip %s.\n", Inventory.EquippedChest.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedChest.Name);
    show_slots(Inventory.Slot1.Item.Name, Inventory.Slot2.Item.Name, Inventory.Slot3.Item.Name);

    char newInput[10];
    FGETS(newInput);
    REMOVE_NEWLINE_CHAR(newInput);
    if (STR_CMP(newInput, "1") || STR_CMP(newInput, Inventory.Slot1.Item.Name) || STR_CMP(newInput, "slot1") && Inventory.Slot1.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.AddedDamage, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Value, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
    }
    else if (STR_CMP(newInput, "2") || STR_CMP(newInput, Inventory.Slot2.Item.Name) || STR_CMP(newInput, "slot2") && Inventory.Slot2.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.AddedDamage, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Value, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
    }
    else if (STR_CMP(newInput, "3") || STR_CMP(newInput, Inventory.Slot3.Item.Name) || STR_CMP(newInput, "slot3") && Inventory.Slot3.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.AddedDamage, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Value, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
    }
    else
    {
      puts("Check 3 failed.");
    }
  }

  else if (STR_CMP(input, "4") || STR_CMP(input, Inventory.EquippedLegs.Name) || STR_CMP(input, "legs") && Inventory.EquippedLegs.Name[0] != '\0')
  {
    printf("You have chosen to unequip %s.\n", Inventory.EquippedLegs.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedLegs.Name);
    show_slots(Inventory.Slot1.Item.Name, Inventory.Slot2.Item.Name, Inventory.Slot3.Item.Name);

    char newInput[10];
    FGETS(newInput);
    REMOVE_NEWLINE_CHAR(newInput);

    if (STR_CMP(newInput, "1") || STR_CMP(newInput, Inventory.Slot1.Item.Name) || STR_CMP(newInput, "slot1") && Inventory.Slot1.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedLegs.Name, Inventory.EquippedLegs.Description, Inventory.EquippedLegs.Type, Inventory.EquippedLegs.Weight, Inventory.EquippedLegs.AddedDamage, Inventory.EquippedLegs.AddedHealth, Inventory.EquippedLegs.Value, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
    }
    else if (STR_CMP(newInput, "2") || STR_CMP(newInput, Inventory.Slot2.Item.Name) || STR_CMP(newInput, "slot2") && Inventory.Slot2.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedLegs.Name, Inventory.EquippedLegs.Description, Inventory.EquippedLegs.Type, Inventory.EquippedLegs.Weight, Inventory.EquippedLegs.AddedDamage, Inventory.EquippedLegs.AddedHealth, Inventory.EquippedLegs.Value, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
    }
    else if (STR_CMP(newInput, "3") || STR_CMP(newInput, Inventory.Slot3.Item.Name) || STR_CMP(newInput, "slot3") && Inventory.Slot3.Item.Name[0] == '\0')
    {
      choose_open_slot_to_move_to(&newInput, Inventory.EquippedLegs.Name, Inventory.EquippedLegs.Description, Inventory.EquippedLegs.Type, Inventory.EquippedLegs.Weight, Inventory.EquippedLegs.AddedDamage, Inventory.EquippedLegs.AddedHealth, Inventory.EquippedLegs.Value, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
    }

    else
    {
      puts("Check 3 failed.");
    }
  }
  else
  {
    puts("Canceling process.");
    return;
  }
}
//============================================================================================================//
void show_slots(char *slotItemName1, char *slotItemName2, char *slotItemName3)
{
  {
    if (Inventory.Slot1.isOpen == 1)
    {
      printf("(1)Slot 1: Empty\n");
    }
    else
    {
      printf("(1)Slot 1: %s\n", slotItemName1);
    }

    if (Inventory.Slot2.isOpen == 1)
    {
      printf("(2)Slot 2: Empty\n");
    }
    else
    {
      printf("(2)Slot 2: %s\n", slotItemName2);
    }

    if (Inventory.Slot3.isOpen == 1)
    {
      printf("(3)Slot 3: Empty\n");
    }
    else
    {
      printf("(3)Slot 3: %s\n", slotItemName3);
    }
  }
}
//============================================================================================================//
// this function takes in and handles the logic for  UN-EQUIPPING an item. See logic in void unequip_logic()

void choose_open_slot_to_move_to(char *newInput, char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, int slotItemWeight, int slotItemAddedDamage, int slotItemAddedHealth, int slotItemValue)
{

  if (STR_CMP(newInput, "1") && Inventory.Slot1.isOpen == 1)
  {
    puts("You have chosen to move your item to Slot 1.");
    if (Inventory.Slot1.isOpen == 0)
    {
      printf("Slot one currently has %s in it.\n", Inventory.Slot1.Item.Name);
      puts("Please choose another slot.");
    }
    else
    {
      Inventory.Slot1.isOpen = 0;

      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      slotItemWeight = equippedItemWeight;
      slotItemAddedDamage = equippedItemAddedDamage;
      slotItemAddedHealth = equippedItemAddedHealth;
      slotItemValue = equippedItemValue;
      puts("Slot 1 is now full.");
      printf("%s has been placed in Slot 1\n", equippedItemName);
      strcpy(equippedItemName, "Empty");
      strcpy(equippedItemDesc, "Empty");
      strcpy(equippedItemType, "Empty");
      equippedItemWeight = 0;
      equippedItemAddedDamage = 0;
      equippedItemAddedHealth = 0;
      equippedItemValue = 0;
    }
  }
  else if (STR_CMP(newInput, "1") && Inventory.Slot1.isOpen == 0)
  {
    puts("Slot 1 is full.");
    puts("Please try again.");
    sleep(2);
    selected_to_unequip();
  }
  else if (STR_CMP(newInput, "2") && Inventory.Slot2.isOpen == 1)
  {
    puts("You have chosen to move your item to Slot 2.");
    if (Inventory.Slot2.isOpen == 0)
    {
      printf("Slot two currently has %s in it.\n", Inventory.Slot2.Item.Name);
      puts("Please choose another slot.");
    }
    else
    {
      Inventory.Slot2.isOpen = 0;
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      slotItemWeight = equippedItemWeight;
      slotItemAddedDamage = equippedItemAddedDamage;
      slotItemAddedHealth = equippedItemAddedHealth;
      slotItemValue = equippedItemValue;
      puts("Slot 2 is now full.");
      printf("%s has been placed in Slot 2\n", equippedItemName);
      strcpy(equippedItemName, "Empty");
      strcpy(equippedItemDesc, "Empty");
      strcpy(equippedItemType, "Empty");
      equippedItemWeight = 0;
      equippedItemAddedDamage = 0;
      equippedItemAddedHealth = 0;
      equippedItemValue = 0;
    }
  }
  else if (STR_CMP(newInput, "2") && Inventory.Slot2.isOpen == 0)
  {
    puts("Slot 2 is full.");
    puts("Please try again.");
    sleep(2);
    selected_to_unequip();
  }
  else if (STR_CMP(newInput, "3") && Inventory.Slot3.isOpen == 1)
  {
    puts("You have chosen to move your item to Slot 3.");
    if (Inventory.Slot3.isOpen == 0)
    {
      printf("Slot three currently has %s in it.\n", Inventory.Slot3.Item.Name);
      puts("Please choose another slot.");
    }
    else
    {
      Inventory.Slot3.isOpen = 0;
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      slotItemWeight = equippedItemWeight;
      slotItemAddedDamage = equippedItemAddedDamage;
      slotItemAddedHealth = equippedItemAddedHealth;
      slotItemValue = equippedItemValue;
      puts("Slot 3 is now full.");
      printf("%s has been placed in Slot 3\n", equippedItemName);
      strcpy(equippedItemName, "Empty");
      strcpy(equippedItemDesc, "Empty");
      strcpy(equippedItemType, "Empty");
      equippedItemWeight = 0;
      equippedItemAddedDamage = 0;
      equippedItemAddedHealth = 0;
      equippedItemValue = 0;
    }
  }
  else if (STR_CMP(newInput, "3") && Inventory.Slot3.isOpen == 0)
  {
    puts("Slot 3 is full.");
    puts("Please try again.");
    sleep(2);
    selected_to_unequip();
  }
  else
  {
    puts("Check failed.");
  }
}

void equip_item()
{
  system("clear");
  selected_inventory_option("Equip");
  // check if slot 1 is empty
  if (Inventory.Slot1.Item.Name[0] == '\0' && Inventory.Slot2.Item.Name[0] == '\0' && Inventory.Slot3.Item.Name[0] == '\0')
  {
    puts("You have no items in your inventory.");
    puts("Slot 1: Empty");
    puts("Slot 2: Empty");
    puts("Slot 3: Empty");
    puts("Once you have items they will appear here.");
    return;
  }
  else
  {
    puts("Which of these items would you like to equip? Enter the slot number\n");
    printf("Slot 1: %s\n", Inventory.Slot1.Item.Name);
    printf("Slot 2: %s\n", Inventory.Slot2.Item.Name);
    printf("Slot 3: %s\n", Inventory.Slot3.Item.Name);
  }

  char input[10];
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (STR_CMP(input, "1") || STR_CMP(input, "slot1"))
  {
    equip_logic(Inventory.Slot1.Item.Name, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value);
  }
  // else
  // {
  //   MAKE_VALID_DECISION;
  //   equip_item();
  // }
}
//============================================================================================================//
// this function contains all the logic for EQUIPPING an item. See implementation in void equip_item()
void equip_logic(char *itemInSlot, char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue)
{
  printf("You have chosen to equip %s. \n", itemInSlot);
  if (strcmp(itemInSlot, "Empty") == 0)
  {
    puts("There is nothing in this slot.");
  }
  /*
  The following 'else if' statements
  Run checks to see if an equippable slot is empty
  AND if the user is trying to equip correct type for
  that equippable slot then equip it. If not throw error
  */
  else if (strcmp(Inventory.EquippedWeapon.Name, "Empty") == 0 && strcmp(Inventory.Slot1.Item.Type, "Weapon") == 0)
  {
    is_it_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedHealth, equippedItemAddedDamage, equippedItemValue, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.Value);
  }

  else
  {
    puts("Check failed.");
  }
}
//============================================================================================================//
// this function runs a check to so if an item is equippable to the correct equippable slot see implementation in void equip_logic()
void is_it_equippable(char *equippedItemName, char *equippedItemDesc, char *equippedItemType, char *equippedItemWeight, char *equippedItemAddedHealth, char *equippedItemAddedDamage, char *equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, char *slotItemWeight, char *slotItemAddedHealth, char *slotItemAddedDamage, char *slotItemValue)
{

  printf("You have equipped %s.\n", slotItemName);
  strcpy(equippedItemName, slotItemName);
  strcpy(equippedItemDesc, slotItemDesc);
  strcpy(equippedItemType, Inventory.Slot1.Item.Type);
  equippedItemWeight = slotItemWeight;
  equippedItemAddedDamage = slotItemAddedDamage;
  equippedItemValue = slotItemValue;
  strcpy(slotItemName, "Empty");
  strcpy(slotItemDesc, "Empty");
  strcpy(slotItemType, "Empty");
  slotItemWeight = 0;
  slotItemAddedDamage = 0;
  slotItemAddedHealth = 0;
  slotItemValue = 0;
}

//============================================================================================================//
// this function is used to drop an item if the slot is not empty
void drop_item()
{
  system("clear");
  selected_inventory_option("Drop");
  char input[10];
  puts("Would you like to drop an item?");
  MAKE_RED("WARNING: This action is irreversible.\n");
  MAKE_RED("You will lose the item forever.\n");
  MAKE_RED("Are you sure you want to drop an item?\n");
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
    else if (strcmp(input, "2") == 0)
    {
      printf("You have chosen to drop slot 2.\n");
      if (Inventory.Slot2.isOpen == 0)
      {
        printf("You have dropped '%s'.\n", Inventory.Slot2.Item.Name);
        Inventory.Slot2.isOpen = 1;
        strcpy(Inventory.Slot2.Item.Name, "Empty");
        strcpy(Inventory.Slot2.Item.Description, "Empty");
        strcpy(Inventory.Slot2.Item.Type, "Empty");
        Inventory.Slot2.Item.Weight = 0;
        Inventory.Slot2.Item.AddedDamage = 0;
        Inventory.Slot2.Item.Value = 0;
      }
      else if (Inventory.Slot2.isOpen == 1)
      {
        printf("Slot 2 is already empty.\n");
      }
      else
      {
        printf("Check failed.\n");
      }
    }
    else if (strcmp(input, "3") == 0)
    {
      printf("You have chosen to drop slot 3.\n");
      if (Inventory.Slot3.isOpen == 0)
      {
        printf("The address of %s is at %p\n", Inventory.Slot3.Item.Name, &Inventory.Slot3.Item.Name);
        printf("You have dropped '%s'.\n", Inventory.Slot3.Item.Name);
        Inventory.Slot3.isOpen = 1;
        strcpy(Inventory.Slot3.Item.Name, "Empty");
        strcpy(Inventory.Slot3.Item.Description, "Empty");
        strcpy(Inventory.Slot3.Item.Type, "Empty");
        Inventory.Slot3.Item.Weight = 0;
        Inventory.Slot3.Item.AddedDamage = 0;
        Inventory.Slot3.Item.Value = 0;
      }
      else if (Inventory.Slot3.isOpen == 1)
      {
        printf("Slot 3 is already empty.\n");
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
// this function just prints what inventory action the user is currently on i.e equip, unequip, drop, etc.
void selected_inventory_option(const char *string)
{
  printf("--- %s ---\n", string);
}