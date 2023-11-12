#ifndef XP_COMBAT_H
#define XP_COMBAT_H

//+=+=+=+=+=+1_ExperienceSystem.c Prototypes+=+=+=+=+=+//
void update_current_xp();
void calculate_max_xp_at_level();
void calculate_xp_to_next_level();
void level_up();
void run_funcs(); // TODO delete when done with debugging
//+=+=+=+=+=+2_CombatSystem.c Prototypes+=+=+=+=+=+//
int initiate_combat();
void calculate_dmg_done_to_enemy();
void calculate_mana_spent();
//+=+=+=+=+=+3_EnemyGeneration.c Prototypes+=+=+=+=+=+//
void generate_enemy();

// Enemy struct TODO prob move this to utils.h
typedef struct
{
  char Name[20];
  char Description[100];
  char Type[20];
  int Health;
  int Level;
  int ExperienceDroppedOnDeath;
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