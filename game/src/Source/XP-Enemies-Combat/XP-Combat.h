#ifndef XP_COMBAT_H
#define XP_COMBAT_H

// START OF PROTOTYPES
//+=+=+=+=+=+1_ExperienceSystem.c Prototypes+=+=+=+=+=+//
void calculate_current_xp();
void calculate_xp_cap_at_current_level();
void level_up();
void calculate_hero_health_after_level_up();
void calculate_hero_mana_after_level_up();

void calculate_enemy_base_xp_dropped();
void calculate_enemy_xp_dropped_with_modifier();
//+=+=+=+=+=+2_CombatSystem.c Prototypes+=+=+=+=+=+//
int initiate_combat();
void calculate_dmg_done_to_enemy();
void calculate_mana_spent();
void calculate_dmg_done_to_hero();
void enemy_makes_move();
int check_hero_remaining_mana();
void refresh_combat_ui();
void show_combat_help_menu();
void show_combat_inventory_menu();
void log_combat_hero_actions();
void log_combat_enemy_actions();
//+=+=+=+=+=+3_EnemyGeneration.c Prototypes+=+=+=+=+=+//
void generate_enemy();
void generate_random_enemy_ability1();
void generate_random_enemy_ability2();
int calculate_new_enemy_ability_dmg1();
int calculate_new_enemy_ability_dmg2();
void set_enemy_health();
void calculate_enemy_health_with_modifier();
//+=+=+=+=+=+4_HeroGeneration.c Prototypes+=+=+=+=+=+//

// Enemy struct TODO prob move this to utils.h
typedef struct
{
  char Name[20];
  char Description[100];
  char Type[20];
  int Health;
  int Level;
  float ExperienceDroppedOnDeath;
  int GoldDroppedOnDeath; // might not be used
  // int mana; might be used
  struct EnemyAbility
  {
    char Name[20];
    char Description[100];
    char Type[15];
    int Damage;
  } EnemyAbility1, EnemyAbility2
} Enemy;
#endif