#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Functions/Logger.h"
#include "./../Hero/Source/Creation.c"

#define MAX_INPUT_LENGTH 100

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
    if (strcmp(input, "restart") == 0)
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

    else if (strcmp(input, "exit") == 0 ||
             strcmp(input, "quit") == 0)
    {
      printf("Exiting...\n");
      logMessage(logFile, "Exiting Program.");
      exit(0);
    }

    else if (strcmp(input, "Start") == 0 ||
             strcmp(input, "start") == 0)
    {
      logMessage(logFile, "Program started.");
      startHeroCreation();

      return 0;
    }
    else if (strcmp(input, "Save") == 0 ||
             strcmp(input, "save") == 0)
    {
    }

    else
    {
      printf("Invalid command.\n");
    }
  }

  return 0;
}
