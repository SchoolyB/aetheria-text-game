#include <stdio.h>
#include <string.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"

Hero hero;
#define IS_OF_CLASS(classname, string) (strcmp(classname, string) == 0)

void determine_class_for_inventory()
{
  if (IS_OF_CLASS(hero.Class, "Warrior"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.EquippedHead, &Inventory.EquippedChest, &Inventory.EquippedLegs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.EquippedWeapon);
    Inventory.Slot1.isOpen = TRUE;
    Inventory.Slot2.isOpen = TRUE;
    Inventory.Slot3.isOpen = TRUE;

    printf("You currently have a %s equipped. The %s adds %d, because of this the damage for %s in now:%d, the damage for %s is now %d, and the damage for %s is now %d \n", Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.AddedDamage, hero.Ability1.Name, hero.Ability1.Damage, hero.Ability2.Name, hero.Ability2.Damage, hero.Ability3.Name, hero.Ability3.Damage);
  }
  else if (IS_OF_CLASS(hero.Class, "Mage"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.EquippedHead, &Inventory.EquippedChest, &Inventory.EquippedLegs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.EquippedWeapon);

    Inventory.Slot1.isOpen = TRUE;
    Inventory.Slot2.isOpen = TRUE;
    Inventory.Slot3.isOpen = TRUE;
  }
  else if (IS_OF_CLASS(hero.Class, "Rogue"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.EquippedHead, &Inventory.EquippedChest, &Inventory.EquippedLegs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.EquippedWeapon);

    Inventory.Slot1.isOpen = TRUE;
    Inventory.Slot2.isOpen = TRUE;
    Inventory.Slot3.isOpen = TRUE;
  }
  else if (IS_OF_CLASS(hero.Class, "Cleric"))
  {

    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.EquippedHead, &Inventory.EquippedChest, &Inventory.EquippedLegs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.EquippedWeapon);

    Inventory.Slot1.isOpen = TRUE;
    Inventory.Slot2.isOpen = TRUE;
    Inventory.Slot3.isOpen = TRUE;
  }
  else if (IS_OF_CLASS(hero.Class, "Bard"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.EquippedHead, &Inventory.EquippedChest, &Inventory.EquippedLegs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.EquippedWeapon);

    Inventory.Slot1.isOpen = TRUE;
    Inventory.Slot2.isOpen = TRUE;
    Inventory.Slot3.isOpen = TRUE;
  }

  else if (IS_OF_CLASS(hero.Class, "Archer"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.EquippedHead, &Inventory.EquippedChest, &Inventory.EquippedLegs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.EquippedWeapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.EquippedWeapon);

    Inventory.Slot1.isOpen = TRUE;
    Inventory.Slot2.isOpen = TRUE;
    Inventory.Slot3.isOpen = TRUE;
  }
  else
  {
    perror("Invalid class");
    log_error("Invalid class", "determine_class_for_inventory", "exit");
  }
}
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=//
void initialize_starting_weapon(Item *equipped_weapon, char *Name, char *Description, char *Type, int AddedDamage, int Weight, int Value)
{
  strcpy(equipped_weapon->Name, Name);
  strcpy(equipped_weapon->Description, Description);
  strcpy(equipped_weapon->Type, Type);
  equipped_weapon->AddedDamage = AddedDamage;
  equipped_weapon->Weight = Weight;
  equipped_weapon->Value = Value;
}
//=============================================================//
void initialize_starting_head_armor(Item *equipped_head_armor, char *Name, char *Description, char *Type, int AddedHealth, int Weight, int Value)
{
  strcpy(equipped_head_armor->Name, Name);
  strcpy(equipped_head_armor->Description, Description);
  strcpy(equipped_head_armor->Type, Type);
  equipped_head_armor->AddedHealth = AddedHealth;
  equipped_head_armor->Weight = Weight;
  equipped_head_armor->Value = Value;
}
//=============================================================//
void initialize_starting_chest_armor(Item *equipped_chest_armor, char *Name, char *Description, char *Type, int AddedHealth, int Weight, int Value)
{
  strcpy(equipped_chest_armor->Name, Name);
  strcpy(equipped_chest_armor->Description, Description);
  strcpy(equipped_chest_armor->Type, Type);
  equipped_chest_armor->AddedHealth = AddedHealth;
  equipped_chest_armor->Weight = Weight;
  equipped_chest_armor->Value = Value;
}
//=============================================================//
void initialize_starting_leg_armor(Item *equipped_leg_armor, char *Name, char *Description, char *Type, int AddedHealth, int Weight, int Value)
{
  strcpy(equipped_leg_armor->Name, Name);
  strcpy(equipped_leg_armor->Description, Description);
  strcpy(equipped_leg_armor->Type, Type);
  equipped_leg_armor->AddedHealth = AddedHealth;
  equipped_leg_armor->Weight = Weight;
  equipped_leg_armor->Value = Value;
}
//=============================================================//

