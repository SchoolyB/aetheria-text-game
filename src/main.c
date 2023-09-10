#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Creation.c"

// Function to log messages to a file
void logMessage(FILE *logFile, const char *message) {
    time_t currentTime;
    time(&currentTime);
    fprintf(logFile, "[%s] %s\n", ctime(&currentTime), message);
}

int main() {
    FILE *logFile = fopen(".log", "a"); // "a" mode appends to the file if it exists
    if (logFile == NULL) {
        perror("Error opening the log file");
        exit(1);
    }
    logMessage(logFile, "Program started.");
    startHeroCreation(); 
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
