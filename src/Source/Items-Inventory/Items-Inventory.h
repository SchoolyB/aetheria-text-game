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
int get_status_and_return_val();
void examine_item();
void show_item_information();

#endif
