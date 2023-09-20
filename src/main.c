#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Hero/Source/StatPool.c"
#include "./Chapters/Chapter1/Source/Chapter1.c"
#include "./Utils/Functions/Escape.c"
#include "./Utils/Functions/Logger.c"
#include "./Utils/Functions/Fight.c"
#include "./Utils/Commands.c"
// Function to log messages to a file

int main()
{
    FILE *logFile = fopen("logs/runtime.log", "a"); // "a" mode appends to the file if it exists
    if (logFile == NULL)
    {
        perror("Error opening the log file");
        exit(1);
    }
    command_line_entry(logFile);
    setAllHeroStats();
    startChapterOne();
    // startFight();
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
