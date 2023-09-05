#ifndef _PLAYERSTATSH_
#define _PLAYERSTATSH_
// Player stats will be constantly referenced and updated throughout the game

struct player_info{
  char player_first_name[20];
  char player_dynasty_name[20];
  char player_origin[20];
  char player_profession[20];
  int  player_age;
  bool player_has_dynasty;
  bool player_has_origin;
  bool player_has_age;
  bool player_is_21;
  bool player_is_30;
  bool player_is_50;
  bool player_has_profession;
  bool player_is_soldier;
  bool player_is_merchant;
  bool player_is_farmer;

  // plan on adding the following:
  // total inventory space
  // current inventory space
  // current gold
  // hero class
  // hero level
  // hero experience
  // hero total health pool
  // hero current health
  // hero total mana pool
  // hero current mana
  // hero total stamina pool
  // hero current stamina
  // hero strength
  // hero dexterity
  // hero intelligence
  // hero wisdom
  // hero charisma
  // hero luck
  // hero physical attack rating
  // hero physical defense rating
  // hero magic attack rating
  // hero magic defense rating 
};
#endif