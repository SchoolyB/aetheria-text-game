#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Functions/Logger.h"
#include "./../Hero/Source/Creation.c"
#include "Macros/Macros.h"
//?+++++For other Macros See: Macros/Macros.h+++++?

#define MAX_INPUT_LENGTH 100 // this is a non-global macro

char commands[10][100] = {
    "Start ---> This Command will start the program\n",
    "/restart ---> This Command will restart the program\n",
    "/exit ---> This Command will exit the program\n",
    "/quit ---> This Command will exit the program\n",
    "/commands ---> This Command will list all available commands\n"};

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
      // Log a restart message
      logMessage(logFile, "Restarting Program.");

      // Execute the program again using execv() with the current command
      if (execv("./a.out", NULL) == -1)
      {
        perror("execv");
        exit(1);
      }
    }

    else if (strcmp(input, "Start") == 0 ||
             strcmp(input, "start") == 0 ||
             strcmp(input, "START") == 0)
    {
      logMessage(logFile, "Program started.");
      startHeroCreation(); // this is a function from Hero/Source/Creation.c STARTS THE PROGRAM

      return 0;
    }

    else if (strcmp(input, "/exit") == 0 ||
             strcmp(input, "/quit") == 0)
    {
      char exitConfirmation[10];
      printf("Requesting to exit program...\n");
      printf("Are you sure you want to exit? (y/n): \n");
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
      printf("\x1b[32mA\x1b[0m");
      printf("\x1b[32mV\x1b[0m");
      printf("\x1b[32mA\x1b[0m");
      printf("\x1b[32mI\x1b[0m");
      printf("\x1b[32mL\x1b[0m");
      printf("\x1b[32mA\x1b[0m");
      printf("\x1b[32mB\x1b[0m");
      printf("\x1b[32mL\x1b[0m");
      printf("\x1b[32mE\x1b[0m");

      printf("\x1b[32m \x1b[0m"); // space

      printf("\x1b[32mC\x1b[0m");
      printf("\x1b[32mO\x1b[0m");
      printf("\x1b[32mM\x1b[0m");
      printf("\x1b[32mM\x1b[0m");
      printf("\x1b[32mA\x1b[0m");
      printf("\x1b[32mN\x1b[0m");
      printf("\x1b[32mD\x1b[0m");
      printf("\x1b[32mS\x1b[0m");
      printf("\x1b[32m:\x1b[0m\n");
      
      for (int i = 0; i < 5; i++)
      {
        printf("%s\n", commands[i]);
      }
      logMessage(logFile, "Requested to see list of available commands.\n");
    }

    else
    {
      printf("Invalid command.\n");
    }
  }

  return 0;
}
