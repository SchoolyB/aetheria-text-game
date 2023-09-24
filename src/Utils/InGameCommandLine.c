#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Functions/Logger.h"
#include "./Globals.h"

char in_game_commands[10][100] = {
  "inventory ---> This Command will list all items in your inventory\n",
  "info ---> This Command will show all hero info and\n",
  "help ---> This command will open a help menu\n",
  "/exit ---> This Command will exit the program\n",
  "/quit ---> This Command will exit the program\n",
  "/restart ---> This Command will restart the program\n",
  "/commands ---> This Command will list all available commands\n"
  };

int IN_GAME_COMMAND_LINE(FILE *logFile){
  char in_game_input[MAX_INPUT_LENGTH];
  while (1)
  {
    // Prompt the user for input
    printf("Enter a an in game command: ");
    if (fgets(in_game_input, sizeof(in_game_input), stdin) == NULL)
    {
      // Handle in_game_input error
      perror("fgets");
      exit(1);
    }

    // Remove the newline character from the in_game_input
    in_game_input[strcspn(in_game_input, "\n")] = '\0';

    // Check if the in_game_input is "restart"
    if (strcmp(in_game_input, "/restart") == 0)
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
        printf("Restart canceled.\n");
        IN_GAME_COMMAND_LINE(logFile);
      }
      else{
        printf("Invalid input.\n");
        IN_GAME_COMMAND_LINE(logFile);
      }
    }
    else if(strcmp(in_game_input, "/info") == 0){
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
  }
  return 0; 
}
