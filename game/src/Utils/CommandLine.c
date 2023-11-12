#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "./Utils.h"
#include "../Source/Items-Inventory/Items-Inventory.h"
#include "../Source/Items-Inventory/2_InventoryManagement.c"

#include "../testing.c"
// start creation includes
#include "../Source/HeroCreation/1_Creation.c"
#include "../Source/HeroCreation/2_Abilities.c"
#include "../Source/HeroCreation/3_BaselineStats.c"
#include "../Source/HeroCreation/4_Attributes.c"
#include "../Source/HeroCreation/5_Inventory.c"
#include "../Source/HeroCreation/6_Confirmation.c"
#include "../Source/HeroCreation/7_Changes.c"
// end hero creation includes

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
    "Allows the player to see and manage their inventory\n",
    "Allows the player to see and manage their inventory\n"};

char possibleOrigins[5][10];
#define FALSE 0
#define TRUE 1

int isRunning = FALSE;
void start_game()
{
  if (isRunning == FALSE)
  {
    isRunning = TRUE;
    printf("Starting Game...\n");
    get_first_name();                  // from 1_Creation.c
    set_abilities();                   // from 2_Abilities.c
    set_baseline_stats();              // from 3_BaselineStats.c
    set_attributes();                  // from 4_Attributes.c
    determine_class_for_inventory();   // from 5_Inventory.c
    confirm_hero_creation_and_stats(); // from 6_Confirmation.c
  }
  else
  {
    printf("Game is already running\n");
    system("clear");
  }
}

