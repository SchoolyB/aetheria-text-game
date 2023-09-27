#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Source/Stats.c"
#include "./Source/Chapter1.c"
#include "./Utils/Functions/Escape.c"
#include "./Utils/Functions/Logger.c"
#include "./Utils/RootCommandLine.c"
#include "./Utils/InGameCommandLine.c"

int main()
{
    CREATE_LOG_FILE(logFile, "logs/runtime.log");    
    ROOT_LEVEL_COMMAND_LINE(logFile); //starting point
    // IN_GAME_COMMAND_LINE(logFile);
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
