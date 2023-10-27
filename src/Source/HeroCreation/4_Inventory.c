#include <stdio.h>
#include <string.h>
#include "../../Utils/Utils.h"

Hero hero;
#define IS_OF_CLASS(classname, string) (strcmp(classname, string) == 0)

void determine_class_for_inventory()
{
  if (IS_OF_CLASS(hero.Class, "Warrior"))
  {
    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Rusty Sword", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);

    printf("You currently have a %s equipped. The %s adds %d, because of this the damage for %s in now:%d, the damage for %s is now %d, and the damage for %s is now %d \n", Inventory.Weapon.Name, Inventory.Weapon.Name, Inventory.Weapon.AddedDamage, hero.Ability1.Name, hero.Ability1.Damage, hero.Ability2.Name, hero.Ability2.Damage, hero.Ability3.Name, hero.Ability3.Damage);
  }
  else if (IS_OF_CLASS(hero.Class, "Mage"))
  {
    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Driftwood staff", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
  else if (IS_OF_CLASS(hero.Class, "Rogue"))
  {
    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Rusty Dagger", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
  else if (IS_OF_CLASS(hero.Class, "Cleric"))
  {

    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Rusty Mace", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
    calculate_dmg_with_equipped_weapon(&hero.Ability1.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability2.Damage, &Inventory.Weapon);
    calculate_dmg_with_equipped_weapon(&hero.Ability3.Damage, &Inventory.Weapon);
  }
  else if (IS_OF_CLASS(hero.Class, "Bard"))
  {
    // Setting starting weapon,head/chest/and leg armor, bag, and gold
    initialize_inventory(&Inventory, "Small Rucksack", "Driftwood Lute", "Fisherman's Hat", "Puffy Shirt", "Leather Leggings", 5);
    // set_attributes();
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
void initialize_starting_bag_slot1(BagSlot *Slot1, Item *Item, bool IsSlotOpen)
{
  strcpy(Slot1->Item->Name, "A test potion");
  strcpy(Slot1->Item->Description, "Empty");
  strcpy(Slot1->Item->Type, "Empty");
  Slot1->Item->Weight = 0;
  Slot1->Item->Value = 0;
  Slot1->IsSlotOpen = true;
}
//=============================================================//
void initialize_starting_bag_slot2(BagSlot *Slot2, Item *Item, bool IsSlotOpen)
{
  strcpy(Slot2->Item->Name, "Empty");
  strcpy(Slot2->Item->Description, "Empty");
  strcpy(Slot2->Item->Type, "Empty");
  Slot2->Item->Weight = 0;
  Slot2->Item->Value = 0;
  Slot2->IsSlotOpen = true;
}
//=============================================================//
void initialize_starting_bag_slot3(BagSlot *Slot3, Item *Item, bool IsSlotOpen)
{
  strcpy(Slot3->Item->Name, "Empty");
  strcpy(Slot3->Item->Description, "Empty");
  strcpy(Slot3->Item->Type, "Empty");
  Slot3->Item->Weight = 0;
  Slot3->Item->Value = 0;
  Slot3->IsSlotOpen = true;
}
//=============================================================//
void initialize_starting_bag_slot4(BagSlot *Slot4, Item *Item, bool IsSlotOpen)
{
  strcpy(Slot4->Item->Name, "Empty");
  strcpy(Slot4->Item->Description, "Empty");
  strcpy(Slot4->Item->Type, "Empty");
  Slot4->Item->Weight = 0;
  Slot4->Item->Value = 0;
  Slot4->IsSlotOpen = true;
}
//=============================================================//
void initialize_starting_bag_slot5(BagSlot *Slot5, Item *Item, bool IsSlotOpen)
{
  strcpy(Slot5->Item->Name, "Empty");
  strcpy(Slot5->Item->Description, "Empty");
  strcpy(Slot5->Item->Type, "Empty");
  Slot5->Item->Weight = 0;
  Slot5->Item->Value = 0;
  Slot5->IsSlotOpen = true;
}
//=============================================================//
void initialize_starting_bag(Bag *bag, char *name, char *description, int carryingCapacity, char *Type)
{
  strcpy(bag->Name, name);
  strcpy(bag->Description, description);
  bag->CarryingCapacity = carryingCapacity;
}
//=============================================================//
void initialize_inventory(struct Inventory *HeroInventory, const char *backpackName, const char *weaponName, const char *headArmorName, const char *chestArmorName, const char *legsArmorName, int Gold)
{
  initialize_starting_bag(&HeroInventory->Backpack, backpackName, "A small rucksack for your items", 20, "Rucksack");
  initialize_starting_bag_slot1(&HeroInventory->Backpack.Slot1, &HeroInventory->Backpack.Slot1.Item, true);
  initialize_starting_bag_slot2(&HeroInventory->Backpack.Slot2, &HeroInventory->Backpack.Slot2.Item, true);
  initialize_starting_bag_slot3(&HeroInventory->Backpack.Slot3, &HeroInventory->Backpack.Slot3.Item, true);
  initialize_starting_bag_slot4(&HeroInventory->Backpack.Slot4, &HeroInventory->Backpack.Slot4.Item, true);
  initialize_starting_bag_slot5(&HeroInventory->Backpack.Slot5, &HeroInventory->Backpack.Slot5.Item, true);
  initialize_starting_weapon(&HeroInventory->Weapon, weaponName, "Starting weapon description", "Weapon Type", 10, 5, 30);
  initialize_starting_head_armor(&HeroInventory->Head, headArmorName, "Starting head armor description", "Head Armor Type", 10, 5, 30);
  initialize_starting_chest_armor(&HeroInventory->Chest, chestArmorName, "Starting chest armor description", "Chest Armor Type", 10, 5, 30);
  initialize_starting_leg_armor(&HeroInventory->Legs, legsArmorName, "Starting leg armor description", "Leg Armor Type", 10, 5, 30);
  HeroInventory->CurrentGold = Gold;
}