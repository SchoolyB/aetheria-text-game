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
void drop_item();
void equip_head_armor();
void equip_chest_armor();
void equip_leg_armor();
void equip_weapon();
void equip_bag();
#endif
