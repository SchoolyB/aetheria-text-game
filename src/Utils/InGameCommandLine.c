#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Functions/Logger.h"
#include "./Globals.h"

  // "inventory ---> This Command will list all items in your inventory\n",
char in_game_commands[10][100] = {
  "info ---> This Command will show all hero info\n",
  "/exit ---> This Command will exit the program\n",
  "/quit ---> This Command will exit the program\n",
  "/restart ---> This Command will restart the program\n",
  "/commands ---> This Command will list all available commands\n",
  "/game ---> This Command logs info about the game\n",
  "/clear ---> This Command clears the terminal\n",
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
    if (IS_RESTART_COMMAND(in_game_input))
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
    else if(IS_INFO_COMMAND(in_game_input)){
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

    else if(IS_IN_GAME_COMMANDS_COMMAND(in_game_input)){
      printf("\x1b[32mIN GAME COMMANDS: \x1b[0m\n");
      for (int i = 0; i < 10; i++)
      {
        printf("%s\n", in_game_commands[i]);
      }
    }

    else if(IS_GAME_COMMAND(in_game_input)){
      printf("\x1b[32mGAME INFORMATION: \x1b[0m\n");
      printf("Game Version: %f\n", GAME_VERSION);
      // printf("Game Name: %s\n", game_name);
      // printf("Game Description: %s\n", game_description);
      printf("Game Author: Marshall Burns\n" );
    }

    else if(IS_EXIT_COMMAND(in_game_input)){
      char exitConfirmation[10];
      printf("\x1b[31mRequesting to exit program... \x1b[0m\n");
      printf("\x1b[31mAre you sure you want to exit? (y/n): \x1b[0m\n");
      fgets(exitConfirmation, sizeof(exitConfirmation), stdin);
      REMOVE_NEWLINE_CHARACTER(exitConfirmation);
      if (IS_YES(exitConfirmation))
      {
        printf("Exiting...\n");
        logMessage(logFile, "Exited Program.");
        exit(0);
      }
      else if(IS_NO(exitConfirmation)){
        printf("Exit canceled.\n");
        IN_GAME_COMMAND_LINE(logFile);
      }
      else{
        printf("Invalid input.\n");
        IN_GAME_COMMAND_LINE(logFile);
      }
    }
    else if(strcmp(in_game_input, "/clear") == 0 ){\
      char clearConfirmation[10];
      printf("\x1b[31mRequesting to clear terminal...\x1b[0m\n");
      sleep(1);
      printf("\x1b[31mThis can potentially be a destructive decision. Are you sure you'd like to continue?(y/n)\x1b[0m\n");
      fgets(clearConfirmation, sizeof(clearConfirmation), stdin);
      REMOVE_NEWLINE_CHARACTER(clearConfirmation);
      if(IS_YES(clearConfirmation)){
        printf("Clearing terminal...\n");
        system("clear");
      }
      else if(IS_NO(clearConfirmation)){
        printf("Clear canceled.\n");
      }
      else{
        printf("Invalid input.\n");
        ROOT_LEVEL_COMMAND_LINE(logFile);
      }
    }
    else
    {
      printf("Invalid command.\n");
    }
  }
  return 0;
}