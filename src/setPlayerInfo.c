#include <string.h>
#include "./headers/PlayerInfoAndStats.h"
#include "./headers/Perks.h"

int solidifyPlayerInfo(){
  struct player_info first_name;
  struct player_info dynasty_name;
  struct player_info origin;
  struct player_info profession;
  struct player_info age;
  struct player_info has_dynasty;
  struct player_info has_origin;
  struct player_info has_age;
  struct player_info is_21; 
  struct player_info is_30;
  struct player_info is_50;
  struct player_info has_profession;
  struct player_info is_soldier;
  struct player_info is_merchant;
  struct player_info is_farmer;
strcpy(first_name.player_first_name, "first_name");
printf("%s\n", first_name.player_first_name);
}
int setSoldierPerks(){
  struct perk_1 soldier_perk_1;
  struct perk_2 soldier_perk_2;
  struct perk_3 soldier_perk_3;

  strcpy(soldier_perk_1.name, "Thick Skin");
  strcpy(soldier_perk_1.description, "Take less damage");
  
  strcpy(soldier_perk_2.name, "Pack Mule");
  strcpy(soldier_perk_2.description, "Carry more items");
  
  strcpy(soldier_perk_3.name, "Recruit");
  strcpy(soldier_perk_3.description, "You have some training");
}

int setMerchantPerks(){
  struct perk_1 merchant_perk_1;
  struct perk_2 merchant_perk_2;
  struct perk_3 merchant_perk_3;

  strcpy(merchant_perk_1.name, "Haggler");
  strcpy(merchant_perk_1.description, "Get better prices");
  
  strcpy(merchant_perk_2.name, "Pack Mule");
  strcpy(merchant_perk_2.description, "Carry more items");
  
  strcpy(merchant_perk_3.name, "Recruit");
  strcpy(merchant_perk_3.description, "You have some training");
}

int setFarmerPerks(){
  struct perk_1 farmer_perk_1;
  struct perk_2 farmer_perk_2;
  struct perk_3 farmer_perk_3;

  strcpy(farmer_perk_1.name, "Green Thumb");
  strcpy(farmer_perk_1.description, "Grow more crops");
  
  strcpy(farmer_perk_2.name, "Pack Mule");
  strcpy(farmer_perk_2.description, "Carry more items");
  
  strcpy(farmer_perk_3.name, "Recruit");
  strcpy(farmer_perk_3.description, "You have some training");
}
