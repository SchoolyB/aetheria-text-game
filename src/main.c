#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Hero/Source/Creation.c"
#include "./Hero/Source/StatPool.c"
#include "./Chapters/Chapter1/Source/Chapter1.c"
// Function to log messages to a file
void logMessage(FILE *logFile, const char *message) {
    time_t currentTime;
    time(&currentTime);
    fprintf(logFile, "[%s] %s\n", ctime(&currentTime), message);
    fflush(logFile);

}

int main() {
    FILE *logFile = fopen(".log", "a"); // "a" mode appends to the file if it exists
    if (logFile == NULL) {
        perror("Error opening the log file");
        exit(1);
    }
    logMessage(logFile, "Program started.");
    // startHeroCreation(); 
    // setAllHeroStats();
    startChapter();
    printf("%s\n", hero_first_name);
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
