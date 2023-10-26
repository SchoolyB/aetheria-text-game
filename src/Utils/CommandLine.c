#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "./Utils.h"
#include "../Source/HeroCreation.c"
#include "../Source/Stats.c"

char commands[20][100] = {
    "start"
    "/info"
    "/exit"
    "/quit"
    "/restart"
    "/commands"
    "/game"
    "/clear"
    "/nw"
    "/nr"
    "/nc"
    "/lore"
    "/inventory"
    "/inv"};
// TODO possibly make commands single letters example: /i for inventory or /c for commands
char command_descriptions[20][100] = {
    "Shows all hero info\n",
    "Exit the program\n",
    "Exit the program\n",
    "Restart the program\n",
    "Lists all available commands\n",
    "Logs info about the game\n",
    "Clears the terminal\n",
    "Opens the notepad and allows the user to make an entry\n",
    "Opens the notepad and allows the user to read all entries\n",
    "Clears all entries from the notepad",
    "Shows the players inventory\n",
    "Shows the players inventory\n"};

char possibleOrigins[5][10];

int isRunning = 0;
void start_game()
{
  if (isRunning == 0)
  {
    isRunning = 1;
    printf("Starting Game...\n");
    get_first_name();
    set_stats_and_abilities_and_inventory();
    set_attributes();
    confirm_hero_creation_and_stats();
  }
  else
  {
    printf("Game is already running\n");
  }
}

