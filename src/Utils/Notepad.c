#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "./Macros.h"
#include "./Globals.h"

#define MAX_NOTE_LENGTH 300
int createNote(){
  FILE *notePad = fopen("notepad.txt", "a"); // "a" mode appends to the file if it exists
    if (notePad == NULL)
    {
        perror("Error opening the log file");
        exit(1);
    }
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
  fprintf(notePad, "%s %s\n", ctime(&entryTimeAndDate), note);
  fflush(notePad);
}