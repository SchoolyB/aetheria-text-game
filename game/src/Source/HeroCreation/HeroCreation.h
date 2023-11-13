#ifndef HERO_CREATION_H
#define HERO_CREATION_H

//+=+=+=+=+=+1_HeroCreation.c Prototypes+=+=+=+=+=+//
void get_first_name();
void ask_for_dynasty_name();
void get_dynasty_name();
void confirm_dynasty_name();
void ask_for_gender();
void confirm_no_gender();
void get_gender();
void confirm_gender();
void get_homeland();
void confirm_homeland();
void get_profession();
void confirm_profession();
void get_class();
void confirm_class();
void set_hero_level();
void log_creation_data_to_file();
//+=+=+=+=+=+2_Abilities.c Prototypes+=+=+=+=+=+//
int set_abilities();
//+=+=+=+=+=+3_BaselineStats.c Prototypes+=+=+=+=+=+//
void set_baseline_stats();
//+=+=+=+=+=+4_Attributes.c Prototypes+=+=+=+=+=+//
int set_attributes();
//+=+=+=+=+=+5_Inventory.c Prototypes+=+=+=+=+=+//
void determine_class_for_inventory();
void initialize_starting_weapon();
void initialize_starting_head_armor();
void initialize_starting_chest_armor();
void initialize_starting_leg_armor();
void initialize_inventory();
void check_if_empty_show_none();
//+=+=+=+=+=+6_Confirmation.c Prototypes+=+=+=+=+=+//
void confirm_hero_creation_and_stats();
void show_creation_data();
//+=+=+=+=+=+7_Changes.c Prototypes+=+=+=+=+=+//
void change_specific_creation_item();
#endif