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
    calculate_new_health_from_armor(&hero.Health, &Inventory.Head, &Inventory.Chest, &Inventory.Legs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);

    printf("You currently have a %s equipped. The %s adds %d, because of this the damage for %s in now:%d, the damage for %s is now %d, and the damage for %s is now %d \n", Inventory.Weapon.Name, Inventory.Weapon.Name, Inventory.Weapon.AddedDamage, hero.Ability1.Name, hero.Ability1.Damage, hero.Ability2.Name, hero.Ability2.Damage, hero.Ability3.Name, hero.Ability3.Damage);
  }
  else if (IS_OF_CLASS(hero.Class, "Mage"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Driftwood staff", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.Head, &Inventory.Chest, &Inventory.Legs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
  else if (IS_OF_CLASS(hero.Class, "Rogue"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Dagger", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.Head, &Inventory.Chest, &Inventory.Legs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
  else if (IS_OF_CLASS(hero.Class, "Cleric"))
  {

    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Rusty Mace", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.Head, &Inventory.Chest, &Inventory.Legs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
  else if (IS_OF_CLASS(hero.Class, "Bard"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Driftwood Lute", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.Head, &Inventory.Chest, &Inventory.Legs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }

  else if (IS_OF_CLASS(hero.Class, "Archer"))
  {
    // Setting starting weapon,head/chest/and leg armor, and gold
    initialize_inventory(&Inventory, "Driftwood Bow", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    calculate_new_health_from_armor(&hero.Health, &Inventory.Head, &Inventory.Chest, &Inventory.Legs);
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
}
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=//
void initialize_starting_weapon(Weapon *Weapon, char *Name, char *Description, char *Type, int AddedDamage, int Weight, int Value)
{
  strcpy(Weapon->Name, Name);
  strcpy(Weapon->Description, Description);
  strcpy(Weapon->Type, Type);
  Weapon->AddedDamage = AddedDamage;
  Weapon->Weight = Weight;
  Weapon->Value = Value;
}
//=============================================================//
void initialize_starting_head_armor(HeadArmor *Armor, char *Name, char *Description, char *Type, int AddedHealth, int Weight, int Value)
{
  strcpy(Armor->Name, Name);
  strcpy(Armor->Description, Description);
  strcpy(Armor->Type, Type);
  Armor->AddedHealth = AddedHealth;
  Armor->Weight = Weight;
  Armor->Value = Value;
}
//=============================================================//
void initialize_starting_chest_armor(ChestArmor *Armor, char *Name, char *Description, char *Type, int AddedHealth, int Weight, int Value)
{
  strcpy(Armor->Name, Name);
  strcpy(Armor->Description, Description);
  strcpy(Armor->Type, Type);
  Armor->AddedHealth = AddedHealth;
  Armor->Weight = Weight;
  Armor->Value = Value;
}
//=============================================================//
void initialize_starting_leg_armor(LegArmor *Armor, char *Name, char *Description, char *Type, int AddedHealth, int Weight, int Value)
{
  strcpy(Armor->Name, Name);
  strcpy(Armor->Description, Description);
  strcpy(Armor->Type, Type);
  Armor->AddedHealth = AddedHealth;
  Armor->Weight = Weight;
  Armor->Value = Value;
}
//=============================================================//

//=============================================================//
void initialize_inventory(struct Inventory *HeroInventory, char *weaponName, char *headArmorName, char *chestArmorName, char *legsArmorName, int Gold)
{
  initialize_starting_weapon(&HeroInventory->Weapon, weaponName, "description", "Crappy", 10, 5, 25);
  initialize_starting_head_armor(&HeroInventory->Head, headArmorName, "description", "Crappy", 10, 5, 15);
  initialize_starting_chest_armor(&HeroInventory->Chest, chestArmorName, "description", "Crappy", 10, 5, 10);
  initialize_starting_leg_armor(&HeroInventory->Legs, legsArmorName, "description", "Crappy", 10, 5, 22);
  HeroInventory->CarryingCapacity = 50;
  calculate_remaining_carrying_capacity(&HeroInventory->CarryingCapacity, &HeroInventory->Weapon, &HeroInventory->Head, &HeroInventory->Chest, &HeroInventory->Legs);
  HeroInventory->CurrentGold = Gold;
}