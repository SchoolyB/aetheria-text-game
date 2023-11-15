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
    "/exit or /quit"
    "/restart"
    "/commands"
    "/game"
    "/clear"
    "/nw"
    "/nr"
    "/nc"
    "/lore"
    "/inventory or /inv"};
// TODO possibly make commands single letters example: /i for inventory or /c for commands
char command_descriptions[20][100] = {
    "Shows all hero info\n",
    "Exit the program\n",
    "Restart the program\n",
    "Lists all available commands\n",
    "Clears the terminal\n",
    "Opens the notepad and allows the user to make an entry\n",
    "Opens the notepad and allows the user to read all entries\n",
    "Clears all entries from the notepad",
    "Allows the player to see and manage their inventory\n"};

char possibleOrigins[5][10];

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
  while (1)
  {
    // Prompt the user for input
    printf("Enter an in game command: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
      // Handle input error
      perror("fgets");
      log_error("fgets is NULL", "COMMAND_LINE", "return");
      exit(1);
    }
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "start") == 0)
    {
      logMessage(logFile, "Program started.");
      start_game();

      printf("%s\n", titleArt);
      // TODO Read introduction then do hero creation
      // start_ch0(); //TODO uncomment this when working on story
    }
    else if (IS_RESTART_COMMAND(input))
    {
      // Check if the input is "restart
      char input[10];

      logMessage(logFile, "Requesting To Restart Program.");
      printf(RED "Requesting to restart program..." RESET "\n");
      printf(RED "mAre you sure you want to restart? (y/n):" RESET "\n");
      FGETS(input);
      REMOVE_NEWLINE_CHAR(input);
      if (INPUT_IS_YES(input))
      { // TODO need to find out why path is read  but not execute
      }
      else if (INPUT_IS_NO(input))
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
      MAKE_GREEN(heroInfoArt);
      printf("============================================================================\n");
      printf("%-15s | %-15s | %-15s | %-15s \n", "First Name", "Dynasty Name", "Gender", "Country of Origin");
      printf("%-15s | %-15s | %-15s | %-15s \n", hero.FirstName, hero.LastName, hero.Gender, hero.Homeland);
      printf("----------------------------------------------------------------------------\n");
      printf("%-15s | %-15s | %-15s | %-15s \n", "Profession", "Class", "Health", "Mana");
      printf("%-15s | %-15s | %-15d | %-15d \n", hero.Profession, hero.Class, hero.Health, hero.Mana);
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
      MAKE_GREEN(commands_art);
      printf("=============================================================================\n");
      printf("%-20s | %-30s \n", "Command", "Description");
      printf("----------------------------------------------------------------------------\n");
      printf("%-20s | %-30s \n", "start", "Start the program");
      printf("%-20s | %-30s \n", "/info", "Shows all hero info");
      printf("%-20s | %-30s \n", "/exit or /quit", "Exit the program");
      printf("%-20s | %-30s \n", "/restart", "Restart the program");
      printf("%-20s | %-30s \n", "/commands", "Lists all available commands");
      printf("%-20s | %-30s \n", "/clear", "Clears the terminal");
      printf("%-20s | %-30s \n", "/lore", "Opens the lore menu");
      printf("%-20s | %-30s \n", "/nw", "Opens the notepad and allows the user to make an entry");
      printf("%-20s | %-30s \n", "/nr", "Opens the notepad and allows the user to read all entries");
      printf("%-20s | %-30s \n", "/nc", "Clears all entries from the notepad");
      printf("%-20s | %-30s \n", "/inventory or /inv", "Shows and manage the heros inventory");
      printf("=============================================================================\n");
    }
    else if (IS_EXIT_COMMAND(input))
    {
      char exitConfirmation[10];
      printf(RED "Requesting to exit program..." RESET "\n");
      printf(RED "Are you sure you want to exit? (y/n):" RESET "\n");
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
      printf(RED "Requesting to clear terminal..." RESET "\n");
      sleep(1);
      printf(RED "31mThis can potentially be a destructive decision. Are you sure you'd like to continue?(y/n)" RESET "\n");
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
      printf(RED "Requesting to clear notepad..." RESET "\n");
      sleep(1);
      printf(RED "Once you clear your notepad you will be unable see past notes. Are you sure you'd like to continue?(y/n)" RESET "\n");
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
      char inventoryArt[1000] = ".####.##....##.##.....##.########.##....##.########..#######..########..##....##\n"
                                "..##..###...##.##.....##.##.......###...##....##....##.....##.##.....##..##..##.\n"
                                "..##..####..##.##.....##.##.......####..##....##....##.....##.##.....##...####..\n"
                                "..##..##.##.##.##.....##.######...##.##.##....##....##.....##.########.....##...\n"
                                "..##..##..####..##...##..##.......##..####....##....##.....##.##...##......##...\n"
                                "..##..##...###...##.##...##.......##...###....##....##.....##.##....##.....##...\n"
                                ".####.##....##....###....########.##....##....##.....#######..##.....##....##...\n";
      MAKE_GREEN(inventoryArt);
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
      if (Inventory.Slot1.isOpen == TRUE)
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

      if (Inventory.Slot2.isOpen == TRUE)
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

      if (Inventory.Slot3.isOpen == TRUE)
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
    // TODO GOD MODE & TEST IS FOR DEBUGGING. REMOVE BEFORE RELEASE
    else if (IS_GOD_MODE_COMMAND(input))
    {
      activate_god_mode();
      printf("God mode activated.\n");
      sleep(1);
      system("clear");
    }
    else if (strcmp(input, "test") == 0)
    {
      int inTestMode = TRUE;
      puts("Booting testing module...");
      printf("This testing module is for testing new features and functions.\n");
      sleep(1);

      while (inTestMode == TRUE)
      {
        puts("============================================================================");
        puts("In testing module");
        // RUN FUNCTIONS HERE
        testing_stuff();
        // END FUNCTIONS HERE
        inTestMode = FALSE;
      }
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
