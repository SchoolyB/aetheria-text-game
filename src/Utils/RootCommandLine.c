#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Functions/Logger.h"
#include "../Source/HeroCreation.c"
#include "./Globals.h"

char commands[10][100] = {
    "Start ---> This Command will start the program\n",
    "/restart ---> This Command will restart the program\n",
    "/exit ---> This Command will exit the program\n",
    "/quit ---> This Command will exit the program\n",
    "/commands ---> This Command will list all available commands\n",
    "/heroinfo ---> This Command logs all the heros current info to CLI\n",
    "/gameinfo ---> This Command logs info about the game\n"
    };


int ROOT_LEVEL_COMMAND_LINE(FILE *logFile)
{ // Accept logFile as an argument
  char input[MAX_INPUT_LENGTH];
  while (1)
  {
    // Prompt the user for input
    printf("Enter a root commands: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
      // Handle input error
      perror("fgets");
      exit(1);
    }

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Check if the input is "restart"
    if (strcmp(input, "/restart") == 0)
    {
      char restartConfirmation[10];
      // Log a restart message
      logMessage(logFile, "Restarting Program.");
      printf("\x1b[31mRequesting to restart program... \x1b[0m\n");
      printf("\x1b[31mAre you sure you want to restart? (y/n): \x1b[0m\n");
      fgets(restartConfirmation, sizeof(restartConfirmation), stdin);
      REMOVE_NEWLINE_CHARACTER(restartConfirmation);
      if(IS_YES(restartConfirmation)){
        printf("Restarting...\n");
        if (execv("./a.out", NULL) == -1)
        {
          perror("execv");
          exit(1);
        }
      }
      else if(IS_NO(restartConfirmation)){
        printf("Restart cancelelseed.\n");
        ROOT_LEVEL_COMMAND_LINE(logFile);
      }
      else{
        printf("Invalid input.\n");
        ROOT_LEVEL_COMMAND_LINE(logFile);
      }

      // Execute the program again using execv() with the current command
    }

    else if (strcmp(input, "start") == 0)
    {
      logMessage(logFile, "Program started.");
      char titleArt[] =
"  ______               __      __                            __ \n"                
" /      \             /  |    /  |                          /  |\n"                
"/$$$$$$  |  ______   _$$ |_   $$ |____    ______    ______  $$/   ______\n"        
"$$ |__$$ | /      \ / $$   |  $$      \  /      \  /      \ /  | /      \ \n"     
"$$    $$ |/$$$$$$  |$$$$$$/   $$$$$$$  |/$$$$$$  |/$$$$$$  |$$ | $$$$$$  |\n"  
"$$$$$$$$ |$$    $$ |  $$ | __ $$ |  $$ |$$    $$ |$$ |  $$/ $$ | /    $$ |\n"
"$$ |  $$ |$$$$$$$$/   $$ |/  |$$ |  $$ |$$$$$$$$/ $$ |      $$ |/$$$$$$$ |\n"
"$$ |  $$ |$$       |  $$  $$/ $$ |  $$ |$$       |$$ |      $$ |$$    $$ |\n"
"$$/   $$/  $$$$$$$/    $$$$/  $$/   $$/  $$$$$$$/ $$/       $$/  $$$$$$$/\n";
      printf("%s\n", titleArt);
      startHeroCreation(); // this is a function from Hero/Source/Creation.c STARTS THE PROGRAM
      setAllHeroStats();
      return 0;
    }
    else if (strcmp(input, "/exit") == 0 ||
             strcmp(input, "/quit") == 0)
    {
      char exitConfirmation[10];
      printf("\x1b[31mRequesting to exit program... \x1b[0m\n");
      printf("\x1b[31mAre you sure you want to exit? (y/n): \x1b[0m\n");

      // printf("Are you sure you want to exit? (y/n): \n");
      fgets(exitConfirmation, sizeof(exitConfirmation), stdin);
      REMOVE_NEWLINE_CHARACTER(exitConfirmation);
      if (IS_YES(exitConfirmation))
      {
        printf("Exiting...\n");
        logMessage(logFile, "Exited Program.");
        exit(0);
      }
    }
    else if (strcmp(input, "/commands") == 0)
    {
      printf("\x1b[32mAVAILABLE COMMANDS: \x1b[0m\n");
      for (int i = 0; i < 7; i++)
      {
        printf("%s\n", commands[i]);
      }
      logMessage(logFile, "Requested to see list of available commands.\n");
    }

    else if(strcmp(input, "/heroinfo") == 0){
      logMessage(logFile, "Requested hero information.\n");
      printf("\x1b[32mHERO INFORMATION: \x1b[0m\n");
      // TODO add if var is null then print "Not set"
      printf("First Name: %s\n", hero_first_name);
      printf("Dynasty Name: %s \n", hero_dynasty_name);
      printf("Gender: %s \n", hero_gender);
      printf("Country of Origin: %s \n", hero_homeland);
      printf("Profession: %s \n", hero_profession);
      printf("Class: %s \n", hero_class);
      printf("Level: %d\n", hero_level);
      printf("Hero Health: %d\n", hero_health);
      printf("Hero Mana: %d\n", hero_mana);
      printf("Strength: %d\n", hero_strength);
      printf("Dexterity: %d\n", hero_dexterity);
      printf("Intelligence: %d\n", hero_intelligence);
      printf("Luck: %d\n", hero_luck);
      
      
    }
    else if(strcmp(input, "/gameinfo") == 0){
      logMessage(logFile, "Requested game information.\n");
      printf("\x1b[32mGAME INFORMATION: \x1b[0m\n");
      printf("Build Version: %f\n", GAME_VERSION);
      printf("Game Name: Untitled Text Game\n");
      printf("Game Developer: Marshall Burns\n");
      printf("Game Description: COMING SOON\n");
    }
    else
    {
      printf("Invalid command.\n");
    }
  }

  return 0;
}