#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Functions/Logger.h"
#include "./Globals.h"

char commands[10][100] = {
  "inventory ---> This Command will list all items in your inventory\n",
  "info ---> This Command will show all hero info and\n",
  "help ---> This command will open a help menu\n",
  "/exit ---> This Command will exit the program\n",
  "/quit ---> This Command will exit the program\n",
  "/restart ---> This Command will restart the program\n",
  "/commands ---> This Command will list all available commands\n",
  };



  int IN_GAME_COMMAND_LINE(FILE *logFile){
    char input[MAX_INPUT_LENGTH];
    while(1){
      printf("Enter an in game command: ");
      if(fgets(input, sizeof(input), stdin) == NULL){
        perror("fgets");
        exit(1);
      }
      input[strcspn(input, "\n")] = '\0';
    //   if(strcmp(input, "inventory") == 0){
    //     printf("You have %d gold\n", hero.gold);
    //     printf("You have %d potions\n", hero.potions);
    //     printf("You have %d keys\n", hero.k
    // }
      if(strcmp(input, "restart") == 0){
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
        printf("Restart canceled.\n");
        ROOT_LEVEL_COMMAND_LINE(logFile);
      }
      else{
        printf("Invalid input.\n");
        ROOT_LEVEL_COMMAND_LINE(logFile);
      }
      }


     else if(strcmp(input, "info") == 0){
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
    else{
      printf("Invalid Command.\n");
    }
  }
  return 0;
  }