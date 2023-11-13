#ifndef ITEMS_INVENTORY_H
#define ITEMS_INVENTORY_H

//+=+=+=+=+=+1_ItemGeneration.c Prototypes+=+=+=+=+=+//
void generate_weapon();
void generate_head_armor();
void generate_chest_armor();
void generate_leg_armor();
void generate_consumable_item();
int generate_item();
int call_generate_function();
void found_loot_chest();
void open_loot_chest();
void generate_loot_chest_contents();
void show_loot_chest_contents();
void ask_to_pick_up();
//+=+=+=+=+=+2_InventoryManagement.c Prototypes+=+=+=+=+=+//
void inventory_options();
void equip_item();
void unequip_item();
void selected_to_unequip();
void choose_open_slot_to_move_to();
void unequip_logic();
int drop_item();
void pick_up_item();
void selected_inventory_option();
void check_and_see_if_none();
void selected_inventory_option();
void get_and_show_inventory_slot_status();
int get_inv_status_and_return_val();
void examine_item();
void show_item_information();

// INVENTORY STRUCTS
// this struct will be applicable to all things in the game that the user can pick up from weapons, armor, and items, to potions, books, etc
typedef struct
{
  char Name[20];
  char Description[100];
  char Type[20]; // weapon, armors, consumable, etc
  int AddedDamage;
  int AddedHealth;
  int Weight;
  int Value;
  char Art[1000];
  char Rarity[10]; // common, uncommon, rare, epic,
  // char Style[10];  // for weapons..i.e sword,axe,mace,staff,wand,etc
} Item;

typedef struct
{
  Item Item;
  int Quantity;
  int isOpen; // 0 = false, 1 = true
} InventorySlot;
struct Inventory
{
  Item EquippedWeapon;
  Item EquippedHead;
  Item EquippedChest;
  Item EquippedLegs;
  InventorySlot Slot1;
  InventorySlot Slot2;
  InventorySlot Slot3;
  int CarryingCapacity;
  int MaxCarryingCapacity;
  int CurrentGold;
} Inventory;

#endif
