#ifndef ITEMS_INVENTORY_H
#define ITEMS_INVENTORY_H

//+=+=+=+=+=+1_ItemGeneration.c Prototypes+=+=+=+=+=+//
void generate_possible_armor();
//+=+=+=+=+=+2_Chests.c Prototypes+=+=+=+=+=+//
void found_loot_chests();
void generate_loot_chest_contents();
void open_loot_chest();
void show_loot_chest_contents();
void close_loot_chest();
//+=+=+=+=+=+3_InventoryManagement.c Prototypes+=+=+=+=+=+//
void inventory_options();
void choose_open_slot_to_move_to();
void drop_item();
void pick_up_item();
void equip_item();
void unequip_item();
void equip_logic();
void unequip_logic();
void is_it_equippable();
#endif
