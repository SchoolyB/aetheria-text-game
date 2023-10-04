#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Source/Stats.c"
#include "./Source/Chapter0.c"
#include "./Utils/Functions/Escape.c"
#include "./Utils/Functions/Logger.c"
#include "./Utils/CommandLine.c"
#include "./Source/Enemies.c"

int main()
{
    CREATE_LOG_FILE(logFile, "logs/runtime.log");    
    COMMAND_LINE(logFile);
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