//================================================================================================//
int COMMAND_LINE(FILE *logFile)
{
  Hero NewHero;
  char input[100];
  // TODO remove these 3. They are only here when debugging inventory and god mode. see activate_god_mode() in Utils.h
  Inventory.Slot1.isOpen = 1; // 0 = false, 1 = true
  Inventory.Slot2.isOpen = 1; // 0 = false, 1 = true
  Inventory.Slot3.isOpen = 1;

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
      printf("%-15s | %-15s | %-15s | %-10s | %-10s \n", "Profession", "Class", "Level", "Health", "Mana");
      printf("%-15s | %-15s | %-15d | %-10d | %-10d \n", hero.Profession, hero.Class, hero.Level, hero.Health, hero.Mana);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s | %-15s \n", "Strength", "Intelligence", "Dexterity", "Luck");
      printf("%-15d | %-15d | %-15d | %-15d \n", hero.StrengthAttribute.CurrentPoints, hero.IntelligenceAttribute.CurrentPoints, hero.DexterityAttribute.CurrentPoints, hero.LuckAttribute.CurrentPoints);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s |%-15s \n", "Hero Level", "Current XP");
      printf("%-15d |%-f/%-15f \n", hero.Level, hero.CurrentXP, hero.MaxXP);

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
      system("clear");
      check_if_empty_show_none();
      printf("Max Carrying Capacity: %d(lbs)\n", Inventory.MaxCarryingCapacity);
      printf("Current Carrying Capacity Remaining: %d(lbs)\n", Inventory.CarryingCapacity);
      if (Inventory.CarryingCapacity <= 0)
      {
        printf("You are over encumbered and cannot carry any more.\n");
      }
      printf("=====================================================================================================================================\n");
      printf("%-30s | %-35s | %-11s | %-10s | %-10s | %-10s \n", "Equipped Wpn", "Desc.", "Dmg Incr", "Type", "Wt(lbs)", "Val(gold)");
      printf("%-30s | %-35s | %-11d | %-10s | %-10d | %-10d \n", Inventory.EquippedWeapon.Name, Inventory.EquippedWeapon.Description, Inventory.EquippedWeapon.AddedDamage, Inventory.EquippedWeapon.Type, Inventory.EquippedWeapon.Weight, Inventory.EquippedWeapon.Value);
      printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      printf("%-30s | %-35s | %-10s | %-10s | %-10s | %-10s\n", "Eqpd Head Armr", "Desc.", "Health Incr", "Type", "Wt(lbs)", "Val(gold)");
      printf("%-30s | %-35s | %-11d | %-10s | %-10d | %-10d\n", Inventory.EquippedHead.Name, Inventory.EquippedHead.Description, Inventory.EquippedHead.AddedHealth, Inventory.EquippedHead.Type, Inventory.EquippedHead.Weight, Inventory.EquippedHead.Value);
      printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      printf("%-30s | %-35s | %-10s | %-10s | %-10s | %-10s\n", "Eqpd Chest Armr", "Desc.", "Health Incr", "Type", "Wt(lbs)", "Val(gold)");
      printf("%-30s | %-35s | %-11d | %-10s | %-10d | %-10d\n", Inventory.EquippedChest.Name, Inventory.EquippedChest.Description, Inventory.EquippedChest.AddedHealth, Inventory.EquippedChest.Type, Inventory.EquippedChest.Weight, Inventory.EquippedChest.Value);
      printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      printf("%-30s | %-35s | %-10s | %-10s | %-10s | %-10s\n", "Eqpd Leg Armr", "Desc.", "Health Incr", "Type", "Wt(lbs)", "Val(gold)");
      printf("%-30s | %-35s | %-11d | %-10s | %-10d | %-10d\n", Inventory.EquippedLegs.Name, Inventory.EquippedLegs.Description, Inventory.EquippedLegs.AddedHealth, Inventory.EquippedLegs.Type, Inventory.EquippedLegs.Weight, Inventory.EquippedLegs.Value);
      printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      if (Inventory.Slot1.isOpen == 1)
      {
        printf("%-15s \n", "Inventory Slot 1");
        printf("%-15s \n", "None");
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      }
      else
      {
        printf("%-30s | %-35s | %-5s| %-6s | %-10s | %-10s | %-10s\n", "Inventory Slot 1", "Desc.", "Dmg", "Health", "Type", "Wt(lbs)", "Val(gold)");
        printf("%-30s | %-35s | %-5d | %-5d | %-10s | %-10d | %-10d\n", Inventory.Slot1.Item.Name, Inventory.Slot1.Item.Description, Inventory.Slot1.Item.AddedDamage, Inventory.Slot1.Item.AddedHealth, Inventory.Slot1.Item.Type, Inventory.Slot1.Item.Weight, Inventory.Slot1.Item.Value);
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      }

      if (Inventory.Slot2.isOpen == 1)
      {
        printf("%-15s \n", "Inventory Slot 2");
        printf("%-15s \n", "None");
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      }
      else
      {
        printf("%-30s | %-35s | %-5s| %-6s | %-10s | %-10s | %-10s\n", "Inventory Slot 2", "Desc.", "Dmg", "Health", "Type", "Wt(lbs)", "Val(gold)");
        printf("%-30s | %-35s | %-5d | %-5d | %-10s | %-10d | %-10d\n", Inventory.Slot2.Item.Name, Inventory.Slot2.Item.Description, Inventory.Slot2.Item.AddedDamage, Inventory.Slot2.Item.AddedHealth, Inventory.Slot2.Item.Type, Inventory.Slot2.Item.Weight, Inventory.Slot2.Item.Value);
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
      }

      if (Inventory.Slot3.isOpen == 1)
      {
        printf("%-15s \n", "Inventory Slot 3");
        printf("%-15s \n", "None");
      }
      else
      {
        printf("%-30s | %-35s | %-5s| %-6s | %-10s | %-10s | %-10s\n", "Inventory Slot 3", "Desc.", "Dmg", "Health", "Type", "Wt(lbs)", "Val(gold)");
        printf("%-30s | %-35s | %-5d | %-5d | %-10s | %-10d | %-10d\n", Inventory.Slot3.Item.Name, Inventory.Slot3.Item.Description, Inventory.Slot3.Item.AddedDamage, Inventory.Slot3.Item.AddedHealth, Inventory.Slot3.Item.Type, Inventory.Slot3.Item.Weight, Inventory.Slot3.Item.Value);
      }
      printf("=====================================================================================================================================\n");
      inventory_options();
    }
    // GOD MODE IS FOR DEBUGGING. REMOVE BEFORE RELEASE
    else if (IS_GOD_MODE_COMMAND(input))
    {
      activate_god_mode();
      printf("God mode activated.\n");
      sleep(1);
      system("clear");
      printf("Call all functions that you would like to debug here.\n");
      testing_xp_stuff();
    }
    else if (strcmp(input, "test") == 0)
    {
      testing_xp_stuff();
    }

    else
    {
      printf("Invalid command.\n");
      sleep(1);
      system("clear");
    }
  }
  return 0;
}
