#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Functions/Logger.h"
#include "./../Hero/Source/Creation.c"
#include "./Macros/Macros.h"
#include "../Utils/Global_Project_Variables.h"
//?+++++For other Macros See: Macros/Macros.h+++++?

#define MAX_INPUT_LENGTH 100 // this is a non-global macro

char commands[10][100] = {
    "Start ---> This Command will start the program\n",
    "/restart ---> This Command will restart the program\n",
    "/exit ---> This Command will exit the program\n",
    "/quit ---> This Command will exit the program\n",
    "/commands ---> This Command will list all available commands\n",
    "/heroinfo ---> This Command logs all the heros current info to CLI\n",
    "/gameinfo ---> This Command logs info about the game\n",
    //"inventory ---> This Command will list all items currently in inventory\n",
    //"save ---> This Command will save the game\n",
    //"load ---> This Command will load the game\n",
    };


int command_line_entry(FILE *logFile)
{ // Accept logFile as an argument
  char input[MAX_INPUT_LENGTH];
  while (1)
  {
    // Prompt the user for input
    printf("Enter a command: ");
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
        printf("Restart cancelled.\n");
        command_line_entry(logFile);
      }
      else{
        printf("Invalid input.\n");
        command_line_entry(logFile);
      }

      // Execute the program again using execv() with the current command
    }

    else if (strcmp(input, "start") == 0)
    {
      logMessage(logFile, "Program started.");
      startHeroCreation(); // this is a function from Hero/Source/Creation.c STARTS THE PROGRAM
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
    // else if (strcmp(input, "Save") == 0 ||
    //          strcmp(input, "save") == 0)
    // {
    // DO SOMETHING
    // }
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
