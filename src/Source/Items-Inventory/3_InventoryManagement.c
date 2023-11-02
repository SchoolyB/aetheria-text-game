#include <stdio.h>
#include <stdlib.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"

//============================================================================================================//
char possibleInventoryOptions[10][20] = {
    "1.Equip",   // TODO Close but not working yet
    "2.Unequip", // Works
    "3.Drop",    // Works
    "4.Use",     // TODO only if type consumable
    "5.Examine", // Works
    "6.Exit"};   // Works
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
    drop_item(0);
  }
  else if (STR_CMP_TWO(input, "4", "use"))
  {
    // use_item();
    puts("You chose the use option.");
  }
  else if (STR_CMP_TWO(input, "5", "examine"))
  {
    examine_item();
  }
  else if (STR_CMP_TWO(input, "6", "exit"))
  {
    puts("Exiting Inventory.\n");
    sleep(2);
    system("clear");
    return;
  }
  else
  {
    MAKE_VALID_DECISION;
    inventory_options();
  }
}

//============================================================================================================//
void selected_to_unequip()
{

  system("clear");
  selected_inventory_option("Un-equip Item");
  if (Inventory.Slot1.isOpen == 0 && Inventory.Slot2.isOpen == 0 && Inventory.Slot3.isOpen == 0)
  {
    puts("You do not have enough open inventory slots to unequip anything.");
    puts("Please clear up an inventory slot and try again.");
    puts("You can also drop the item that you want to unequip.");
    return;
  }

  if (strcmp(Inventory.Slot1.Item.Name, "None") == 0 && strcmp(Inventory.Slot2.Item.Name, "None") == 0 && strcmp(Inventory.Slot3.Item.Name, "None") == 0)
  {
    puts("You have no items in your inventory.");
    puts("Slot 1: None");
    puts("Slot 2: None");
    puts("Slot 3: None");
    puts("Once you have items they will appear here.");
    return;
  }

  if (Inventory.EquippedWeapon.Name[0] == '\0' && Inventory.EquippedHead.Name[0] == '\0' && Inventory.EquippedChest.Name[0] == '\0' && Inventory.EquippedLegs.Name[0] == '\0')
  {
    puts("You have nothing equipped.");
    return;
  }
  else
  {
    printf("Which of these would you like to unequip?\n");
    puts("Enter '5', 'exit', or 'cancel' to 'exit' the unequip menu");
    printf("(1)Equipped Weapon:%s\n", Inventory.EquippedWeapon.Name);
    printf("(2)Equipped Head Armor:%s\n", Inventory.EquippedHead.Name);
    printf("(3)Equipped Chest Armor:%s\n", Inventory.EquippedChest.Name);
    printf("(4)Equipped Leg Armor:%s\n", Inventory.EquippedLegs.Name);
    printf("(5)Exit\n");
  }

  char input[10]; // this is the input for the actual item to unequip
  FGETS(input);
  REMOVE_NEWLINE_CHAR(input);

  if (STR_CMP(input, "1") || STR_CMP(input, Inventory.EquippedWeapon.Name) || STR_CMP(input, "weapon") && strcmp(Inventory.EquippedWeapon.Name, "None") != 0)
  {
    check_and_see_if_none(&input);
    printf("You have chosen to unequip %s.\n", Inventory.EquippedWeapon.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedWeapon.Name);
    get_and_show_inventory_slot_status();

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
      MAKE_VALID_DECISION;
      sleep(2);
      selected_to_unequip();
    }
  }

  else if (STR_CMP(input, "2") || STR_CMP(input, Inventory.EquippedHead.Name) || STR_CMP(input, "head") && Inventory.EquippedHead.Name[0] != '\0')
  {
    check_and_see_if_none(&input);
    printf("You have chosen to unequip %s.\n", Inventory.EquippedHead.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedHead.Name);
    get_and_show_inventory_slot_status();
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
      MAKE_VALID_DECISION;
      sleep(2);
      selected_to_unequip();
    }
  }
  else if (STR_CMP(input, "3") || STR_CMP(input, Inventory.EquippedChest.Name) || STR_CMP(input, "chest") && Inventory.EquippedChest.Name[0] != '\0')
  {
    check_and_see_if_none(&input);
    printf("You have chosen to unequip %s.\n", Inventory.EquippedChest.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedChest.Name);
    get_and_show_inventory_slot_status();
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
      MAKE_VALID_DECISION;
      sleep(2);
      selected_to_unequip();
    }
  }
  else if (STR_CMP(input, "4") || STR_CMP(input, Inventory.EquippedLegs.Name) || STR_CMP(input, "legs") && Inventory.EquippedLegs.Name[0] != '\0')
  {
    check_and_see_if_none(&input);
    printf("You have chosen to unequip %s.\n", Inventory.EquippedLegs.Name);
    printf("Which slot would you like to move %s to?\n", Inventory.EquippedLegs.Name);
    get_and_show_inventory_slot_status();
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
      MAKE_VALID_DECISION;
      sleep(2);
      selected_to_unequip();
    }
  }
}
//============================================================================================================//

