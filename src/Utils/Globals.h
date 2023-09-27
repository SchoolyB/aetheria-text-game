#ifndef GLOBALS_H 
#define GLOBALS_H 


// TODO change this to a string
float GAME_VERSION = 0.1;


// This file contains all the global variables that are used to store the hero's information
extern char hero_first_name[10];
extern char hero_dynasty_name[10];
extern char hero_gender[10];
extern char hero_homeland[10];
extern char hero_profession[15];
extern char hero_class[10];
// Hero Primary Stats Have a max value of 200....this might change
extern int hero_health;
extern int hero_mana;
// Hero Secondary Stats Have a max value of 50
extern int hero_strength;
extern int hero_intelligence;
extern int hero_dexterity;
extern int hero_luck;
extern int hero_level;
// Hero Attack and Defense
extern int hero_atk;
extern int hero_def;

//Hero abilities
extern char hero_ability1[20];
extern char hero_ability2[20];
extern char hero_ability3[20];

#endif

