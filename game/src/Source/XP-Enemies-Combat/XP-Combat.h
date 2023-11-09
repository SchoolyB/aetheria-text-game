#ifndef XP_COMBAT_H
#define XP_COMBAT_H

void calculate_xp_to_next_level();
// Enemy struct
typedef struct
{
  char Name[20];
  char Description[100];
  char Type[15];
  int Health;
  int ExperienceDroppedOnDeath;
  int GoldDroppedOnDeath; // might not be used
  // int mana; might be used
  struct EnemyAbility
  {
    char Name[20];
    char Description[100];
    char Type[15];
    int Damage;
  } EnemyAbility1, EnemyAbility2;

} Enemy;

#endif