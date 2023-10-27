#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Utils/CommandLine.c"

int main()
{
    CREATE_LOG_FILE(logFile, "logs/runtime.log");
    COMMAND_LINE(logFile);
    logMessage(logFile, "Program ended.");
    fclose(logFile);
    return 0;
}