//================================================================================================//
int COMMAND_LINE(FILE *logFile)
{
  Hero NewHero;
  char input[100];
  while (1)
  {
    // Prompt the user for input
    printf("Enter an in game command: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
      // Handle input error
      perror("fgets");
      exit(1);
    }
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "start") == 0)
    {
      logMessage(logFile, "Program started.");
      start_game();
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
      // TODO Read introduction then do hero creation
      // start_ch0(); //TODO uncomment this when working on story
    }
    else if (IS_RESTART_COMMAND(input))
    {
      // Check if the input is "restart
      char restartConfirmation[10];
      // Log a restart message
      logMessage(logFile, "Restarting Program.");
      printf("\x1b[31mRequesting to restart program... \x1b[0m\n");
      printf("\x1b[31mAre you sure you want to restart? (y/n): \x1b[0m\n");
      fgets(restartConfirmation, sizeof(restartConfirmation), stdin);
      REMOVE_NEWLINE_CHAR(restartConfirmation);
      if (INPUT_IS_YES(restartConfirmation))
      {
        printf("Restarting...\n");
        if (execv("./Aetheria.o", NULL) == -1)
        {
          perror("execv");
          exit(1);
        }
      }
      else if (INPUT_IS_NO(restartConfirmation))
      {
        printf("Restart canceled.\n");
        COMMAND_LINE(logFile);
      }
      else
      {
        printf("Invalid input.\n");
        COMMAND_LINE(logFile);
      }
    }
    else if (IS_INFO_COMMAND(input))
    {
      logMessage(logFile, "Requested hero information.\n");
      char heroInfoArt[1000] =
          ".##.....##.########.########...#######.....####.##....##.########.#######. \n"
          ".##.....##.##.......##.....##.##.....##.....##..###...##.##......##.....## \n"
          ".##.....##.##.......##.....##.##.....##.....##..####..##.##......##.....## \n"
          ".#########.######...########..##.....##.....##..##.##.##.######..##.....## \n"
          ".##.....##.##.......##...##...##.....##.....##..##..####.##......##.....## \n"
          ".##.....##.##.......##....##..##.....##.....##..##...###.##......##.....## \n"
          ".##.....##.########.##.....##..#######.....####.##....##.##.......#######. \n";
      printf("\x1b[32m%s\x1b[0m\n", heroInfoArt);
      printf("============================================================================\n");
      printf("%-15s | %-15s | %-15s | %-15s \n", "First Name", "Dynasty Name", "Gender", "Country of Origin");
      printf("%-15s | %-15s | %-15s | %-15s \n", hero.FirstName, hero.LastName, hero.Gender, hero.Homeland);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s | %-15s | %-15s \n", "Profession", "Class", "Level", "Health", "Mana");
      printf("%-15s | %-15s | %-15d | %-15d | %-15d \n", hero.Profession, hero.Class, hero.Level, hero.Health, hero.Mana);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s | %-15s \n", "Strength", "Intelligence", "Dexterity", "Luck");
      printf("%-15d | %-15d | %-15d | %-15d \n", hero.StrengthAttribute.CurrentPoints, hero.IntelligenceAttribute.CurrentPoints, hero.DexterityAttribute.CurrentPoints, hero.LuckAttribute.CurrentPoints);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s \n", "Ability 1", "Ability 2", "Ability 3");
      printf("%-15s | %-15s | %-15s \n", hero.Ability1.Name, hero.Ability2.Name, hero.Ability3.Name);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s | %-15s \n", "Equipped Weapon", "Head Armor", "Chest Armor", "Leg Armor");
      printf("%-15s | %-15s | %-15s | %-15s \n", Inventory.Weapon.Name, Inventory.Head.Name, Inventory.Chest.Name, Inventory.Legs.Name);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s\n", "Equipped Bag", "Carrying Capacity", "Gold");
      printf("%-15s | %-15d | %-15d\n", Inventory.Backpack.Name, Inventory.Backpack.CarryingCapacity, Inventory.CurrentGold);
      printf("============================================================================\n");
    }
    else if (IS_COMMANDS_COMMAND(input))
    {
      logMessage(logFile, "Requested in game commands.\n");
      char commands_art[1000] =
          "..######...#######..##.....##.##.....##....###....##....##.########...######.\n"
          ".##....##.##.....##.###...###.###...###...##.##...###...##.##.....##.##....##\n"
          ".##.......##.....##.####.####.####.####..##...##..####..##.##.....##.##......\n"
          ".##.......##.....##.##.###.##.##.###.##.##.....##.##.##.##.##.....##..######.\n"
          ".##.......##.....##.##.....##.##.....##.#########.##..####.##.....##.......##\n"
          ".##....##.##.....##.##.....##.##.....##.##.....##.##...###.##.....##.##....##\n"
          "..######...#######..##.....##.##.....##.##.....##.##....##.########...######.\n";
      printf("\x1b[32m%s\x1b[0m\n", commands_art);
      printf("=============================================================================\n");
      printf("%-10s | %-30s \n", "Command", "Description");
      printf("----------------------------------------------------------------------------\n");
      printf("%-10s | %-30s \n", "start", "Start the program");
      printf("%-10s | %-30s \n", "/info", "Shows all hero info");
      printf("%-10s | %-30s \n", "/exit", "Exit the program");
      printf("%-10s | %-30s \n", "/quit", "Exit the program");
      printf("%-10s | %-30s \n", "/restart", "Restart the program");
      printf("%-10s | %-30s \n", "/commands", "Lists all available commands");
      printf("%-10s | %-30s \n", "/game", "Logs info about the game");
      printf("%-10s | %-30s \n", "/clear", "Clears the terminal");
      printf("%-10s | %-30s \n", "/lore", "Opens the lore menu");
      printf("%-10s | %-30s \n", "/nw", "Opens the notepad and allows the user to make an entry");
      printf("%-10s | %-30s \n", "/nr", "Opens the notepad and allows the user to read all entries");
      printf("%-10s | %-30s \n", "/nc", "Clears all entries from the notepad");
      printf("%-10s | %-30s \n", "/inventory", "Shows the players inventory");
      printf("%-10s | %-30s \n", "/inv", "Shows the players inventory");
      printf("=============================================================================\n");
    }

    else if (IS_GAME_COMMAND(input))
    {
      printf("\x1b[32mGAME INFORMATION: \x1b[0m\n");
      printf("Game Version: v0.0.1 \n");
      printf("Game Author: Marshall Burns\n");
    }
    else if (IS_EXIT_COMMAND(input))
    {
      char exitConfirmation[10];
      printf("\x1b[31mRequesting to exit program... \x1b[0m\n");
      printf("\x1b[31mAre you sure you want to exit? (y/n): \x1b[0m\n");
      fgets(exitConfirmation, sizeof(exitConfirmation), stdin);
      REMOVE_NEWLINE_CHAR(exitConfirmation);
      if (INPUT_IS_YES(exitConfirmation))
      {

        printf("Exiting...\n");
        logMessage(logFile, "Exited Program.");
        exit(0);
      }
      else if (INPUT_IS_NO(exitConfirmation))
      {
        printf("Exit canceled.\n");
        COMMAND_LINE(logFile);
      }
      else
      {
        printf("Invalid input.\n");
        COMMAND_LINE(logFile);
      }
    }
    else if (IS_CLEAR_COMMAND(input))
    {
      char clearConfirmation[10];
      printf("\x1b[31mRequesting to clear terminal...\x1b[0m\n");
      sleep(1);
      printf("\x1b[31mThis can potentially be a destructive decision. Are you sure you'd like to continue?(y/n)\x1b[0m\n");
      fgets(clearConfirmation, sizeof(clearConfirmation), stdin);
      REMOVE_NEWLINE_CHAR(clearConfirmation);
      if (INPUT_IS_YES(clearConfirmation))
      {
        printf("Clearing terminal...\n");
        system("clear");
      }
      else if (INPUT_IS_NO(clearConfirmation))
      {
        printf("Clear canceled.\n");
      }
      else
      {
        printf("Invalid input.\n");
        COMMAND_LINE(logFile);
      }
    }

    else if (IS_WRITE_NOTE_COMMAND(input))
    {
      createNote();
    }

    else if (IS_READ_NOTES_COMMAND(input))
    {
      readNotes();
    }

    else if (IS_CLEAR_NOTES_COMMAND(input))
    {
      char clearNotesConfirmation[10];
      printf("\x1b[31mRequesting to clear notepad...\x1b[0m\n");
      sleep(1);
      printf("\x1b[31mOnce you clear your notepad you will be unable see past notes. Are you sure you'd like to continue?(y/n)\x1b[0m\n");
      fgets(clearNotesConfirmation, sizeof(clearNotesConfirmation), stdin);
      REMOVE_NEWLINE_CHAR(clearNotesConfirmation);
      if (INPUT_IS_YES(clearNotesConfirmation))
      {
        printf("Clearing notes...\n");
        clearNotes();
      }
      else if (INPUT_IS_NO(clearNotesConfirmation))
      {
        printf("Clear canceled.\n");
      }
      else
      {
        printf("Invalid input.\n");
      }
    }
    else if (IS_LORE_COMMAND(input))
    {
      initscr();            // Initialize the ncurses library
      cbreak();             // Line buffering disabled, pass on all characters
      noecho();             // Don't echo while we do getch()
      keypad(stdscr, TRUE); // Enable special keys like arrow keys

      char possibleOrigins[6][15] = {
          "1: Empyrea",
          "2: Wesward",
          "3: Magdalar",
          "4: Ashvadan",
          "5: Nadafia",
          "Back\n"};

      int selected_option = 0;
      int num_options = sizeof(possibleOrigins) / sizeof(possibleOrigins[0]);

      while (1)
      {
        clear(); // Clear the screen

        // Print the menu options
        for (int i = 0; i < num_options; i++)
        {
          if (i == selected_option)
          {
            attron(A_REVERSE); // Highlight the selected option
          }
          mvprintw(i, 0, possibleOrigins[i]);
          attroff(A_REVERSE);
        }

        // Get user input
        int ch = getch();
        switch (ch)
        {
        case KEY_UP:
          selected_option--;
          if (selected_option < 0)
          {
            selected_option = num_options - 1;
          }
          break;
        case KEY_DOWN:
          selected_option++;
          if (selected_option >= num_options)
          {
            selected_option = 0;
          }
          break;
        case 10: // Enter key
          // Handle the selected option here
          if (selected_option == 0)
          {
            READ_FULL_TXT_FILE("./Lore/Countries/Empyrea.txt");
          }
          else if (selected_option == 1)
          {
            READ_FULL_TXT_FILE("./Lore/Countries/Wesward.txt");
          }
          else if (selected_option == 2)
          {
            READ_FULL_TXT_FILE("./Lore/Countries/Magdalar.txt");
          }
          else if (selected_option == 3)
          {
            READ_FULL_TXT_FILE("./Lore/Countries/Ashvadan.txt");
          }
          else if (selected_option == 4)
          {
            READ_FULL_TXT_FILE("./Lore/Countries/Nadafia.txt");
          }
          else if (selected_option == 5)
          {
            endwin(); // End ncurses mode
            COMMAND_LINE(logFile);
          }
          break;
        }
      }
      return 0;
    }
    else if (IS_INVENTORY_COMMAND(input))
    {
      printf("===============================================\n");
      printf("Equipped Weapon | Description  | Added Damage\n");
      printf("%-20s | %-20s | %-20d \n", Inventory.Weapon.Name, Inventory.Weapon.Description, Inventory.Weapon.AddedDamage);
      printf("-----------------------------------------------\n");
      printf("Equipped Head Armor | Description \n");
      printf("%-20s | %-20s | \n", Inventory.Head.Name, Inventory.Head.Description);
      printf("-----------------------------------------------\n");
      printf("Equipped Chest Armor | Description \n");
      printf("%-20s | %-20s | \n", Inventory.Chest.Name, Inventory.Chest.Description);
      printf("-----------------------------------------------\n");
      printf("Equipped Leg Armor | About Description \n");
      printf("%-20s | %-20s | \n", Inventory.Legs.Name, Inventory.Legs.Description);
      printf("-----------------------------------------------\n");
      printf("Equipped Bag | Description \n");
      printf("%-20s | %-20s | \n", Inventory.Backpack.Name, Inventory.Backpack.Description);
      printf("===============================================\n");
    }
    else
    {
      printf("Invalid command.\n");
    }
  }
  return 0;
}