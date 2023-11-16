#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Utils/CommandLine.c"

int main()
{
    // !IMPORTANT the path of the log file is accessed from where the executable is located
    CREATE_LOG_FILE(logFile, "../game/src/logs/runtime.log");
    logMessage(logFile, "Program Started Successfully.");
    COMMAND_LINE(logFile);
    logMessage(logFile, "Program closed Successfully.");
    fclose(logFile);
    return 0;
}
