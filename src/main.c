#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Hero/Source/Creation.c"
#include "./Hero/Source/StatPool.c"
#include "./Chapters/Chapter1/Source/Chapter1.c"
#include "./utils/Escape.c"
#include "./utils/Logger.c"
// Function to log messages to a file

int main()
{
    FILE *logFile = fopen("logs/runtime.log", "a"); // "a" mode appends to the file if it exists
    if (logFile == NULL)
    {
        perror("Error opening the log file");
        exit(1);
    }
    logMessage(logFile, "Program started.");
    startHeroCreation();
    setAllHeroStats();
    startChapterOne();
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