// this function takes in and handles the logic for  UN-EQUIPPING an item. See logic in void unequip_logic()
void choose_open_slot_to_move_to(char *newInput, char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int *equippedItemWeight, int *equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, int *slotItemWeight, int *slotItemAddedDamage, int *slotItemAddedHealth, int *slotItemValue)
{

  if (STR_CMP(newInput, "1") && Inventory.Slot1.isOpen == 1)
  {
    puts("You have chosen to move your item to Slot 1.");
    Inventory.Slot1.isOpen = 0;

    if (strcmp(equippedItemType, "Weapon") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot1.Item.Weight = equippedItemWeight;
      Inventory.Slot1.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot1.Item.Value = equippedItemValue;
      puts("Slot 1 is now full.");
      printf("%s has been placed in Slot 1\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedWeapon.Weight = 0;
      Inventory.EquippedWeapon.AddedDamage = 0;
      Inventory.EquippedWeapon.AddedHealth = 0;
      Inventory.EquippedWeapon.Value = 0;
    }
    else if (strcmp(equippedItemType, "Head") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot1.Item.Weight = equippedItemWeight;
      Inventory.Slot1.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot1.Item.Value = equippedItemValue;
      puts("Slot 1 is now full.");
      printf("%s has been placed in Slot 1\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedHead.Weight = 0;
      Inventory.EquippedHead.AddedDamage = 0;
      Inventory.EquippedHead.AddedHealth = 0;
      Inventory.EquippedHead.Value = 0;
    }
    else if (strcmp(equippedItemType, "Chest") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot1.Item.Weight = equippedItemWeight;
      Inventory.Slot1.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot1.Item.Value = equippedItemValue;
      puts("Slot 1 is now full.");
      printf("%s has been placed in Slot 1\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedChest.Weight = 0;
      Inventory.EquippedChest.AddedDamage = 0;
      Inventory.EquippedChest.AddedHealth = 0;
      Inventory.EquippedChest.Value = 0;
    }
    else if (strcmp(equippedItemType, "Legs") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot1.Item.Weight = equippedItemWeight;
      Inventory.Slot1.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot1.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot1.Item.Value = equippedItemValue;
      puts("Slot 1 is now full.");
      printf("%s has been placed in Slot 1\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedLegs.Weight = 0;
      Inventory.EquippedLegs.AddedDamage = 0;
      Inventory.EquippedLegs.AddedHealth = 0;
      Inventory.EquippedLegs.Value = 0;
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
    Inventory.Slot2.isOpen = 0;

    if (strcmp(equippedItemType, "Weapon") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot2.Item.Weight = equippedItemWeight;
      Inventory.Slot2.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot2.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot2.Item.Value = equippedItemValue;
      puts("Slot 2 is now full.");
      printf("%s has been placed in Slot 2\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedWeapon.Weight = 0;
      Inventory.EquippedWeapon.AddedDamage = 0;
      Inventory.EquippedWeapon.AddedHealth = 0;
      Inventory.EquippedWeapon.Value = 0;
    }
    else if (strcmp(equippedItemType, "Head") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot2.Item.Weight = equippedItemWeight;
      Inventory.Slot2.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot2.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot2.Item.Value = equippedItemValue;
      puts("Slot 2 is now full.");
      printf("%s has been placed in Slot 2\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedHead.Weight = 0;
      Inventory.EquippedHead.AddedDamage = 0;
      Inventory.EquippedHead.AddedHealth = 0;
      Inventory.EquippedHead.Value = 0;
    }
    else if (strcmp(equippedItemType, "Chest") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot2.Item.Weight = equippedItemWeight;
      Inventory.Slot2.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot2.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot2.Item.Value = equippedItemValue;
      puts("Slot 2 is now full.");
      printf("%s has been placed in Slot 2\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedChest.Weight = 0;
      Inventory.EquippedChest.AddedDamage = 0;
      Inventory.EquippedChest.AddedHealth = 0;
      Inventory.EquippedChest.Value = 0;
    }
    else if (strcmp(equippedItemType, "Legs") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot2.Item.Weight = equippedItemWeight;
      Inventory.Slot2.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot2.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot2.Item.Value = equippedItemValue;
      puts("Slot 2 is now full.");
      printf("%s has been placed in Slot 2\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedLegs.Weight = 0;
      Inventory.EquippedLegs.AddedDamage = 0;
      Inventory.EquippedLegs.AddedHealth = 0;
      Inventory.EquippedLegs.Value = 0;
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

    Inventory.Slot3.isOpen = 0;

    if (strcmp(equippedItemType, "Weapon") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot3.Item.Weight = equippedItemWeight;
      Inventory.Slot3.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot3.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot3.Item.Value = equippedItemValue;
      puts("Slot 3 is now full.");
      printf("%s has been placed in Slot 3\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedWeapon.Weight = 0;
      Inventory.EquippedWeapon.AddedDamage = 0;
      Inventory.EquippedWeapon.AddedHealth = 0;
      Inventory.EquippedWeapon.Value = 0;
    }
    else if (strcmp(equippedItemType, "Head") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot3.Item.Weight = equippedItemWeight;
      Inventory.Slot3.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot3.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot3.Item.Value = equippedItemValue;
      puts("Slot 3 is now full.");
      printf("%s has been placed in Slot 3\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedHead.Weight = 0;
      Inventory.EquippedHead.AddedDamage = 0;
      Inventory.EquippedHead.AddedHealth = 0;
      Inventory.EquippedHead.Value = 0;
    }
    else if (strcmp(equippedItemType, "Chest") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot3.Item.Weight = equippedItemWeight;
      Inventory.Slot3.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot3.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot3.Item.Value = equippedItemValue;
      puts("Slot 3 is now full.");
      printf("%s has been placed in Slot 3\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedChest.Weight = 0;
      Inventory.EquippedChest.AddedDamage = 0;
      Inventory.EquippedChest.AddedHealth = 0;
      Inventory.EquippedChest.Value = 0;
    }
    else if (strcmp(equippedItemType, "Legs") == 0)
    {
      strcpy(slotItemName, equippedItemName);
      strcpy(slotItemDesc, equippedItemDesc);
      strcpy(slotItemType, equippedItemType);
      Inventory.Slot3.Item.Weight = equippedItemWeight;
      Inventory.Slot3.Item.AddedDamage = equippedItemAddedDamage;
      Inventory.Slot3.Item.AddedHealth = equippedItemAddedHealth;
      Inventory.Slot3.Item.Value = equippedItemValue;
      puts("Slot 3 is now full.");
      printf("%s has been placed in Slot 3\n", equippedItemName);
      strcpy(equippedItemName, "None");
      strcpy(equippedItemDesc, "None");
      strcpy(equippedItemType, "None");
      Inventory.EquippedLegs.Weight = 0;
      Inventory.EquippedLegs.AddedDamage = 0;
      Inventory.EquippedLegs.AddedHealth = 0;
      Inventory.EquippedLegs.Value = 0;
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
//============================================================================================================//
// this function is used to equip an item from the players inventory into one of there "equippable" slots
void equip_item()
{
  system("clear");
  selected_inventory_option("Equip Item");
  // check if slot 1 is None
  if (Inventory.Slot1.Item.Name[0] == '\0' && Inventory.Slot2.Item.Name[0] == '\0' && Inventory.Slot3.Item.Name[0] == '\0')
  {
    puts("You have no items in your inventory.");
    puts("Slot 1: None");
    puts("Slot 2: None");
    puts("Slot 3: None");
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
    printf("You have chosen to equip %s. \n", Inventory.Slot1.Item.Name);
    if (strcmp(Inventory.Slot1.Item.Name, "None") == 0)
    {
      puts("There is nothing in this slot.");
    }
    else
    {
      equip_logic(Inventory.Slot1.Item.Name, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value);
    }
  }
  else if (STR_CMP(input, "2") || STR_CMP(input, "slot2"))
  {
    printf("You have chosen to equip %s. \n", Inventory.Slot2.Item.Name);
    if (strcmp(Inventory.Slot2.Item.Name, "None") == 0)
    {
      puts("There is nothing in this slot.");
    }
    else
    {
      equip_logic(Inventory.Slot2.Item.Name, Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.AddedDamage, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Value);
    }
  }
  else if (STR_CMP(input, "3") || STR_CMP(input, "slot3"))
  {
    printf("You have chosen to equip %s. \n", Inventory.Slot3.Item.Name);
    if (strcmp(Inventory.Slot3.Item.Name, "None") == 0)
    {
      puts("There is nothing in this slot.");
    }
    else
    {
      equip_logic(Inventory.Slot3.Item.Name, Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.AddedDamage, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Value);
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    equip_item();
  }
}
//============================================================================================================//
// this function contains all the logic for EQUIPPING an item. See implementation in void equip_item()
void equip_logic(char *itemInSlot, char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue)
{
  printf("You have chosen to equip %s. \n", itemInSlot);
  if (strcmp(itemInSlot, "None") == 0)
  {
    puts("There is nothing in this slot.");
  }
  /*
  The following 'else if' statements
  Run checks to see if an equippable slot is None
  AND if the user is trying to equip correct type for
  that equippable slot then equip it. If not throw error
  */
  else if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && strcmp(Inventory.Slot1.Item.Type, "Weapon") == 0)
  {
    is_weapon_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
  }
  else if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && strcmp(Inventory.Slot2.Item.Type, "Weapon") == 0)
  {
    is_weapon_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
  }
  else if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && strcmp(Inventory.Slot3.Item.Type, "Weapon") == 0)
  {
    is_weapon_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
  }
  else if (strcmp(Inventory.EquippedHead.Name, "None") == 0 && strcmp(Inventory.Slot1.Item.Type, "Head") == 0)
  {
    is_head_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
  }
  else if (strcmp(Inventory.EquippedHead.Name, "None") == 0 && strcmp(Inventory.Slot2.Item.Type, "Head") == 0)
  {
    is_head_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
  }
  else if (strcmp(Inventory.EquippedHead.Name, "None") == 0 && strcmp(Inventory.Slot3.Item.Type, "Head") == 0)
  {
    is_head_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
  }
  else if (strcmp(Inventory.EquippedChest.Name, "None") == 0 && strcmp(Inventory.Slot1.Item.Type, "Chest") == 0)
  {
    is_chest_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
  }
  else if (strcmp(Inventory.EquippedChest.Name, "None") == 0 && strcmp(Inventory.Slot2.Item.Type, "Chest") == 0)
  {
    is_chest_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
  }
  else if (strcmp(Inventory.EquippedChest.Name, "None") == 0 && strcmp(Inventory.Slot3.Item.Type, "Chest") == 0)
  {
    is_chest_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
  }
  else if (strcmp(Inventory.EquippedLegs.Name, "None") == 0 && strcmp(Inventory.Slot1.Item.Type, "Legs") == 0)
  {
    is_legs_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
  }
  else if (strcmp(Inventory.EquippedLegs.Name, "None") == 0 && strcmp(Inventory.Slot2.Item.Type, "Legs") == 0)
  {
    is_legs_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
  }
  else if (strcmp(Inventory.EquippedLegs.Name, "None") == 0 && strcmp(Inventory.Slot3.Item.Type, "Legs") == 0)
  {
    is_legs_equippable(equippedItemName, equippedItemDesc, equippedItemType, equippedItemWeight, equippedItemAddedDamage, equippedItemAddedHealth, equippedItemValue, Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
  }
  else
  {
    puts("There is an item already equipped in this slot.");
  }
}
//============================================================================================================//
// The following 4 function run a check to so if an item is equippable to the correct equippable slot see implementation in void equip_logic()
void is_weapon_equippable(char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, int slotItemWeight, int slotItemAddedDamage, int slotItemAddedHealth, int slotItemValue)
{
  if (strcmp(slotItemType, "Weapon") == 0)
  {
    puts("You have chosen to equip a weapon.");
    puts("You have equipped the weapon.");
    strcpy(equippedItemName, slotItemName);
    strcpy(equippedItemDesc, slotItemDesc);
    strcpy(equippedItemType, slotItemType);
    equippedItemWeight = slotItemWeight;
    equippedItemAddedDamage = slotItemAddedDamage;
    equippedItemAddedHealth = slotItemAddedHealth;
    equippedItemValue = slotItemValue;
    strcpy(slotItemName, "None");
    strcpy(slotItemDesc, "None");
    strcpy(slotItemType, "None");
    slotItemWeight = 0;
    slotItemAddedDamage = 0;
    slotItemAddedHealth = 0;
    slotItemValue = 0;
  }
  else
  {
    puts("Check failed.");
  }
}
//============================================================================================================//
void is_head_equippable(char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, int slotItemWeight, int slotItemAddedDamage, int slotItemAddedHealth, int slotItemValue)
{
  if (strcmp(slotItemType, "Head") == 0)
  {
    puts("You have chosen to equip head armor.");
    puts("You have equipped the head armor.");
    strcpy(equippedItemName, slotItemName);
    strcpy(equippedItemDesc, slotItemDesc);
    strcpy(equippedItemType, slotItemType);
    equippedItemWeight = slotItemWeight;
    equippedItemAddedDamage = slotItemAddedDamage;
    equippedItemAddedHealth = slotItemAddedHealth;
    equippedItemValue = slotItemValue;
    strcpy(slotItemName, "None");
    strcpy(slotItemDesc, "None");
    strcpy(slotItemType, "None");
    slotItemWeight = 0;
    slotItemAddedDamage = 0;
    slotItemAddedHealth = 0;
    slotItemValue = 0;
  }
  else
  {
    puts("Check failed.");
  }
}
//============================================================================================================//
void is_chest_equippable(char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, int slotItemWeight, int slotItemAddedDamage, int slotItemAddedHealth, int slotItemValue)
{
  if (strcmp(slotItemType, "Chest") == 0)
  {
    puts("You have chosen to equip chest armor.");
    puts("You have equipped the chest armor.");
    strcpy(equippedItemName, slotItemName);
    strcpy(equippedItemDesc, slotItemDesc);
    strcpy(equippedItemType, slotItemType);
    equippedItemWeight = slotItemWeight;
    equippedItemAddedDamage = slotItemAddedDamage;
    equippedItemAddedHealth = slotItemAddedHealth;
    equippedItemValue = slotItemValue;
    strcpy(slotItemName, "None");
    strcpy(slotItemDesc, "None");
    strcpy(slotItemType, "None");
    slotItemWeight = 0;
    slotItemAddedDamage = 0;
    slotItemAddedHealth = 0;
    slotItemValue = 0;
  }
  else
  {
    puts("Check failed.");
  }
}
//============================================================================================================//
void is_legs_equippable(char *equippedItemName, char *equippedItemDesc, char *equippedItemType, int equippedItemWeight, int equippedItemAddedDamage, int equippedItemAddedHealth, int equippedItemValue, char *slotItemName, char *slotItemDesc, char *slotItemType, int slotItemWeight, int slotItemAddedDamage, int slotItemAddedHealth, int slotItemValue)
{
  if (strcmp(slotItemType, "Legs") == 0)
  {
    puts("You have chosen to equip leg armor.");
    puts("You have equipped the leg armor.");
    strcpy(equippedItemName, slotItemName);
    strcpy(equippedItemDesc, slotItemDesc);
    strcpy(equippedItemType, slotItemType);
    equippedItemWeight = slotItemWeight;
    equippedItemAddedDamage = slotItemAddedDamage;
    equippedItemAddedHealth = slotItemAddedHealth;
    equippedItemValue = slotItemValue;
    strcpy(slotItemName, "None");
    strcpy(slotItemDesc, "None");
    strcpy(slotItemType, "None");
    slotItemWeight = 0;
    slotItemAddedDamage = 0;
    slotItemAddedHealth = 0;
    slotItemValue = 0;
  }
  else
  {
    puts("Check failed.");
  }
}
//============================================================================================================//
// this function is used to drop an item if the slot is not None
int drop_item(int *val)
{
  system("clear");
  selected_inventory_option("Drop Item");
  char input[10];
  int result = get_inv_status_and_return_val(&val);

  if (result == 3)
  {
    puts("You have no items equipped nor in your inventory.");
    return;
  }
  else if (result == 2)
  {

    puts("Would you like to drop an item?");
    MAKE_RED("WARNING: This action is IRREVERSIBLE.\n");
    MAKE_RED("You will lose the item forever.\n");
    MAKE_RED("Are you sure you want to drop an item?(y/n)\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (INPUT_IS_YES(input))
    {
      puts("You have chosen to drop an item.");
      puts("Which slot would you like to drop?");
      puts("For inventory slots enter the slot number.");
      puts("For equipped slots enter the slot name.");
      puts("An example of an equipped slot is 'weapon' or 'head'.");
      printf("Slot 1: %s\n", Inventory.Slot1.Item.Name);
      printf("Slot 2: %s\n", Inventory.Slot2.Item.Name);
      printf("Slot 3: %s\n", Inventory.Slot3.Item.Name);
      printf("Weapon: %s\n", Inventory.EquippedWeapon.Name);
      printf("Head: %s\n", Inventory.EquippedHead.Name);
      printf("Chest: %s\n", Inventory.EquippedChest.Name);
      printf("Legs: %s\n", Inventory.EquippedLegs.Name);
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);
      if (strcmp(input, "1") == 0)
      {
        printf("You have chosen to empty slot 1.\n");
        if (strcmp(Inventory.Slot1.Item.Name, "None") != 0)
        {
          printf("You have dropped '%s'.\n", Inventory.Slot1.Item.Name);
          Inventory.Slot1.isOpen = 1;
          strcpy(Inventory.Slot1.Item.Name, "None");
          strcpy(Inventory.Slot1.Item.Description, "None");
          strcpy(Inventory.Slot1.Item.Type, "None");
          Inventory.Slot1.Item.Weight = 0;
          Inventory.Slot1.Item.AddedDamage = 0;
          Inventory.Slot1.Item.AddedHealth = 0;
          Inventory.Slot1.Item.Value = 0;
        }
        else if (strcmp(Inventory.Slot1.Item.Name, "None") == 0)
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
          strcpy(Inventory.Slot2.Item.Name, "None");
          strcpy(Inventory.Slot2.Item.Description, "None");
          strcpy(Inventory.Slot2.Item.Type, "None");
          Inventory.Slot2.Item.Weight = 0;
          Inventory.Slot2.Item.AddedDamage = 0;
          Inventory.Slot2.Item.AddedHealth = 0;
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
          printf("You have dropped '%s'.\n", Inventory.Slot3.Item.Name);
          Inventory.Slot3.isOpen = 1;
          strcpy(Inventory.Slot3.Item.Name, "None");
          strcpy(Inventory.Slot3.Item.Description, "None");
          strcpy(Inventory.Slot3.Item.Type, "None");
          Inventory.Slot3.Item.Weight = 0;
          Inventory.Slot3.Item.AddedDamage = 0;
          Inventory.Slot3.Item.AddedHealth = 0;
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
      else if (strcmp(input, "weapon") == 0)
      {
        printf("You have chosen to drop your weapon.\n");
        system("clear");
        if (strcmp(Inventory.EquippedWeapon.Name, "None") != 0)
        {
          printf("You have dropped '%s'.\n", Inventory.EquippedWeapon.Name);
          strcpy(Inventory.EquippedWeapon.Name, "None");
          strcpy(Inventory.EquippedWeapon.Description, "None");
          strcpy(Inventory.EquippedWeapon.Type, "None");
          Inventory.EquippedWeapon.Weight = 0;
          Inventory.EquippedWeapon.AddedDamage = 0;
          Inventory.EquippedWeapon.AddedHealth = 0;
          Inventory.EquippedWeapon.Value = 0;
        }
        else if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0)
        {
          printf("You have no weapon equipped.\n");
        }
        else
        {
          printf("Check failed.\n");
        }
      }
      else if (strcmp(input, "head") == 0)
      {
        printf("You have chosen to drop your head armor.\n");
        if (strcmp(Inventory.EquippedHead.Name, "None") != 0)
        {
          printf("You have dropped '%s'.\n", Inventory.EquippedHead.Name);
          strcpy(Inventory.EquippedHead.Name, "None");
          strcpy(Inventory.EquippedHead.Description, "None");
          strcpy(Inventory.EquippedHead.Type, "None");
          Inventory.EquippedHead.Weight = 0;
          Inventory.EquippedHead.AddedDamage = 0;
          Inventory.EquippedHead.AddedHealth = 0;
          Inventory.EquippedHead.Value = 0;
        }
        else if (strcmp(Inventory.EquippedHead.Name, "None") == 0)
        {
          printf("You have no head armor equipped.\n");
        }
        else
        {
          printf("Check failed.\n");
        }
      }
      else if (strcmp(input, "chest") == 0)
      {
        printf("You have chosen to drop your chest armor.\n");
        if (strcmp(Inventory.EquippedChest.Name, "None") != 0)
        {
          printf("You have dropped '%s'.\n", Inventory.EquippedChest.Name);
          strcpy(Inventory.EquippedChest.Name, "None");
          strcpy(Inventory.EquippedChest.Description, "None");
          strcpy(Inventory.EquippedChest.Type, "None");
          Inventory.EquippedChest.Weight = 0;
          Inventory.EquippedChest.AddedDamage = 0;
          Inventory.EquippedChest.AddedHealth = 0;
          Inventory.EquippedChest.Value = 0;
        }
        else if (strcmp(Inventory.EquippedChest.Name, "None") == 0)
        {
          printf("You have no chest armor equipped.\n");
        }
        else
        {
          printf("Check failed.\n");
        }
      }
      else if (strcmp(input, "legs" || "leg") == 0)
      {
        printf("You have chosen to drop your leg armor.\n");
        if (strcmp(Inventory.EquippedLegs.Name, "None") != 0)
        {
          printf("You have dropped '%s'.\n", Inventory.EquippedLegs.Name);
          strcpy(Inventory.EquippedLegs.Name, "None");
          strcpy(Inventory.EquippedLegs.Description, "None");
          strcpy(Inventory.EquippedLegs.Type, "None");
          Inventory.EquippedLegs.Weight = 0;
          Inventory.EquippedLegs.AddedDamage = 0;
          Inventory.EquippedLegs.AddedHealth = 0;
          Inventory.EquippedLegs.Value = 0;
        }
        else if (strcmp(Inventory.EquippedLegs.Name, "None") == 0)
        {
          printf("You have no leg armor equipped.\n");
        }
        else
        {
          printf("Check failed.\n");
        }
      }
      else
      {
        printf("Invalid input.\n");
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
  return 0;
}

//============================================================================================================//
// this function is used to pick up an item and place it in an open slot
void pick_up_item(char itemName[20], char itemDesc[50], char itemType[15], int itemWeight, int itemAddedDamage, int itemValue)
{
  char input[10];

  if (Inventory.Slot1.isOpen == 0 && Inventory.Slot2.isOpen == 0 && Inventory.Slot3.isOpen == 0)
  {
    puts("You have no open slots.");
    puts("You must drop an item before you can pick up this item.");
    return;
  }
  else if (Inventory.Slot1.isOpen == 1 || Inventory.Slot2.isOpen == 1 || Inventory.Slot3.isOpen == 1)
  {

    printf("Which inventory slot would you like to put '%s' in?\n", itemName);
    get_and_show_inventory_slot_status();
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);
    if (atoi(input) == 1)
    {
      if (Inventory.Slot1.isOpen == 1)
      {
        system("clear");
        puts("You have chosen to put the item in slot 1.");
        strcpy(Inventory.Slot1.Item.Name, itemName);
        strcpy(Inventory.Slot1.Item.Description, itemDesc);
        strcpy(Inventory.Slot1.Item.Type, itemType);
        Inventory.Slot1.Item.Weight = itemWeight;
        Inventory.Slot1.Item.AddedDamage = itemAddedDamage;
        Inventory.Slot1.Item.Value = itemValue;
        Inventory.Slot1.isOpen = 0;
        printf("You have placed '%s' in slot 1.\n", itemName);
      }
      else if (Inventory.Slot1.isOpen == 0)
      {
        puts("Slot 1 is already full.");
        puts("Please try again.");
        sleep(2);
        pick_up_item(itemName, itemDesc, itemType, itemWeight, itemAddedDamage, itemValue);
      }
      else
      {
        puts("Check failed.");
      }
    }
    else if (atoi(input) == 2)
    {
      if (Inventory.Slot2.isOpen == 1)
      {
        system("clear");
        puts("You have chosen to put the item in slot 2.");
        strcpy(Inventory.Slot2.Item.Name, itemName);
        strcpy(Inventory.Slot2.Item.Description, itemDesc);
        strcpy(Inventory.Slot2.Item.Type, itemType);
        Inventory.Slot2.Item.Weight = itemWeight;
        Inventory.Slot2.Item.AddedDamage = itemAddedDamage;
        Inventory.Slot2.Item.Value = itemValue;
        Inventory.Slot2.isOpen = 0;
        printf("You have placed '%s' in slot 2.\n", itemName);
      }
      else if (Inventory.Slot2.isOpen == 0)
      {
        puts("Slot 2 is already full.");
        puts("Please try again.");
        sleep(2);
        pick_up_item(itemName, itemDesc, itemType, itemWeight, itemAddedDamage, itemValue);
      }
      else
      {
        puts("Check failed.");
      }
    }
    else if (atoi(input) == 3)
    {
      if (Inventory.Slot3.isOpen == 1)
      {
        system("clear");
        puts("You have chosen to put the item in slot 3.");
        strcpy(Inventory.Slot3.Item.Name, itemName);
        strcpy(Inventory.Slot3.Item.Description, itemDesc);
        strcpy(Inventory.Slot3.Item.Type, itemType);
        Inventory.Slot3.Item.Weight = itemWeight;
        Inventory.Slot3.Item.AddedDamage = itemAddedDamage;
        Inventory.Slot3.Item.Value = itemValue;
        Inventory.Slot3.isOpen = 0;
        printf("You have placed '%s' in slot 3.\n", itemName);
      }
      else if (Inventory.Slot3.isOpen == 0)
      {
        puts("Slot 3 is already full.");
        puts("Please try again.");
        sleep(2);
        pick_up_item(itemName, itemDesc, itemType, itemWeight, itemAddedDamage, itemValue);
      }
      else
      {
        puts("Check failed.");
      }
    }
    else
    {
      puts("Invalid input.");
      puts("Please try again.");
      sleep(2);
      pick_up_item(itemName, itemDesc, itemType, itemWeight, itemAddedDamage, itemValue);
    }
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
//============================================================================================================//
// this function is similar to get_and_show_inventory_slot_status() but has different use cases. TBH this can prob be deleted or combined
void check_and_see_if_none(char *input)
{
  if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && STR_CMP(input, "1"))
  {
    puts("You dont have a weapon equipped please try again");
    sleep(2);
    selected_to_unequip();
  }
  else if (strcmp(Inventory.EquippedHead.Name, "None") == 0 && STR_CMP(input, "2"))
  {
    puts("You dont have head armor equipped please try again");
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
}
//============================================================================================================//
// this function is used to check if slot is empty or full and show the name of its content see implementation in void unequip_item()
void get_and_show_inventory_slot_status()
{
  if (Inventory.Slot1.isOpen == 1)
  {
    printf("Slot 1: %s\n", Inventory.Slot1.Item.Name);
  }
  else if (Inventory.Slot1.isOpen == 0)
  {
    printf("Slot 1: %s\n", Inventory.Slot1.Item.Name);
  }
  else
  {
    puts("Check failed.");
  }
  if (Inventory.Slot2.isOpen == 1)
  {
    printf("Slot 2: %s\n", Inventory.Slot2.Item.Name);
  }
  else if (Inventory.Slot2.isOpen == 0)
  {
    printf("Slot 2: %s\n", Inventory.Slot2.Item.Name);
  }
  else
  {
    puts("Check failed.");
  }
  if (Inventory.Slot3.isOpen == 1)
  {
    printf("Slot 3: %s\n", Inventory.Slot3.Item.Name);
  }
  else if (Inventory.Slot3.isOpen == 0)
  {
    printf("Slot 3: %s\n", Inventory.Slot3.Item.Name);
  }
  else
  {
    puts("Check failed.");
  }
}

//============================================================================================================//
// this function evaluates if slots are empty or full then return a value. see use in drop_item()
int get_inv_status_and_return_val(int *val)
{
  if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && strcmp(Inventory.EquippedHead.Name, "None") == 0 && strcmp(Inventory.EquippedChest.Name, "None") == 0 && strcmp(Inventory.EquippedLegs.Name, "None") == 0)
  {
    int val = 3;
    return val;
  }
  else if (strcmp(Inventory.EquippedWeapon.Name, "None") != 0 || strcmp(Inventory.EquippedHead.Name, "None") != 0 || strcmp(Inventory.EquippedChest.Name, "None") != 0 || strcmp(Inventory.EquippedLegs.Name, "None") != 0 || Inventory.Slot1.Item.Name[0] != '\0' || Inventory.Slot2.Item.Name[0] != '\0' || Inventory.Slot3.Item.Name[0] != '\0')
  {
    int val = 2;
    return val;
  }
}
//============================================================================================================//
// this function is used to check if the player wants to examine an item in there inventory. as well as show the item information see implementation in void selected_inventory_option()
void examine_item()
{
  char input[10];
  system("clear");
  selected_inventory_option("Examine Item");
  if (strcmp(Inventory.EquippedWeapon.Name, "None") == 0 && strcmp(Inventory.EquippedHead.Name, "None") == 0 && strcmp(Inventory.EquippedChest.Name, "None") == 0 && strcmp(Inventory.EquippedLegs.Name, "None") == 0)
  {
    puts("You have no items equipped nor in your inventory.");
    return;
  }
  else if (strcmp(Inventory.EquippedWeapon.Name, "None") != 0 || strcmp(Inventory.EquippedHead.Name, "None") != 0 || strcmp(Inventory.EquippedChest.Name, "None") != 0 || strcmp(Inventory.EquippedLegs.Name, "None") != 0 || Inventory.Slot1.Item.Name[0] != '\0' || Inventory.Slot2.Item.Name[0] != '\0' || Inventory.Slot3.Item.Name[0] != '\0')
  {
    puts("Which item would you like to examine?");
    puts("Enter an inventory slot number or equip slot name.");
    printf("Slot 1: %s\n", Inventory.Slot1.Item.Name);
    printf("Slot 2: %s\n", Inventory.Slot2.Item.Name);
    printf("Slot 3: %s\n", Inventory.Slot3.Item.Name);
    printf("Weapon: %s\n", Inventory.EquippedWeapon.Name);
    printf("Head: %s\n", Inventory.EquippedHead.Name);
    printf("Chest: %s\n", Inventory.EquippedChest.Name);
    printf("Legs: %s\n", Inventory.EquippedLegs.Name);

    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);
    if (strcmp(input, "1") == 0 && Inventory.Slot1.isOpen == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.Slot1.Item.Name);
      show_item_information(Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Value);
    }
    else if (strcmp(input, "1") == 0 && Inventory.Slot1.isOpen == 1)
    {
      puts("There is nothing in this slot.");
      puts("Please choose a slot that has an item in it.");
      examine_item();
    }

    else if (strcmp(input, "2") == 0 && Inventory.Slot2.isOpen == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.Slot2.Item.Name);
      show_item_information(Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Value);
    }
    else if (strcmp(input, "2") == 0 && Inventory.Slot2.isOpen == 1)
    {
      puts("There is nothing in this slot.");
      puts("Please choose a slot that has an item in it.");
      examine_item();
    }

    else if (strcmp(input, "3") == 0 && Inventory.Slot3.isOpen == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.Slot3.Item.Name);
      show_item_information(Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Value);
    }
    else if (strcmp(input, "3") == 0 && Inventory.Slot3.isOpen == 1)
    {
      puts("There is nothing in this slot.");
      puts("Please choose a slot that has an item in it.");
      examine_item();
    }
    else if (strcmp(input, "weapon") == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.EquippedWeapon.Name);
      show_item_information(Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.AddedHealth, Inventory.EquippedWeapon.Value);
    }
    else if (strcmp(input, "head") == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.EquippedHead.Name);
      show_item_information(Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.AddedDamage, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Value);
    }
    else if (strcmp(input, "chest") == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.EquippedChest.Name);
      show_item_information(Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.AddedDamage, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Value);
    }
    else if (strcmp(input, "legs") == 0)
    {
      system("clear");
      printf("You have chosen to examine %s.\n", Inventory.EquippedLegs.Name);
      show_item_information(Inventory.EquippedLegs.Name, Inventory.EquippedLegs.Description, Inventory.EquippedLegs.Type, Inventory.EquippedLegs.Weight, Inventory.EquippedLegs.AddedDamage, Inventory.EquippedLegs.AddedHealth, Inventory.EquippedLegs.Value);
    }
    else
    {
      puts("Invalid input.");
      puts("Please try again.");
      examine_item();
    }
  }
}
//============================================================================================================//
// this function shows a chart of information and some ascii art of the current item being examined see implementation in void examine_item()
void show_item_information(char *itemName, char *itemDesc, char *itemType, int itemWeight, int itemAddedDamage, int itemAddedHealth, int itemValue)
{
  printf("Name: %s\n", itemName);
  printf("Description: %s\n", itemDesc);
  printf("Type: %s\n", itemType);
  printf("Weight: %d\n", itemWeight);
  printf("Added Damage: %d\n", itemAddedDamage);
  printf("Added Health: %d\n", itemAddedHealth);
  printf("Value: %d\n", itemValue);
  return;
}