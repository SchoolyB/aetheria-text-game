#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Source/Stats.c"
#include "./Source/Chapter1.c"
#include "./Utils/Functions/Escape.c"
#include "./Utils/Functions/Logger.c"
#include "./Utils/Functions/Fight.c"
#include "./Utils/RootCommandLine.c"
#include "./Utils/InGameCommandLine.c"
// Function to log messages to a file

int main()
{
    FILE *logFile = fopen("logs/runtime.log", "a"); // "a" mode appends to the file if it exists
    if (logFile == NULL)
    {
        perror("Error opening the log file");
        exit(1);
    }
    ROOT_LEVEL_COMMAND_LINE(logFile); //starting point
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
