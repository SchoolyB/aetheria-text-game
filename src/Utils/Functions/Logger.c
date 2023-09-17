#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void logMessage(FILE *logFile, const char *message)
{
  time_t currentTime;
  time(&currentTime);
  fprintf(logFile, "[%s] %s\n", ctime(&currentTime), message);
  fflush(logFile);
}
