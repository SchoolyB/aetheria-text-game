#include <stdio.h>
#include "../Global_Variables/Hero.h"

int hero_health;
int hero_mana;
int hero_strength;
int hero_dexterity;
int hero_intelligence;
int hero_luck;
int hero_level;
char hero_class[10];  

int setHeroHealth() {
  if(strcmp(hero_class, "Warrior") == 0 ||
  strcmp(hero_class, "warrior") == 0 ||
  strcmp(hero_class, "WARRIOR") == 0) {
    hero_health = 120;
  }
  else if(strcmp(hero_class, "Mage") == 0 ||
  strcmp(hero_class, "mage") == 0 ||
  strcmp(hero_class, "MAGE") == 0) {
    hero_health = 70;
  }
  else if(strcmp(hero_class, "Rogue") == 0 ||
  strcmp(hero_class, "rogue") == 0 ||
  strcmp(hero_class, "ROGUE") == 0) {
    hero_health = 80;
  }
  else if(strcmp(hero_class, "Cleric") == 0 ||
  strcmp(hero_class, "cleric") == 0 ||
  strcmp(hero_class, "CLERIC") == 0) {
    hero_health = 100;
  }
  else if(strcmp(hero_class, "Bard") == 0 ||
  strcmp(hero_class, "bard") == 0 ||
  strcmp(hero_class, "BARD") == 0) {
    hero_health = 70;
  }
  else {
    return 1;
  }
  return 0;
}

int setHeroMana() {
  if(strcmp(hero_class, "Warrior") == 0 ||
  strcmp(hero_class, "warrior") == 0 ||
  strcmp(hero_class, "WARRIOR") == 0) {
    hero_mana = 20;
  }
  else if(strcmp(hero_class, "Mage") == 0 ||
  strcmp(hero_class, "mage") == 0 ||
  strcmp(hero_class, "MAGE") == 0) {
    hero_mana = 120;
  }
  else if(strcmp(hero_class, "Rogue") == 0 ||
  strcmp(hero_class, "rogue") == 0 ||
  strcmp(hero_class, "ROGUE") == 0) {
    hero_mana = 80;
  }
  else if(strcmp(hero_class, "Cleric") == 0 ||
  strcmp(hero_class, "cleric") == 0 ||
  strcmp(hero_class, "CLERIC") == 0) {
    hero_mana = 100;
  }
  else if(strcmp(hero_class, "Bard") == 0 ||
  strcmp(hero_class, "bard") == 0 ||
  strcmp(hero_class, "BARD") == 0) {
    hero_mana = 70;
  }
  else {
    return 1;
  }
  return 0;
}

int setHeroStrength() {
  if(strcmp(hero_class, "Warrior") == 0 ||
    strcmp(hero_class, "warrior") == 0 ||
    strcmp(hero_class, "WARRIOR") == 0) {
      hero_strength = 10;
    }
    else if(strcmp(hero_class, "Mage") == 0 ||
    strcmp(hero_class, "mage") == 0 ||
    strcmp(hero_class, "MAGE") == 0) {
      hero_strength = 5;
    }
    else if(strcmp(hero_class, "Rogue") == 0 ||
    strcmp(hero_class, "rogue") == 0 ||
    strcmp(hero_class, "ROGUE") == 0) {
      hero_strength = 7;
    }
    else if(strcmp(hero_class, "Cleric") == 0 ||
    strcmp(hero_class, "cleric") == 0 ||
    strcmp(hero_class, "CLERIC") == 0) {
      hero_strength = 8;
    }
    else if(strcmp(hero_class, "Bard") == 0 ||
    strcmp(hero_class, "bard") == 0 ||
    strcmp(hero_class, "BARD") == 0) {
      hero_strength = 5;
    }
    else {
      return 1;
    }
    return 0;
}

int setHeroDexterity() {
  if(strcmp(hero_class, "Warrior") == 0 ||
  strcmp(hero_class, "warrior") == 0 ||
  strcmp(hero_class, "WARRIOR") == 0) {
    hero_dexterity = 5;
  }
  else if(strcmp(hero_class, "Mage") == 0 ||
  strcmp(hero_class, "mage") == 0 ||
  strcmp(hero_class, "MAGE") == 0) {
    hero_dexterity = 7;
  }
  else if(strcmp(hero_class, "Rogue") == 0 ||
  strcmp(hero_class, "rogue") == 0 ||
  strcmp(hero_class, "ROGUE") == 0) {
    hero_dexterity = 10;
  }
  else if(strcmp(hero_class, "Cleric") == 0 ||
  strcmp(hero_class, "cleric") == 0 ||
  strcmp(hero_class, "CLERIC") == 0) {
    hero_dexterity = 8;
  }
  else if(strcmp(hero_class, "Bard") == 0 ||
  strcmp(hero_class, "bard") == 0 ||
  strcmp(hero_class, "BARD") == 0) {
    hero_dexterity = 7;
  }
  else {
    return 1;
  }
  return 0;
}

int setHeroIntelligence() {
  if(strcmp(hero_class, "Warrior") == 0 ||
  strcmp(hero_class, "warrior") == 0 ||
  strcmp(hero_class, "WARRIOR") == 0) {
    hero_intelligence = 5;
  }
  else if(strcmp(hero_class, "Mage") == 0 ||
  strcmp(hero_class, "mage") == 0 ||
  strcmp(hero_class, "MAGE") == 0) {
    hero_intelligence = 10;
  }
  else if(strcmp(hero_class, "Rogue") == 0 ||
  strcmp(hero_class, "rogue") == 0 ||
  strcmp(hero_class, "ROGUE") == 0) {
    hero_intelligence = 7;
  }
  else if(strcmp(hero_class, "Cleric") == 0 ||
  strcmp(hero_class, "cleric") == 0 ||
  strcmp(hero_class, "CLERIC") == 0) {
    hero_intelligence = 8;
  }
  else if(strcmp(hero_class, "Bard") == 0 ||
  strcmp(hero_class, "bard") == 0 ||
  strcmp(hero_class, "BARD") == 0) {
    hero_intelligence = 10;
  }
  else {
    return 1;
  }
  return 0;
}

int setHeroLuck() {
  if(strcmp(hero_class, "Warrior") == 0 ||
  strcmp(hero_class, "warrior") == 0 ||
  strcmp(hero_class, "WARRIOR") == 0) {
    hero_luck = 5;
  }
  else if(strcmp(hero_class, "Mage") == 0 ||
  strcmp(hero_class, "mage") == 0 ||
  strcmp(hero_class, "MAGE") == 0) {
    hero_luck = 7;
  }
  else if(strcmp(hero_class, "Rogue") == 0 ||
  strcmp(hero_class, "rogue") == 0 ||
  strcmp(hero_class, "ROGUE") == 0) {
    hero_luck = 8;
  }
  else if(strcmp(hero_class, "Cleric") == 0 ||
  strcmp(hero_class, "cleric") == 0 ||
  strcmp(hero_class, "CLERIC") == 0) {
    hero_luck = 10;
  }
  else if(strcmp(hero_class, "Bard") == 0 ||
  strcmp(hero_class, "bard") == 0 ||
  strcmp(hero_class, "BARD") == 0) {
    hero_luck = 7;
  }
  else {
    return 1;
  }
  return 0;
}

int setHeroLvl() {
  hero_level = 1;
  return 0;
}

int setAllHeroStats() {
  setHeroHealth();
  setHeroMana();
  setHeroStrength();
  setHeroDexterity();
  setHeroIntelligence();
  setHeroLuck();
  setHeroLvl();
  return 0;
}