//=============================================================//
void initialize_inventory(struct Inventory *HeroInventory, char *weaponName, char *headArmorName, char *chestArmorName, char *legsArmorName, int Gold)
{
  initialize_starting_weapon(&HeroInventory->EquippedWeapon, weaponName, "description", "Weapon", 10, 20, 25);
  initialize_starting_head_armor(&HeroInventory->EquippedHead, headArmorName, "description", "Head", 10, 10, 15);
  initialize_starting_chest_armor(&HeroInventory->EquippedChest, chestArmorName, "description", "Chest", 10, 5, 10);
  initialize_starting_leg_armor(&HeroInventory->EquippedLegs, legsArmorName, "description", "Legs", 10, 15, 22);
  // HeroInventory->MaxCarryingCapacity = 60;
  // calculate_remaining_carrying_capacity(&HeroInventory->CarryingCapacity, &HeroInventory->Weapon, &HeroInventory->Head, &HeroInventory->Chest, &HeroInventory->Legs); //old

  calculate_remaining_carrying_capacity(&HeroInventory->CarryingCapacity, &HeroInventory->MaxCarryingCapacity, &HeroInventory->EquippedWeapon, &HeroInventory->EquippedHead, &HeroInventory->EquippedChest, &HeroInventory->EquippedLegs); // new
  HeroInventory->CurrentGold = Gold;
}

//=============================================================//
void check_if_empty_show_none()
{
  if (strlen(Inventory.EquippedHead.Name) == 0)
  {
    strcpy(Inventory.EquippedHead.Name, "None");
    strcpy(Inventory.EquippedHead.Description, "None");
    strcpy(Inventory.EquippedHead.Type, "None");
    Inventory.EquippedHead.AddedHealth = 0;
    Inventory.EquippedHead.Weight = 0;
    Inventory.EquippedHead.Value = 0;
  }
  if (strlen(Inventory.EquippedChest.Name) == 0)
  {
    strcpy(Inventory.EquippedChest.Name, "None");
    strcpy(Inventory.EquippedChest.Description, "None");
    strcpy(Inventory.EquippedChest.Type, "None");
    Inventory.EquippedChest.AddedHealth = 0;
    Inventory.EquippedChest.Weight = 0;
    Inventory.EquippedChest.Value = 0;
  }
  if (strlen(Inventory.EquippedLegs.Name) == 0)
  {
    strcpy(Inventory.EquippedLegs.Name, "None");
    strcpy(Inventory.EquippedLegs.Description, "None");
    strcpy(Inventory.EquippedLegs.Type, "None");
    Inventory.EquippedLegs.AddedHealth = 0;
    Inventory.EquippedLegs.Weight = 0;
    Inventory.EquippedLegs.Value = 0;
  }
  if (strlen(Inventory.EquippedWeapon.Name) == 0)
  {
    strcpy(Inventory.EquippedWeapon.Name, "None");
    strcpy(Inventory.EquippedWeapon.Description, "None");
    strcpy(Inventory.EquippedWeapon.Type, "None");
    Inventory.EquippedWeapon.AddedDamage = 0;
    Inventory.EquippedWeapon.Weight = 0;
    Inventory.EquippedWeapon.Value = 0;
  }
}