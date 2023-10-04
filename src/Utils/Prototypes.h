// This file contains ALL the prototypes for the functions in the program.

//-----====================-----//
//  SECTION 0: COMMAND LINE PROTOTYPES
#ifndef ROOT_LEVEL_COMMAND_LINE_H
#define ROOT_LEVEL_COMMAND_LINE_H
int ROOT_LEVEL_COMMAND_LINE();
#endif
//-----------------------------------//
#ifndef IN_GAME_COMMAND_LINE_H
#define IN_GAME_COMMAND_LINE_H
int IN_GAME_COMMAND_LINE();
#endif
//END OF COMMAND LINE PROTOTYPES//


//-----====================-----//
//     SECTION 1: Util functions Prototypes
// For logger
#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
void logMessage(FILE *logFile, const char *message);
#endif
//-----------------------------------//
// For notepad commands
#ifndef NOTEPAD_H
#define NOTEPAD_H
int createNote();
int readNotes();
#endif
//-----------------------------------//
//END OF UTIL FUNCTIONS PROTOTYPES//


//-----====================-----//
//     SECTION 2: Hero Creation Prototypes
int startHeroCreation();
int getFirstName();
int dynastyNameCheck();
int getDynastyName();
int confirmDynastyName();
int heroGenderCheck();
int getHeroGender();
int confirmHeroGender();
int getHeroHomeland();
int getHeroHomelandWithoutDescriptions();
int seeHomelandDescriptions();
int getHeroProfession();
int getHeroClass();
int setWarriorAbilities();
//END OF HERO CREATION PROTOTYPES//

void logCreationData();
int appendToLog();


//-----====================-----//
//     SECTION 3: Hero Stats Prototypes
int setHeroStatsAndAbilities();
int setAllHeroStats();
int setHeroLvl();
int initialSKillPointAllocation();
int capAllocation();
int refreshPoints();
//END OF HERO STATS PROTOTYPES//


//-----====================-----//
//   SECTION 4: STORIES PROTOTYPES
// Chapter 0
void start_ch0();
void ch0_wake_up();
void ch0_go_to_main_deck();
