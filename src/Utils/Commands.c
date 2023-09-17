#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Functions/Logger.h"

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

    if (strcmp(input, "exit") == 0 ||
        strcmp(input, "quit") == 0)
    {
      printf("Exiting...\n");
      exit(0);
    }
  }

  return 0;
}
