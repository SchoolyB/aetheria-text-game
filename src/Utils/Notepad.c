#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Globals.h"

#define MAX_NOTE_LENGTH 300
int createNote(){
  
  CREATE_LOG_FILE(notePad, "notepad.txt");
  CREATE_LOG_FILE(logFile, "logs/runtime.log");
    char note[MAX_NOTE_LENGTH];
    printf("Enter a note: ");
    if (fgets(note, sizeof(note), stdin) == NULL)
    {
        // Handle note error
        perror("fgets");
        exit(1);
    }
  REMOVE_NEWLINE_CHARACTER(note);
  time_t entryTimeAndDate;
  time(&entryTimeAndDate);
  fprintf(notePad, "---------Start of Entry---------\n");
  fprintf(notePad, "%s %s\n", ctime(&entryTimeAndDate), note);
  fprintf(notePad, "----------End of Entry----------\n");
  fflush(notePad);
  usleep(500000);
  printf("\x1b[32mNote Added Successfully!\x1b[0m\n");
  logMessage(logFile, "Note Added Successfully!");
  fclose(logFile);
  return 0;
  
}
//===================================================================================================//
// Read all notes from the notepad
int readNotes(){
  FILE *notePad = fopen("notepad.txt", "r"); // "a" mode appends to the file if it exists
    if (notePad == NULL)
    {
        perror("Error opening the log file");
        exit(1);
    }
    char note[MAX_NOTE_LENGTH];
    while (fgets(note, sizeof(note), notePad) != NULL)
    {
        printf("%s", note);
    }
    fclose(notePad);
    return 0;
}

