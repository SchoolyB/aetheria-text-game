#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Globals.h"
#include "./Prototypes.h"
#include "../Source/HeroCreation.c"
char root_level_commands[10][100] = {
    "Start ---> This Command will start the program\n",
    "/restart ---> This Command will restart the program\n",
    "/exit ---> This Command will exit the program\n",
    "/quit ---> This Command will exit the program\n",
    "/commands ---> This Command will list all available commands\n",
    "/game ---> This Command logs info about the game\n",
    "/clear ---> This Command clears the terminal\n",
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
    if (IS_RESTART_COMMAND(input))
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
      IN_GAME_COMMAND_LINE(logFile);
    
      return 0;
    }
    else if (IS_EXIT_COMMAND(input))
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
    else if (IS_ROOT_COMMANDS_COMMAND(input))
    {
      logMessage(logFile, "Requested in game commands.\n");
      char root_level_commands_art[1000] =
      "..######...#######..##.....##.##.....##....###....##....##.########...######.\n"
      ".##....##.##.....##.###...###.###...###...##.##...###...##.##.....##.##....##\n"
      ".##.......##.....##.####.####.####.####..##...##..####..##.##.....##.##......\n"
      ".##.......##.....##.##.###.##.##.###.##.##.....##.##.##.##.##.....##..######.\n"
      ".##.......##.....##.##.....##.##.....##.#########.##..####.##.....##.......##\n"
      ".##....##.##.....##.##.....##.##.....##.##.....##.##...###.##.....##.##....##\n"
      "..######...#######..##.....##.##.....##.##.....##.##....##.########...######.\n";
      printf("\x1b[32m%s\x1b[0m\n", root_level_commands_art);
      printf("=============================================================================\n");
      printf("%-10s | %-30s \n", "Command", "Description");
      printf("----------------------------------------------------------------------------\n");
      printf("%-10s | %-30s \n", "/info", "Shows all hero info");
      printf("%-10s | %-30s \n", "/exit", "Exit the program");
      printf("%-10s | %-30s \n", "/quit", "Exit the program");
      printf("%-10s | %-30s \n", "/restart", "Restart the program");
      printf("%-10s | %-30s \n", "/commands", "Lists all available commands");
      printf("%-10s | %-30s \n", "/game", "Logs info about the game");
      printf("%-10s | %-30s \n", "/clear", "Clears the terminal");
      printf("=============================================================================\n");
    }
    else if(strcmp(input, "/game") == 0){
      logMessage(logFile, "Requested game information.\n");
      printf("\x1b[32mGAME INFORMATION: \x1b[0m\n");
      printf("Build Version: %f\n", GAME_VERSION);
      printf("Game Name: Untitled Text Game\n");
      printf("Game Developer: Marshall Burns\n");
      printf("Game Description: COMING SOON\n");
    }
    else if(IS_CLEAR_COMMAND(input)){
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
